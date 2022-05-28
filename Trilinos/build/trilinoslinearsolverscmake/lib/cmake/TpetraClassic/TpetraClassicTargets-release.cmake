#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tpetraclassic" for configuration "RELEASE"
set_property(TARGET tpetraclassic APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tpetraclassic PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtpetraclassic.so.13.1"
  IMPORTED_SONAME_RELEASE "libtpetraclassic.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS tpetraclassic )
list(APPEND _IMPORT_CHECK_FILES_FOR_tpetraclassic "${_IMPORT_PREFIX}/lib/libtpetraclassic.so.13.1" )

# Import target "tpetraclassicnodeapi" for configuration "RELEASE"
set_property(TARGET tpetraclassicnodeapi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tpetraclassicnodeapi PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtpetraclassicnodeapi.so.13.1"
  IMPORTED_SONAME_RELEASE "libtpetraclassicnodeapi.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS tpetraclassicnodeapi )
list(APPEND _IMPORT_CHECK_FILES_FOR_tpetraclassicnodeapi "${_IMPORT_PREFIX}/lib/libtpetraclassicnodeapi.so.13.1" )

# Import target "tpetraclassiclinalg" for configuration "RELEASE"
set_property(TARGET tpetraclassiclinalg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tpetraclassiclinalg PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtpetraclassiclinalg.so.13.1"
  IMPORTED_SONAME_RELEASE "libtpetraclassiclinalg.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS tpetraclassiclinalg )
list(APPEND _IMPORT_CHECK_FILES_FOR_tpetraclassiclinalg "${_IMPORT_PREFIX}/lib/libtpetraclassiclinalg.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
