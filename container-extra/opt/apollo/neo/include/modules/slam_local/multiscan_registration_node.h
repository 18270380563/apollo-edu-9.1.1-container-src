#pragma once

#include <future>
#include <memory>

#include "modules/slam_local/proto/loam_velodyne_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/slam_local/common/MultiScanRegistration.h"

namespace apollo {
namespace loam_velodyne {

class MultiScanRegistrationNode : public apollo::cyber::Component<> {
public:
    bool Init() override;

    ~MultiScanRegistrationNode();

private:
    void run();
    std::shared_ptr<LoamVelodyneConf> config_;
    std::shared_ptr<loam_velodyne::TransformFusion> multi_scan_registration_;

    std::shared_ptr<loam_velodyne::IMUPreintegration> imu_preintegration;

    std::future<void> async_result_;
};

CYBER_REGISTER_COMPONENT(MultiScanRegistrationNode)
}  // namespace loam_velodyne
}  // namespace apollo