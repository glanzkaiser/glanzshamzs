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
# CMake variable for use by Trilinos/KokkosKernels clients.
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################


# Include guard
if (KokkosKernels_CONFIG_INCLUDED)
  return()
endif()
set(KokkosKernels_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
if (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  get_filename_component(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  set(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
endif()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos/KokkosKernels build
## ---------------------------------------------------------------------------

set(KokkosKernels_CXX_COMPILER "/opt/hamzstlib/bin/mpicxx")

set(KokkosKernels_C_COMPILER "/opt/hamzstlib/bin/mpicc")

set(KokkosKernels_Fortran_COMPILER "/opt/hamzstlib/bin/mpif90")
# Deprecated!
set(KokkosKernels_FORTRAN_COMPILER "/opt/hamzstlib/bin/mpif90") 


## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos/KokkosKernels build
## ---------------------------------------------------------------------------

## Give the build type
set(KokkosKernels_CMAKE_BUILD_TYPE "RELEASE")

## Set compiler flags, including those determined by build type
set(KokkosKernels_CXX_FLAGS [[ -pedantic -Wall -Wno-long-long -Wwrite-strings -ansi -pedantic -Wall -fopenmp  -O3 -DNDEBUG]])

set(KokkosKernels_C_FLAGS [[ -pedantic -Wall -Wno-long-long -std=c99  -fopenmp -O3 -DNDEBUG]])

set(KokkosKernels_Fortran_FLAGS [[ -O3]])
# Deprecated
set(KokkosKernels_FORTRAN_FLAGS [[ -O3]])

## Extra link flags (e.g., specification of fortran libraries)
set(KokkosKernels_EXTRA_LD_FLAGS [[]])

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty.
set(KokkosKernels_SHARED_LIB_RPATH_COMMAND "-Wl,-rpath,/opt/hamzstlib/trilinos/lib")
set(KokkosKernels_BUILD_SHARED_LIBS "ON")

set(KokkosKernels_LINKER /usr/bin/ld)
set(KokkosKernels_AR /usr/bin/ar)

## ---------------------------------------------------------------------------
## Set library specifications and paths
## ---------------------------------------------------------------------------

## Base install location (if not in the build tree)
set(KokkosKernels_INSTALL_DIR "/opt/hamzstlib/trilinos")

## List of package include dirs
set(KokkosKernels_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../include")

## List of package library paths
set(KokkosKernels_LIBRARY_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../lib")

## List of package libraries
set(KokkosKernels_LIBRARIES "kokkoskernels;kokkosalgorithms;kokkoscontainers;kokkoscore")

## Specification of directories for TPL headers
set(KokkosKernels_TPL_INCLUDE_DIRS "")

## Specification of directories for TPL libraries
set(KokkosKernels_TPL_LIBRARY_DIRS "")

## List of required TPLs
set(KokkosKernels_TPL_LIBRARIES "/usr/lib/libdl.a;/opt/hamzstlib/lib/liblapack.so;/opt/hamzstlib/lib/libblas.so")

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

set(KokkosKernels_MPI_LIBRARIES "")
set(KokkosKernels_MPI_LIBRARY_DIRS "")
set(KokkosKernels_MPI_INCLUDE_DIRS "")
set(KokkosKernels_MPI_EXEC "/opt/hamzstlib/bin/mpiexec")
set(KokkosKernels_MPI_EXEC_MAX_NUMPROCS "4")
set(KokkosKernels_MPI_EXEC_NUMPROCS_FLAG "-np")

## ---------------------------------------------------------------------------
## Set useful general variables
## ---------------------------------------------------------------------------

## The packages enabled for this project
set(KokkosKernels_PACKAGE_LIST "KokkosKernels;KokkosAlgorithms;KokkosContainers;KokkosCore")

## The TPLs enabled for this project
set(KokkosKernels_TPL_LIST "DLlib;LAPACK;BLAS;Pthread")


# Include configuration of dependent packages
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosAlgorithms/KokkosAlgorithmsConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosContainers/KokkosContainersConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosCore/KokkosCoreConfig.cmake")

# Import KokkosKernels targets
include("${CMAKE_CURRENT_LIST_DIR}/KokkosKernelsTargets.cmake")
