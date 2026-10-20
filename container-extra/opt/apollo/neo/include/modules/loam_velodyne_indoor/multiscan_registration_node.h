#pragma once

#include <future>
#include <memory>

#include "modules/loam_velodyne_indoor/proto/loam_velodyne_indoor_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/loam_velodyne_indoor/common/MultiScanRegistration.h"

namespace apollo {
namespace loam_velodyne_indoor {

class MultiScanRegistrationNode : public apollo::cyber::Component<> {
public:
    bool Init() override;

    ~MultiScanRegistrationNode();

private:
    void run();
    std::shared_ptr<LoamVelodyneIndoorConf> config_;
    std::shared_ptr<loam::TransformFusion> multi_scan_registration_;

    std::shared_ptr<loam::IMUPreintegration> imu_preintegration;

    std::future<void> async_result_;
};

CYBER_REGISTER_COMPONENT(MultiScanRegistrationNode)
}  // namespace loam_velodyne_indoor
}  // namespace apollo