#ifndef LIO_SAM_CUDA_CALC_SURF_COEFF_CUH
#define LIO_SAM_CUDA_CALC_SURF_COEFF_CUH

#include <cuda_runtime.h>

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <cusolverDn.h>

namespace apollo {
namespace loam_velodyne {

struct CalcSurfCoeffKernel {
public:
    CalcSurfCoeffKernel() {
        cudaStreamCreateWithFlags(&cuda_stream, cudaStreamNonBlocking);
    }
    ~CalcSurfCoeffKernel() {
        Sync();
        cudaStreamDestroy(cuda_stream);
    }

    void LaunchKernel(
            unsigned int num_points,
            thrust::device_vector<float4>& point_sel,
            thrust::device_vector<char>& flag,
            thrust::device_vector<float4>& nbr_0,
            thrust::device_vector<float4>& nbr_1,
            thrust::device_vector<float4>& nbr_2,
            thrust::device_vector<float4>& nbr_3,
            thrust::device_vector<float4>& nbr_4,
            thrust::device_vector<float4>& coeff,
            thrust::device_vector<float>& debug_icp_score_,
            thrust::device_vector<float>& debug_intensity_score_);
    void Sync() const {
        cudaStreamSynchronize(cuda_stream);
    }

public:
    cudaStream_t cuda_stream{};
};

}  // namespace loam_velodyne
}  // namespace apollo

#endif  // LIO_SAM_CUDA_CALC_SURF_COEFF_CUH
