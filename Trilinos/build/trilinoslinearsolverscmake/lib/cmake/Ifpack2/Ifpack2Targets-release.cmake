#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ifpack2" for configuration "RELEASE"
set_property(TARGET ifpack2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ifpack2 PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libifpack2.so.13.1"
  IMPORTED_SONAME_RELEASE "libifpack2.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS ifpack2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_ifpack2 "${_IMPORT_PREFIX}/lib/libifpack2.so.13.1" )

# Import target "ifpack2-adapters" for configuration "RELEASE"
set_property(TARGET ifpack2-adapters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ifpack2-adapters PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libifpack2-adapters.so.13.1"
  IMPORTED_SONAME_RELEASE "libifpack2-adapters.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS ifpack2-adapters )
list(APPEND _IMPORT_CHECK_FILES_FOR_ifpack2-adapters "${_IMPORT_PREFIX}/lib/libifpack2-adapters.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
