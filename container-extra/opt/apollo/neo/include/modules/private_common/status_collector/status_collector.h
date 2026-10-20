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

#include <map>
#include <mutex>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/sensor_msgs/gnss_best_pose.pb.h"
// #include "modules/loam_velodyne/proto/slamStatus.pb.h"

#include "cyber/cyber.h"
#include "cyber/message/raw_message.h"

namespace apollo {
namespace common {

#define MAX_DELAY_TIME 2

struct ChannelDelayItem {
    ChannelDelayItem(
            const std::string& name,
            const std::string& channel_name,
            const double& delay_sec = MAX_DELAY_TIME) :
            name(name), channel_name(channel_name), delay_threshold_sec(delay_sec) {}
    std::string name;            // item name
    std::string channel_name;    // channel name
    double delay_threshold_sec;  // delay threshold in ms
};
struct ChannelDelayTask {
    std::shared_ptr<cyber::Reader<cyber::message::RawMessage>> reader;
    ChannelDelayItem item;
};

struct LocalizationStatusItem {
    LocalizationStatusItem(const std::string& name = "Localization", const double& delay_sec = MAX_DELAY_TIME) :
            name(name), delay_threshold_sec(delay_sec) {}
    std::string name;  // item name
    double delay_threshold_sec;
};

struct GpsStatusItem {
    GpsStatusItem(const std::string& name = "GPS", const double& delay_sec = MAX_DELAY_TIME) :
            name(name), delay_threshold_sec(delay_sec) {}
    std::string name;  // item name
    double delay_threshold_sec;
};

struct ChassisStatusItem {
    ChassisStatusItem(const std::string& name = "Chassis", const double& delay_sec = MAX_DELAY_TIME) :
            name(name), delay_threshold_sec(delay_sec) {}
    std::string name;  // item name
    double delay_threshold_sec;
};

// struct SlamStatusItem {
//     SlamStatusItem(const std::string& name = "Slam", const double& delay_sec = MAX_DELAY_TIME) :
//             name(name), delay_threshold_sec(delay_sec) {}
//     std::string name;  // item name
//     double delay_threshold_sec;
// };

enum ItemStatusLevel { STATUS_OK, STATUS_WARN, STATUS_ERROR };
const std::map<ItemStatusLevel, std::string> STATUS_LEVEL_MAP
        = {{STATUS_OK, "Ok"}, {STATUS_WARN, "Warning"}, {STATUS_ERROR, "Error"}};
struct ItemStatusInfo {
    ItemStatusLevel level;
    std::string info;
};
using ItemStatusMap = std::map<std::string, ItemStatusInfo>;

const uint32_t DEFAULT_STATUS_COLLECT_INTERVAL_MS = 1000;
/**
 * @brief status collector
 */
class StatusCollector {
public:
    explicit StatusCollector(
            const std::shared_ptr<apollo::cyber::Node>& node,
            const uint32_t& check_interval = DEFAULT_STATUS_COLLECT_INTERVAL_MS);
    /**
     * @brief Add channel delay item
     */
    bool Add(const ChannelDelayItem& item);

    /**
     * @brief Add localization status check item
     */
    bool Add(const LocalizationStatusItem& item);

    /**
     * @brief Add gps status check item
     */
    bool Add(const GpsStatusItem& item);

    /**
     * @brief Add chassis status check item
     */
    bool Add(const ChassisStatusItem& item);

    /**
     * @brief Add slam status check item
     */
    // bool Add(const SlamStatusItem& item);

    void Reset();

    const std::shared_ptr<ItemStatusMap> GetStatus();

    const nlohmann::json GetStatusJson();

private:
    void Run();

    void CheckChannelDelay();

    void CheckLocalizationStatus();

    void CheckGpsStatus();

    // void CheckSlamStatus();

private:
    std::shared_ptr<apollo::cyber::Node> node_;
    uint32_t check_interval_;
    std::unique_ptr<cyber::Timer> timer_ = nullptr;

    // channel delay
    std::map<std::string, ChannelDelayTask> channel_delay_item_map_;
    // localization status
    std::unique_ptr<LocalizationStatusItem> loc_status_item_ = nullptr;
    std::shared_ptr<cyber::Reader<localization::LocalizationStatus>> loc_reader_ = nullptr;
    // gps status
    std::unique_ptr<GpsStatusItem> gps_status_item_ = nullptr;
    std::shared_ptr<cyber::Reader<drivers::gnss::GnssBestPose>> gps_reader_ = nullptr;
    // chassis status
    std::unique_ptr<ChassisStatusItem> chassis_status_item_ = nullptr;
    std::shared_ptr<cyber::Reader<canbus::Chassis>> chassis_reader_ = nullptr;
    // slam status
    // std::unique_ptr<SlamStatusItem> slam_status_item_ = nullptr;
    // std::shared_ptr<cyber::Reader<loam_velodyne::slamStatus>> slam_reader_ = nullptr;

    std::shared_ptr<ItemStatusMap> cur_status_map_;
    std::shared_ptr<ItemStatusMap> update_status_map_;
    std::mutex status_map_mutex_;

    std::mutex mutex_;
};

}  // namespace common
}  // namespace apollo
