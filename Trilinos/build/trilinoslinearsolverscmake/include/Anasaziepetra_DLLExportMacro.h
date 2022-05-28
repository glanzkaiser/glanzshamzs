#define BUILD_SHARED_LIBS
#if defined (_WIN32) && defined (BUILD_SHARED_LIBS)
#  if defined(ANASAZIEPETRA_LIB_EXPORTS_MODE)
#    define ANASAZIEPETRA_LIB_DLL_EXPORT __declspec(dllexport)
#  else
#    define ANASAZIEPETRA_LIB_DLL_EXPORT __declspec(dllimport)
#  endif
#else
#  define ANASAZIEPETRA_LIB_DLL_EXPORT
#endif
