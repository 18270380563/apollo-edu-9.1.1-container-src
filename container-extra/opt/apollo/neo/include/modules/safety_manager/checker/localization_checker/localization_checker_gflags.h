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

DECLARE_string(localization_checker_name);

// The safety status fatal threshold, when the localization status value is
// greater than the threshold, set safety status to fatal. Only used in the
// following status, and the values of these status is following:
// MeasureState::ERROR: 1
// MeasureState::CRITICAL_ERROR: 2
// MeasureState::FATAL_ERROR: 3
DECLARE_uint32(safety_status_fatal_threshold);

DECLARE_string(slam_status_channel);

DECLARE_double(slam_icp_score_threshold);
