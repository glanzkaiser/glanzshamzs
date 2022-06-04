# About
Contains all the packages / modules for supporting Project Chrono' main modules

| Chrono Main Module  | Required Third-Party Modules |
| ------------- | ------------- | 
| CASCADE | matrix-matrix product
| COSIMULATION | solving a system of linear equations with matrix-matrix operations
| DISTRIBUTED | rank-k update of a matrix
| FSI | rank-k update of a matrix
| GPU | rank-k update of a matrix
| IRRLICHT | rank-k update of a matrix
| MATLAB | rank-k update of a matrix
| MODAL | Spectra 
| MULTICORE | rank-k update of a matrix
| MUMPS | rank-k update of a matrix
| OpenGL | rank-k update of a matrix
| Pardiso MKL | rank-k update of a matrix
| PardisoProject | rank-k update of a matrix
| POSTPROCESS | rank-k update of a matrix
| PYTHON | rank-k update of a matrix
| SENSOR | rank-k update of a matrix
| SYNCHRONO | rank-k update of a matrix
| VEHICLE | rank-k update of a matrix

## Explanation

### 1. OpenCRG
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

# Source
https://api.projectchrono.org/modules.html
