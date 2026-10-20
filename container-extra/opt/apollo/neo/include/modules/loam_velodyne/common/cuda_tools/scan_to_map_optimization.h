#pragma once

#ifndef LIO_SAM_CUDA_SCAN_TO_MAP_OPTIMIZATION_CUH
#define LIO_SAM_CUDA_SCAN_TO_MAP_OPTIMIZATION_CUH

#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

#include "Eigen/Core"
#include "Eigen/Geometry"

#include "modules/loam_velodyne/common/cuda_tools/calc_corner_coeff.h"
#include "modules/loam_velodyne/common/cuda_tools/calc_surf_coeff.h"
#include "modules/loam_velodyne/common/cuda_tools/cloud_hash_map.h"
#include "modules/loam_velodyne/common/cuda_tools/compute_jac_and_res.h"
#include "modules/loam_velodyne/common/cuda_tools/cuda_ata.h"
#include "modules/loam_velodyne/common/cuda_tools/cuda_atb.h"
#include "modules/loam_velodyne/common/cuda_tools/point_associate_to_map.h"

namespace apollo {
namespace loam_velodyne {

struct CUDAScanToMapOpt {
public:
    CUDAScanToMapOpt(
            unsigned int max_size_surf_map_,
            unsigned int max_size_corner_map_,
            unsigned int max_size_surf_query_,
            unsigned int max_size_corner_query_) :
            surf_hash_map(max_size_surf_map_),
            corner_hash_map(max_size_corner_map_),
            jac(max_size_surf_query_, 6),
            res(max_size_surf_query_, 1),
            max_size_surf_map(max_size_surf_map_),
            max_size_corner_map(max_size_corner_map_),
            max_size_surf_query(max_size_surf_query_),
            max_size_corner_query(max_size_corner_query_) {};

public:
    CUDACloudHashMap surf_hash_map;
    CUDACloudHashMap corner_hash_map;
    PointAssociateToMapKernel surf_associate_to_map;
    PointAssociateToMapKernel corner_associate_to_map;
    CalcSurfCoeffKernel calc_surf_coeff;
    CalcCornerCoeffKernel calc_corner_coeff;
    ComputeJacAndResKernel compute_jac_and_res;

public:
    void SetAffineMatInit(const Eigen::Affine3f& mat_3x4);
    void SetTrans6DOFInit(const Eigen::Matrix<float, 6, 1>& mat_6x1);
    void Trans3x4ToTrans6();
    void Trans6ToTrans3x4();
    void BuildSurfHashMap(const thrust::host_vector<float4>& surf_map_3d);
    void BuildSurfAndCornerHashMap(const thrust::host_vector<float4>& host_surf_map_3d);
    void SetSurfPoints(const thrust::host_vector<float4>& surf_pts_3d);
    void SetCornerPoints(const thrust::host_vector<float4>& corner_pts_3d);
    void TransformSurfPoints();
    void TransformCornerPoints();
    void TransformSurfAndCornerPoints();
    void SearchSurfPointsWithHashMap();
    void SearchCornerPointsWithHashMap();
    void SearchSurfAndCornerPointsWithHashMap();
    void CalcSurfAndCornerCoeff(
            float* debug_icp_score_,
            float* debug_intensity_score_,
            float* debug_icp_score_ground,
            int* debug_ground_size,
            int* debug_matched_lidar_points_num_,
            const std::vector<bool>& ground_label);
    void MallocForJacAndRes();
    void ComputeJacAndRes();
    void UpdateTranform(double* deltaR, double* deltaT);
    void PrintStates();
    int getNumberOfAvailableThreads();
    // EIGEN_MAKE_ALIGNED_OPERATOR_NEW

public:
    thrust::device_vector<float4> surf_ori;
    thrust::device_vector<float4> surf_sel;

    thrust::device_vector<char> surf_flag;

    thrust::device_vector<float4> surf_nbr_0;
    thrust::device_vector<float4> surf_nbr_1;
    thrust::device_vector<float4> surf_nbr_2;
    thrust::device_vector<float4> surf_nbr_3;
    thrust::device_vector<float4> surf_nbr_4;

    thrust::device_vector<float4> surf_coeff;

public:
    thrust::device_vector<float4> corner_ori;
    thrust::device_vector<float4> corner_sel;

    thrust::device_vector<char> corner_flag;

    thrust::device_vector<float4> corner_nbr_0;
    thrust::device_vector<float4> corner_nbr_1;
    thrust::device_vector<float4> corner_nbr_2;
    thrust::device_vector<float4> corner_nbr_3;
    thrust::device_vector<float4> corner_nbr_4;

    thrust::device_vector<float4> corner_coeff;

public:
    thrust::device_vector<float4> surf_and_corner_ori;
    thrust::device_vector<char> surf_and_corner_flag;
    thrust::device_vector<float4> surf_and_corner_coeff;
    thrust::device_vector<float> debug_icp_score_;
    thrust::device_vector<float> debug_intensity_score_;

public:
    CUDAMatrix<float> jac;
    CUDAMatrix<float> res;

public:
    CUDAATA cuda_AtA;
    CUDAATB cuda_AtB;

public:
    unsigned int num_surf_points = 0;
    unsigned int num_corner_points = 0;
    unsigned int max_size_surf_map;
    unsigned int max_size_corner_map;
    unsigned int max_size_surf_query;
    unsigned int max_size_corner_query;
    unsigned int iter_count = 0;
    bool degenerated = false;
    bool converged = false;
    float trans3x4_init[3][4];
    float trans6_init[6];
    float trans3x4[3][4];
    float trans6[6];  // roll, pitch, yaw, x, y, z
    unsigned int max_threads = 0;
};

}  // namespace loam_velodyne
}  // namespace apollo

#endif  // LIO_SAM_CUDA_SCAN_TO_MAP_OPTIMIZATION_CUH
