/******************************************************************************
 * Copyright 2024 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 */
#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace apollo {
namespace dreamview {
/**
 * @brief Convert a string of latitude and longitude to radians.
 */
double ParseDMSToD(const std::string &dms);

/**
 * @brief Lat. lng. coordinate to utm
 */
bool LatlonToUtm(double &lat, double &lon, const std::string &proj4_text, apollo::common::math::Vec2d *utm);

/**
 * @brief Judge need offset when coordinate in of China
 * @return If out of China, return true
 */
bool IfOutOfChina(double &lng, double &lat);
/**
 * @brief BD09 to GCJ02
 */
bool BD09ToGCJ02(double &b_lng, double &b_lat, double &g_lng, double &g_lat);

/**
 * @brief GCJ02 to WGS84
 */
bool GCJ02ToWGS84(double &g_lng, double &g_lat, double &w_lng, double &w_lat);

/**
 * @brief BD09 to WGS84
 */
bool BD09ToWGS84(std::string &b_lng, std::string &b_lat, double &w_lng, double &w_lat);

/**
 * Transfrom lng.
 */
double TransformLng(double lng, double lat);

/**
 * Transfrom lng.
 */
double TransformLat(double lng, double lat);

}  // namespace dreamview
}  // namespace apollo