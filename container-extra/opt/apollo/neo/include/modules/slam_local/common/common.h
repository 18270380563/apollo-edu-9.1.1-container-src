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

#ifndef LOAM_COMMON_H
#define LOAM_COMMON_H

// #include <ros/ros.h>
#include <memory>

#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"

#include "cyber/cyber.h"
#include "cyber/time/time.h"
// #include <sensor_msgs/PointCloud2.h>
// #include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "modules/slam_local/common/time_utils.h"

namespace loam {
/** \brief Construct a new point cloud message from the specified information
 * and publish it via the given publisher.
 *
 * @tparam PointT the point type
 * @param publisher the publisher instance
 * @param cloud the cloud to publish
 * @param stamp the time stamp of the cloud message
 * @param frameID the message frame ID
 */
// template <typename PointT>
// inline void publishCloudMsg(ros::Publisher& publisher,
//                             const pcl::PointCloud<PointT>& cloud,
//                             const ros::Time& stamp,
//                             std::string frameID) {
//   sensor_msgs::PointCloud2 msg;
//   pcl::toROSMsg(cloud, msg);
//   msg.header.stamp = stamp;
//   msg.header.frame_id = frameID;
//   publisher.publish(msg);
// }

template <typename PointT>
void apolloMsgsToPclPointcloud2(
        const std::shared_ptr<apollo::drivers::PointCloud>& msg,
        pcl::PointCloud<PointT>& cloud) {
    if (msg->height() > 1 && msg->width() > 1) {
        for (unsigned int i = 0; i < msg->height(); ++i) {
            for (unsigned int j = 0; j < msg->width(); ++j) {
                PointT onePt;
                onePt.x = msg->point(i * msg->width() + j).x();
                onePt.y = msg->point(i * msg->width() + j).y();
                onePt.z = msg->point(i * msg->width() + j).z();
                if (!std::isnan(onePt.x) && !std::isnan(onePt.y) && !std::isnan(onePt.z)) {
                    unsigned char intensity = static_cast<unsigned char>(msg->point(i * msg->width() + j).intensity());
                    onePt.intensity = intensity;
                    cloud.push_back(onePt);
                }
            }
        }
    } else {
        AINFO << "Receiving un-organized-point-cloud, width " << msg->width() << " height " << msg->height() << "size "
              << msg->point_size();
        for (int i = 0; i < msg->point_size(); ++i) {
            PointT onePt;
            onePt.x = msg->point(i).x();
            onePt.y = msg->point(i).y();
            onePt.z = msg->point(i).z();
            if (!std::isnan(onePt.x) && !std::isnan(onePt.y) && !std::isnan(onePt.z)) {
                unsigned char intensity = static_cast<unsigned char>(msg->point(i).intensity());
                onePt.intensity = intensity;
                cloud.push_back(onePt);
            }
        }
    }
}

// template<typename PointT>
inline void PclPointcloudToApolloMsgs(
        const pcl::PointCloud<pcl::PointXYZI>& cloud,
        std::shared_ptr<apollo::drivers::PointCloud>& apollo_msgs) {
    apollo_msgs->mutable_point()->Reserve(cloud.size());
    for (int k = 0; k < cloud.size(); k++) {
        auto* point_new = apollo_msgs->add_point();
        point_new->set_intensity(cloud[k].intensity);
        point_new->set_x(static_cast<float>(cloud[k].x));
        point_new->set_y(static_cast<float>(cloud[k].y));
        point_new->set_z(static_cast<float>(cloud[k].z));
    }
    return;
}

// template<typename PointT>
inline void publishCloudMsg(
        const std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>>& writer,
        const pcl::PointCloud<pcl::PointXYZI>& cloud,
        apollo::cyber::Time time,
        std::string frameID) {
    auto msg_ptr = std::shared_ptr<apollo::drivers::PointCloud>(new apollo::drivers::PointCloud);
    PclPointcloudToApolloMsgs(cloud, msg_ptr);
    msg_ptr->mutable_header()->set_timestamp_sec(time.ToSecond());
    msg_ptr->mutable_header()->set_frame_id(frameID);
    writer->Write(msg_ptr);
}

// ROS time adapters
// inline Time fromROSTime(ros::Time const& rosTime)
// {
//   auto epoch = std::chrono::system_clock::time_point();
//   auto since_epoch = std::chrono::seconds(rosTime.sec) +
//   std::chrono::nanoseconds(rosTime.nsec); return epoch + since_epoch;
// }

// inline ros::Time toROSTime(Time const& time_point)
// {
//   return
//   ros::Time().fromNSec(std::chrono::duration_cast<std::chrono::nanoseconds>(time_point.time_since_epoch()).count());
// }

}  // end namespace loam

#endif  // LOAM_COMMON_H
