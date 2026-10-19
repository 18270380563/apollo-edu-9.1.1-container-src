"""calibration utils"""
from collections import defaultdict
import math
import os
import random

import h5py
import numpy as np

from modules.control.vehicle_calibration.proto.calibration_table_pb2  import CalibrationTable
from modules.control.vehicle_calibration.features.filters import Filters
import modules.control.vehicle_calibration.common.file_utils as file_utils
import modules.control.vehicle_calibration.common.h5_utils as h5_utils
import modules.control.vehicle_calibration.common.logging as logging
import modules.control.vehicle_calibration.common.proto_utils as proto_utils


segment_store_num = 12
wanted_driving_mode = "COMPLETE_MANUAL"


def feature_filter(elem, filter_window=20):
    """
    filter feature with mean filter
    feature is one colm of elem
    """
    # elem is a matrix:
    # row: different type of features,
    # col: different value of a feature
    num_row = elem.shape[0]  # data points in a feature
    for i in range(3):
        # feature_num: numbers of data in one feature
        feature = [0 for k in range(num_row)]
        f = Filters(filter_window)
        for j in range(num_row):
            value = elem[j][i]
            feature[j] = f.mean_filter(value)
        elem[:, i] = feature
    return elem


def write_h5_cal_tab(data, file_dir, file_name):
    """
    write_h5_cal_tab
    """
    file_utils.makedirs(file_dir)
    file_name = file_name + '.hdf5'
    file_path = os.path.join(file_dir, file_name)
    with h5py.File(file_path, 'w') as h5_file:
        h5_file.create_dataset('segment', data=data, dtype='float64')
