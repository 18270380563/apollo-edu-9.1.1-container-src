/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#include "modules/sim_obstacle/agent_server_common/bag_io.h"

#include "cyber/blocker/blocker_manager.h"
#include "cyber/common/file.h"
#include "cyber/common/global_data.h"
#include "cyber/common/log.h"
#include "cyber/common/macros.h"
#include "cyber/cyber.h"
#include "cyber/message/message_traits.h"
#include "cyber/proto/component_conf.pb.h"
#include "cyber/time/time.h"

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/chassis_msgs/chassis_detail.pb.h"
#include "modules/common_msgs/monitor_msgs/monitor_log.pb.h"
#include "modules/common_msgs/basic_msgs/drive_event.pb.h"
#include "modules/common_msgs/control_msgs/control_cmd.pb.h"
#include "modules/common_msgs/control_msgs/pad_msg.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/common_msgs/sensor_msgs/sensor_image.pb.h"
#include "modules/common_msgs/guardian_msgs/guardian.pb.h"
#include "modules/common_msgs/localization_msgs/gps.pb.h"
#include "modules/common_msgs/localization_msgs/imu.pb.h"
#include "modules//common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/planning_msgs/navigation.pb.h"
#include "modules/common_msgs/monitor_msgs/system_status.pb.h"
#include "modules/common_msgs/perception_msgs/perception_obstacle.pb.h"
#include "modules/common_msgs/perception_msgs/traffic_light_detection.pb.h"
#include "modules/common_msgs/planning_msgs/pad_msg.pb.h"
#include "modules/common_msgs/planning_msgs/planning.pb.h"
#include "modules/common_msgs/prediction_msgs/prediction_obstacle.pb.h"
#include "modules/common_msgs/routing_msgs/routing.pb.h"
#include "modules/common_msgs/planning_msgs/planning_command.pb.h"
#include "modules/common_msgs/external_command_msgs/command_status.pb.h"
#include "modules/common_msgs/external_command_msgs/lane_follow_command.pb.h"
#include "modules/common_msgs/external_command_msgs/valet_parking_command.pb.h"
#include "modules/common_msgs/storytelling_msgs/story.pb.h"
#include "modules/common_msgs/transform_msgs/transform.pb.h"

using apollo::cyber::blocker::BlockerManager;
using apollo::cyber::common::DirectoryExists;
using apollo::cyber::common::EnsureDirectory;
using apollo::cyber::common::GetProtoFromASCIIFile;
using apollo::cyber::common::GetProtoFromFile;
using apollo::cyber::common::PathExists;
using apollo::cyber::common::SetProtoToASCIIFile;