# About 
The examples and tutorial in C++ for Project Chrono using Irrlicht

#### Project Chrono 7.0.3
#### Irrlicht 1.8.5

# Tutorial
Tutorial Videos for Project Chrono and Irrlicht have been made and available at:

https://www.youtube.com/watch?v=X7YCNnkWK9I&list=PLjKBQAK4kvpiLYBVSjuHMAfqqKFKwkPa1

# How to Build

In building Project Chrono, I use this configuration scripts:

    CMAKE_BUILD_TYPE=Release
    CMAKE_INSTALL_PREFIX=/opt/hamzstlib
    IRRLICHT_LIBRARY=/opt/hamzstlib/Physics/irrlicht-1.8.5/lib/Linux/libIrrlicht.so.1.8.5
    IRRLICHT_ROOT=/opt/hamzstlib/Physics/irrlicht-1.8.5/
    BUILD_DEMOS=ON
    ENABLE_MODULE_IRRLICHT=ON
    ENABLE_MODULE_MODAL=ON
    ENABLE_MODULE_OPENGL=ON
    ENABLE_MODULE_POSTPROCESS=ON
    ENABLE_MODULE_SYNCHRONO=ON
    ENABLE_MODULE_VEHICLE=ON
    ENABLE_OPENMP=ON
    Eigen3_DIR=/opt/hamzstlib/share/eigen3/cmake
    USE_BULLET_OPENMP=ON
    USE_EIGEN_OPENMP=ON
    USE_SIMD=ON

## MODAL Module
To enable MODAL module, we need Spectra thus:

    git clone https://github.com/yixuan/spectra.git
    
## VEHICLE Module
To use the CRGTerrain feature, you must download, install, and enable the OpenCRG library.

    git clone https://github.com/hlrs-vis/opencrg.git
    
# Sources
https://irrlicht.sourceforge.io/docu/index.html

https://api.projectchrono.org/tutorial_root.html

https://www.asam.net/index.php?eID=dumpFile&t=f&f=3950&token=21a7ae456ec0eb0f9ec3aee5bae3e8c9ebaea140

https://spectralib.org/
