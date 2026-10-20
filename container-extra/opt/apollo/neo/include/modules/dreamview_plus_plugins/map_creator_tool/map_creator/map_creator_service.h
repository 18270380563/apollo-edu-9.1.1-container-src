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

/**
 * @file
 */

#pragma once

#include <chrono>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <boost/thread/shared_mutex.hpp>

#include "cyber/proto/record.pb.h"
#include "modules/common_msgs/localization_msgs/gps.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/localization_msgs/localization_status.pb.h"
#include "modules/common_msgs/sensor_msgs/gnss_best_pose.pb.h"
#include "modules/common_msgs/sensor_msgs/imu.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/dreamview/proto/dv_plugin_msg.pb.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/proto/error_code.pb.h"
#include "modules/drivers/gnss/proto/config.pb.h"
#include "modules/loam_velodyne/proto/slamStatus.pb.h"
#include "modules/loam_velodyne/proto/slam_service.pb.h"

#include "cyber/common/file.h"
#include "cyber/common/time_conversion.h"
#include "cyber/cyber.h"
#include "cyber/record/record_writer.h"
#include "cyber/tools/cyber_recorder/recorder.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/math/aabox2d.h"
#include "modules/common/math/vec2d.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/common/map_creator_gflags.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/map_creator/geo_convert_impl.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/map_creator/map_creator.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/map_creator/map_creator_impl.h"
/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */

namespace apollo {
namespace dreamview {

/**
 * @class MapCreatorService
 * @brief A map creation tool service supported by dreamview.
 */
class MapCreatorService {
public:
    explicit MapCreatorService(WebSocketHandler *websocket);
    /**
     * Check whether the basemap exceeds the valid area
     * @param json_path tiles.json path
     */
    static bool CheckBaseMapRange(const std::string &json_path);

private:
    WebSocketHandler *websocket_;
    std::unique_ptr<cyber::Node> node_ = nullptr;
    std::shared_ptr<cyber::Reader<drivers::PointCloud>> point_cloud_reader_ = nullptr;
    std::shared_ptr<cyber::Reader<drivers::gnss::Imu>> imu_reader_ = nullptr;
    std::shared_ptr<cyber::Reader<localization::LocalizationStatus>> localization_status_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<drivers::gnss::GnssBestPose>> gnssbestpose_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<drivers::PointCloud>> lidar2world_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<loam_velodyne::slamStatus>> slam_status_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<localization::Gps>> gps_odometry_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<apollo::dreamview::DvPluginMsg>> accountpluin_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Writer<apollo::dreamview::DvPluginMsg>> accountpluin_writer_ = nullptr;
    std::shared_ptr<
            apollo::cyber::Client<apollo::dreamview::maptool::SlamRequest, apollo::dreamview::maptool::SlamResponse>>
            slam_client_ = nullptr;
    std::shared_ptr<apollo::cyber::record::Recorder> recorder_ = nullptr;

    std::string map_data_dir_ = "";
    std::unique_ptr<apollo::dreamview::MapCreator> map_creator_ = nullptr;
    std::string curr_mapping_mode_ = "slam";
    std::map<std::string, bool> mapping_mode_status_;
    std::string start_record_timestamps_;
    apollo::tile_map_images_creator::ImagesCreatorConf conf_;
    std::string token_ = "";
    std::string auth_id_ = "";
    std::string auth_secret_ = "";
    bool account_pass_ = false;
    std::string proj4_text_ = "";
    int zone_id_ = 50;  // default is beijing
    // collect region

private:
    void Init();
    void InitMappingMode();
    void InitReaders();
    void InitWriters();
    void InitClients();
    void LoadConf();
    void RegisterMessageHandlers();
    bool StartRecord();
    bool StopRecord();
    /**
     * @brief Check lidar, localization, gps status.
     */
    nlohmann::json CheckStatus();
    nlohmann::json CheckLidarStatus();
    nlohmann::json CheckImuStatus();
    nlohmann::json CheckLocalizationStatus();
    nlohmann::json CheckGpsStatus();
    nlohmann::json CheckSlamStatus();
    bool StartMapCreator(const std::string &request_id, WebSocketHandler::Connection *conn);
    void BreakMapCreator();
    nlohmann::json PublishMapCreatorProgress(
            const float &progress,
            const std::string &request_id,
            const std::string &output_dir);
    bool StartMappingMode();
    bool StopMappingMode();
    void UpdateGeoInfo(const std::shared_ptr<apollo::drivers::gnss::GnssBestPose> &best_pose);
    bool CheckCollectionRegion(nlohmann::json &check_res);
    bool GetAccountServiceInfo(nlohmann::json &service_info);
    void UpdateToken(const std::shared_ptr<apollo::dreamview::DvPluginMsg> &msg);
    bool GetTokenRequest(int conn_retry_num);
    bool TryGetTokenAndAccount(int conn_retry_num, std::string &error_message);
    bool GetAccountFromStudio(const uint64_t &info_size, std::string &error_message);
    void UpdateServiceInfo(nlohmann::json &info);
    int FindCollectionRegion(apollo::common::math::Vec2d &adc_loc);
    bool AddGeoLocationInfo(const std::string &dst_dir);
};

enum OutOfRangeWarning {
    INSIDE_THE_NORMAL_ROOM,
    WARNING_200M_BEYOND_THE_AREA,
    WARNING_100M_BEYOND_THE_AREA,
    WARNING_50M_BEYOND_THE_AREA,
    ARRIVE_LIMIT,
    OUT_OF_RANGE,
};

}  // namespace dreamview
}  // namespace apollo
