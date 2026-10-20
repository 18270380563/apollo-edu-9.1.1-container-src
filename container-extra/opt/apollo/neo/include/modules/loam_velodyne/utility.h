#ifndef _UTILITY_LIDAR_ODOMETRY_H_
#define _UTILITY_LIDAR_ODOMETRY_H_

// #include <ros/ros.h>

// #include <sensor_msgs/Imu.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <nav_msgs/Odometry.h>

// #include "cloud_msgs/cloud_info.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "opencv2/opencv.hpp"
// #include <pcl_ros/point_cloud.h>
// #include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/common.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/range_image/range_image.h>
#include <pcl/registration/icp.h>

// #include <tf/transform_broadcaster.h>
// #include <tf/transform_datatypes.h>

#include <unistd.h>

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

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#define PI 3.14159265

using namespace std;

typedef pcl::PointXYZI PointType;

// VLP-16
extern const int N_SCAN = 16;
extern const int Horizon_SCAN = 1800;
extern const float ang_res_x = 0.2;
extern const float ang_res_y = 2.0;
extern const float ang_bottom = 15.0 + 0.1;
extern const int groundScanInd = 7;

// Ouster OS1-64
// extern const int N_SCAN = 64;
// extern const int Horizon_SCAN = 1024;
// extern const float ang_res_x = 360.0/float(Horizon_SCAN);
// extern const float ang_res_y = 33.2/float(N_SCAN-1);
// extern const float ang_bottom = 16.6+0.1;
// extern const int groundScanInd = 15;

extern const bool loopClosureEnableFlag = true;
extern const double mappingProcessInterval = 0.005;

extern const float scanPeriod = 0.1;
extern const int systemDelay = 0;
extern const int imuQueLength = 200;
extern const string imuTopic = "/imu/data";

extern const float sensorMountAngle = 0.0;
extern const float segmentTheta = 1.0472;
extern const int segmentValidPointNum = 5;
extern const int segmentValidLineNum = 3;
extern const float segmentAlphaX = ang_res_x / 180.0 * M_PI;
extern const float segmentAlphaY = ang_res_y / 180.0 * M_PI;

extern const int edgeFeatureNum = 2;
extern const int surfFeatureNum = 4;
extern const int sectionsTotal = 6;
extern const float edgeThreshold = 0.1;
extern const float surfThreshold = 0.1;
extern const float nearestFeatureSearchSqDist = 25;

extern const float surroundingKeyframeSearchRadius = 50.0;
extern const int surroundingKeyframeSearchNum = 50;

extern const float historyKeyframeSearchRadius = 7.0;
extern const int historyKeyframeSearchNum = 25;
extern const float historyKeyframeFitnessScore = 0.3;

extern const float globalMapVisualizationSearchRadius = 1000.0;

struct smoothness_t {
    float value;
    size_t ind;
};

struct by_value {
    bool operator()(smoothness_t const &left, smoothness_t const &right) {
        return left.value < right.value;
    }
};

struct PointXYZIRPYT {
    PCL_ADD_POINT4D
    PCL_ADD_INTENSITY;
    float roll;
    float pitch;
    float yaw;
    double time;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;

POINT_CLOUD_REGISTER_POINT_STRUCT(
        PointXYZIRPYT,
        (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(float, roll, roll)(float, pitch, pitch)(
                float,
                yaw,
                yaw)(double, time, time))

typedef PointXYZIRPYT PointTypePose;
#pragma pack(1)
typedef struct {
    char FileSignature[4];
    unsigned short File_Source_ID : 16;
    unsigned short Global_Encoding : 16;
    unsigned long Project_ID_GUID_data_1 : 32;
    unsigned short Project_ID_GUID_data_2 : 16;
    unsigned short Project_ID_GUID_data_3 : 16;
    unsigned char Project_ID_GUID_data_4[8];

    unsigned char Version_Major : 8;
    unsigned char Version_Minor : 8;
    char System_Identifier[32];
    char Generating_Software[32];
    unsigned short File_Creation_Day_of_Year : 16;
    unsigned short File_Creation_Year : 16;
    unsigned short Header_Size : 16;

    unsigned long Offset_to_point_data : 32;
    unsigned long Number_of_Variable_Length_Records : 32;
    unsigned char Point_Data_Format_ID : 8;
    unsigned short Point_Data_Record_Length : 16;
    unsigned long Number_of_point_records : 32;

    uint32_t Number_of_points_by_return[5];

    double X_scale_factor;
    double Y_scale_factor;
    double Z_scale_factor;
    double X_offset;
    double Y_offset;
    double Z_offset;

    double Max_X;
    double Min_X;
    double Max_Y;
    double Min_Y;
    double Max_Z;
    double Min_Z;

} Public_Header_Block;

typedef struct {
    long X : 32;
    long Y : 32;
    long Z : 32;
    unsigned short Intensity : 16;

    unsigned char Return_Number : 3;
    unsigned char Number_of_Returns : 3;
    unsigned char Scan_Direction_Flag : 1;
    unsigned char Edge_of_Flight_Line : 1;

    unsigned char Classification : 8;
    unsigned char Scan_Angle_Rank : 8;
    unsigned char User_Data : 8;
    unsigned short Point_Source_ID : 16;
    double GPS_Time;
    unsigned short Red : 16;
    unsigned short Green : 16;
    unsigned short Blue : 16;
} Point_Data;
#pragma pack()

#endif
