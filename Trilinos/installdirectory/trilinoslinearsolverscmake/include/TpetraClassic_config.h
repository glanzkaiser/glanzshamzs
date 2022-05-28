#ifndef TPETRACLASSIC_CONFIG_H
#define TPETRACLASSIC_CONFIG_H
/* CMake uses this file to generate TpetraClassic_config.h. */

/* Define if you want to build kokkos-debug */
/* #undef HAVE_TPETRACLASSIC_DEBUG */
#ifdef HAVE_TPETRACLASSIC_DEBUG
#  define HAVE_KOKKOSCLASSIC_DEBUG
#endif // HAVE_TPETRACLASSIC_DEBUG

/* Define if the TeuchosKokkosCompat subpackage is available in TpetraClassic */
/* #undef HAVE_TPETRACLASSIC_TEUCHOSKOKKOSCOMPAT */
#ifdef HAVE_TPETRACLASSIC_TEUCHOSKOKKOSCOMPAT
#  define HAVE_KOKKOSCLASSIC_TEUCHOSKOKKOSCOMPAT
#  define HAVE_KOKKOSCLASSIC_KOKKOSCOMPAT
#endif // HAVE_TPETRACLASSIC_TEUCHOSKOKKOSCOMPAT

/* Other package dependencies */

/* #undef HAVE_TPETRACLASSIC_TEUCHOS */
#ifdef HAVE_TPETRACLASSIC_TEUCHOS
#  define HAVE_KOKKOSCLASSIC_TEUCHOS
#endif // HAVE_TPETRACLASSIC_TEUCHOS

/* #undef HAVE_TPETRACLASSIC_KOKKOSCORE */
#ifdef HAVE_TPETRACLASSIC_KOKKOSCORE
#  define HAVE_KOKKOSCLASSIC_KOKKOSCORE
#endif // HAVE_TPETRACLASSIC_KOKKOSCORE

#ifndef TPETRA_DEPRECATED
#  if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
#    define TPETRA_DEPRECATED  __attribute__((__deprecated__))
#  else
#    define TPETRA_DEPRECATED
#  endif
#endif

#ifndef TPETRA_DEPRECATED_MSG
#  if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5))
#    define TPETRA_DEPRECATED_MSG(MSG)  __attribute__((__deprecated__ (#MSG) ))
#  elif (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
#    define TPETRA_DEPRECATED_MSG(MSG)  __attribute__((__deprecated__))
#  else
#    define TPETRA_DEPRECATED_MSG(MSG)
#  endif
#endif


/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

#endif // TPETRACLASSIC_CONFIG_H
