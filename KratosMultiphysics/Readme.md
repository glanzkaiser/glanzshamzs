# About 
KRATOS Multiphysics ("Kratos") is a framework for building parallel, multi-disciplinary simulation software, aiming at modularity, extensibility, and high performance. Kratos is written in C++, and counts with an extensive Python interface. 

#### Use Kratos-9.1

# Download Third Party Modules: GKlib, METIS, MMG

## Gklib
A library of various helper routines and frameworks used by many of the lab's software.

To download it:
```
git clone https://github.com/KarypisLab/GKlib.git
```

Enter the directory then type:
```
make config
make prefix=/opt/hamzstlib
make install
```
Make sure the installed include, bin and lib are in the correct path.

## METIS
METIS is a set of serial programs for partitioning graphs, partitioning finite element meshes, and producing fill reducing orderings for sparse matrices. The algorithms implemented in METIS are based on the multilevel recursive-bisection, multilevel k-way, and multi-constraint partitioning schemes developed in our lab.

To download it:
```
git clone https://github.com/KarypisLab/METIS.git
```

Enter the directory then type:
```
make config shared=1 cc=gcc prefix=/opt/hamzstlib
make install
```

## MMG
Mmg is an open source software for simplicial remeshing. It provides 3 applications and 4 libraries:

* the mmg2d application and the libmmg2d library: adaptation and optimization of a two-dimensional triangulation and generation of a triangulation from a set of points or from given boundary edges
* the mmgs application and the libmmgs library: adaptation and optimization of a surface triangulation and isovalue discretization
* the mmg3d application and the libmmg3d library: adaptation and optimization of a tetrahedral mesh and implicit domain meshing
* the libmmg library gathering the libmmg2d, libmmgs and libmmg3d libraries

To download it
```
git clone https://github.com/MmgTools/mmg.git
```

Enter the directory then type:
```
ccmake ..
make 
make install
```

My ccmake configuration for MMG:
![mmg](https://github.com/glanzkaiser/glanzshamzs/blob/main/KratosMultiphysics/images/mmgccmake.png)

# Download Kratos
    wget https://github.com/KratosMultiphysics/Kratos/archive/refs/tags/v9.1.tar.gz
    tar -xvf v9.1.tar.gz
    cd Kratos-9.1

# Choose Set Applications to compile
See the list of available applications here

```
https://github.com/KratosMultiphysics/Kratos/tree/master/applications
```

Then edit the configure file (configure.sh located at ../Kratos-9.1/scripts/) type for example :
```
export KRATOS_APPLICATIONS=
add_app ${KRATOS_APP_DIR}/LinearSolversApplication
add_app ${KRATOS_APP_DIR}/StructuralMechanicsApplication
add_app ${KRATOS_APP_DIR}/ConstitutiveLawsApplication
add_app ${KRATOS_APP_DIR}/ContactStructuralMechanicsApplication
add_app ${KRATOS_APP_DIR}/FluidDynamicsApplication
add_app ${KRATOS_APP_DIR}/MeshingApplication
add_app ${KRATOS_APP_DIR}/ParticleMechanicsApplication
add_app ${KRATOS_APP_DIR}/ConvectionDiffusionApplication
add_app ${KRATOS_APP_DIR}/CSharpWrapperApplication
add_app ${KRATOS_APP_DIR}/HDF5Application
add_app ${KRATOS_APP_DIR}/TrilinosApplication
add_app ${KRATOS_APP_DIR}/MetisApplication
add_app ${KRATOS_APP_DIR}/ShapeOptimizationApplication
add_app ${KRATOS_APP_DIR}/CoSimulationApplication
```

or you can use my configure.sh or standard-configure.sh that will work with you, don't forget to adjust with your own path to each dependencies and libraries.

# Compile and Install Kratos
```
mkdir build 
cd build
ccmake ..
```  

 Configure it the way you wanted then type
 
```  
make
make install
```    

or just cd to /Kratos/scripts/ then type:
```
./configure.sh
```

The installation folder is inside /opt/hamzstlib/Physics/Kratos/bin/Release

# Sources
https://github.com/KratosMultiphysics/Kratos/blob/master/INSTALL.md
