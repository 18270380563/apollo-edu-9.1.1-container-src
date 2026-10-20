#pragma once

#include <future>
#include <memory>

#include "modules/slam_local/proto/loam_velodyne_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/slam_local/common/LaserOdometry.h"
#include "modules/transform/buffer.h"

namespace apollo {
namespace loam_velodyne {

class LaserOdoMetryNode : public apollo::cyber::Component<> {
public:
    bool Init() override;

    ~LaserOdoMetryNode();

private:
    void run();

    transform::Buffer* tf2_buffer_ptr_;
    std::shared_ptr<LoamVelodyneConf> config_;
    std::shared_ptr<loam::ImageProjection> laser_odom_;

    std::future<void> async_result_;
};

CYBER_REGISTER_COMPONENT(LaserOdoMetryNode)

}  // namespace loam_velodyne
}  // namespace apollo
