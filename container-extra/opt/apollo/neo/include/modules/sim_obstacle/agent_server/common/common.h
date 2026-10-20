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

#include <cmath>
#include <vector>
#include<iostream>

using namespace std;

namespace apollo {
namespace dreamview {
namespace common {

constexpr double EPSILON = 1e-10;

struct AdcStatus {
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  double h = 0.0;
  double v = 0.0;
};

template <typename T>
inline double Distance(T x1, T y1, T x2, T y2) {
  return std::hypot(x1 - x2, y1 - y2);
}

template <typename P1, typename P2>
inline double Distance(const P1& p1, const P2& p2) {
  return Distance(p1.x(), p1.y(), p2.x(), p2.y());
}

// Given start_v, acceleration and distance to calculate the
// time traveling from start to end.
// Assume constant acceleration.
// Based on d = start_v * t + 0.5 * a * t^2
// t = (-2 * start_v + sqrt(4 * start_v^2 + 8 * a * d)) / (2 * a)
template <typename T>
inline double GetTravelTimeWithAcc(const T& x1, const T& y1, const T& u,
                                   const T& a, const T& x2, const T& y2) {
  if (Distance(x1, y1, x2, y2) < EPSILON) {
    return 0.0;
  }

  double discriminant = 4 * u * u + 8 * a * Distance(x1, y1, x2, y2);
  if (discriminant < 0 || (fabs(a) < EPSILON && fabs(u) < EPSILON)) {
    // No real roots, unable to reach end with the given conditions.
    return -1.0;
  }
  if (fabs(a) < EPSILON) {
    return Distance(x1, y1, x2, y2) / u;
  }
  return (-2 * u + std::sqrt(discriminant)) / (2 * a);
}

// Given start_v, end_v and distance to calculate the
// acceleration between start to end.
// Assume constant acceleration.
// a = (end_v * end_v - start_v * start_v) / (2 * d)
template <typename T>
inline double GetAccelerationBetweenTwoPoints(const T& x1, const T& y1,
                                              const T& v1, const T& x2,
                                              const T& y2, const T& v2) {
  if (Distance(x1, y1, x2, y2) < EPSILON) {
    return 0.0;
  }
  return (v2 * v2 - v1 * v1) / 2 / Distance(x1, y1, x2, y2);
}

}  // common
}  // dreamview
}  // apollo
