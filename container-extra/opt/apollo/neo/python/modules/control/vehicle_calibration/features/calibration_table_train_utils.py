"""calibration train utils"""
import os

import h5py
import numpy as np

import modules.control.control_component.proto.calibration_table_pb2 as calibration_table_pb2

from modules.control.vehicle_calibration.features.neural_network_tf import NeuralNetworkTF
import modules.control.vehicle_calibration.common.logging as logging
import modules.control.vehicle_calibration.common.proto_utils as proto_utils
import modules.control.vehicle_calibration.features.calibration_table_utils as calibration_table_utils


def generate_segments(h5s):
    """
    generate segments
    """
    segments = []
    for h5 in h5s:
        logging.info('Loading %s' % str(h5))
        with h5py.File(h5, 'r+') as fin:
            # print("fin values: ", fin.values())
            # values_veiw = fin.values()
            # for dataset in values_veiw:
            #     print("dataset name is ", dataset.name)
            #     print("dataset is ", dataset[:])
            segments.extend(map(np.array, fin.values()))
    # shuffle(segments)
    logging.info('Segments count: %d', len(segments))
    # print("list segments: ", segments)
    return segments


def generate_data(segments):
    """ combine data from each segments """
    total_len = 0
    for segment in segments:
        total_len += segment.shape[0]
        # print("each segment is: ", segment)
        # print("each segment shape is: ", segment.shape[0])
    logging.info('total_len = %d' % total_len)
    # print("total_len = ", total_len)
    dim_input = 2
    dim_output = 1
    X = np.zeros([total_len, dim_input])
    Y = np.zeros([total_len, dim_output])
    i = 0
    for segment in segments:
            if segment.ndim == 1:
                X[i, 0] = segment[0]  # speed
                X[i, 1] = segment[2]  # cmd
                Y[i, 0] =segment[1]  # acc
                i += 1
            elif segment.ndim == 2:
                for k in range(1, segment.shape[0]):
                    # print("k is ", k)
                    # print("segment[k]: ", segment[k])
                    # print("segment[k, [0, 2]]: ", segment[k, [0, 2]])
                    # print("segment[k, 1]: ", segment[k, 1])
                    X[i, 0:2] = segment[k, [0, 2]]  # speed & cmd
                    Y[i, 0] = segment[k, 1]  # acc
                    i += 1
    return X, Y


def train_model(data_sets, layer, train_alpha):
    """
    train model
    """
    (X_train, Y_train), (X_test, Y_test) = data_sets

    model = NeuralNetworkTF(layer)
    _, train_cost, test_cost = model.train(X_train, Y_train, X_test, Y_test,
                                           alpha=train_alpha, print_loss=True)
    logging.info(" model train cost: %f" % train_cost)
    logging.info(" model test cost: %f " % test_cost)
    return model


def write_table(model, target_dir,
                speed_min, speed_max, speed_segment_num,
                axis_cmd_min, axis_cmd_max, cmd_segment_num,
                table_filename):
    """
    write calibration table
    """
    calibration_table_pb = calibration_table_pb2.calibration_table()

    speed_array = np.linspace(speed_min, speed_max, num=speed_segment_num)
    cmd_array = np.linspace(axis_cmd_min, axis_cmd_max, num=cmd_segment_num)

    speed_array, cmd_array = np.meshgrid(speed_array, cmd_array)  # col, row
    grid_array = np.array([[s, c] for s, c in zip(np.ravel(speed_array), np.ravel(cmd_array))])
    acc_array = model.predict(grid_array).reshape(speed_array.shape)

    for cmd_index in range(cmd_segment_num):
        for speed_index in range(speed_segment_num):
            item = calibration_table_pb.calibration.add()
            item.speed = speed_array[cmd_index][speed_index]
            item.command = cmd_array[cmd_index][speed_index]
            item.acceleration = acc_array[cmd_index][speed_index]

    path = target_dir

    calibration_table_utils.write_h5_cal_tab(acc_array, path, table_filename)

    with open(os.path.join(path, table_filename), 'w') as wf:
        wf.write(str(calibration_table_pb))
    return os.path.join(path, table_filename)


