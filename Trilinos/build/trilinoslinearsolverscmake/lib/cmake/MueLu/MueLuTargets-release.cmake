#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "muelu" for configuration "RELEASE"
set_property(TARGET muelu APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(muelu PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmuelu.so.13.1"
  IMPORTED_SONAME_RELEASE "libmuelu.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS muelu )
list(APPEND _IMPORT_CHECK_FILES_FOR_muelu "${_IMPORT_PREFIX}/lib/libmuelu.so.13.1" )

# Import target "muelu-interface" for configuration "RELEASE"
set_property(TARGET muelu-interface APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(muelu-interface PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmuelu-interface.so.13.1"
  IMPORTED_SONAME_RELEASE "libmuelu-interface.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS muelu-interface )
list(APPEND _IMPORT_CHECK_FILES_FOR_muelu-interface "${_IMPORT_PREFIX}/lib/libmuelu-interface.so.13.1" )

# Import target "muelu-adapters" for configuration "RELEASE"
set_property(TARGET muelu-adapters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(muelu-adapters PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmuelu-adapters.so.13.1"
  IMPORTED_SONAME_RELEASE "libmuelu-adapters.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS muelu-adapters )
list(APPEND _IMPORT_CHECK_FILES_FOR_muelu-adapters "${_IMPORT_PREFIX}/lib/libmuelu-adapters.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
