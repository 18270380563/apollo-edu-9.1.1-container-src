#pragma once

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

#include "cyber/common/macros.h"
#include "cyber/time/clock.h"
#include "cyber/timer/timer.h"
#include "modules/dreamview/backend/common/sim_control_manager/proto/dynamic_model_conf.pb.h"
#include "modules/dreamview/proto/record.pb.h"
#include "modules/studio_connector/proto/account.pb.h"
#include "modules/dreamview/proto/scenario.pb.h"
#include "modules/studio_connector/proto/dynamic_model.grpc.pb.h"
#include "modules/studio_connector/proto/progress.pb.h"
#include "modules/studio_connector/proto/record.grpc.pb.h"
#include "modules/studio_connector/proto/scenario.grpc.pb.h"
#include "modules/studio_connector/proto/v2x.grpc.pb.h"
#include "modules/studio_connector/proto/v2x.pb.h"
#include "modules/studio_connector/proto/vehicle.grpc.pb.h"
#include "modules/studio_connector/proto/vehicle.pb.h"
#include "modules/studio_connector/proto/map.grpc.pb.h"
#include "modules/studio_connector/proto/map.pb.h"
#include "modules/studio_connector/proto/auca_agent/auca_agent_grpc_api.grpc.pb.h"
#include "modules/common/util/json_util.h"
#include "utils.h"

namespace apollo {
namespace dreamview {
namespace plugins {

namespace {
using Callback = std::function<void(const apollo::studio::Progress &)>;
class ProgressTracker {
 private:
  ::apollo::studio::Progress progress_;
  int64_t data_length_;
  double pre_percentage_;
  Callback callback_;

 public:
  // Constructor
  ProgressTracker(const ::apollo::studio::Progress &progress,
                  const int64_t &data_length, const double &pre_percentage,
                  const Callback &callback)
      : progress_(progress), data_length_(data_length),
        pre_percentage_(pre_percentage), callback_(callback) {}
  int64_t GetDataLength() { return data_length_; }
  double GetPrePercentage() { return pre_percentage_; }
  void SetPrePercentage(const double &pre_percentage) {
    pre_percentage_ = pre_percentage;
  }
  ::apollo::studio::Progress GetProgress() { return progress_; }
  void SetPercentage(const double &percentage) {
    progress_.set_percentage(percentage);
  }
  void PublishProgress() { callback_(progress_); }
};
} // namespace

namespace studio_connector {

// change token expired time from 2h to 1day to keep offline use
const uint32_t kMaxExpiredTimeS = 24*60*60;
class Authenticator : public grpc::MetadataCredentialsPlugin {
 public:
  Authenticator();
  grpc::Status
  GetMetadata(grpc::string_ref service_url, grpc::string_ref method_name,
      const grpc::AuthContext &channel_auth_context,
      std::multimap<grpc::string, grpc::string> *metadata) override;

 private:
  std::string auth_id_;
  std::string auth_id_signed_;
  RSA *client_key_;
  X509 *client_crt_;
};

class StudioProfileClient {
 public:
  using Callback = std::function<void(const apollo::studio::Progress&)>;
  // This msg callback used for Studio Profile Client to callback StudioConnector function
  using MsgCallback = std::function<void(size_t& size, int& shm_id)>;
  StudioProfileClient(std::shared_ptr<grpc::Channel> channel);
  ~StudioProfileClient();
  bool GetScenarioByScenarioSetId(
      const std::string scenario_set_id,
      ::apollo::dreamview::UserAdsGroup &scenario_set,
      std::vector<::apollo::dreamview::SimTicket> &scenarios,
      std::uint32_t &code,
     std::string &message,
     std::string request_id,
      const Callback &callback);
  void SetMsgCallback(MsgCallback callback);
  bool GetDynamicModelByName(const std::string dynamic_model_name,
                             const std::string dm_models_dir,
                             const std::string dm_library_dir,
                             std::uint32_t &code,
                            std::string &message,
                             std::string request_id,
                            const Callback &callback);

