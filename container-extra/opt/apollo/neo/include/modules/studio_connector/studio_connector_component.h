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

#include <memory>

#include "cyber/component/component.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview/proto/dv_plugin_msg.pb.h"
#include "modules/studio_connector/proto/record.pb.h"
#include "modules/dreamview/proto/scenario.pb.h"
#include "modules/dreamview/proto/record.pb.h"
#include "modules/studio_connector/proto/account.pb.h"
#include "modules/studio_connector/proto/v2x.pb.h"
#include "modules/studio_connector/proto/vehicle.pb.h"
#include "modules/studio_connector/proto/progress.pb.h"

namespace apollo {
namespace dreamview {
namespace plugins {
namespace studio_connector {

using apollo::cyber::Component;
// using apollo::cyber::ComponentBase;
using apollo::dreamview::DvPluginMsg;
// 之后怎么调用！！！ 不放在apollo里的话

class StudioConnectorComponent : public Component<DvPluginMsg> {
 public:
  using Callback = std::function<void(const apollo::studio::Progress&)>;
  StudioConnectorComponent() = default;

  ~StudioConnectorComponent() = default;

  typedef bool (*DvPluginMsgHandler)(StudioConnectorComponent *inst,
                                     const DvPluginMsg &msg);
  bool Init() override;
  bool Proc(const std::shared_ptr<DvPluginMsg> &msg) override;

  static bool GetMapListHandler(StudioConnectorComponent *inst,
                                        const DvPluginMsg &msg);
  
  static bool DownloadMapHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);

  static bool GetScenarioSetListHandler(StudioConnectorComponent *inst,
                                        const DvPluginMsg &msg);

  static bool DownloadScenarioSetHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);

  static bool GetDynamicModelListHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);

  static bool DownloadDynamicModelHandler(StudioConnectorComponent *inst,
                                          const DvPluginMsg &msg);

  static bool CheckCertStatusHandler(StudioConnectorComponent *inst,
                                     const DvPluginMsg &msg);

  static bool GetRecordsListHandler(StudioConnectorComponent *inst,
                                    const DvPluginMsg &msg);

  static bool DownloadRecordHandler(StudioConnectorComponent *inst,
                                    const DvPluginMsg &msg);

  static bool GetVehicleInfoHandler(StudioConnectorComponent *inst,
                                    const DvPluginMsg &msg);

  static bool RefreshVehicleConfigHandler(StudioConnectorComponent *inst,
                                          const DvPluginMsg &msg);

  static bool ResetVehicleConfigHandler(StudioConnectorComponent *inst,
                                        const DvPluginMsg &msg);

  static bool UploadVehicleConfigHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);

  static bool GetV2xInfoHandler(StudioConnectorComponent *inst,
                                const DvPluginMsg &msg);

  static bool RefreshV2xConfHandler(StudioConnectorComponent *inst,
                                    const DvPluginMsg &msg);

  static bool ResetV2xConfHandler(StudioConnectorComponent *inst,
                                  const DvPluginMsg &msg);

  static bool UploadV2xConfHandler(StudioConnectorComponent *inst,
                                   const DvPluginMsg &msg);
  static bool GetAccountInfoHandler(StudioConnectorComponent *inst,
                                   const DvPluginMsg &msg);
  static bool GetSubscriberInfoHandler(StudioConnectorComponent *inst,
                                   const DvPluginMsg &msg);
  static bool CheckInHwDeviceHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);
  static bool CheckCertificateStatusHandler(StudioConnectorComponent *inst,
                                      const DvPluginMsg &msg);
  static bool FetchAuthorizationInfoHandler(StudioConnectorComponent *inst,
                                            const DvPluginMsg &msg);
  static bool AuthServerControlHandler(StudioConnectorComponent *inst,
                                              const DvPluginMsg &msg);
  static bool GetSubscriberListHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);
  static bool GetSubscriberTokenHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);
  static bool GetSubscriberDevicesListHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);
  static bool RefreshProductInfoHandler(StudioConnectorComponent *inst,
                                         const DvPluginMsg &msg);                                                                                                             
  bool EmitMessage(const DvPluginMsg &msg);
  bool EmitMessage(const std::string &msg_name, const std::string &info,
                   const std::string request_id, bool broadcast = true);
  bool EmitMessage(const std::string &msg_name, const nlohmann::json &info,
                   const std::string request_id, bool broadcast = true);
  const std::string CompareScenarioStatus(
      const std::string &scenario_set_id, const std::string &scenario_id,
      const ::apollo::dreamview::SimTicket &scenario);
  const std::string CompareScenarioSetStatus(
      const std::string &scenario_set_id,
      const ::apollo::dreamview::UserAdsGroup &scenario_set);
  const std::string
  CompareDynamicModelStatus(const std::string &dynamic_model_name);
  const std::string CompareRecordStatus(const std::string &record_id);
  const std::string CompareDeviceStatus(const std::uint64_t &device_id, std::string device_type);
  const std::string CompareMapStatus(const std::string &map_name);
  uint64_t GetServerCertExpirationSeconds();
  uint64_t GetClientCertExpirationSeconds();
 
  /**
   * @brief callback function to send download progress
   * @param progress resource data current download progress
  */
  void OnProgress(const apollo::studio::Progress &progress);
  /**
   * @brief callback function to send product info changed message
   * @param size product_info_size
   * @param shm_id shm_id
  */
  void MsgCallback(size_t& size, int& shm_id);

private:
  void RegisterDvPluginMsgHandlers();
  void RegisterDvPluginMsgHandlersForAucaAgent();
  void RegisterDvPluginMsgHandlersForStudioHttpClient();
  void RegisterDvPluginMsgHandler(const std::string &msg_name,
                                  DvPluginMsgHandler related_handler);
  std::shared_ptr<cyber::Writer<DvPluginMsg>> writer_;
  std::map<std::string, DvPluginMsgHandler> dv_plugin_msg_handlers_;
};
CYBER_REGISTER_COMPONENT(StudioConnectorComponent)

} // namespace studio_connector
} // namespace plugins
} // namespace dreamview
} // namespace apollo
