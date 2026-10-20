/******************************************************************************
 * Copyright 2023 The Apollo Authors. All Rights Reserved.
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

DECLARE_string(control_checker_name);
DECLARE_double(chassis_msg_expired_sec);
DECLARE_double(gear_inconsistency_sec_threshold);
DECLARE_double(throttle_inconsistency_threshold);
DECLARE_double(throttle_failure_sec_threshold);
DECLARE_double(brake_inconsistency_threshold);
DECLARE_double(brake_failure_sec_threshold);
DECLARE_double(brake_check_speed_limit);
DECLARE_double(steer_inconsistency_threshold);
DECLARE_double(steer_failure_sec_threshold);
DECLARE_double(sliding_speed_threshold);
DECLARE_double(sliding_accident_sec_threshold);
DECLARE_double(speed_inconsistency_threshold_percentage);
DECLARE_double(speed_percentage_check_limit);
DECLARE_double(speed_inconsistency_sec_threshold);
