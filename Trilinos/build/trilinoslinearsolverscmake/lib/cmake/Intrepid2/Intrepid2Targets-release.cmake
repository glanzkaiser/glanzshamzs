#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "intrepid2" for configuration "RELEASE"
set_property(TARGET intrepid2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(intrepid2 PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libintrepid2.so.13.1"
  IMPORTED_SONAME_RELEASE "libintrepid2.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS intrepid2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_intrepid2 "${_IMPORT_PREFIX}/lib/libintrepid2.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
