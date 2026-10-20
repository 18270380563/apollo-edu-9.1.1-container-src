#pragma once

#ifndef LIO_SAM_CUDA_COMPUTE_JAC_AND_RHS_CUH
#define LIO_SAM_CUDA_COMPUTE_JAC_AND_RHS_CUH
#define EIGEN_USE_GPU
#define EIGEN_USE_THREADS
#include "Eigen/Core"
#include "Eigen/Geometry"

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

#include "cuda_matrix.h"

namespace apollo {
namespace loam_velodyne {

struct ComputeJacAndResKernel {
public:
    ComputeJacAndResKernel() {
        cudaStreamCreateWithFlags(&cuda_stream, cudaStreamNonBlocking);
    }
    ~ComputeJacAndResKernel() {
        Sync();
        cudaStreamDestroy(cuda_stream);
    }

    void LaunchKernel(
            unsigned int num_points,
            thrust::device_vector<float4>& point_ori,
            thrust::device_vector<char>& flag,
            thrust::device_vector<float4>& coeff,
            float trans_0,
            float trans_1,
            float trans_2,
            CUDAMatrix<float>& A,
            CUDAMatrix<float>& B);
    // EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    void Sync() const {
        cudaStreamSynchronize(cuda_stream);
    }

public:
    float srx;
    float crx;
    float sry;
    float cry;
    float srz;
    float crz;

public:
    cudaStream_t cuda_stream{};
};

}  // namespace loam_velodyne
}  // namespace apollo

#endif  // LIO_SAM_CUDA_COMPUTE_JAC_AND_RHS_CUH
