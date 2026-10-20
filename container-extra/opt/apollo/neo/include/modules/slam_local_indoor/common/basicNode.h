#pragma once
#ifndef _UTILITY_LIDAR_ODOMETRY_H_
#define _UTILITY_LIDAR_ODOMETRY_H_
#define PCL_NO_PRECOMPILE

#include <pcl/common/common.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/crop_box.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/octree/octree_pointcloud_voxelcentroid.h>
#include <pcl/octree/octree_search.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/range_image/range_image.h>
#include <pcl/registration/icp.h>
#include <pcl/search/impl/search.hpp>

#include "modules/slam_local_indoor/common/common_lib.h"
// #include <pcl_conversions/pcl_conversions.h>

#include <opencv2/opencv.hpp>
// #include <opencv/cv.h>

#include <algorithm>
#include <array>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "modules/common_msgs/localization_msgs/imu.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/slam_local_indoor/proto/loam_velodyne_conf.pb.h"
#include "modules/common_msgs/sensor_msgs/imu.pb.h"                       // imu msg

#include "cyber/cyber.h"

typedef pcl::PointXYZI PointType;
// std::shared_ptr<CommonLib::common_lib> common_lib_;

enum class SensorType { VELODYNE, OUSTER, LIVOX, ROBOSENSE, MULRAN };
using apollo::slam_local_indoor::LoamVelodyneConf;

class ParamServer {
public:
    std::string robot_id;

    // Topics
    std::string pointCloudTopic;
    std::string imuTopic;
    std::string odomTopic;
    std::string gpsTopic;

    // Frames
    std::string lidarFrame;
    std::string baselinkFrame;
    std::string odometryFrame;
    std::string mapFrame;
    std::string imuFrame;

    // GPS Settings
    bool useImuHeadingInitialization;
    bool useGpsElevation;
    float gpsCovThreshold;
    float poseCovThreshold;

    // Save pcd
    bool savePCD;
    std::string savePCDDirectory;

    // Lidar Sensor Configuration
    SensorType sensor;
    int N_SCAN;
    int Horizon_SCAN;
    int downsampleRate;
    int point_filter_num;
    float lidarMinRange;
    float lidarMaxRange;

    // IMU
    int imuType;
    float imuRate;
    float imuAccNoise;
    float imuGyrNoise;
    float imuAccBiasN;
    float imuGyrBiasN;
    float imuGravity;
    float imuRPYWeight;
    // std::vector<double> extRotV;
    // std::vector<double> extRPYV;
    // std::vector<double> extTransV;
    // Eigen::Matrix3d extRot;
    // Eigen::Matrix3d extRPY;
    // Eigen::Vector3d extTrans;
    // Eigen::Quaterniond extQRPY;

    // voxel filter paprams
    float mappingSurfLeafSize;
    float surroundingKeyframeMapLeafSize;
    float loopClosureICPSurfLeafSize;

    float z_tollerance;
    float rotation_tollerance;

    // CPU Params
    int numberOfCores;
    double mappingProcessInterval;

    // Surrounding map
    float surroundingkeyframeAddingDistThreshold;
    float surroundingkeyframeAddingAngleThreshold;
    float surroundingKeyframeDensity;
    float surroundingKeyframeSearchRadius;

    // Loop closure
    bool loopClosureEnableFlag;
    float loopClosureFrequency;
    int surroundingKeyframeSize;
    float historyKeyframeSearchRadius;
    float historyKeyframeSearchTimeDiff;
    int historyKeyframeSearchNum;
    float historyKeyframeFitnessScore;

    // global map visualization radius
    float globalMapVisualizationSearchRadius;
    float globalMapVisualizationPoseDensity;
    float globalMapVisualizationLeafSize;

    ParamServer() {}

