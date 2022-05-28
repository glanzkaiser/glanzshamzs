#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teko" for configuration "RELEASE"
set_property(TARGET teko APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teko PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libteko.so.13.1"
  IMPORTED_SONAME_RELEASE "libteko.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS teko )
list(APPEND _IMPORT_CHECK_FILES_FOR_teko "${_IMPORT_PREFIX}/lib/libteko.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
