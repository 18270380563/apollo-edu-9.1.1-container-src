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

#include <vector>

#include "modules/map/hdmap/hdmap_common.h"

namespace apollo {
namespace dreamview {

bool GetNearestLane(double x, double y,
                    apollo::hdmap::LaneInfoConstPtr* nearest_lane);

bool GetNearestLane(double x, double y,
                    apollo::hdmap::LaneInfoConstPtr* nearest_lane,
                    double* nearest_s, double* nearest_l);

double GetNearestLaneHeading(double x, double y);

double GetNearestLaneSpeedLimit(double x, double y);

bool GetCrosswalk(double x, double y,
                  apollo::hdmap::CrosswalkInfoConstPtr* crosswalk);

bool GetJunctions(double x, double y, double radius,
                  std::vector<apollo::hdmap::JunctionInfoConstPtr>* junctions);

bool GetLanes(double x, double y, double radius,
              std::vector<apollo::hdmap::LaneInfoConstPtr>* lanes);

bool GetExactLanes(double x, double y, double radius,
                   std::vector<apollo::hdmap::LaneInfoConstPtr>* lanes);

double GetLaneHeading(const std::string& id_str, double s);

bool GetSignals(double x, double y, double radius,
                std::vector<apollo::hdmap::SignalInfoConstPtr>* signals);

bool GetSignalsByIds(std::vector<std::string>,
                     std::vector<apollo::hdmap::SignalInfoConstPtr>* signals);

bool GetStopSigns(double x, double y, double radius,
                  std::vector<apollo::hdmap::StopSignInfoConstPtr>* stop_signs);

bool GetForwardNearestSignalsOnLane(
    double x, double y, double radius,
    std::vector<apollo::hdmap::SignalInfoConstPtr>* signals);

bool IsPedestrianOnCrosswalk(double x, double y, double radius,
                             apollo::common::math::Polygon2d person,
                             apollo::hdmap::CrosswalkInfoConstPtr* crosswalk);

bool GetBoxHeadTailPosition(
    double width, double heading, apollo::common::math::Polygon2d& poly,
    apollo::common::math::Vec2d& head_position,
    apollo::common::math::Vec2d& tail_position);

}  // namespace dreamview
}  // namespace apollo
