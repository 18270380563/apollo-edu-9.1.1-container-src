"""#!/usr/bin/env python"""
import glob
import os
import sys

from absl import app
from absl import flags

import modules.control.vehicle_calibration.common.multi_job_utils as multi_job_utils
import modules.control.vehicle_calibration.common.multi_vehicle_utils as multi_vehicle_utils
import modules.control.vehicle_calibration.features.calibration_table_train_utils as train_utils
import modules.control.vehicle_calibration.common.logging as logging


flags.DEFINE_string('input_data_path', None, 'Input data path which is commonly used by pipelines.')


def get_data_from_hdf5(hdf5_files):
    """
    get data for h5 file
    """
    data = {}
    for key, files in hdf5_files.items():
        segments = train_utils.generate_segments(files)
        data[key] = train_utils.generate_data(segments)
    return data

class MultiJobTrain():
    """
    calibration job train
    """
    def init(self):
        """
        init
        """
        current_dir = sys.path[0]
        print("current dir is", current_dir)
        FLAGS = flags.FLAGS
        self.FLAGS = FLAGS.flag_values_dict()
        logging.info('Running calibration job with input_data_path=%s', str(FLAGS.input_data_path))

    def run(self):
        """
        run job
        """
        # target folder is the same as origin folder for test case
        origin_prefix = self.FLAGS.get('input_data_path') or \
                            '/apollo_workspace/modules/control/vehicle_calibration/testdata/vehicle_calib_20240424204200'
        target_prefix = os.path.join(origin_prefix, 'result')
        logging.info("input data path is %s", str(origin_prefix))
        logging.info("target result path is %s", str(target_prefix))

        def get_feature_hdf5_files(feature_dir, throttle_or_brake, train_or_test):
            """
            get hdf5 files
            """
            vehicle_files = {}
            for vehicle, path in feature_dir.items():
                feature_path = os.path.join(path, throttle_or_brake, train_or_test)
                hdf5_files = glob.glob(os.path.join(feature_path, '*.hdf5'))
                vehicle_files[(vehicle, throttle_or_brake)] = hdf5_files
            return vehicle_files

        # Get vehicle directories
        vehicle_type = 'collection_data'
        path = os.path.join(origin_prefix, vehicle_type)
        origin_vehicle_dir = {vehicle_type: path}

        # Get throttle and brake files for training and testing
        throttle_train_files = get_feature_hdf5_files(origin_vehicle_dir, 'throttle', 'train')
        throttle_test_files = get_feature_hdf5_files(origin_vehicle_dir, 'throttle', 'test')
        brake_train_files = get_feature_hdf5_files(origin_vehicle_dir, 'brake', 'train')
        brake_test_files = get_feature_hdf5_files(origin_vehicle_dir, 'brake', 'test')

        feature_dir = (throttle_train_files, throttle_test_files, brake_train_files, brake_test_files)

        self.run_internal(feature_dir, origin_vehicle_dir, target_prefix)


    def run_internal(self, feature_dir, origin_vehicle_conf_dir, target_dir):
        """
        calibration process
        """
        # get confs
        vehicle_conf = {key: multi_vehicle_utils.get_vehicle_param(value) 
                            for key, value in origin_vehicle_conf_dir.items()}

        train_conf = {key: multi_job_utils.get_train_conf(value) for key, value in origin_vehicle_conf_dir.items()}

        conf = {key: (vehicle_conf[key], train_conf[key]) for key in origin_vehicle_conf_dir}


        throttle_train_files, throttle_test_files, brake_train_files, brake_test_files = feature_dir

        # throttle data processing
        throttle_train_data = get_data_from_hdf5(throttle_train_files)
        throttle_test_data = get_data_from_hdf5(throttle_test_files)
        throttle_data = {key: (throttle_train_data[key], throttle_test_data[key]) for key in throttle_train_data}
        logging.info("throttle_data: %s", str(throttle_data))

        throttle_train_param = {(key, 'throttle'): multi_vehicle_utils.gen_param_w_train_conf(
                                conf[key][0], conf[key][1], 'throttle') for key in conf}
        logging.info("throttle_train_param: %s", str(throttle_train_param))

        throttle_model_train_input_data = {key: (throttle_data[key], throttle_train_param[key]) 
                                            for key in throttle_data if key in throttle_train_param}
        # logging.info("throttle_model_input_data: %s", str(throttle_model_train_input_data))

        for key, value in throttle_model_train_input_data.items():
            throttle_model_train_input_elem = tuple((key, value))
            # print("throttle_model_train_input_elem is ", throttle_model_train_input_elem)
            throttle_model = train_utils.train_write_model(throttle_model_train_input_elem, target_dir)
            # print("throttle_model train result is ", throttle_model)

        # brake data processing
        brake_train_data = get_data_from_hdf5(brake_train_files)
        brake_test_data = get_data_from_hdf5(brake_test_files)
        brake_data = {key: (brake_train_data[key], brake_test_data[key]) for key in brake_train_data}
        logging.info("brake_data: %s", str(brake_data))

        brake_train_param = {(key, 'brake'): multi_vehicle_utils.gen_param_w_train_conf(
                                conf[key][0], conf[key][1], 'brake') for key in conf}
        logging.info("brake_train_param: %s", str(brake_train_param))

        brake_model_train_input_data = { key: (brake_data[key], brake_train_param[key])
                                            for key in brake_data if key in brake_train_param }
        # logging.info("brake_model_train_input_data: %s", str(brake_model_train_input_data))

        for key, value in brake_model_train_input_data.items():
            brake_model_train_input_elem = tuple((key, value))
            # print("brake_model_train_input_elem is ", brake_model_train_input_data)
            brake_model = train_utils.train_write_model(brake_model_train_input_elem, target_dir)
            # print("brake_model train result is ", brake_model)

        brake_model_dict = {brake_model[0]: brake_model[1]}
        throttle_model_dict = {throttle_model[0]: throttle_model[1]}

        model_combine_input = {key: (brake_model_dict[key], throttle_model_dict[key])
                                    for key in brake_model_dict
                                    if key in throttle_model_dict}
        logging.info("model_combine_input is %s", str(model_combine_input))

        for key, value in model_combine_input.items():
            files = tuple(model_combine_input[key])
            logging.info("combine file files input is %s", str(files))
            result = train_utils.combine_file(files)
            logging.info("combine file result is %s", str(result))
            train_utils.sort_single_config(result)

        logging.info("vehcile calibration train job done.")

    def __main__(self, argv):
        """
        main process
        """
        self.init()
        self.run()

    def main(self):
        """
        main
        """
        app.run(self.__main__)


if __name__ == '__main__':
    train_model = MultiJobTrain()
    train_model.main()
