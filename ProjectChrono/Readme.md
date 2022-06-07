# About 
The examples and tutorial in C++ for Project Chrono using Irrlicht

#### Project Chrono 7.0.3
#### Irrlicht 1.8.5

# Tutorial
Tutorial Videos for Project Chrono and Irrlicht have been made and available at:

https://www.youtube.com/watch?v=X7YCNnkWK9I&list=PLjKBQAK4kvpiLYBVSjuHMAfqqKFKwkPa1

# Download Project Chrono

## Project Chrono (latest develop version)
From /opt/hamzstlib/physics, type:

        git clone https://github.com/projectchrono/chrono.git
        cd chrono

## Project Chrono-7.0.3
From /opt/hamzstlib/physics, type:

        wget https://github.com/projectchrono/chrono/archive/refs/tags/7.0.3.tar.gz
        tar -xvf 7.0.3.tar.gz
        cd chrono-7.0.3

# How to Build

In building Project Chrono, I use this configuration scripts:
    
    mkdir build
    cd build
    
    CMAKE_BUILD_TYPE=Release
    CMAKE_INSTALL_PREFIX=/opt/hamzstlib
    IRRLICHT_LIBRARY=/opt/hamzstlib/Physics/irrlicht-1.8.5/lib/Linux/libIrrlicht.so.1.8.5
    IRRLICHT_ROOT=/opt/hamzstlib/Physics/irrlicht-1.8.5/
    BUILD_DEMOS=ON
    ENABLE_MODULE_COSIMULATION=ON
    ENABLE_MODULE_IRRLICHT=ON
    ENABLE_MODULE_MODAL=ON
    ENABLE_MODULE_OPENGL=ON
    ENABLE_MODULE_POSTPROCESS=ON
    ENABLE_MODULE_SYNCHRONO=ON
    ENABLE_MODULE_VEHICLE=ON
    ENABLE_OPENMP=ON
    ENABLE_OPENCRG=ON
    GLEW_LIBRARY=/usr/lib/libGLEW.so
    GLEW_INCLUDE_DIR=/usr/include
    GLFW_LIBRARY=/opt/hamzstlib/lib/libglfw.so.3
    GLFW_INCLUDE_DIR=/opt/hamzstlib/include/GLFW
    OPENCRG_LIBRARY=/opt/hamzstlib/lib/libOpenCRG.so
    OPENCRG_INCLUDE_DIR=/opt/hamzstlib/Physics/OpenCRG.1.1.2/c-api/baseline/inc
    SPECTRA_INCLUDE_DIR=/opt/hamzstlib/include/Spectra
    Eigen3_DIR=/opt/hamzstlib/share/eigen3/cmake
    USE_BULLET_OPENMP=ON
    USE_EIGEN_OPENMP=ON
    USE_SIMD=ON

![ccmake](https://github.com/glanzkaiser/glanzshamzs/blob/main/ProjectChrono/images/chronoccmake.png)

# Sources
https://irrlicht.sourceforge.io/docu/index.html

https://api.projectchrono.org/tutorial_root.html


