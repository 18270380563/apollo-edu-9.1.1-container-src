/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

namespace apollo {
namespace dreamview {

inline double GetSharpAngle(const double& a, const double& b) {
  /*a and b are in [-pi, pi)*/
  double angle = std::fabs(a - b);
  if (angle <= M_PI) {
    return angle;
  }
  return M_PI - (angle - M_PI);
}

inline double DegreeToRadian(const double& angle_degree) {
  return angle_degree / 180 * M_PI;
}

}  // dreamview
}  // apollo
