/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "gflags/gflags.h"

DECLARE_bool(load_calib_conf_from_local);
DECLARE_string(calibration_conf_path);
DECLARE_string(data_handler_conf_path);
DECLARE_string(calib_collection_data_dir);
DECLARE_string(lidar_task_id_prefix);
DECLARE_string(camera_task_id_prefix);
DECLARE_string(lidar_to_camera_calib_conf_path);
