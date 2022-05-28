#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "galeri-epetra" for configuration "RELEASE"
set_property(TARGET galeri-epetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(galeri-epetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgaleri-epetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libgaleri-epetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS galeri-epetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_galeri-epetra "${_IMPORT_PREFIX}/lib/libgaleri-epetra.so.13.1" )

# Import target "galeri-xpetra" for configuration "RELEASE"
set_property(TARGET galeri-xpetra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(galeri-xpetra PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgaleri-xpetra.so.13.1"
  IMPORTED_SONAME_RELEASE "libgaleri-xpetra.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS galeri-xpetra )
list(APPEND _IMPORT_CHECK_FILES_FOR_galeri-xpetra "${_IMPORT_PREFIX}/lib/libgaleri-xpetra.so.13.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
