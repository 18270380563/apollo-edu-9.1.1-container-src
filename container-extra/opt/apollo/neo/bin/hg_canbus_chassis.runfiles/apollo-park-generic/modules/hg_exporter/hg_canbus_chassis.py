#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
    Usage: hg_canbus_chassis
"""
import os
import json
import time
from cyber.python.cyber_py3 import cyber
from modules.common_msgs.chassis_msgs import chassis_pb2
from modules.canbus_vehicle.devkit.proto import devkit_pb2

STATUS_FILE = os.getenv('HG_CAR_STATUS_FILE',
                        '/home/apollo/.apollo/hg_canbus_data.json')
canbus_data = {}


def callback_chassis(data):
    """ chassis message callback
    """
    global canbus_data
    canbus_chassis = data
    # 油门
    canbus_data["throttle_percentage"] = canbus_chassis.throttle_percentage
    canbus_data["brake_percentage"] = canbus_chassis.brake_percentage  # 刹车
    canbus_data["gear_location"] = canbus_chassis.gear_location         # 档位
    canbus_data["steering_percentage"] = canbus_chassis.steering_percentage  # 转向


def callback_chassis_detail(data):
    """ chassis detail message callback
    """
    global canbus_data
    canbus_chassis = data
    # print(canbus_chassis)
    # print("------------------")
    if hasattr(canbus_chassis, "bms_report_512"):
        # 电量
        canbus_data["battery_soc_percentage"] = canbus_chassis.bms_report_512.battery_soc_percentage
    else:
        # 默认值
        canbus_data["battery_soc_percentage"] = 0

    # 将数据写入 JSON 文件
    save_to_json(canbus_data, STATUS_FILE)


def save_to_json(data, file_path):
    """ write data to json file
    """
    with open(file_path, 'w') as json_file:
        json.dump(data, json_file, indent=4)
        print(f'save data: {data}')


if __name__ == '__main__':
    print('=' * 120)
    cyber.init()
    node = cyber.Node("canbus chassis")
    node_battery = cyber.Node("canbus chassis detail")
    routingsub = node.create_reader(
        '/apollo/canbus/chassis', chassis_pb2.Chassis,
        callback_chassis)
    routingsub = node_battery.create_reader(
        '/apollo/canbus/chassis_detail', devkit_pb2.Devkit,
        callback_chassis_detail)
    while not cyber.is_shutdown():
        time.sleep(1)
