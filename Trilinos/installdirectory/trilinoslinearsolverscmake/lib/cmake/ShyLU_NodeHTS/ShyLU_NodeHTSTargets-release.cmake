#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "shylu_nodehts" for configuration "RELEASE"
set_property(TARGET shylu_nodehts APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(shylu_nodehts PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libshylu_nodehts.so.13.1"
  IMPORTED_SONAME_RELEASE "libshylu_nodehts.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS shylu_nodehts )
list(APPEND _IMPORT_CHECK_FILES_FOR_shylu_nodehts "${_IMPORT_PREFIX}/lib/libshylu_nodehts.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
