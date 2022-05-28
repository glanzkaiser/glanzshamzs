#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "epetraext" for configuration "RELEASE"
set_property(TARGET epetraext APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(epetraext PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libepetraext.so.13.1"
  IMPORTED_SONAME_RELEASE "libepetraext.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS epetraext )
list(APPEND _IMPORT_CHECK_FILES_FOR_epetraext "${_IMPORT_PREFIX}/lib/libepetraext.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
