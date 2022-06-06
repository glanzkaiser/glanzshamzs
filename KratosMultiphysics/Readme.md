# About 
KRATOS Multiphysics ("Kratos") is a framework for building parallel, multi-disciplinary simulation software, aiming at modularity, extensibility, and high performance. Kratos is written in C++, and counts with an extensive Python interface. 

#### Use Kratos-9.1

# Download Third Party Modules: GKlib, METIS

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

or you can use my configure.sh

# Compile and Install Kratos
```
mkdir build 
cd build
ccmake ..
```  
 Configure it the way you wanted
```  
make install
```    

The installation folder is inside /opt/hamzstlib/Physics/Kratos-9.1/bin/Release

# Sources
https://github.com/KratosMultiphysics/Kratos/blob/master/INSTALL.md