  bool GetMapList(std::vector<std::string> &maps, std::uint32_t &code, std::string &message);
  bool GetMapByName(const std::string map_name, std::uint32_t &code,
                    std::string &message,
                            std::string request_id, const Callback &callback);
  bool GetScenarioSetList(
      std::vector<::apollo::dreamview::UserAdsGroup> &scenario_sets, std::uint32_t &code, std::string &message);
  bool GetDynamicModelList(std::vector<std::string> &dynamic_models, std::uint32_t &code, std::string &message);
  bool GetRecordList(::apollo::dreamview::RecordList &record_list, std::uint32_t &code, std::string &message);
  bool GetRecordByRecordId(const std::string record_id, std::uint32_t &code,
                           std::string &message,
                            std::string request_id, const Callback &callback);
  bool GetVehicleInfo(
      std::vector<::apollo::studio::VehicleInfo> &vehicle_infos,
      std::vector<::apollo::studio::VehicleProfile> &profile_infos,
      std::vector<std::string> &vtype_name_map, std::uint32_t &code, std::string &message);
  bool RefreshVehicleConfig(const std::uint64_t vehicle_id, bool is_original,
                            std::uint32_t &code, std::string &message);
  bool RefreshVehicleConfig(const std::uint64_t vehicle_id,
                            const std::uint64_t profile_id, bool is_original,
                            std::uint32_t &code, std::string &message);
  bool ResetVehicleConfig(const std::uint64_t vehicle_id, bool is_original,
                          std::uint32_t &code, std::string &message);
  bool ResetVehicleConfig(const std::uint64_t vehicle_id,
                          const std::uint64_t profile_id, bool is_original,
                          std::uint32_t &code, std::string &message);
  bool UploadVehicleProfile(const std::uint64_t vehicle_id,
                            const std::uint64_t profile_id,
                           std::uint32_t &code, std::string &message);
  bool GetV2xInfo(std::vector<::apollo::studio::V2xInfo> &v2x_infos,
                  std::uint32_t &code, std::string &messageg);
  bool GetV2xConf(std::uint64_t v2x_id, bool is_original,
                 std::uint32_t &code, std::string &message);
  bool PutV2xConf(std::uint64_t v2x_id, std::uint32_t &code, std::string &message);
  bool GetAccountInfo(::apollo::studio::AccountInfo &info,
                     std::uint32_t &code, std::string &message);
  bool GetSubscriberInfo(std::uint32_t &code, std::string &message,
                         std::string &response, bool is_initializing = false);
  bool GetSubscriberList(std::uint32_t &code, std::string &message,
                         std::string &response, bool network_first = false, bool is_initializing = false);
  bool GetSubscriberToken(std::string subscriber_id, std::uint32_t &code,
                          std::string &message, bool is_initializing = false);
  bool GetSubscriberDevicesList(nlohmann::json param,std::uint32_t &code, std::string &message,std::string& response);
  bool RefreshProductInfo(size_t &product_info_size, int& shm_fd);
  bool RefreshSubscriberCache();
  bool InitSubscriberInfo();

 private:
  bool GetDynamicModelFileWithRetry(const std::string dynamic_model_name,
                                    const std::string file_name,
                                    const std::string save_path,
                                    ::apollo::studio::FileType file_type);

