cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FrogSlice)

find_package(VTK COMPONENTS 
  vtkCommonColor
  vtkCommonCore
  vtkCommonTransforms
  vtkFiltersCore
  vtkFiltersGeneral
  vtkFiltersSources
  vtkIOImage
  vtkImagingCore
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
)

if (NOT VTK_FOUND)
  message("Skipping FrogSlice: ${VTK_NOT_FOUND_MESSAGE}")
  return()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(FrogSlice MACOSX_BUNDLE FrogSlice.cxx )
  target_link_libraries(FrogSlice PRIVATE ${VTK_LIBRARIES})
else()
  # Prevent a "command line is too long" failure in Windows.
  set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
  add_executable(FrogSlice MACOSX_BUNDLE FrogSlice.cxx )
  target_link_libraries(FrogSlice PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS FrogSlice
    MODULES ${VTK_LIBRARIES}
    )
endif()
