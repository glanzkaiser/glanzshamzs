#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "xpetra" for configuration "RELEASE"
set_property(TARGET xpetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(xpetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libxpetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libxpetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS xpetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_xpetra "${_IMPORT_PREFIX}/lib/libxpetra.so.13.1" )

# Import target "xpetra-sup" for configuration "RELEASE"
set_property(TARGET xpetra-sup APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(xpetra-sup PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libxpetra-sup.so.13.1"
  IMPORTED_SONAME_RELEASE "libxpetra-sup.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS xpetra-sup )
list(APPEND _IMPORT_CHECK_FILES_FOR_xpetra-sup "${_IMPORT_PREFIX}/lib/libxpetra-sup.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
