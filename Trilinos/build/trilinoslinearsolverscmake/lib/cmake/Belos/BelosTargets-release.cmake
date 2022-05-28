#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "belos" for configuration "RELEASE"
set_property(TARGET belos APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(belos PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libbelos.so.13.1"
  IMPORTED_SONAME_RELEASE "libbelos.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS belos )
list(APPEND _IMPORT_CHECK_FILES_FOR_belos "${_IMPORT_PREFIX}/lib/libbelos.so.13.1" )

# Import target "belosepetra" for configuration "RELEASE"
set_property(TARGET belosepetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(belosepetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libbelosepetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libbelosepetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS belosepetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_belosepetra "${_IMPORT_PREFIX}/lib/libbelosepetra.so.13.1" )

# Import target "belostpetra" for configuration "RELEASE"
set_property(TARGET belostpetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(belostpetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libbelostpetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libbelostpetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS belostpetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_belostpetra "${_IMPORT_PREFIX}/lib/libbelostpetra.so.13.1" )

# Import target "belosxpetra" for configuration "RELEASE"
set_property(TARGET belosxpetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(belosxpetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libbelosxpetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libbelosxpetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS belosxpetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_belosxpetra "${_IMPORT_PREFIX}/lib/libbelosxpetra.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
