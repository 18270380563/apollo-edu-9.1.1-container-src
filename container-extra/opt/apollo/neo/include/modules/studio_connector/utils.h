#pragma once

#include <openssl/rsa.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include <cstdbool>
#include <fstream>
#include <cstring>
#include "nlohmann/json.hpp"
#include "google/protobuf/util/json_util.h"

#include "cyber/common/file.h" 
#include "modules/dreamview/backend/common/dreamview_gflags.h"
#include "modules/dreamview/backend/common/sim_control_manager/proto/dynamic_model_conf.pb.h"
#include "modules/dreamview/proto/scenario.pb.h"
#include "modules/studio_connector/proto/v2x.pb.h"
#include "modules/studio_connector/proto/vehicle.pb.h"
#include "modules/studio_connector/proto/progress.pb.h"

namespace apollo {
namespace dreamview {
namespace plugins {
namespace studio_connector {

template <typename T>
bool LoadMessageByPath(const std::string &path, T *message) {
    std::string json_data;
    if (!::apollo::cyber::common::GetContent(path, &json_data)) {
        AERROR << "file: " << path << " can not be opened";
        return false;
    }
    google::protobuf::util::JsonParseOptions options;
    options.ignore_unknown_fields = true;
    auto ret = google::protobuf::util::JsonStringToMessage(json_data, message, options);
    if (!ret.ok()) {
      AERROR << "load message from json format failed, "
             << ret.error_message().ToString();
      return false;
    }
    return true;
}


template <typename T>
bool SaveMessageByPath(const std::string &path, const T &message) {
  std::string proto_data;
  auto ret = google::protobuf::util::MessageToJsonString(message, &proto_data);
  if (!ret.ok()) {
    AERROR "dump message to json format failed";
    return false;
  }
  std::ofstream fout(path);
  if (!fout.is_open()) {
    AERROR << "file: " << path << " can not be opened";
    return false;
  }
  fout << proto_data;
  fout.close();
  return true;
}

bool LoadScenario(const std::string scenario_set_id,
                  const std::string scenario_id,
                  ::apollo::dreamview::SimTicket *sim_ticket);

bool SaveScenario(const std::string scenario_set_id,
                  const std::string scenario_id,
                  const ::apollo::dreamview::SimTicket &sim_ticket);

bool LoadScenarioSet(const std::string scenario_set_id,
                     ::apollo::dreamview::UserAdsGroup *user_ads_group);

bool LoadDynamicModel(std::string dynamic_model_dir);

bool LoadRecord(const std::string record_id); 
bool LoadMap(const std::string map_name);

bool SaveScenarioSet(const std::string scenario_set_id,
                     const ::apollo::dreamview::UserAdsGroup user_ads_group);

std::string GetSaveMapPath(const std::string map_name);

std::string GetSaveRecordPath(const std::string record_id);
std::string GetSaveRecordDir();

bool SignRsaSha256(const std::string content, RSA *key, std::string &signature);

bool PackageExist(const std::string package_name);

bool InstallBuildtool();

void RemoveBuildtool();

const std::string GetFileContent(const char *fpath);

const bool RewriteFileContent(const char *fpath, const std::string &content);

const std::string GetInnerFilePath(const char *fpath);

bool GetInnerFileContent(const char *fpath, std::string *content);

bool LoadCert(X509 **crt, const std::string &fpath);

bool UnpackRecordTar(std::string record_id);
bool UnpackMapTar(std::string map_name);

std::string ProRecordName(const std::string record_id);

std::string GetResourcesPath();

void UpdateVehicleInfo(std::vector<::apollo::studio::VehicleInfo> vehicles);

void UpdateProfileInfo(std::vector<::apollo::studio::VehicleProfile> profiles);

void UpdateV2xInfo(std::vector<::apollo::studio::V2xInfo> v2xInfos);

void UpdateVtypeMap(std::vector<std::string> vtype_name_map);

std::string GetVehicleProfilesResourcePath();

std::string GetVehicleTypeName(std::uint32_t vtype);

bool MakeVehicleResourceDir(std::uint32_t vtype);

bool GetProfileIdbyVehicleId(std::uint64_t vehicle_id,
                             std::uint64_t &profile_id);

bool GetVehicleTypeByVehicleId(std::uint64_t vehicle_id, std::uint32_t &v_type);

std::string GetVehicleResourceDir(std::uint32_t vtype);

bool GetProfileNameByVehicleID(std::uint64_t vehicle_id,
                               std::string &profile_name);

std::string GetUnpackPath(std::string profile_name);

bool UnpackVehicleTarball(std::string profile_dir, std::string profile_name);

std::string GetV2xConfPathByV2xId(std::uint64_t v2x_id);

const std::string GetConfigCachePath();

bool clearCache();

std::string GetSaveV2xDir();

std::string GetSaveV2xTarPath(std::string digest, std::uint64_t v2x_id);

const bool CompressConfig(std::string profile_name);

const bool CompressV2xConf(std::uint64_t v2x_id);

std::string GetV2xConfCachePath();

std::string GetV2xConfPath(std::string vname);

bool clearV2xCache();

bool UnPackV2xTar(std::string v2x_file_path, std::uint64_t v2x_id);

bool GetVehicleIdByV2xID(std::uint64_t v2x_id, std::uint64_t &vehicle_id);

std::string GetCommandRes(const std::string &cmd);

/**
 * @brief The function to fill a progress from params
 * @param progress the progress to fill in
 * @param percentage the percentage to fill in
 * @param log_string a log indicating the current download status
 * @param resource_id the resource id to fill in
 */
void FillProgress(::apollo::studio::Progress &progress, double percentage, 
                  std::string log_string, std::string resource_id, std::string resource_type, std::string request_id);

const std::string GetStatus(const std::uint64_t &device_id, std::string device_type);

/**
 * @brief The function used to parse string to json
 * @param json_str the str to parse
 * @param json parse result
 * @return if the action is successful
 */
bool ParseStringToJson(std::string json_str,nlohmann::json& json);

bool HttpGet(std::string api, std::uint32_t &code, std::string &message,
             std::string &response_str, std::string auth_id,
             std::string auth_secret, std::string http_token,
             bool with_token = false);

bool HttpPost(std::string api, std::string fields, std::uint32_t &code,
              std::string &message, std::string &response_str, std::string auth_id,
              std::string auth_secret, std::string http_token,
              bool with_token = false);

char* CreateSharedMemory(int &shm_id, const std::string shm_name, const std::uint32_t shm_size = 4096);

void DeleteSharedMemory(int &shm_id);

static std::vector<::apollo::studio::VehicleInfo> vehicle_infos;

static std::vector<::apollo::studio::VehicleProfile> profile_infos;

static std::vector<::apollo::studio::V2xInfo> v2x_infos;

static std::map<uint32_t, std::string> VTYPE_NAME_MAPPING;

static std::map<std::string, int> DEVICE_TYPE_MAPPING = {
    {"vehicle", 0},
    {"v2x", 1}};
}  // namespace studio_connector
}  // namespace plugins
}  // namespace dreamview
}  // namespace apollo
