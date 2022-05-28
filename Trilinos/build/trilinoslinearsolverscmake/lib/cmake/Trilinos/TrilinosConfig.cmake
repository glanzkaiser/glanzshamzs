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
# CMake variable for use by Trilinos clients. 
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################

#
# Ensure CMAKE_CURRENT_LIST_DIR is usable.
#

# Include guard
if (Trilinos_CONFIG_INCLUDED)
  return()
endif()
set(Trilinos_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
if (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  get_filename_component(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  set(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
endif()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos build
## ---------------------------------------------------------------------------

set(Trilinos_CXX_COMPILER "/opt/hamzstlib/bin/mpicxx")

set(Trilinos_C_COMPILER "/opt/hamzstlib/bin/mpicc")

set(Trilinos_Fortran_COMPILER "/opt/hamzstlib/bin/mpif90")

## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos build
## ---------------------------------------------------------------------------

set(Trilinos_CMAKE_BUILD_TYPE "RELEASE")

set(Trilinos_CXX_COMPILER_FLAGS [[-ansi -pedantic -Wall -fopenmp  -O3 -DNDEBUG]])

set(Trilinos_C_COMPILER_FLAGS [[ -fopenmp -O3 -DNDEBUG]])

set(Trilinos_Fortran_COMPILER_FLAGS [[ -fopenmp -O3]])

## Extra link flags (e.g., specification of fortran libraries)
set(Trilinos_EXTRA_LD_FLAGS [[]])

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty. 
set(Trilinos_SHARED_LIB_RPATH_COMMAND "-Wl,-rpath,/opt/hamzstlib/trilinos/lib")
set(Trilinos_BUILD_SHARED_LIBS "ON")

set(Trilinos_LINKER /usr/bin/ld)
set(Trilinos_AR /usr/bin/ar)


## ---------------------------------------------------------------------------
## Set library specifications and paths 
## ---------------------------------------------------------------------------

## The project version number
set(Trilinos_VERSION "13.1")

# For best practices in handling of components, see
# <http://www.cmake.org/cmake/help/v3.2/manual/cmake-developer.7.html#find-modules>.
#
# If components were requested, include only those. If not, include all of
# Trilinos.
if (Trilinos_FIND_COMPONENTS)
  set(COMPONENTS_LIST ${Trilinos_FIND_COMPONENTS})
else()
  set(COMPONENTS_LIST MueLu;Intrepid2;Teko;Stratimikos;Ifpack2;Anasazi;Amesos2;ShyLU_Node;ShyLU_NodeTacho;ShyLU_NodeHTS;Belos;ML;Ifpack;Zoltan2Core;Pamgen;Amesos;Galeri;AztecOO;Isorropia;Xpetra;Thyra;ThyraTpetraAdapters;ThyraEpetraExtAdapters;ThyraEpetraAdapters;ThyraCore;TrilinosSS;Tpetra;TpetraCore;TpetraTSQR;TpetraClassic;EpetraExt;Triutils;Shards;Zoltan;Epetra;Sacado;RTOp;KokkosKernels;Teuchos;TeuchosKokkosComm;TeuchosKokkosCompat;TeuchosRemainder;TeuchosNumerics;TeuchosComm;TeuchosParameterList;TeuchosParser;TeuchosCore;Kokkos;KokkosAlgorithms;KokkosContainers;KokkosCore;Gtest)
endif()

# Initialize Trilinos_FOUND with true, and set it to FALSE if any of
# the required components wasn't found.
set(Trilinos_FOUND TRUE)
foreach(comp ${COMPONENTS_LIST})
  set(
    INCLUDE_FILE
    ${CMAKE_CURRENT_LIST_DIR}/../${comp}/${comp}Config.cmake
    )
 if (EXISTS ${INCLUDE_FILE})
   # Set Trilinos_<component>_FOUND.
   set(Trilinos_${comp}_FOUND TRUE)
   # Include the package file.
   include(${INCLUDE_FILE})
   # Add variables to lists.
   list(APPEND Trilinos_INCLUDE_DIRS ${${comp}_INCLUDE_DIRS})
   list(APPEND Trilinos_LIBRARY_DIRS ${${comp}_LIBRARY_DIRS})
   list(APPEND Trilinos_LIBRARIES ${${comp}_LIBRARIES})
   list(APPEND Trilinos_TPL_INCLUDE_DIRS ${${comp}_TPL_INCLUDE_DIRS})
   list(APPEND Trilinos_TPL_LIBRARY_DIRS ${${comp}_TPL_LIBRARY_DIRS})
   list(APPEND Trilinos_TPL_LIBRARIES ${${comp}_TPL_LIBRARIES})
 else()
   # Set Trilinos_<component>_FOUND to FALSE.
   set(Trilinos_${comp}_FOUND FALSE)
   # Set Trilinos_FOUND to FALSE if component is not optional.
   if(Trilinos_FIND_REQUIRED_${comp})
     set(Trilinos_FOUND FALSE)
   endif()
 endif()
endforeach()

# Resolve absolute paths and remove duplicate paths
# for LIBRARY_DIRS and INCLUDE_DIRS
# This reduces stress on regular expressions later
set(short_dirs)
foreach(dir ${Trilinos_INCLUDE_DIRS})
  get_filename_component(dir_abs ${dir} ABSOLUTE)
  list(APPEND short_dirs ${dir_abs})
endforeach()
list(REMOVE_DUPLICATES short_dirs)
set(Trilinos_INCLUDE_DIRS ${short_dirs})

set(short_dirs)
foreach(dir ${Trilinos_LIBRARY_DIRS})
  get_filename_component(dir_abs ${dir} ABSOLUTE)
  list(APPEND short_dirs ${dir_abs})
endforeach()
list(REMOVE_DUPLICATES short_dirs)
set(Trilinos_LIBRARY_DIRS ${short_dirs})

# Remove duplicates in Trilinos_LIBRARIES
list(REVERSE Trilinos_LIBRARIES)
list(REMOVE_DUPLICATES Trilinos_LIBRARIES)
list(REVERSE Trilinos_LIBRARIES)

# Remove duplicates in Trilinos_TPL_INCLUDE_DIRS
if (Trilinos_TPL_INCLUDE_DIRS)
  list(REMOVE_DUPLICATES Trilinos_TPL_INCLUDE_DIRS)
endif()

# NOTE: It is *NOT* safe to try to remove duplicate in
# Trilinos_TPL_LIBRARIES because these can be specified as -L, -l, etc.
# Actually, we should think about that.

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

set(Trilinos_INSTALL_DIR "/opt/hamzstlib/trilinos")
set(Trilinos_MPI_LIBRARIES "")
set(Trilinos_MPI_LIBRARY_DIRS "")
set(Trilinos_MPI_INCLUDE_DIRS "")
set(Trilinos_MPI_EXEC "/opt/hamzstlib/bin/mpiexec")
set(Trilinos_MPI_EXEC_PRE_NUMPROCS_FLAGS "")
set(Trilinos_MPI_EXEC_MAX_NUMPROCS "4")
set(Trilinos_MPI_EXEC_POST_NUMPROCS_FLAGS "")
set(Trilinos_MPI_EXEC_NUMPROCS_FLAG "-np")

## ---------------------------------------------------------------------------
## Compiler vendor identifications
## ---------------------------------------------------------------------------
set(Trilinos_SYSTEM_NAME "Linux")
set(Trilinos_CXX_COMPILER_ID "GNU")
set(Trilinos_C_COMPILER_ID "GNU")
set(Trilinos_Fortran_COMPILER_ID "GNU")
set(Trilinos_Fortran_IMPLICIT_LINK_LIBRARIES "mpi_mpifh;mpi;open-rte;open-pal;gfortran;m;udev;pciaccess;gfortran;m;gcc_s;gcc;quadmath;m;gcc_s;gcc;c;gcc_s;gcc")

## ---------------------------------------------------------------------------
## Set useful general variables 
## ---------------------------------------------------------------------------

## The packages enabled for this project
set(Trilinos_PACKAGE_LIST "MueLu;Intrepid2;Teko;Stratimikos;Ifpack2;Anasazi;Amesos2;ShyLU_Node;ShyLU_NodeTacho;ShyLU_NodeHTS;Belos;ML;Ifpack;Zoltan2Core;Pamgen;Amesos;Galeri;AztecOO;Isorropia;Xpetra;Thyra;ThyraTpetraAdapters;ThyraEpetraExtAdapters;ThyraEpetraAdapters;ThyraCore;TrilinosSS;Tpetra;TpetraCore;TpetraTSQR;TpetraClassic;EpetraExt;Triutils;Shards;Zoltan;Epetra;Sacado;RTOp;KokkosKernels;Teuchos;TeuchosKokkosComm;TeuchosKokkosCompat;TeuchosRemainder;TeuchosNumerics;TeuchosComm;TeuchosParameterList;TeuchosParser;TeuchosCore;Kokkos;KokkosAlgorithms;KokkosContainers;KokkosCore;Gtest")

## The TPLs enabled for this project
set(Trilinos_TPL_LIST "DLlib;Boost;LAPACK;BLAS;MPI;Pthread")
