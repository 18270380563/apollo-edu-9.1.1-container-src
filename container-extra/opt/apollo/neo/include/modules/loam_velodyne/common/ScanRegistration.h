// Copyright 2013, Ji Zhang, Carnegie Mellon University
// Further contributions copyright (c) 2016, Southwest Research Institute
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from this
//    software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is an implementation of the algorithm described in the following paper:
//   J. Zhang and S. Singh. LOAM: Lidar Odometry and Mapping in Real-time.
//     Robotics: Science and Systems Conference (RSS). Berkeley, CA, July 2014.

#ifndef LOAM_SCANREGISTRATION_H
#define LOAM_SCANREGISTRATION_H

#include "modules/loam_velodyne/common/common.h"

#include <stdint.h>

#include "modules/loam_velodyne/common/BasicScanRegistration.h"
#include "modules/loam_velodyne/proto/loam_velodyne_conf.pb.h"
#include "cyber/cyber.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"

namespace loam {
using apollo::loam_velodyne::LoamVelodyneConf;
/** \brief Base class for LOAM scan registration implementations.
 *
 * As there exist various sensor devices, producing differently formatted point clouds,
 * specific implementations are needed for each group of sensor devices to achieve an accurate registration.
 * This class provides common configurations, buffering and processing logic.
 */
class ScanRegistration : protected BasicScanRegistration {
public:
    /** \brief Setup component.
     *
     * @param node the ROS node handle
     * @param privateNode the private ROS node handle
     */
    virtual bool setupROS(
            std::shared_ptr<LoamVelodyneConf> conf,
            std::shared_ptr<apollo::cyber::Node> node,
            RegistrationParams& config_out);

    /** \brief Handler method for IMU messages.
     *
     * @param imuIn the new IMU message
     */
    virtual void handleIMUMessage(const std::shared_ptr<apollo::drivers::PointCloud>& imuMsg);

protected:
    /** \brief Publish the current result via the respective topics. */
    void publishResult();

private:
    /** \brief Parse node parameter.
     *
     * @param nh the ROS node handle
     * @return true, if all specified parameters are valid, false if at least one specified parameter is invalid
     */
    bool parseParams(std::shared_ptr<LoamVelodyneConf> conf, RegistrationParams& config_out);

private:
    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::PointCloud>> _subImu = nullptr;  ///< IMU message subscriber
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> _pubLaserCloud
            = nullptr;  ///< full resolution cloud message publisher
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> _pubCornerPointsSharp
            = nullptr;  ///< sharp corner cloud message publisher
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> _pubCornerPointsLessSharp
            = nullptr;  ///< less sharp corner cloud message publisher
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> _pubSurfPointsFlat
            = nullptr;  ///< flat surface cloud message publisher
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> _pubSurfPointsLessFlat
            = nullptr;  ///< less flat surface cloud message publisher
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> _pubImuTrans
            = nullptr;  ///< IMU transformation message publisher
};

}  // end namespace loam

#endif  // LOAM_SCANREGISTRATION_H
