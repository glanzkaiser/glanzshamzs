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
# CMake variable for use by Trilinos/Ifpack2 clients.
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################


# Include guard
if (Ifpack2_CONFIG_INCLUDED)
  return()
endif()
set(Ifpack2_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
if (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  get_filename_component(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  set(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
endif()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos/Ifpack2 build
## ---------------------------------------------------------------------------

set(Ifpack2_CXX_COMPILER "/opt/hamzstlib/bin/mpicxx")

set(Ifpack2_C_COMPILER "/opt/hamzstlib/bin/mpicc")

set(Ifpack2_Fortran_COMPILER "/opt/hamzstlib/bin/mpif90")
# Deprecated!
set(Ifpack2_FORTRAN_COMPILER "/opt/hamzstlib/bin/mpif90") 


## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos/Ifpack2 build
## ---------------------------------------------------------------------------

## Give the build type
set(Ifpack2_CMAKE_BUILD_TYPE "RELEASE")

## Set compiler flags, including those determined by build type
set(Ifpack2_CXX_FLAGS [[ -pedantic -Wall -Wno-long-long -Wwrite-strings -ansi -pedantic -Wall -fopenmp  -O3 -DNDEBUG]])

set(Ifpack2_C_FLAGS [[ -pedantic -Wall -Wno-long-long -std=c99  -fopenmp -O3 -DNDEBUG]])

set(Ifpack2_Fortran_FLAGS [[ -O3]])
# Deprecated
set(Ifpack2_FORTRAN_FLAGS [[ -O3]])

## Extra link flags (e.g., specification of fortran libraries)
set(Ifpack2_EXTRA_LD_FLAGS [[]])

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty.
set(Ifpack2_SHARED_LIB_RPATH_COMMAND "-Wl,-rpath,/opt/hamzstlib/trilinos/lib")
set(Ifpack2_BUILD_SHARED_LIBS "ON")

set(Ifpack2_LINKER /usr/bin/ld)
set(Ifpack2_AR /usr/bin/ar)

## ---------------------------------------------------------------------------
## Set library specifications and paths
## ---------------------------------------------------------------------------

## Base install location (if not in the build tree)
set(Ifpack2_INSTALL_DIR "/opt/hamzstlib/trilinos")

## List of package include dirs
set(Ifpack2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../include")

## List of package library paths
set(Ifpack2_LIBRARY_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../lib")

## List of package libraries
set(Ifpack2_LIBRARIES "ifpack2-adapters;ifpack2;amesos2;tacho;shylu_nodehts;belosxpetra;belostpetra;belosepetra;belos;zoltan2;aztecoo;xpetra-sup;xpetra;thyratpetra;thyraepetraext;thyraepetra;thyracore;trilinosss;tpetraext;tpetrainout;tpetra;kokkostsqr;tpetraclassiclinalg;tpetraclassicnodeapi;tpetraclassic;epetraext;triutils;zoltan;epetra;rtop;kokkoskernels;teuchoskokkoscomm;teuchoskokkoscompat;teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;kokkosalgorithms;kokkoscontainers;kokkoscore")

## Specification of directories for TPL headers
set(Ifpack2_TPL_INCLUDE_DIRS "/usr/include")

## Specification of directories for TPL libraries
set(Ifpack2_TPL_LIBRARY_DIRS "")

## List of required TPLs
set(Ifpack2_TPL_LIBRARIES "/usr/lib/libdl.a;/opt/hamzstlib/lib/liblapack.so;/opt/hamzstlib/lib/libblas.so")

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

set(Ifpack2_MPI_LIBRARIES "")
set(Ifpack2_MPI_LIBRARY_DIRS "")
set(Ifpack2_MPI_INCLUDE_DIRS "")
set(Ifpack2_MPI_EXEC "/opt/hamzstlib/bin/mpiexec")
set(Ifpack2_MPI_EXEC_MAX_NUMPROCS "4")
set(Ifpack2_MPI_EXEC_NUMPROCS_FLAG "-np")

## ---------------------------------------------------------------------------
## Set useful general variables
## ---------------------------------------------------------------------------

## The packages enabled for this project
set(Ifpack2_PACKAGE_LIST "Ifpack2;Amesos2;ShyLU_NodeTacho;ShyLU_NodeHTS;Belos;Zoltan2Core;AztecOO;Xpetra;Thyra;ThyraTpetraAdapters;ThyraEpetraExtAdapters;ThyraEpetraAdapters;ThyraCore;TrilinosSS;Tpetra;TpetraCore;TpetraTSQR;TpetraClassic;EpetraExt;Triutils;Zoltan;Epetra;RTOp;KokkosKernels;Teuchos;TeuchosKokkosComm;TeuchosKokkosCompat;TeuchosRemainder;TeuchosNumerics;TeuchosComm;TeuchosParameterList;TeuchosParser;TeuchosCore;Kokkos;KokkosAlgorithms;KokkosContainers;KokkosCore")

## The TPLs enabled for this project
set(Ifpack2_TPL_LIST "DLlib;Boost;LAPACK;BLAS;MPI;Pthread")


# Include configuration of dependent packages
include("${CMAKE_CURRENT_LIST_DIR}/../Amesos2/Amesos2Config.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../ShyLU_NodeTacho/ShyLU_NodeTachoConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../ShyLU_NodeHTS/ShyLU_NodeHTSConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Belos/BelosConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Zoltan2Core/Zoltan2CoreConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../AztecOO/AztecOOConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Xpetra/XpetraConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Thyra/ThyraConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../ThyraTpetraAdapters/ThyraTpetraAdaptersConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../ThyraEpetraExtAdapters/ThyraEpetraExtAdaptersConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../ThyraEpetraAdapters/ThyraEpetraAdaptersConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../ThyraCore/ThyraCoreConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TrilinosSS/TrilinosSSConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Tpetra/TpetraConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TpetraCore/TpetraCoreConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TpetraTSQR/TpetraTSQRConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TpetraClassic/TpetraClassicConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../EpetraExt/EpetraExtConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Triutils/TriutilsConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Zoltan/ZoltanConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Epetra/EpetraConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../RTOp/RTOpConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosKernels/KokkosKernelsConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Teuchos/TeuchosConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosKokkosComm/TeuchosKokkosCommConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosKokkosCompat/TeuchosKokkosCompatConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosRemainder/TeuchosRemainderConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosNumerics/TeuchosNumericsConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosComm/TeuchosCommConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosParameterList/TeuchosParameterListConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosParser/TeuchosParserConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../TeuchosCore/TeuchosCoreConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../Kokkos/KokkosConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosAlgorithms/KokkosAlgorithmsConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosContainers/KokkosContainersConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../KokkosCore/KokkosCoreConfig.cmake")

# Import Ifpack2 targets
include("${CMAKE_CURRENT_LIST_DIR}/Ifpack2Targets.cmake")
