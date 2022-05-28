/* define if we want to include experimental code */
/* #undef INCLUDE_ZOLTAN2CORE_EXPERIMENTAL */
#ifdef INCLUDE_ZOLTAN2CORE_EXPERIMENTAL
#  define INCLUDE_ZOLTAN2_EXPERIMENTAL
#endif

/* define if we want to include wolf experimental code */
/* #undef INCLUDE_ZOLTAN2CORE_EXPERIMENTAL_WOLF */
#ifdef INCLUDE_ZOLTAN2CORE_EXPERIMENTAL_WOLF
#  define INCLUDE_ZOLTAN2_EXPERIMENTAL_WOLF
#endif

/* define if we have MPI */
#define HAVE_ZOLTAN2CORE_MPI
#ifdef HAVE_ZOLTAN2CORE_MPI
#  define HAVE_ZOLTAN2_MPI
#endif

/* define if we want to use OpenMP */
/* #undef HAVE_ZOLTAN2CORE_OMP */
#ifdef HAVE_ZOLTAN2CORE_OMP
#  define HAVE_ZOLTAN2_OMP
#endif

/* define if we have the METIS library*/
/* #undef HAVE_ZOLTAN2CORE_METIS */
#ifdef HAVE_ZOLTAN2CORE_METIS
#  define HAVE_ZOLTAN2_METIS
#endif

/* define if we have the PaToH library*/
/* #undef HAVE_ZOLTAN2CORE_PATOH */
#ifdef HAVE_ZOLTAN2CORE_PATOH
#  define HAVE_ZOLTAN2_PATOH
#endif

/* define if we have the Scotch library*/
/* #undef HAVE_ZOLTAN2CORE_SCOTCH */
#ifdef HAVE_ZOLTAN2CORE_SCOTCH
#  define HAVE_ZOLTAN2_SCOTCH
#endif

/* define if we have the ParMETIS library*/
/* #undef HAVE_ZOLTAN2CORE_PARMETIS */
#ifdef HAVE_ZOLTAN2CORE_PARMETIS
#  define HAVE_ZOLTAN2_PARMETIS
#endif

/* define if we have the PuLP library*/
/* #undef HAVE_ZOLTAN2CORE_PULP */
#ifdef HAVE_ZOLTAN2CORE_PULP
#  define HAVE_ZOLTAN2_PULP
#endif

/* define if we have the SARMA library*/
/* #undef HAVE_ZOLTAN2CORE_SARMA */
#ifdef HAVE_ZOLTAN2CORE_SARMA
#  define HAVE_ZOLTAN2_SARMA
#endif

/* define if we have the ParMA library*/
/* #undef HAVE_ZOLTAN2CORE_PARMA */
#ifdef HAVE_ZOLTAN2CORE_PARMA
#  define HAVE_ZOLTAN2_PARMA
#endif

/* define if we have the AMD library*/
/* #undef HAVE_ZOLTAN2CORE_AMD */
#ifdef HAVE_ZOLTAN2CORE_AMD
#  define HAVE_ZOLTAN2_AMD
#endif

/* define if we have the Ovis library*/
/* #undef HAVE_ZOLTAN2CORE_OVIS */
#ifdef HAVE_ZOLTAN2CORE_OVIS
#  define HAVE_ZOLTAN2_OVIS
#endif

/* define if we have Epetra */
#define HAVE_ZOLTAN2CORE_EPETRA
#ifdef HAVE_ZOLTAN2CORE_EPETRA
#  define HAVE_ZOLTAN2_EPETRA
#endif

/* define if we have Galeri */
#define HAVE_ZOLTAN2CORE_GALERI
#ifdef HAVE_ZOLTAN2CORE_GALERI
#  define HAVE_ZOLTAN2_GALERI
#endif

/* define if we have Pamgen */
#define HAVE_ZOLTAN2CORE_PAMGEN
#ifdef HAVE_ZOLTAN2CORE_PAMGEN
#  define HAVE_ZOLTAN2_PAMGEN
#endif

/* define if we have Anasazi */
/* #undef HAVE_ZOLTAN2CORE_ANASAZI */
#ifdef HAVE_ZOLTAN2CORE_ANASAZI
#  define HAVE_ZOLTAN2_ANASAZI
#endif

/* define to turn on runtime display of
 * total memory committed at points throughout
 * the execution of zoltan2
 */
/* #undef SHOW_ZOLTAN2CORE_LINUX_MEMORY */
#ifdef SHOW_ZOLTAN2CORE_LINUX_MEMORY
#  define SHOW_ZOLTAN2_LINUX_MEMORY
#endif

/* define to turn on runtime display of
 * maximum memory used by scotch
 * (requires a hack to the scotch library)
 */
/* #undef SHOW_ZOLTAN2_SCOTCH_MEMORY */
#ifdef SHOW_ZOLTAN2CORE_SCOTCH_MEMORY
#  define SHOW_ZOLTAN2_SCOTCH_MEMORY
#endif

/* Use Zoltan's Comm package instead of Tpetra for migration */
/* #undef ZOLTAN2CORE_USEZOLTANCOMM */
#ifdef HAVE_ZOLTAN2CORE_USEZOLTANCOMM
#  define HAVE_ZOLTAN2_USEZOLTANCOMM
#endif

/* Enable workarounds for Purify builds */
/* #undef HAVE_ZOLTAN2CORE_PURIFY */
#ifdef HAVE_ZOLTAN2CORE_PURIFY
#  define HAVE_ZOLTAN2_PURIFY
#endif

/* define if we have TopoManager installed */
/* #undef HAVE_ZOLTAN2CORE_TOPOMANAGER */
#ifdef HAVE_ZOLTAN2CORE_TOPOMANAGER
#  define HAVE_ZOLTAN2_TOPOMANAGER
#endif

/* define if we have RCALIB installed */
/* #undef HAVE_ZOLTAN2CORE_RCALIB */
#ifdef HAVE_ZOLTAN2CORE_RCALIB
#  define HAVE_ZOLTAN2_RCALIB
#endif

/* define if we set Enable_MACHINE_DRAGONFLY:BOOL=ON */
/* #undef ZOLTAN2CORE_MACHINE_DRAGONFLY */
#ifdef ZOLTAN2CORE_MACHINE_DRAGONFLY
#  define ZOLTAN2_MACHINE_DRAGONFLY
#endif

/* define if we set Enable_MACHINE_TORUS:BOOL=ON */
/* #undef ZOLTAN2CORE_MACHINE_TORUS */
#ifdef ZOLTAN2CORE_MACHINE_TORUS
#  define ZOLTAN2_MACHINE_TORUS
#endif
