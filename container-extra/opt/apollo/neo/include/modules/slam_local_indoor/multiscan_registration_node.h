#pragma once

#include <future>
#include <memory>

#include "modules/slam_local_indoor/proto/loam_velodyne_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/slam_local_indoor/common/MultiScanRegistration.h"

namespace apollo {
namespace loam_velodyne {

class MultiScanRegistrationNode : public apollo::cyber::Component<> {
public:
    bool Init() override;

    ~MultiScanRegistrationNode();

private:
    void run();
    std::shared_ptr<LoamVelodyneConf> config_;
    std::shared_ptr<loam::TransformFusion> multi_scan_registration_;

    std::shared_ptr<loam::IMUPreintegration> imu_preintegration;

    std::future<void> async_result_;
};

CYBER_REGISTER_COMPONENT(MultiScanRegistrationNode)
}  // namespace loam_velodyne
}  // namespace apollo