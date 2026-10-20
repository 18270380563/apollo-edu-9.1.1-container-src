#pragma once

#include <future>
#include <memory>

#include "modules/loam_velodyne_indoor/proto/loam_velodyne_indoor_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/loam_velodyne_indoor/common/LaserOdometry.h"
#include "modules/transform/buffer.h"

namespace apollo {
namespace loam_velodyne_indoor {

class LaserOdoMetryNode : public apollo::cyber::Component<> {
public:
    bool Init() override;

    ~LaserOdoMetryNode();

private:
    void run();

    transform::Buffer* tf2_buffer_ptr_;
    std::shared_ptr<LoamVelodyneIndoorConf> config_;
    std::shared_ptr<loam::ImageProjection> laser_odom_;

    std::future<void> async_result_;
};

CYBER_REGISTER_COMPONENT(LaserOdoMetryNode)

}  // namespace loam_velodyne_indoor
}  // namespace apollo
