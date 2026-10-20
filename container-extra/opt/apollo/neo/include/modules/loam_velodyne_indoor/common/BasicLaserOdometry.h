#pragma once
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "modules/loam_velodyne_indoor/common/Twist.h"
#include "modules/loam_velodyne_indoor/common/nanoflann_pcl.h"

namespace loam {

/** \brief Implementation of the LOAM laser odometry component.
 *
 */
class BasicLaserOdometry {
public:
    explicit BasicLaserOdometry(float scanPeriod = 0.1, size_t maxIterations = 25);

    /** \brief Try to process buffered data. */
    void process();
    void updateIMU(pcl::PointCloud<pcl::PointXYZ> const& imuTrans);

    auto& cornerPointsSharp() {
        return _cornerPointsSharp;
    }
    auto& cornerPointsLessSharp() {
        return _cornerPointsLessSharp;
    }
    auto& surfPointsFlat() {
        return _surfPointsFlat;
    }
    auto& surfPointsLessFlat() {
        return _surfPointsLessFlat;
    }
    auto& laserCloud() {
        return _laserCloud;
    }

    auto& laserCloudAddInts() {
        return _laserCloudAddInts;
    }

    auto const& transformSum() {
        return _transformSum;
    }
    auto const& transform() {
        return _transform;
    }
    auto const& lastCornerCloud() {
        return _lastCornerCloud;
    }
    auto const& lastSurfaceCloud() {
        return _lastSurfaceCloud;
    }

    void setScanPeriod(float val) {
        _scanPeriod = val;
    }
    void setMaxIterations(size_t val) {
        _maxIterations = val;
    }
    void setDeltaTAbort(float val) {
        _deltaTAbort = val;
    }
    void setDeltaRAbort(float val) {
        _deltaRAbort = val;
    }
    void setProjectName(std::string projectName) {
        _projectName = projectName;
    }

    auto frameCount() const {
        return _frameCount;
    }
    auto scanPeriod() const {
        return _scanPeriod;
    }
    auto maxIterations() const {
        return _maxIterations;
    }
    auto deltaTAbort() const {
        return _deltaTAbort;
    }
    auto deltaRAbort() const {
        return _deltaRAbort;
    }

    std::string _projectName;

    std::string _pointCloudPath;

    double _lastTimeRecord = 0.0;

    int _pointNum = 0;
    FILE* _fp;

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
    Public_Header_Block _HeaderStruct;
    Point_Data _inputPoint;

    /** \brief Transform the given point cloud to the end of the sweep.
     *
     * @param cloud the point cloud to transform
     */
    size_t transformToEnd(pcl::PointCloud<pcl::PointXYZI>::Ptr& cloud);
    size_t transformToEnd(pcl::PointCloud<pcl::PointNormal>::Ptr& cloud);

private:
    /** \brief Transform the given point to the start of the sweep.
     *
     * @param pi the point to transform
     * @param po the point instance for storing the result
     */
    void transformToStart(const pcl::PointXYZI& pi, pcl::PointXYZI& po);

    void pluginIMURotation(
            const Angle& bcx,
            const Angle& bcy,
            const Angle& bcz,
            const Angle& blx,
            const Angle& bly,
            const Angle& blz,
            const Angle& alx,
            const Angle& aly,
            const Angle& alz,
            Angle& acx,
            Angle& acy,
            Angle& acz);

    void
    accumulateRotation(Angle cx, Angle cy, Angle cz, Angle lx, Angle ly, Angle lz, Angle& ox, Angle& oy, Angle& oz);

private:
    float _scanPeriod;      ///< time per scan
    long _frameCount;       ///< number of processed frames
    size_t _maxIterations;  ///< maximum number of iterations
    bool _systemInited;     ///< initialization flag

    float _deltaTAbort;  ///< optimization abort threshold for deltaT
    float _deltaRAbort;  ///< optimization abort threshold for deltaR

    pcl::PointCloud<pcl::PointXYZI>::Ptr _lastCornerCloud;   ///< last corner points cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr _lastSurfaceCloud;  ///< last surface points cloud

    pcl::PointCloud<pcl::PointXYZI>::Ptr _laserCloudOri;  ///< point selection
    pcl::PointCloud<pcl::PointXYZI>::Ptr _coeffSel;       ///< point selection coefficients

    nanoflann::KdTreeFLANN<pcl::PointXYZI> _lastCornerKDTree;   ///< last corner cloud KD-tree
    nanoflann::KdTreeFLANN<pcl::PointXYZI> _lastSurfaceKDTree;  ///< last surface cloud KD-tree

    pcl::PointCloud<pcl::PointXYZI>::Ptr _cornerPointsSharp;      ///< sharp corner points cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr _cornerPointsLessSharp;  ///< less sharp corner points cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr _surfPointsFlat;         ///< flat surface points cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr _surfPointsLessFlat;     ///< less flat surface points cloud
    pcl::PointCloud<pcl::PointXYZI>::Ptr _laserCloud;             ///< full resolution cloud

    pcl::PointCloud<pcl::PointXYZI>::Ptr _laserCloudAddInts;

    std::vector<int> _pointSearchCornerInd1;  ///< first corner point search index buffer
    std::vector<int> _pointSearchCornerInd2;  ///< second corner point search index buffer

    std::vector<int> _pointSearchSurfInd1;  ///< first surface point search index buffer
    std::vector<int> _pointSearchSurfInd2;  ///< second surface point search index buffer
    std::vector<int> _pointSearchSurfInd3;  ///< third surface point search index buffer

    Twist _transform;     ///< optimized pose transformation
    Twist _transformSum;  ///< accumulated optimized pose transformation

    Angle _imuRollStart, _imuPitchStart, _imuYawStart;
    Angle _imuRollEnd, _imuPitchEnd, _imuYawEnd;

    Vector3 _imuShiftFromStart;
    Vector3 _imuVeloFromStart;
};

}  // end namespace loam
