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
 ******************************************************************************/

#pragma once

#define PCL_NO_PRECOMPILE
#include <Eigen/Dense>
#include <pcl/io/pcd_io.h>
#include <pcl/pcl_macros.h>

#include "pcl/point_cloud.h"
#include "pcl/point_types.h"

struct EIGEN_ALIGN16 PointTypeXYZIT {
    PCL_ADD_POINT4D;
    float intensity;
    double timestamp;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
};

POINT_CLOUD_REGISTER_POINT_STRUCT(
        PointTypeXYZIT,
        (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(double, timestamp, timestamp))