    bool getConfPara(std::shared_ptr<LoamVelodyneConf> conf) {
        pointCloudTopic = conf->pointcloudtopic();
        imuTopic = conf->imutopic();
        odomTopic = conf->odomtopic();
        gpsTopic = conf->gpstopic();

        lidarFrame = conf->lidarframe();
        baselinkFrame = conf->baselinkframe();
        odometryFrame = conf->odometryframe();
        mapFrame = conf->mapframe();
        imuFrame = conf->imuframe();

        AINFO << "imuFrame is " << imuFrame;

        useImuHeadingInitialization = conf->useimuheadinginitialization();
        useGpsElevation = conf->usegpselevation();
        gpsCovThreshold = conf->gpscovthreshold();
        poseCovThreshold = conf->posecovthreshold();

        AINFO << "useGpsElevation is " << useGpsElevation;

        savePCD = conf->savepcd();
        savePCDDirectory = conf->savepcddirectory();

        std::string sensorStr;
        sensorStr = conf->sensor();
        if (sensorStr == "velodyne") {
            sensor = SensorType::VELODYNE;
        } else if (sensorStr == "ouster") {
            sensor = SensorType::OUSTER;
        } else if (sensorStr == "livox") {
            sensor = SensorType::LIVOX;
        } else if (sensorStr == "robosense") {
            sensor = SensorType::ROBOSENSE;
        } else if (sensorStr == "mulran") {
            sensor = SensorType::MULRAN;
        } else {
            AERROR << "Invalid sensor type (must be either 'velodyne' or 'ouster' or "
                      "'livox' or 'robosense' or 'mulran'): "
                   << sensorStr;
            return false;
        }

        AINFO << "lidar sensor type is " << sensorStr;

        N_SCAN = conf->n_scan();
        Horizon_SCAN = conf->horizon_scan();
        downsampleRate = conf->downsamplerate();
        point_filter_num = conf->point_filter_num();
        lidarMinRange = conf->lidarminrange();
        lidarMaxRange = conf->lidarmaxrange();

        imuType = conf->imutype();
        imuRate = conf->imurate();
        imuAccNoise = conf->imuaccnoise();
        imuGyrNoise = conf->imugyrnoise();
        imuAccBiasN = conf->imuaccbiasn();
        imuGyrBiasN = conf->imugyrbiasn();
        imuGravity = conf->imugravity();
        imuRPYWeight = conf->imurpyweight();
        // extRotV = conf->extRotV();
        // extRPYV = conf->extRPYV();
        // extTransV = conf->extTransV();
        // extRot = Eigen::Map<const Eigen::Matrix<double, -1, -1,
        // Eigen::RowMajor>>(extRotV.data(), 3, 3); extRPY = Eigen::Map<const
        // Eigen::Matrix<double, -1, -1, Eigen::RowMajor>>(extRPYV.data(), 3, 3);
        // extTrans = Eigen::Map<const Eigen::Matrix<double, -1, -1,
        // Eigen::RowMajor>>(extTransV.data(), 3, 1); extQRPY =
        // Eigen::Quaterniond(extRPY).inverse();

        mappingSurfLeafSize = conf->mappingsurfleafsize();
        surroundingKeyframeMapLeafSize = conf->surroundingkeyframemapleafsize();

        z_tollerance = conf->z_tollerance();
        rotation_tollerance = conf->rotation_tollerance();

        numberOfCores = conf->numberofcores();
        mappingProcessInterval = conf->mappingprocessinterval();

        AINFO << "mappingProcessInterval is " << mappingProcessInterval;

        surroundingkeyframeAddingDistThreshold = conf->surroundingkeyframeaddingdistthreshold();
        surroundingkeyframeAddingAngleThreshold = conf->surroundingkeyframeaddinganglethreshold();
        surroundingKeyframeDensity = conf->surroundingkeyframedensity();
        loopClosureICPSurfLeafSize = conf->loopclosureicpsurfleafsize();
        surroundingKeyframeSearchRadius = conf->surroundingkeyframesearchradius();

        loopClosureEnableFlag = conf->loopclosureenableflag();
        loopClosureFrequency = conf->loopclosurefrequency();
        surroundingKeyframeSize = conf->surroundingkeyframesize();
        historyKeyframeSearchRadius = conf->historykeyframesearchradius();
        historyKeyframeSearchTimeDiff = conf->historykeyframesearchtimediff();
        historyKeyframeSearchNum = conf->historykeyframesearchnum();
        historyKeyframeFitnessScore = conf->historykeyframefitnessscore();

        globalMapVisualizationSearchRadius = conf->globalmapvisualizationsearchradius();
        globalMapVisualizationPoseDensity = conf->globalmapvisualizationposedensity();
        globalMapVisualizationLeafSize = conf->globalmapvisualizationleafsize();
        AINFO << "globalMapVisualizationLeafSize is " << globalMapVisualizationLeafSize;
        return true;
    }

