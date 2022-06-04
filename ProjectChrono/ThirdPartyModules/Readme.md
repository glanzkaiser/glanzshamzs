# About
Contains all the packages / modules for supporting Project Chrono' main modules

| Chrono Main Module  | Required Third-Party Modules for Build |
| ------------- | ------------- | 
| CASCADE | OpenCASCADE libraries 
| COSIMULATION | -
| C# | SWIG wrapper generator
| DISTRIBUTED |  an MPI distribution is required + Enable the Chrono::Multicore module
| FSI | a CUDA installation and appropriate compiler are required
| GPU | you must have CUDA installed
| IRRLICHT | you must have the Irrlicht SDK installed
| MATLAB | you must have a licensed copy of Matlab(TM) installed on your system
| MODAL | Spectra 
| MULTICORE | Blaze library + the Boost library (only for Blaze 3.1 or older) + the Thrust (also included in CUDA SDK)
| MUMPS | the MUMPS library must be installed on your machine
| OpenGL | the GLM library + the GLFW library + the GLEW library
| Pardiso MKL | the Intel MKL Library must be installed on your machine
| PardisoProject |  The Pardiso solver + A valid PardisoProject licence
| POSTPROCESS | no requirements except for running you need GNUPLOT or POVray
| PYTHON | you must have Python installed + you must have the SWIG wrapper generator installed
| SENSOR | CUDA + OptiX - version 7.2 only (will NOT work with 6.X or 7.3) + GLFW - version 3.0 or later + GLEW - version 1.0 or later + OpenGL + TensoRT (optional) - version 7.0.0
| SYNCHRONO |  OpenMPI or MPICH + FlatBuffers (included in chrono_thirdparty as a submodule) + FastDDS (optional)
| VEHICLE | To use the CRGTerrain feature, you must download, install, and enable the OpenCRG library.

## Third Party Modules Explanation

### 1. OpenCRG
ASAM OpenCRG defines a file format for the description of road surfaces. It was originally developed to store high-precision elevation data from road surface scans. The primary use for this data is in tire, vibration or driving simulation. Precise elevation data allows realistic endurance simulation of vehicle components or the entire vehicle. For driving simulators, it allows a realistic 3D-rendering of the road surface. The file format can also be used for other types of road surface properties, e.g. for the friction coefficient or grey values.  

OpenCRG is a complete free and open-source project for the creation, modification and evaluation of road surfaces, and an open file format specification CRG (curved regular grid). Its objective is to standardize a detailed road surface description and it may be used for applications like tire-, vibration- or driving-simulation. 

OpenCRG is a standardized efficient 3D road data representation defined in base plane by its direction (heading, yaw angle). It is optionally complemented by hilliness (slope, inclination, grade, pitch angle) and cross slope (super-elevation, banking, cant, camber, roll angle). Compact storage and sufficient accuracy, even for long tracks are the objectives for the open file format specification CRG. 

### 2. Spectra
Spectra stands for Sparse Eigenvalue Computation Toolkit as a Redesigned ARPACK. It is a C++ library for large scale eigenvalue problems, built on top of Eigen, an open source linear algebra library.

Spectra is implemented as a header-only C++ library, whose only dependency, Eigen, is also header-only. Hence Spectra can be easily embedded in C++ projects that require calculating eigenvalues of large matrices.

ARPACK is a software written in FORTRAN for solving large scale eigenvalue problems. The development of Spectra is much inspired by ARPACK, and as the whole name indicates, Spectra is a redesign of the ARPACK library using C++ language.

Download it:
```
wget https://github.com/yixuan/spectra/archive/v1.0.1.tar.gz
```
or
```
git clone https://github.com/yixuan/spectra.git
```

To build and install it from the extracted Spectra directory / source directory, type:
```
mkdir build
cd build &&

cmake -D CMAKE_INSTALL_PREFIX=/opt/hamzstlib \
-D CMAKE_BUILD_TYPE=Release \
-D Eigen3_DIR=/opt/hamzstlib/share/eigen3/cmake ..

make &&

make install
```

### 3. OpenCASCADE
Open CASCADE Technology (OCCT) is an object-oriented C++ class library designed for rapid production of sophisticated domain-specific CAD/CAM/CAE applications.

A typical application developed using OCCT deals with two or three-dimensional (2D or 3D) geometric modeling in general-purpose or specialized Computer Aided Design (CAD) systems, manufacturing or analysis applications, simulation applications, or even illustration tools.

* The kernel for CAD, almost like the BLAS LAPACK for CAD.

```
wget https://dev.opencascade.org/system/files/occt/OCC_7.6.0_release/opencascade-7.6.0.tgz
```

### 4. CUDA
CUDA (or Compute Unified Device Architecture) is a parallel computing platform and application programming interface (API) that allows software to use certain types of graphics processing units (GPUs) for general purpose processing, an approach called general-purpose computing on GPUs (GPGPU). CUDA is a software layer that gives direct access to the GPU's virtual instruction set and parallel computational elements, for the execution of compute kernels.

The NVIDIA® CUDA® Toolkit provides a development environment for creating high performance GPU-accelerated applications. With the CUDA Toolkit, you can develop, optimize, and deploy your applications on GPU-accelerated embedded systems, desktop workstations, enterprise data centers, cloud-based platforms and HPC supercomputers. The toolkit includes GPU-accelerated libraries, debugging and optimization tools, a C/C++ compiler, and a runtime library to deploy your application.

CUDA was originally an acronym for Compute Unified Device Architecture. CUDA C/C++ and CUDA Fortran. CUDA operations are programmed in traditional programming languages. C/C++ and Fortran source code is compiled with NVIDIA's own CUDA compilers for each language.

Using built-in capabilities for distributing computations across multi-GPU configurations, scientists and researchers can develop applications that scale from single GPU workstations to cloud installations with thousands of GPUs.

# Source
https://api.projectchrono.org/modules.html

https://www.asam.net/index.php?eID=dumpFile&t=f&f=3950&token=21a7ae456ec0eb0f9ec3aee5bae3e8c9ebaea140

https://spectralib.org/
