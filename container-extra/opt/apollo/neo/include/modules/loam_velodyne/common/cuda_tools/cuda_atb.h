#pragma once

#ifndef LIO_SAM_CUDA_CUDA_ATB_CUH
#define LIO_SAM_CUDA_CUDA_ATB_CUH

#include "Eigen/Core"

#include <cuda_runtime.h>
#include <cublas_v2.h>

#include "cuda_matrix.h"
namespace apollo {
namespace loam_velodyne {

struct CUDAATB {
    cudaError_t m_cuda_status;
    cublasHandle_t m_cublas_handle;
    cublasStatus_t m_cublas_status;

    CUDAATB() {
        cublasCreate_v2(&m_cublas_handle);
        m_cublas_status = CUBLAS_STATUS_SUCCESS;
    }

    const float m_alpha = 1.0;
    const float m_beta = 0.0;

    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> m_host_ATB;

    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> Compute(
            CUDAMatrix<float>& A,
            CUDAMatrix<float>& B) {
        assert(A.rows() > 0);
        assert(A.cols() > 0);
        assert(A.ld() >= A.rows());
        assert(B.rows() > 0);
        assert(B.cols() > 0);
        assert(B.ld() >= B.rows());

        CUDAMatrix<float> ATB(A.cols(), B.cols());
        ATB.resize(A.cols(), B.cols());

        m_cublas_status = cublasSgemm_v2(
                m_cublas_handle,
                CUBLAS_OP_T,
                CUBLAS_OP_N,
                A.cols(),
                B.cols(),
                A.rows(),
                &m_alpha,
                A.GetDevicePtr(),
                A.ld(),
                B.GetDevicePtr(),
                B.ld(),
                &m_beta,
                ATB.GetDevicePtr(),
                ATB.ld());
        // m_cuda_status = cudaStreamSynchronize(0);
        assert(cudaSuccess == m_cuda_status);
        assert(CUBLAS_STATUS_SUCCESS == m_cublas_status);

        m_host_ATB.resize(ATB.rows(), ATB.cols());
        m_host_ATB.setZero();
        for (int i = 0; i < ATB.cols(); i++) {
            m_cuda_status = cudaMemcpy(
                    (void*)(m_host_ATB.col(i).data()),
                    (void*)(ATB.GetDevicePtr() + i * ATB.ld()),
                    sizeof(float) * ATB.rows(),
                    cudaMemcpyDeviceToHost);
            assert(cudaSuccess == m_cuda_status);
        }

        return m_host_ATB;
    }
    // EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    ~CUDAATB() {
        if (m_cublas_handle) {
            cublasDestroy(m_cublas_handle);
        }
    }
};

}  // namespace loam_velodyne
}  // namespace apollo

#endif  // LIO_SAM_CUDA_CUDA_ATB_CUH