    // std::shared_ptr<localization::CorrectedImu> imuConverter(const
    // std::shared_ptr<localization::CorrectedImu> imu_in)
    // {
    //     std::shared_ptr<localization::CorrectedImu> imu_out = imu_in;
    //     // rotate acceleration
    //     Eigen::Vector3d acc(imu_in->imu().linear_acceleration().x(),
    //     imu_in->imu().linear_acceleration().y(),
    //     imu_in->imu().linear_acceleration().z()); acc = extRot * acc;
    //     imu_out->imu().linear_acceleration().x() = acc.x();
    //     imu_out->imu().linear_acceleration().y() = acc.y();
    //     imu_out->imu().linear_acceleration().z() = acc.z();
    //     // rotate gyroscope
    //     Eigen::Vector3d gyr(imu_in->imu().angular_velocity().x(),
    //     imu_in->imu().angular_velocity().y(),
    //     imu_in->imu().angular_velocity().z()); gyr = extRot * gyr;
    //     imu_out->imu().angular_velocity().x() = gyr.x();
    //     imu_out->imu().angular_velocity().y() = gyr.y();
    //     imu_out->imu().angular_velocity().z() = gyr.z();

    //     if (imuType) {
    //         // rotate roll pitch yaw
    //         geometry_msgs::Quaternion tmpQ =
    //         tf::createQuaternionMsgFromRollPitchYaw(imu_in.orientation.x,
    //         imu_in.orientation.y, imu_in.orientation.z); Eigen::Quaterniond
    //         q_from(tmpQ.w, tmpQ.x, tmpQ.y, tmpQ.z); Eigen::Quaterniond q_final
    //         = q_from * extQRPY; imu_out.orientation.x = q_final.x();
    //         imu_out.orientation.y = q_final.y();
    //         imu_out.orientation.z = q_final.z();
    //         imu_out.orientation.w = q_final.w();

    //         if (sqrt(q_final.x()*q_final.x() + q_final.y()*q_final.y() +
    //         q_final.z()*q_final.z() + q_final.w()*q_final.w()) < 0.1)
    //         {
    //             ROS_ERROR("Invalid quaternion, please use a 9-axis IMU!");
    //             ros::shutdown();
    //         }
    //     }

    //     return imu_out;
    // }
};

// template<typename T>
// sensor_msgs::PointCloud2 publishCloud(const ros::Publisher& thisPub, const T&
// thisCloud, ros::Time thisStamp, std::string thisFrame)
// {
//     sensor_msgs::PointCloud2 tempCloud;
//     pcl::toROSMsg(*thisCloud, tempCloud);
//     tempCloud.header.stamp = thisStamp;
//     tempCloud.header.frame_id = thisFrame;
//     if (thisPub.getNumSubscribers() != 0)
//         thisPub.publish(tempCloud);
//     return tempCloud;
// }

