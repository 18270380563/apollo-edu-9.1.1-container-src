#pragma once

#include <unistd.h>

#include <cstdio>
#include <thread>

#include "modules/common_msgs/perception_msgs/traffic_light_detection.pb.h"
#include "modules/traffic_light_wj/proto/commons.pb.h"
#include "modules/traffic_light_wj/proto/obu2autopilot.pb.h"
#include "modules/traffic_light_wj/proto/spat.pb.h"

#include "cyber/common/macros.h"
#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"
#include "cyber/timer/timer.h"
#include "modules/common/status/status.h"
#include "modules/traffic_light_wj/common/traffic_light_wj_gflags.h"

/**
 * @namespace apollo::trafficlight
 * @brief apollo::trafficlight
 */
namespace apollo {
namespace trafficlight {

class TrafficLightWjComponent final : public apollo::cyber::TimerComponent {
public:
    TrafficLightWjComponent();
    ~TrafficLightWjComponent();
    /**
     * @brief obtain module name
     * @return module name
     */
    std::string Name() const;

private:
    /**
     * @brief module initialization function
     * @return initialization status
     */
    bool Init() override;

    /**
     * @brief initialize tcp client
     * @return cyber::STATUS
     */
    int InitTcpClient();

    /**
     * @brief module on_time function
     */
    bool Proc() override;

    void TcpReceiveThreadFunc();

private:
    bool runFlag;
    int msgCount;
    int spat_node_focus_id_;
    int spat_phase_focus_id_;

    int sockfd_;
    std::string host_;
    uint16_t port_;
    int64_t last_reconnect_;
    // thread for tcp
    std::unique_ptr<std::thread> thread_;

    // writer
    std::shared_ptr<cyber::Writer<perception::TrafficLightDetection>> writer_;
    std::shared_ptr<cyber::Writer<SPAT>> spat_writer_;
    perception::TrafficLightDetection traffic_light_;
};

CYBER_REGISTER_COMPONENT(TrafficLightWjComponent)

}  // namespace trafficlight
}  // namespace apollo
