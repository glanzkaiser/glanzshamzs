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
# CMake variable for use by Trilinos/Pamgen clients.
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################


# Include guard
if (Pamgen_CONFIG_INCLUDED)
  return()
endif()
set(Pamgen_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
if (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  get_filename_component(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  set(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
endif()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos/Pamgen build
## ---------------------------------------------------------------------------

set(Pamgen_CXX_COMPILER "/opt/hamzstlib/bin/mpicxx")

set(Pamgen_C_COMPILER "/opt/hamzstlib/bin/mpicc")

set(Pamgen_Fortran_COMPILER "/opt/hamzstlib/bin/mpif90")
# Deprecated!
set(Pamgen_FORTRAN_COMPILER "/opt/hamzstlib/bin/mpif90") 


## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos/Pamgen build
## ---------------------------------------------------------------------------

## Give the build type
set(Pamgen_CMAKE_BUILD_TYPE "RELEASE")

## Set compiler flags, including those determined by build type
set(Pamgen_CXX_FLAGS [[ -pedantic -Wall -Wno-long-long -Wwrite-strings -ansi -pedantic -Wall -fopenmp  -O3 -DNDEBUG]])

set(Pamgen_C_FLAGS [[ -pedantic -Wall -Wno-long-long -std=c99  -fopenmp -O3 -DNDEBUG]])

set(Pamgen_Fortran_FLAGS [[ -O3]])
# Deprecated
set(Pamgen_FORTRAN_FLAGS [[ -O3]])

## Extra link flags (e.g., specification of fortran libraries)
set(Pamgen_EXTRA_LD_FLAGS [[]])

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty.
set(Pamgen_SHARED_LIB_RPATH_COMMAND "-Wl,-rpath,/opt/hamzstlib/trilinos/lib")
set(Pamgen_BUILD_SHARED_LIBS "ON")

set(Pamgen_LINKER /usr/bin/ld)
set(Pamgen_AR /usr/bin/ar)

## ---------------------------------------------------------------------------
## Set library specifications and paths
## ---------------------------------------------------------------------------

## Base install location (if not in the build tree)
set(Pamgen_INSTALL_DIR "/opt/hamzstlib/trilinos")

## List of package include dirs
set(Pamgen_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../include")

## List of package library paths
set(Pamgen_LIBRARY_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../lib")

## List of package libraries
set(Pamgen_LIBRARIES "pamgen_extras;pamgen")

## Specification of directories for TPL headers
set(Pamgen_TPL_INCLUDE_DIRS "/usr/include")

## Specification of directories for TPL libraries
set(Pamgen_TPL_LIBRARY_DIRS "")

## List of required TPLs
set(Pamgen_TPL_LIBRARIES "")

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

set(Pamgen_MPI_LIBRARIES "")
set(Pamgen_MPI_LIBRARY_DIRS "")
set(Pamgen_MPI_INCLUDE_DIRS "")
set(Pamgen_MPI_EXEC "/opt/hamzstlib/bin/mpiexec")
set(Pamgen_MPI_EXEC_MAX_NUMPROCS "4")
set(Pamgen_MPI_EXEC_NUMPROCS_FLAG "-np")

## ---------------------------------------------------------------------------
## Set useful general variables
## ---------------------------------------------------------------------------

## The packages enabled for this project
set(Pamgen_PACKAGE_LIST "Pamgen")

## The TPLs enabled for this project
set(Pamgen_TPL_LIST "Boost")


# Import Pamgen targets
include("${CMAKE_CURRENT_LIST_DIR}/PamgenTargets.cmake")
