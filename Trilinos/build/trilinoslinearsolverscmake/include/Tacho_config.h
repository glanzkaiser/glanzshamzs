#ifndef __TACHO_CONFIG_H__
#define __TACHO_CONFIG_H__

/* Define if kokkos tasking is enabled */
#define TACHO_HAVE_KOKKOS_TASK

/* Define if want to build with size_type (int)  enabled */
/* #undef TACHO_USE_INT_INT */

/* Define if want to build with size_type (size_t)  enabled */
#define TACHO_USE_INT_SIZE_T

/* Define if want to build with MKL enabled */
/* #undef TACHO_HAVE_MKL */

/* Define if want to build with LAPACK enabled */
#define TACHO_HAVE_LAPACK

/* Define if want to build with BLAS enabled */
#define TACHO_HAVE_BLAS

/* Define if want to build with METIS enabled */
/* #undef TACHO_HAVE_METIS */

/* Define if want to build with METIS enabled */
/* #undef TACHO_HAVE_METIS_MT */

/* Define if want to build with Scotch enabled */
/* #undef TACHO_HAVE_SCOTCH */

/* Define if want to build with CHOLMOD enabled */
/* #undef TACHO_HAVE_SUITESPARSE */

/* Define if want to build with VTune enabled */
/* #undef TACHO_HAVE_VTUNE */

///* Define if want to build with Teuchos enabled */
#define TACHO_HAVE_TRILINOS_SS

#ifndef F77_BLAS_MANGLE
# define F77_BLAS_MANGLE(name,NAME) name ## _
#endif

#endif
