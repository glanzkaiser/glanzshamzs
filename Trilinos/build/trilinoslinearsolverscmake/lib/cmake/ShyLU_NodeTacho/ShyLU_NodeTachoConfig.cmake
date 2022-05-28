# @HEADER
# ************************************************************************
#
#            TriBITS: Tribal Build, Integrate, and Test System
#                    Copyright 2013 Sandia Corporation
#
#
# Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
# the U.S. Government retains certain rights in this software.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the Corporation nor the names of the
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# ************************************************************************
# @HEADER

##############################################################################
#
# CMake variable for use by Trilinos/ShyLU_NodeTacho clients.
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################


# Include guard
if (ShyLU_NodeTacho_CONFIG_INCLUDED)
  return()
endif()
set(ShyLU_NodeTacho_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
if (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  get_filename_component(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  set(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
endif()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos/ShyLU_NodeTacho build
## ---------------------------------------------------------------------------

set(ShyLU_NodeTacho_CXX_COMPILER "/opt/hamzstlib/bin/mpicxx")

set(ShyLU_NodeTacho_C_COMPILER "/opt/hamzstlib/bin/mpicc")

set(ShyLU_NodeTacho_Fortran_COMPILER "/opt/hamzstlib/bin/mpif90")
# Deprecated!
set(ShyLU_NodeTacho_FORTRAN_COMPILER "/opt/hamzstlib/bin/mpif90") 


## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos/ShyLU_NodeTacho build
## ---------------------------------------------------------------------------

## Give the build type
set(ShyLU_NodeTacho_CMAKE_BUILD_TYPE "RELEASE")

## Set compiler flags, including those determined by build type
set(ShyLU_NodeTacho_CXX_FLAGS [[ -pedantic -Wall -Wno-long-long -Wwrite-strings -ansi -pedantic -Wall -fopenmp  -O3 -DNDEBUG]])

set(ShyLU_NodeTacho_C_FLAGS [[ -pedantic -Wall -Wno-long-long -std=c99  -fopenmp -O3 -DNDEBUG]])

set(ShyLU_NodeTacho_Fortran_FLAGS [[ -O3]])
# Deprecated
set(ShyLU_NodeTacho_FORTRAN_FLAGS [[ -O3]])

## Extra link flags (e.g., specification of fortran libraries)
set(ShyLU_NodeTacho_EXTRA_LD_FLAGS [[]])

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty.
set(ShyLU_NodeTacho_SHARED_LIB_RPATH_COMMAND "-Wl,-rpath,/opt/hamzstlib/trilinos/lib")
set(ShyLU_NodeTacho_BUILD_SHARED_LIBS "ON")

set(ShyLU_NodeTacho_LINKER /usr/bin/ld)
set(ShyLU_NodeTacho_AR /usr/bin/ar)

## ---------------------------------------------------------------------------
## Set library specifications and paths
## ---------------------------------------------------------------------------

## Base install location (if not in the build tree)
set(ShyLU_NodeTacho_INSTALL_DIR "/opt/hamzstlib/trilinos")

## List of package include dirs
set(ShyLU_NodeTacho_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../include")

## List of package library paths
set(ShyLU_NodeTacho_LIBRARY_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../lib")

## List of package libraries
set(ShyLU_NodeTacho_LIBRARIES "tacho;kokkosalgorithms;kokkoscontainers;kokkoscore")

## Specification of directories for TPL headers
set(ShyLU_NodeTacho_TPL_INCLUDE_DIRS "")

## Specification of directories for TPL libraries
set(ShyLU_NodeTacho_TPL_LIBRARY_DIRS "")

## List of required TPLs
set(ShyLU_NodeTacho_TPL_LIBRARIES "/usr/lib/libdl.a;/opt/hamzstlib/lib/liblapack.so;/opt/hamzstlib/lib/libblas.so")

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

set(ShyLU_NodeTacho_MPI_LIBRARIES "")
set(ShyLU_NodeTacho_MPI_LIBRARY_DIRS "")
set(ShyLU_NodeTacho_MPI_INCLUDE_DIRS "")
set(ShyLU_NodeTacho_MPI_EXEC "/opt/hamzstlib/bin/mpiexec")
set(ShyLU_NodeTacho_MPI_EXEC_MAX_NUMPROCS "4")
set(ShyLU_NodeTacho_MPI_EXEC_NUMPROCS_FLAG "-np")

## ---------------------------------------------------------------------------
## Set useful general variables
## ---------------------------------------------------------------------------

## The packages enabled for this project
set(ShyLU_NodeTacho_PACKAGE_LIST "ShyLU_NodeTacho;Kokkos;KokkosAlgorithms;KokkosContainers;KokkosCore")

## The TPLs enabled for this project
set(ShyLU_NodeTacho_TPL_LIST "DLlib;LAPACK;BLAS;Pthread")


# Include configuration of dependent packages
include("${CMAKE_CURRENT_LIST_DIR}/../Kokkos/KokkosConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosAlgorithms/KokkosAlgorithmsConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosContainers/KokkosContainersConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosCore/KokkosCoreConfig.cmake")

# Import ShyLU_NodeTacho targets
include("${CMAKE_CURRENT_LIST_DIR}/ShyLU_NodeTachoTargets.cmake")