template <typename PointT>
void apolloMsgsToPclPointcloud2(
        const std::shared_ptr<apollo::drivers::PointCloud> &msg,
        pcl::PointCloud<PointT> &cloud) {
    if (msg->height() > 1 && msg->width() > 1) {
        for (unsigned int i = 0; i < msg->height(); ++i) {
            for (unsigned int j = 0; j < msg->width(); ++j) {
                PointT onePt;
                onePt.x = msg->point(i * msg->width() + j).x();
                onePt.y = msg->point(i * msg->width() + j).y();
                onePt.z = msg->point(i * msg->width() + j).z();
                onePt.time = msg->point(i * msg->width() + j).timestamp() / 1000000000.0;
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
            onePt.time = msg->point(i).timestamp() / 1000000000.0;
            if (!std::isnan(onePt.x) && !std::isnan(onePt.y) && !std::isnan(onePt.z)) {
                unsigned char intensity = static_cast<unsigned char>(msg->point(i).intensity());
                onePt.intensity = intensity;
                cloud.push_back(onePt);
            }
        }
    }
}

template <typename PointT>
void apolloMsgsToPclPointcloud(
        const std::shared_ptr<apollo::drivers::PointCloud> &msg,
        pcl::PointCloud<PointT> &cloud) {
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

template <typename PointT>
inline void PclPointcloudToApolloMsgs(
        const pcl::PointCloud<PointT> &cloud,
        std::shared_ptr<apollo::drivers::PointCloud> &apollo_msgs) {
    apollo_msgs->mutable_point()->Reserve(cloud.size());
    for (int k = 0; k < cloud.size(); k++) {
        auto *point_new = apollo_msgs->add_point();
        point_new->set_intensity(cloud[k].intensity);
        point_new->set_x(static_cast<float>(cloud[k].x));
        point_new->set_y(static_cast<float>(cloud[k].y));
        point_new->set_z(static_cast<float>(cloud[k].z));
    }
    return;
}

inline void publishCloud(
        const std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> &writer,
        const pcl::PointCloud<pcl::PointXYZI> &cloud,
        apollo::cyber::Time time,
        std::string frameID) {
    auto msg_ptr = std::shared_ptr<apollo::drivers::PointCloud>(new apollo::drivers::PointCloud);
    PclPointcloudToApolloMsgs(cloud, msg_ptr);
    msg_ptr->mutable_header()->set_timestamp_sec(time.ToSecond());
    msg_ptr->mutable_header()->set_frame_id(frameID);
    writer->Write(msg_ptr);
}

// template<typename T>
// double ROS_TIME(T msg)
// {
//     return msg->header.stamp.toSec();
// }

template <typename T>
void imuAngular2rosAngular(apollo::localization::CorrectedImu *thisImuMsg, T *angular_x, T *angular_y, T *angular_z) {
    *angular_x = thisImuMsg->imu().angular_velocity().x();
    *angular_y = thisImuMsg->imu().angular_velocity().y();
    *angular_z = thisImuMsg->imu().angular_velocity().z();
}

template <typename T>
void imuAngular2rosAngular(apollo::drivers::gnss::Imu *thisImuMsg, T *angular_x, T *angular_y, T *angular_z) {
    *angular_x = thisImuMsg->angular_velocity().x();
    *angular_y = thisImuMsg->angular_velocity().y();
    *angular_z = thisImuMsg->angular_velocity().z();
}

template <typename T>
void imuAccel2rosAccel(apollo::localization::CorrectedImu *thisImuMsg, T *acc_x, T *acc_y, T *acc_z) {
    *acc_x = thisImuMsg->imu().linear_acceleration().x();
    *acc_y = thisImuMsg->imu().linear_acceleration().y();
    *acc_z = thisImuMsg->imu().linear_acceleration().z();
}

template <typename T>
void imuRPY2rosRPY(apollo::localization::CorrectedImu *thisImuMsg, T *rosRoll, T *rosPitch, T *rosYaw) {
    auto geoQuat = Eigen::AngleAxisd(thisImuMsg->imu().euler_angles().z(), ::Eigen::Vector3d::UnitZ())
            * Eigen::AngleAxisd(thisImuMsg->imu().euler_angles().y(), ::Eigen::Vector3d::UnitY())
            * Eigen::AngleAxisd(thisImuMsg->imu().euler_angles().x(), ::Eigen::Vector3d::UnitX());

    Eigen::Quaterniond q(geoQuat.w(), geoQuat.x(), geoQuat.y(), geoQuat.z());
    Eigen::Matrix3d rx = q.toRotationMatrix();
    Eigen::Vector3d ea = rx.eulerAngles(2, 1, 0);

    *rosRoll = ea[2];
    *rosPitch = ea[1];
    *rosYaw = ea[0];

    // fix roll and pitch value error
    if(fabs(*rosRoll) > 1.0 || fabs(*rosPitch) > 2.0)
    {
      *rosRoll += M_PI;
      *rosPitch += M_PI;
      *rosYaw += M_PI;
      ///
      angleToPI(rosRoll);
      angleToPI(rosPitch);
      angleToPI(rosYaw);

    }
}

#endif
