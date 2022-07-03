# About

CUDA® is a parallel computing platform and programming model that enables dramatic increases in computing performance by harnessing the power of the graphics processing unit (GPU). 

Since its introduction in 2006, CUDA has been widely deployed through thousands of applications and published research papers, and supported by an installed base of hundreds of millions of CUDA-enabled GPUs in notebooks, workstations, compute clusters and supercomputers.  Applications used in astronomy, biology, chemistry, physics, data mining, manufacturing, finance, and other computationally intense fields are increasingly using CUDA to deliver the benefits of GPU acceleration.

The CUDA programming model is a heterogeneous model in which both the CPU and GPU are used. In CUDA, the host refers to the CPU and its memory, while the device refers to the GPU and its memory. Code run on the host can manage memory on both the host and device, and also launches kernels which are functions executed on the device. These kernels are executed by many GPU threads in parallel.

Given the heterogeneous nature of the CUDA programming model, a typical sequence of operations for a CUDA C program is:

1. Declare and allocate host and device memory.
2. Initialize host data.
3. Transfer data from the host to the device.
4. Execute one or more kernels.
5. Transfer results from the device to the host.

#### CUDA is a standard feature in all NVIDIA GeForce, Quadro, and Tesla GPUs as well as NVIDIA GRID solutions. 

# How to get started

Software developers, scientists and researchers can add support for GPU acceleration in their own applications using one of  three simple approaches:

* Drop in a GPU-accelerated library to replace or augment CPU-only libraries such as MKL BLAS, IPP, FFTW and other widely-used libraries
* Automatically parallelize loops in Fortran or C code using OpenACC directives for accelerators
* Develop custom parallel algorithms and libraries using a familiar programming language such as C, C++, C#, Fortran, Java, Python, etc.

# Examples: Compiling Cuda

The CUDA C compiler, nvcc, is part of the NVIDIA CUDA Toolkit.  
To compile our SAXPY example, we save the code in a file with a .cu extension, say saxpy.cu. We can then compile it with nvcc.

## Compiling and Running the Code

```
nvcc -o saxpy saxpy.cu
./saxpy
```

# Sources

https://developer.nvidia.com/about-cuda

https://developer.nvidia.com/blog/easy-introduction-cuda-c-and-c/