  bool GetDynamicModelFile(const std::string dynamic_model_name,
                           const std::string file_name,
                           const std::string save_path,
                           ::apollo::studio::FileType file_type);
  bool IntegrityVerify(const std::string &hash_value, const std::string &flag,
                       const std::string &name, const Callback &callback,
                       const std::string &request_id, std::uint32_t &code,
                       std::string &message);
  bool DownloadFile(const std::string &url, const std::string &output_file,
                    ProgressTracker &progress_tracker);
  bool IsTokenExpired();
  bool GetSubscriberProductInfo(std::uint32_t &code, std::string &message, std::string token);
  bool UpdateSubscriberProductInfo(std::string product_info);
  bool ClearSubscriberProductInfo();
  std::shared_ptr<::apollo::studio::api::Stub> stub_;
  std::shared_ptr<::apollo::studio::dynamicModelApi::Stub> dynamic_model_stub_;
  std::shared_ptr<::apollo::studio::RecordService::Stub> record_stub_;
  std::shared_ptr<::apollo::studio::VehicleService::Stub> vehicle_stub_;
  std::shared_ptr<::apollo::studio::v2xConfService::Stub> v2x_conf_stub_;
  std::shared_ptr<::apollo::studio::mapApi::Stub> map_stub_;
  std::string server_crt_pem_;
  grpc::SslCredentialsOptions ssl_opts_;
  std::shared_ptr<grpc::ChannelCredentials> server_creds_;
  grpc::ChannelArguments channel_args_;
  std::shared_ptr<grpc::Channel> channel_;
  std::int64_t breakpoint_index_ = 0;
  std::int64_t map_breakpoint_index_ = 0;
  int slice = 0;
  std::string http_auth_id_ = "";
  std::string http_auth_secret_ = "";
  std::string http_token_ = "";
  std::atomic<double> last_token_received_s_;
  mutable boost::shared_mutex token_mutex_;
  bool token_refreshed_ = false;
  std::string subscriber_id_ = "";
  // cache last changed subscriber id
  std::string cached_subscriber_id_ = "";
  // Store in a file to ensure use after restart
  std::string subscriber_cached_file_path_ = "";
  // cache subscriber list
  std::string subscriber_list_info_ = "";
  // cache subscriber info
  std::string subscriber_info_ = "";
  bool subscriber_info_is_valid_ = false;
  // shared memory to store product info
  char* product_info_ptr_ = nullptr;
  int shm_id_ = -1;
  const std::string shm_key_ = "subscriber_product_info";
  size_t product_info_size_ = 0;
  // 共享内存锁
  mutable boost::shared_mutex product_info_mutex_;
  bool is_initialized_ = false;
  mutable boost::shared_mutex is_initialized_mutex_;
  // The timer to polling subscriber info
  std::unique_ptr<cyber::Timer> subscriber_timer_;
  // Time interval of the timer, in milliseconds.per 5 second execute initsubscriberinfo function
  static constexpr double kSubscriberTimerIntervalMs = 5 * 1000;
  // Locks related to timer.
  std::mutex timer_mutex_;
  bool timer_is_running_ = false;
  MsgCallback msg_callback_;
  bool msg_callback_enabled_ = false;
  DECLARE_SINGLETON(StudioProfileClient)
};

class AucaAgentClient {
 public:
  using Callback = std::function<void(const apollo::studio::Progress&)>;
  AucaAgentClient(std::shared_ptr<grpc::Channel> channel){};
  ~AucaAgentClient();
  bool CheckInHwDevice(
            const std::string device_id,
            std::uint32_t &code,
                       std::string& message);
  bool CheckCertificateStatus(
                std::uint32_t &code,
                std::string& message,
                              ::AUCAAgent::CertificateState &certificate_state);
  bool FetchAuthorizationInfo(std::uint32_t &code, std::string &message,
                              nlohmann::json &DFATAL_LEVEL);
  bool
  AuthServerControl(std::uint32_t &code, std::string &message,
                    ::AUCAAgent::AuthServerControlCmd auth_server_control_cmd);

private:
  void SetGrpcConnectDeadline(grpc::ClientContext* context);
  std::shared_ptr<::AUCAAgent::AucaAgentService::Stub> agent_stub_;
  std::shared_ptr<grpc::Channel> channel_;
  std::shared_ptr<grpc::ChannelCredentials> server_creds_;
  grpc::ChannelArguments channel_args_;
  DECLARE_SINGLETON(AucaAgentClient)
};
class HttpAuthenticator {
 public:
  HttpAuthenticator();
  void GetAuthInfo(std::string& auth_id,std::string& auth_secret);
 private:
  std::string auth_id_;
  std::string auth_id_signed_;
  RSA *client_key_;
};
} // namespace studio_connector
} // namespace plugins
} // namespace dreamview
} // namespace apollo
