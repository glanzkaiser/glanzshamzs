// gcc -I/usr/local/cuda/include -L/usr/local/cuda/lib64 has_cuda.c -lcudart -o has_cuda

#include <cuda_runtime.h>

int main ()
{
    int deviceCount;
    cudaError_t e = cudaGetDeviceCount(&deviceCount);
    return e == cudaSuccess ? deviceCount : -1;
}
