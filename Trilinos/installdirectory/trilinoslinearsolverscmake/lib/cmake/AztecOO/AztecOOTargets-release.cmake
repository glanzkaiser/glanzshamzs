#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "aztecoo" for configuration "RELEASE"
set_property(TARGET aztecoo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(aztecoo PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libaztecoo.so.13.1"
  IMPORTED_SONAME_RELEASE "libaztecoo.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS aztecoo )
list(APPEND _IMPORT_CHECK_FILES_FOR_aztecoo "${_IMPORT_PREFIX}/lib/libaztecoo.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
