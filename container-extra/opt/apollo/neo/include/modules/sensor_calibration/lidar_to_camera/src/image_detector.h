#pragma once
#include <fstream>
#include <opencv2/opencv.hpp>

#include "modules/sensor_calibration/proto/lidar_to_camera_algorithm_config.pb.h"
#include "modules/sensor_calibration/proto/lidar_to_camera_calibration_config.pb.h"
#include "modules/sensor_calibration/lidar_to_camera/src/common/pre_process.h"

namespace apollo {
namespace sensor_calibration {

class ImageDetector {
public:
    ImageDetector(std::shared_ptr<LidarToCameraAlgorithmConfig> conf) : conf_(conf) {};
    ~ImageDetector() {};
    std::vector<cv::Point2f> SortPose(std::vector<cv::Point2f> points);
    bool ExtractCameraCorners(
            const std::string &sub_folder_path,
            std::string *error_msg,
            std::vector<cv::Point2f> &points);
    double SolvePnp(std::vector<cv::Point3f> objectPoints, std::vector<cv::Point2f> imagePoints);
    void LoadCameraIntrinsic();
    bool Init(std::shared_ptr<LidarToCameraCalibrationConfig> conf, std::string *error_msg);
    void SavePointCloudImage();
    bool ProjectCloudToImg(
            const std::string &image_path,
            const std::string &cloud_path,
            const std::string &save_name,
            bool is_color);
    void SaveFitResult(std::string filepath, std::string filename_fit);
    void PrintResult(bool is_final);
    std::vector<std::string> GetImagePath();
    bool SaveCameraExtrinsicPara(const std::string &save_path, std::string *error_msg);
    bool UpdateCameraExtrinsicPara(const std::string &extrinsic_path, std::string *error_msg);
    bool ProjectCloudToImg(const std::string &sub_folder_path, std::string *error_msg);
    double getScoreFromSum(double error, int score_increment_num);

private:
    int baseIncrement_ = 10;
    int score_increment_num_ = 0;
    double score_increment_ = 5.0;
    std::map<int, double> scoreMap_ = {
            {0 * baseIncrement_, 100.0 - score_increment_num_ *score_increment_},
            {1 * baseIncrement_, 85.0 - score_increment_num_ *score_increment_},
            {2 * baseIncrement_, 80.0 - score_increment_num_ *score_increment_},
            {3 * baseIncrement_, 75.0 - score_increment_num_ *score_increment_},
            {5 * baseIncrement_, 70.0 - score_increment_num_ *score_increment_},
            {8 * baseIncrement_, 65.0 - score_increment_num_ *score_increment_},
            {11 * baseIncrement_, 60.0 - score_increment_num_ *score_increment_},
            {14 * baseIncrement_, 55.0 - score_increment_num_ *score_increment_},
            {50 * baseIncrement_, 1.0},
    };
    void updateScoreMap();
    void setScoreIncrementNum(int num);
    double pattern_box_square_size_;
    int pattern_box_size_in_len_;
    int pattern_box_size_in_width_;
    double pattern_length_;
    double pattern_width_;
    double pre_rotation_angle_;
    std::string log_path_;
    std::string distortion_model_;
    cv::Mat distCoeffs_none_;
    cv::Mat camera_matrix_;
    cv::Mat distCoeffs_;
    cv::Mat rvec_;
    cv::Mat tvec_;
    cv::Mat extrinsic_;
    std::vector<std::string> image_path_;
    std::vector<std::string> log_path_all_;
    std::shared_ptr<LidarToCameraAlgorithmConfig> conf_;
    Transform lidar_to_imu_transform_;
};

}  // namespace sensor_calibration
}  // namespace apollo