def train_write_model(elem, target_prefix):
    """
    Train write model
    """
    (vehicle, throttle_or_brake), (data_set, train_param) = elem
    # print("elem is ", elem)
    # 'elem is '
    # ((('dev_kit_standard_s', 'throttle'), (((array([[0.35714999, 4.5       ],
    #    [2.10559998, 5.36999993],
    #    [2.10319998, 6.39999993],
    #    ...,
    #    [0.        , 0.        ],
    #    [0.        , 0.        ],
    #    [0.        , 0.        ]]), array([[0.19115216],
    #    [0.30476596],
    #    [0.33041079],
    #    ...,
    #    [0.        ],
    #    [0.        ],
    #    [0.        ]])), (array([[2.8379999 , 1.57500004],
    #    [3.01415001, 4.92000008],
    #    [2.92770002, 4.52000008],
    #    ...,
    #    [0.        , 0.        ],
    #    [0.        , 0.        ],
    #    [0.        , 0.        ]]), array([[0.53793343],
    #    [0.86729593],
    #    [0.39320353],
    #    ...,
    #    [0.        ],
    #    [0.        ],
    #    [0.        ]]))), ((0.15000000596046448, 9.385000228881836, 20), (1.5, 100.0, 20), [2, 15, 1], 0.05))),)
    #  'vehicle is '
    #  ('dev_kit_standard_s',)
    # 'throttle_or_brake is '
    # ('throttle',)
    # 'data_set is '
    # (((array([[0.35714999, 4.5       ],
    #     [2.10559998, 5.36999993],
    #     [2.10319998, 6.39999993],
    #     ...,
    #     [0.        , 0.        ],
    #     [0.        , 0.        ],
    #     [0.        , 0.        ]]), array([[0.19115216],
    #     [0.30476596],
    #     [0.33041079],
    #     ...,
    #     [0.        ],
    #     [0.        ],
    #     [0.        ]])), (array([[2.8379999 , 1.57500004],
    #     [3.01415001, 4.92000008],
    #     [2.92770002, 4.52000008],
    #     ...,
    #     [0.        , 0.        ],
    #     [0.        , 0.        ],
    #     [0.        , 0.        ]]), array([[0.53793343],
    #     [0.86729593],
    #     [0.39320353],
    #     ...,
    #     [0.        ],
    #     [0.        ],
    #     [0.        ]]))),)
    # 'train_param is ' (((0.15000000596046448, 9.385000228881836, 20), (1.5, 100.0, 20), [2, 15, 1], 0.05),)

    table_filename = throttle_or_brake + '_calibration_table.pb.txt'
    # for single vehicle
    # target_dir = os.path.join(target_prefix, vehicle)
    target_dir = os.path.join(target_prefix)
    ((speed_min, speed_max, speed_segment_num),
     (cmd_min, cmd_max, cmd_segment_num), layer, train_alpha) = train_param
    model = train_model(data_set, layer, train_alpha)
    return (vehicle, write_table(model, target_dir, speed_min, speed_max, speed_segment_num,
                                 cmd_min, cmd_max, cmd_segment_num, table_filename))


def combine_file(files):
    """
    combine brake calibration table and throttle calibration table
    """
    brake_file, _ = files
    # print("combine file brake_file is ", brake_file)
    file_name = os.path.join(os.path.dirname(brake_file), 'calibration_table_pre.pb.txt')
    logging.info("combine file name is %s", file_name)
    # print("combine file name is ", file_name)
    with open(file_name, 'wb') as outfile:
        for f in files:
            logging.info('infile: %s' % f)
            with open(f, "rb") as infile:
                for line in infile:
                    outfile.write(line)
    return file_name


def sort_single_config(single_file): 
    """ sort pb.txt file w.r.t speed """
    calibration_table_pb = calibration_table_pb2.calibration_table()
    origin_config = proto_utils.get_pb_from_text_file(single_file, calibration_table_pb)
    origin_config.calibration.sort(key=lambda elem: elem.speed)
    # write
    file_name = os.path.join(os.path.dirname(single_file), 'calibration_table.pb.txt')
    print("final calibration file name is ", file_name)
    proto_utils.write_pb_to_text_file(origin_config, file_name)
