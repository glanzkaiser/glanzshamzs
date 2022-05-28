#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tpetra" for configuration "RELEASE"
set_property(TARGET tpetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tpetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtpetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libtpetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS tpetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_tpetra "${_IMPORT_PREFIX}/lib/libtpetra.so.13.1" )

# Import target "tpetrainout" for configuration "RELEASE"
set_property(TARGET tpetrainout APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tpetrainout PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtpetrainout.so.13.1"
  IMPORTED_SONAME_RELEASE "libtpetrainout.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS tpetrainout )
list(APPEND _IMPORT_CHECK_FILES_FOR_tpetrainout "${_IMPORT_PREFIX}/lib/libtpetrainout.so.13.1" )

# Import target "tpetraext" for configuration "RELEASE"
set_property(TARGET tpetraext APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tpetraext PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtpetraext.so.13.1"
  IMPORTED_SONAME_RELEASE "libtpetraext.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS tpetraext )
list(APPEND _IMPORT_CHECK_FILES_FOR_tpetraext "${_IMPORT_PREFIX}/lib/libtpetraext.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
