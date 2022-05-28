/* @HEADER
//
// ***********************************************************************
//
//           Amesos2: Templated Direct Sparse Solver Package
//                  Copyright 2011 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Michael A. Heroux (maherou@sandia.gov)
//
// ***********************************************************************
//
// @HEADER
*/

/******************
 * Package macros *
 ******************/

#define AMESOS2_VERSION "0.3d"

#define AMESOS2_RELEASE_DATE "07/28/2011"

/******************
 * Config Options *
 ******************/

/* Define if want to build amesos2-debug */
/* #undef HAVE_AMESOS2_DEBUG */

/* Define if you want debug-mode to be verbose (print stuff) */
/* #undef HAVE_AMESOS2_VERBOSE_DEBUG */

/* Define if you want performance timer support */
/* #undef HAVE_AMESOS2_TIMERS */

/* Define if want want to build amesos2-explicit_instantiation */
#define HAVE_AMESOS2_EXPLICIT_INSTANTIATION

/* Define if we have MPI */
#define HAVE_AMESOS2_MPI

/* Define if we want EpetraExt support for tests and examples */
#define HAVE_AMESOS2_EPETRAEXT

/* Define if we want Epetra matrix and multivector support */
#define HAVE_AMESOS2_EPETRA

/****************************
 * Solver Interface Defines *
 ****************************/

/* Define if you want to build amesos2-klu2 */
#define HAVE_AMESOS2_KLU2

/* Defined if you want to enable amesos2-umfpack */
/* #undef HAVE_AMESOS2_UMFPACK */

/* Defined if you want to enable amesos2-tacho */
#define HAVE_AMESOS2_TACHO

/* Define if you want to build amesos2-superlu */
/* #undef HAVE_AMESOS2_SUPERLU */

/* Define if you want to build amesos2-superlumt */
/* #undef HAVE_AMESOS2_SUPERLUMT */

/* Define if you want to build amesos2-superludist */
/* #undef HAVE_AMESOS2_SUPERLUDIST */

/* Define if you want to build amesos2-pardisomkl */
/* #undef HAVE_AMESOS2_PARDISO_MKL */

/* Define if you want to build amesos2-lapack */
/* #undef HAVE_AMESOS2_LAPACK */

/* Define if you want to build amesos2-cholmod */
/* #undef HAVE_AMESOS2_CHOLMOD */

/* Define if you want to build amesos2 with triangular solves */
/* #undef HAVE_AMESOS2_TRIANGULAR_SOLVES */

/* Define if you want to enable experimental features */
/* #undef HAVE_AMESOS2_EXPERIMENTAL */

/*Define if you want to use amesos-Basker */
/* #undef HAVE_AMESOS2_BASKER */

/*Define if you want to use ShyLUBasker */
/* #undef HAVE_AMESOS2_SHYLUBASKER */

/* Define to 1 if SuperLU_DIST uses a SLU_ prefix on a few of its enums */
/* #undef HAVE_SUPERLUDIST_ENUM_NAMESPACE */

/* Define to 1 if SuperLU_DIST's LUstructInit is declared with 2 arguments. */
/* #undef HAVE_SUPERLUDIST_LUSTRUCTINIT_2ARG */

/* Defined if you want to enable amesos2-MUMPS */
/* #undef HAVE_AMESOS2_MUMPS */

/* Defined if you want to enable amesos2-STRUMPACK */
/* #undef HAVE_AMESOS2_STRUMPACK */

/* Defined if you want to enable amesos2-cuSPARSE */
/* #undef HAVE_AMESOS2_CUSPARSE */

/* Defined if you want to enable amesos2-cuSOLVER */
/* #undef HAVE_AMESOS2_CUSOLVER */

/* Defined if you want to enable amesos2-Metis */
/* #undef HAVE_AMESOS2_METIS */

/* For experimental Basker in ShyLU*/
#define HAVE_AMESOS2_KOKKOS

/* Define to 1 if SuperLU's *gssvx and *gsisx routines need a GlobalLU_t argument. */
/* #undef HAVE_AMESOS2_SUPERLU5_API */
