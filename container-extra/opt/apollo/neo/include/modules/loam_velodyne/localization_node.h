#pragma once
#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
#include <omp.h>
#include <proj_api.h>

#include <atomic>
#include <future>
#include <memory>

#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Rot3.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/navigation/CombinedImuFactor.h>
#include <gtsam/navigation/GPSFactor.h>
#include <gtsam/navigation/ImuFactor.h>
#include <gtsam/nonlinear/ISAM2.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/Marginals.h>
#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/slam/PriorFactor.h>

#include "absl/strings/str_cat.h"

#include "modules/common_msgs/localization_msgs/gps.pb.h"
#include "modules/common_msgs/sensor_msgs/gnss_best_pose.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/loam_velodyne/proto/cloudWithPoseInfo.pb.h"
#include "modules/loam_velodyne/proto/loam_velodyne_conf.pb.h"
#include "modules/loam_velodyne/proto/odometry.pb.h"
#include "modules/loam_velodyne/proto/slamStatus.pb.h"
#include "modules/loam_velodyne/proto/slam_pose_result.pb.h"
#include "modules/loam_velodyne/proto/slam_service.pb.h"

#include "cyber/cyber.h"
#include "modules/common/math/euler_angles_zxy.h"
#include "modules/common/math/quaternion.h"
#include "modules/loam_velodyne/common/basicNode.h"
#include "modules/loam_velodyne/common/cuda_tools/scan_to_map_optimization.h"
#include "modules/loam_velodyne/common/i_lib/pc/i_ground.h"
#include "modules/loam_velodyne/common/nanoflann_pcl.h"
// #include "Scancontext.h"
struct PointXYZIRPYT {
    PCL_ADD_POINT4D
    PCL_ADD_INTENSITY;  // preferred way of adding a XYZ+padding
    float roll;
    float pitch;
    float yaw;
    double time;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW  // make sure our new allocators are aligned
} EIGEN_ALIGN16;                     // enforce SSE padding for correct memory alignment

