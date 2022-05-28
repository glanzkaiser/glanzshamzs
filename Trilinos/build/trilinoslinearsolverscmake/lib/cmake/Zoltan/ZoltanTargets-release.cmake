#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "zoltan" for configuration "RELEASE"
set_property(TARGET zoltan APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(zoltan PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libzoltan.so.13.1"
  IMPORTED_SONAME_RELEASE "libzoltan.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS zoltan )
list(APPEND _IMPORT_CHECK_FILES_FOR_zoltan "${_IMPORT_PREFIX}/lib/libzoltan.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
