# About
Contains all the packages / modules for supporting Project Chrono' main modules

| Chrono Main Module  | Required Third-Party Modules |
| ------------- | ------------- | 
| CASCADE | OpenCASCADE libraries 
| COSIMULATION | 
| DISTRIBUTED | 
| FSI | 
| GPU | 
| IRRLICHT | 
| MATLAB | 
| MODAL | Spectra 
| MULTICORE | 
| MUMPS | 
| OpenGL | 
| Pardiso MKL | 
| PardisoProject | 
| POSTPROCESS | 
| PYTHON | 
| SENSOR | 
| SYNCHRONO | 
| VEHICLE | To use the CRGTerrain feature, you must download, install, and enable the OpenCRG library.

## Explanation

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
### 3. OpenCASCADE
Open CASCADE Technology (OCCT) is an object-oriented C++ class library designed for rapid production of sophisticated domain-specific CAD/CAM/CAE applications.

A typical application developed using OCCT deals with two or three-dimensional (2D or 3D) geometric modeling in general-purpose or specialized Computer Aided Design (CAD) systems, manufacturing or analysis applications, simulation applications, or even illustration tools.

* The kernel for CAD, almost like the BLAS LAPACK for CAD.

```
wget https://dev.opencascade.org/system/files/occt/OCC_7.6.0_release/opencascade-7.6.0.tgz
```
# Source
https://api.projectchrono.org/modules.html

https://www.asam.net/index.php?eID=dumpFile&t=f&f=3950&token=21a7ae456ec0eb0f9ec3aee5bae3e8c9ebaea140

https://spectralib.org/