POINT_CLOUD_REGISTER_POINT_STRUCT(
        PointXYZIRPYT,
        (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(float, roll, roll)(float, pitch, pitch)(
                float,
                yaw,
                yaw)(double, time, time))

typedef PointXYZIRPYT PointTypePose;

enum class SCInputType { SINGLE_SCAN_FULL, SINGLE_SCAN_FEAT, MULTI_SCAN_FEAT };

struct UTMCoor {
    UTMCoor() : x(0.0), y(0.0), z(0.0) {}
    double x;
    double y;
    double z;
};
using apollo::loam_velodyne::cloudWithPoseInfo;
using apollo::loam_velodyne::LoamVelodyneConf;
using apollo::loam_velodyne::Odometry;
using apollo::loam_velodyne::slamStatus;
using namespace gtsam;

using symbol_shorthand::B;  // Bias  (ax,ay,az,gx,gy,gz)
using symbol_shorthand::G;  // GPS pose
using symbol_shorthand::V;  // Vel   (xdot,ydot,zdot)
using symbol_shorthand::X;  // Pose3 (x,y,z,r,p,y)

namespace apollo {
namespace loam_velodyne {

class MapOptimization : public apollo::cyber::Component<>, public ParamServer {
public:
    using SlamRequest = apollo::dreamview::maptool::SlamRequest;
    using SlamResponse = apollo::dreamview::maptool::SlamResponse;
    bool Init() override;

    ~MapOptimization();

    bool loadPoseAndMap(std::string& filePath, int type);
    void allocateMemory();
    void transformAssociateToMap();
    void transformUpdate();
    void updatePointAssociateToMapSinCos();
    pcl::PointCloud<PointType>::Ptr transformPointCloud(
            pcl::PointCloud<PointType>::Ptr cloudIn,
            PointTypePose* transformIn);
    void laserOdometryHandler(const std::shared_ptr<Odometry>& laserOdometry);

    void laserCloudFullLastHandler(const std::shared_ptr<cloudWithPoseInfo>& surfPointsLessFlatMsg);
    void gnssBestPoseHandler(const std::shared_ptr<apollo::drivers::gnss::GnssBestPose>& laserCloudSurfLastMsg);
    void gnssOdometryHandler(const std::shared_ptr<apollo::localization::Gps>& gnssOdometryMsg);

    void laserCloudOutlierLastHandler(const std::shared_ptr<apollo::drivers::PointCloud>& laserCloudOutlierLastMsg);
    void imuHandler(const std::shared_ptr<apollo::drivers::PointCloud>& imuIn);

    void fullLaserCloudLastHandler(const std::shared_ptr<apollo::drivers::PointCloud>& msg);
    void publishTF();
    void publishKeyPosesAndFrames();
    void visualizeGlobalMapThread();
    void publishGlobalMap();
    void loopClosureThread();
    bool detectLoopClosure();
    void performLoopClosure();
    gtsam::Pose3 pclPointTogtsamPose3(PointTypePose thisPoint);
    Eigen::Affine3f pclPointToAffine3fCameraToLidar(PointTypePose thisPoint);
    void extractSurroundingKeyFrames();
    void downsampleCurrentScan();
    void cornerOptimization(int iterCount);
    void surfOptimization(float const deltaR, float const deltaT);
    bool scan2MapOptimization();
    void saveKeyFramesAndFactor();
    void correctPoses();
    void clearCloud();
    void spin();
    void run();
    void pointAssociateToMap(PointType const* const pi, PointType* const po);
    void fullLaserCloudLastHandler(const std::shared_ptr<apollo::drivers::PointCloud>&& msg);
    ///

    void updateInitialGuess();
    bool LMOptimization(int iterCount, float* const deltaR, float* const deltaT);
    void extractNearby();
    void extractCloud(pcl::PointCloud<PointType>::Ptr cloudToExtract);
    void updatePointAssociateToMap();
    bool saveFrame();
    void addOdomFactor();
    void addGPSFactor();
    void addLoopFactor();
    void publishOdometry();
    Eigen::Affine3f trans2Affine3f(float transformIn[]);
    void performRSLoopClosure();
    void loopFindNearKeyframes(
            pcl::PointCloud<PointType>::Ptr& nearKeyframes,
            const int& key,
            const int& searchNum,
            const int& loop_index);
    float constraintTransformation(float value, float limit);
    void combineOptimizationCoeffs();
    Eigen::Affine3f pclPointToAffine3f(PointTypePose thisPoint);
    gtsam::Pose3 trans2gtsamPose(float transformIn[]);
    bool detectLoopClosureDistance(int* latestID, int* closestID);
    bool LatlonToUtmXY(double lon_rad, double lat_rad, UTMCoor* utm_xy);
    bool SaveCorrectPose(const std::string& pose_path, bool save_global_txt_file);
    void cloudHandler(const std::shared_ptr<apollo::drivers::PointCloud>& laserCloudMsg);
    void voxelFilterAndPreserveIntensity(
            const pcl::PointCloud<PointType>::Ptr& input_cloud,
            pcl::PointCloud<PointType>::Ptr& output_cloud,
            std::vector<float> input_intensity_index,
            std::vector<float>& output_intensity_index,
            float voxel_size);
    pcl::PointCloud<PointType>::Ptr transformPointCloudReverse(
            pcl::PointCloud<PointType>::Ptr cloudIn,
            PointTypePose* transformIn);
    int findModeOrMedianOptimized(std::vector<float>& intensities);
    void update_last_pose(const Eigen::Vector3d& trans_local);
    bool scan2MapOptimizationWithCUDA();

    // tools
    double tool_calculate_mean_distance(
        const std::vector<std::vector<double>>& rtk_pose, 
        const std::vector<std::vector<double>>& slam_pose, 
        const double timestamp_threshold = 0.05);
    double calculate_distance(const std::vector<double>& pose1, const std::vector<double>& pose2);

    std::vector<std::vector<double>> tool_linear_interpolate(const std::vector<std::vector<double>>& pose);

    template <typename T>
    T lerp(const T& a, const T& b, double t) {
        return a * (1 - t) + b * t;
    };
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

private:
    std::shared_ptr<LoamVelodyneConf> config_;
    NonlinearFactorGraph gtSAMgraph;
    Values initialEstimate;
    Values optimizedEstimate;
    ISAM2* isam;
    Values isamCurrentEstimate;
    Eigen::MatrixXd poseCovariance;

    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubLaserCloudSurround = nullptr;
    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubLaserOdometryGlobal;
    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubLaserOdometryIncremental;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubKeyPoses = nullptr;

    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubHistoryKeyFrames = nullptr;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubIcpKeyFrames = nullptr;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubRecentKeyFrames = nullptr;

    std::shared_ptr<apollo::cyber::Writer<slamStatus>> pubSlamStatus = nullptr;

    std::shared_ptr<apollo::cyber::Reader<cloudWithPoseInfo>> subCloud;
    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::gnss::GnssBestPose>> subGnssBestPoseLast;
    std::shared_ptr<apollo::cyber::Reader<apollo::localization::Gps>> subGnssOdometryLast;

    std::deque<Odometry> gpsQueue;
    cloudWithPoseInfo cloudInfo;

    std::vector<pcl::PointCloud<PointType>::Ptr> surfCloudKeyFrames;

    pcl::PointCloud<PointType>::Ptr cloudKeyPoses3D;
    pcl::PointCloud<PointTypePose>::Ptr cloudKeyPoses6D;
    pcl::PointCloud<PointType>::Ptr copy_cloudKeyPoses3D;
    pcl::PointCloud<PointTypePose>::Ptr copy_cloudKeyPoses6D;

    pcl::PointCloud<PointType>::Ptr laserCloudSurfLast;    // surf feature set from odoOptimization
    pcl::PointCloud<PointType>::Ptr laserCloudSurfLastDS;  // downsampled surf feature set from odoOptimization

    pcl::PointCloud<PointType>::Ptr laserCloudOri;
    pcl::PointCloud<PointType>::Ptr coeffSel;

    std::vector<PointType> laserCloudOriSurfVec;  // surf point holder for parallel computation
    std::vector<PointType> coeffSelSurfVec;
    std::vector<bool> laserCloudOriSurfFlag;

    std::map<int, std::pair<pcl::PointCloud<PointType>, pcl::PointCloud<PointType>>> laserCloudMapContainer;
    pcl::PointCloud<PointType>::Ptr laserCloudSurfFromMap;
    pcl::PointCloud<PointType>::Ptr laserCloudSurfFromMapDS;

    pcl::KdTreeFLANN<PointType>::Ptr kdtreeSurfFromMap;

    pcl::KdTreeFLANN<PointType>::Ptr kdtreeSurroundingKeyPoses;
    pcl::KdTreeFLANN<PointType>::Ptr kdtreeHistoryKeyPoses;

    pcl::VoxelGrid<PointType> downSizeFilterSurf;
    pcl::VoxelGrid<PointType> downSizeFilterLocalMapSurf;
    pcl::VoxelGrid<PointType> downSizeFilterICP;
    pcl::VoxelGrid<PointType> downSizeFilterSurroundingKeyPoses;

    Eigen::Quaterniond car_orientation_;

    double timeLaserInfoCur = -1;
    double lastBestGnssTime = -1;

    float transformTobeMapped[6];
    float initTransformTobeMapped[6];

    std::mutex mtx;
    std::mutex mtxLoopInfo;

    bool isDegenerate = false;
    cv::Mat matP;

    int laserCloudSurfFromMapDSNum = 0;
    int laserCloudSurfLastDSNum = 0;

    bool aLoopIsClosed = false;
    std::map<int, int> loopIndexContainer;  // from new to old
    std::vector<std::pair<int, int>> loopIndexQueue;
    std::vector<gtsam::Pose3> loopPoseQueue;
    // vector<gtsam::noiseModel::Diagonal::shared_ptr> loopNoiseQueue;
    std::vector<gtsam::SharedNoiseModel> loopNoiseQueue;
    // deque<std_msgs::Float64MultiArray> loopInfoVec;

    Eigen::Affine3f transPointAssociateToMap;
    Eigen::Affine3f incrementalOdometryAffineFront;
    Eigen::Affine3f incrementalOdometryAffineBack;

    GeographicLib::LocalCartesian gps_trans_;

    // scancontext loop closure
    // SCManager scManager;
    std::string processPath;
    std::shared_ptr<commonlib::CommonLib> common_lib_;
    std::future<void> async_result_;
    bool newLaserCloudSurfLast = false;
    double gnss_map_offset[3];
    std::vector<Odometry> bestGnssPose;

    // SLAM service
    std::shared_ptr<apollo::cyber::Service<SlamRequest, SlamResponse>> service_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::PointCloud>> subLaserCloud;
    int seqNumPointCloud = 0;

    std::unique_ptr<Eigen::Quaterniond> imu_localization_quat_;
    std::unique_ptr<Eigen::Vector3d> imu_localization_translation_;
    std::atomic<bool> isFirstScan_{false};

    std::vector<double> linearInterpolation(const Odometry& lastGPS, const Odometry& thisGPS, double currentTime);

    // slam status output
    int slam_iter_count_number_ = 0;
    double slam_pc_icp_score_ = 0.0;

    std::vector<double> store_icp_distance_;

    float log_rtk_heading_value_ = 0.0;

    // publish status for slam mapping
    int pub_loop_closed_number_ = 0;  // return to DV, number and status
    double pub_coverage_valid_rtk_
            = 0.0;  // 建图区域内有效rtk的覆盖度，建图结束后计算，统计总的rtk回调次数及best pose 的数量
    int coverage_rtk_valid_ = 0;
    int coverage_rtk_sum_ = 0;
    bool rtk_status_ = false;
    PointTypePose last_slam_pose_;
    double distance_of_slam_points_ = 0.0; // 本次rtk信号不好时车辆走过的距离
    double max_distance_of_slam_points_ = 0.0; // max distance of slam points show in channel
    std::pair<double, double> rtk_lost_time_; // 第一次跟最后一次rtk丢失的时间
    std::vector<std::pair<double, double>> rtk_lost_time_store_; // store rtk lost time for check
    // [timestamp0,x,y],[timestamp1,x,y]...
    std::vector<std::vector<double>> pub_rtk_mapping_pose_; // store rtk mapping pose, results check
    std::vector<std::vector<double>> pub_slam_mapping_pose_; // store slam mapping pose, results check
    std::vector<double> pub_mean_slam_icp_; // store slam mapping pose, results check

    // slam status output
    int debug_lmoptimization_iterCount_ = 0;
    bool debug_icp_status_ = false;
    // icp score of matched points
    float debug_icp_score_matched_ = 0.0;
    // icp score of not matched points, which is used to judge whether the icp is realiable
    float debug_icp_score_not_matched_ = 0.0;
    // intensity error score of matched points
    float debug_intensity_score_matched_ = 0.0;
    float debug_intensity_score_not_matched_ = 0.0;
    int debug_matched_lidar_points_num_ = 0;
    int debug_icp_laserCloudSurfFromMapDS_size = 0;
    int debug_icp_laserCloudOri_size = 0;

    std::vector<double> debug_icp_distance_;
    std::vector<float> debug_intensity_value_;
    bool isRTKLocalResult_ = false;
    Odometry current_odomRTK_data_;
    // KD_TREE<PointType>::Ptr kdtree_ptr;
    // KD_TREE<PointType> ikdtree;
    PointType searchPtsLast;
    bool update_kdtree = false;
    std::vector<std::vector<int>> Nearest_Points;
    std::vector<std::vector<float>> pointSearchDis;
    std::vector<bool> point_selected;
    //     LocalizationStatus pubLidarSlamStaus;
    // cuda_tools
    thrust::host_vector<float4> surf_map_3d;
    thrust::host_vector<float4> surf_pts_3d;
    thrust::host_vector<float4> corner_map_3d;
    thrust::host_vector<float4> corner_pts_3d;
    CUDAScanToMapOpt cuda_scan_to_map_opt = {204800, 102400, 20480, 10240};
    bool gpu_avaiable = true;
    PlaneFitGroundDetectorParam* param_ = nullptr;
    PlaneFitGroundDetector* pfdetector_ = nullptr;
    std::vector<float> data_;
    std::vector<float> ground_height_signed_;
    std::vector<bool> ground_label_;
    float debug_icp_score_ground = 0.0;
    int debug_ground_size = 0;
};

CYBER_REGISTER_COMPONENT(MapOptimization)
}  // namespace loam_velodyne
}  // namespace apollo
