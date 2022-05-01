cmake_minimum_required(VERSION 3.1)
project(exp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(vtkbool-master)

add_subdirectory(vtkbool-master)

find_package(VTK REQUIRED COMPONENTS vtkFiltersSources NO_MODULE)
include(${VTK_USE_FILE})

include_directories(vtkbool-master/libs/vp)

add_executable(exp exp.cxx)
target_link_libraries(exp ${VTK_LIBRARIES} vtkbool)
