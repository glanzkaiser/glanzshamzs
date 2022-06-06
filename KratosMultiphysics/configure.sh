#!/bin/bash
# Please do not modify this script

# You can use your interpreter of choice (bash, sh, zsh, ...)

# For any question please contact with us in:
#   - https://github.com/KratosMultiphysics/Kratos

# Optional parameters:
# You can find a list will all the compiation options in INSTALL.md or here:
#   - https://github.com/KratosMultiphysics/Kratos/wiki/Compilation-options

# Function to add apps
add_app () {
    export KRATOS_APPLICATIONS="${KRATOS_APPLICATIONS}$1;"
}

# Set compiler
export CC=gcc
export CXX=g++

# Set variables
export KRATOS_SOURCE="${KRATOS_SOURCE:-"$( cd "$(dirname "$0")" ; pwd -P )"/..}"
export KRATOS_BUILD="${KRATOS_SOURCE}/build"
export KRATOS_APP_DIR="${KRATOS_SOURCE}/applications"
export METIS_ROOT_DIR="/opt/hamzstlib/lib"
export TRILINOS_INCLUDE_DIR="/opt/hamzstlib/trilinos/include"
export TRILINOS_LIBRARY_DIR="/opt/hamzstlib/trilinos/lib"
# export KRATOS_INSTALL_PYTHON_USING_LINKS=ON

# Set basic configuration
export KRATOS_BUILD_TYPE=${KRATOS_BUILD_TYPE:-"Release"}
export PYTHON_EXECUTABLE=${PYTHON_EXECUTABLE:-"/usr/bin/python3"}

# Set applications to compile
export KRATOS_APPLICATIONS=
add_app ${KRATOS_APP_DIR}/CableNetApplication
add_app ${KRATOS_APP_DIR}/ChimeraApplication 
add_app ${KRATOS_APP_DIR}/CoSimulationApplication
add_app ${KRATOS_APP_DIR}/CompressiblePotentialFlowApplication 
add_app ${KRATOS_APP_DIR}/ConstitutiveLawsApplication
add_app ${KRATOS_APP_DIR}/ConstitutiveModelsApplication
add_app ${KRATOS_APP_DIR}/ContactMechanicsApplication
add_app ${KRATOS_APP_DIR}/ContactStructuralMechanicsApplication 
add_app ${KRATOS_APP_DIR}/ConvectionDiffusionApplication
add_app ${KRATOS_APP_DIR}/DEMApplication
add_app ${KRATOS_APP_DIR}/DamApplication
add_app ${KRATOS_APP_DIR}/DelaunayMeshingApplication
add_app ${KRATOS_APP_DIR}/DemStructuresCouplingApplication 
add_app ${KRATOS_APP_DIR}/EigenSolversApplication
add_app ${KRATOS_APP_DIR}/ExaquteSandboxApplication
add_app ${KRATOS_APP_DIR}/FSIApplication
add_app ${KRATOS_APP_DIR}/FemToDemApplication 
add_app ${KRATOS_APP_DIR}/FluidDynamicsApplication
add_app ${KRATOS_APP_DIR}/FluidDynamicsBiomedicalApplication
add_app ${KRATOS_APP_DIR}/FluidTransportApplication 
add_app ${KRATOS_APP_DIR}/FreeSurfaceApplication
add_app ${KRATOS_APP_DIR}/GeoMechanicsApplication 
add_app ${KRATOS_APP_DIR}/HDF5Application 
add_app ${KRATOS_APP_DIR}/IgaApplication
add_app ${KRATOS_APP_DIR}/LinearSolversApplication
add_app ${KRATOS_APP_DIR}/MappingApplication
add_app ${KRATOS_APP_DIR}/MeshMovingApplication
add_app ${KRATOS_APP_DIR}/MeshingApplication
add_app ${KRATOS_APP_DIR}/MetisApplication
add_app ${KRATOS_APP_DIR}/MultilevelMonteCarloApplication
add_app ${KRATOS_APP_DIR}/PFEM2Application
add_app ${KRATOS_APP_DIR}/ParticleMechanicsApplication
add_app ${KRATOS_APP_DIR}/PfemApplication
add_app ${KRATOS_APP_DIR}/PfemFluidDynamicsApplication
add_app ${KRATOS_APP_DIR}/PfemSolidMechanicsApplication
add_app ${KRATOS_APP_DIR}/PoromechanicsApplication
add_app ${KRATOS_APP_DIR}/RANSApplication
add_app ${KRATOS_APP_DIR}/RomApplication
add_app ${KRATOS_APP_DIR}/ShallowWaterApplication
add_app ${KRATOS_APP_DIR}/ShapeOptimizationApplication
add_app ${KRATOS_APP_DIR}/SolidMechanicsApplication
add_app ${KRATOS_APP_DIR}/StatisticsApplication
add_app ${KRATOS_APP_DIR}/StructuralMechanicsApplication
add_app ${KRATOS_APP_DIR}/SwimmingDEMApplication
add_app ${KRATOS_APP_DIR}/ThermalDEMApplication
add_app ${KRATOS_APP_DIR}/TopologyOptimizationApplication
add_app ${KRATOS_APP_DIR}/TrilinosApplication
add_app ${KRATOS_APP_DIR}/ULFapplication
add_app ${KRATOS_APP_DIR}/UmatApplication
add_app ${KRATOS_APP_DIR}/WindEngineeringApplication 


# Clean
clear
rm -rf "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}/cmake_install.cmake"
rm -rf "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}/CMakeCache.txt"
rm -rf "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}/CMakeFiles"

# Configure
cmake -H"${KRATOS_SOURCE}" -B"${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}" -DUSE_TRIANGLE_NONFREE_TPL=ON -DUSE_MPI=OFF -DUSE_EIGEN_MKL=OFF

# Buid
cmake --build "${KRATOS_BUILD}/${KRATOS_BUILD_TYPE}" --target install -- -j4
