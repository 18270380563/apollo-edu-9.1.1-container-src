"""utils for multiple vehicles"""
import os

from collections import namedtuple

import modules.common_msgs.config_msgs.vehicle_config_pb2 as vehicle_config_pb2

import modules.control.vehicle_calibration.common.file_utils as file_utils
import modules.control.vehicle_calibration.common.proto_utils as proto_utils

import modules.control.vehicle_calibration.proto.calibration_table_pb2 as CalibrationTable


TrainParam = namedtuple('TrainParam', ['speed', 'cmd', 'layer', 'alpha'])


def get_vehicle(path):
    """
    get vehicle dir
    """
    return [subdir for subdir in os.listdir(path) if os.path.isdir(os.path.join(path, subdir))]


def get_vehicle_param(folder_dir):
    """
    get vehicle param
    """
    vehicle_para_conf_filename = 'vehicle_param.pb.txt'
    conf_file = os.path.join(folder_dir, vehicle_para_conf_filename)
    VEHICLE_PARAM_CONF = proto_utils.get_pb_from_text_file(
        conf_file, vehicle_config_pb2.VehicleConfig())
    return VEHICLE_PARAM_CONF.vehicle_param


def gen_param_w_train_conf(vehicle_conf, train_conf, throttle_or_brake):
    """
    generate train conf
    """
    if throttle_or_brake == 'throttle':
        cmd_min = vehicle_conf.throttle_deadzone
        cmd_max = train_conf.throttle_max
        layer = [train_conf.throttle_train_layer1,
                 train_conf.throttle_train_layer2,
                 train_conf.throttle_train_layer3]

    elif throttle_or_brake == 'brake':
        cmd_min = -1 * train_conf.brake_max
        cmd_max = -1 * vehicle_conf.brake_deadzone
        layer = [train_conf.brake_train_layer1,
                 train_conf.brake_train_layer2,
                 train_conf.brake_train_layer3]

    speed_min = train_conf.speed_min
    speed_max = train_conf.speed_max
    speed_segment_num = train_conf.train_speed_segment
    cmd_segment_num = train_conf.train_cmd_segment
    train_alpha = train_conf.train_alpha
    return TrainParam((speed_min, speed_max, speed_segment_num),
                        (cmd_min, cmd_max, cmd_segment_num),
                        layer,
                        train_alpha)
