# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData

# Include any dependencies generated for this target.
include CMakeFiles/ImageIteratorDemo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ImageIteratorDemo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageIteratorDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageIteratorDemo.dir/flags.make

CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o: CMakeFiles/ImageIteratorDemo.dir/flags.make
CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o: ImageIteratorDemo.cxx
CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o: CMakeFiles/ImageIteratorDemo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o -MF CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o.d -o CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o -c /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData/ImageIteratorDemo.cxx

CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData/ImageIteratorDemo.cxx > CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.i

CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData/ImageIteratorDemo.cxx -o CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.s

# Object files for target ImageIteratorDemo
ImageIteratorDemo_OBJECTS = \
"CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o"

# External object files for target ImageIteratorDemo
ImageIteratorDemo_EXTERNAL_OBJECTS =

ImageIteratorDemo: CMakeFiles/ImageIteratorDemo.dir/ImageIteratorDemo.o
ImageIteratorDemo: CMakeFiles/ImageIteratorDemo.dir/build.make
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOGeometry-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOPLY-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkImagingMath-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkInteractionImage-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkRenderingGL2PSOpenGL2-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkTestingRendering-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkjsoncpp-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkFiltersModeling-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkImagingGeneral-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkImagingHybrid-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkInteractionStyle-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOXML-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOXMLParser-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOLegacy-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOCore-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkImagingSources-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkRenderingFreeType-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkfreetype-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkRenderingOpenGL2-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkRenderingUI-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkglew-9.1.so.9.1.0
ImageIteratorDemo: /usr/lib/libGL.so
ImageIteratorDemo: /usr/lib/libGLU.so
ImageIteratorDemo: /usr/lib/libX11.so
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkIOImage-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkzlib-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkImagingCore-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkRenderingCore-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonColor-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkFiltersGeometry-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkFiltersSources-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkFiltersGeneral-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkFiltersCore-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonExecutionModel-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonDataModel-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonTransforms-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonMisc-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonMath-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkkissfft-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtkCommonCore-9.1.so.9.1.0
ImageIteratorDemo: /opt/hamzstlib/Kitware/install/VTK/lib/libvtksys-9.1.so.9.1.0
ImageIteratorDemo: CMakeFiles/ImageIteratorDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ImageIteratorDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageIteratorDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageIteratorDemo.dir/build: ImageIteratorDemo
.PHONY : CMakeFiles/ImageIteratorDemo.dir/build

CMakeFiles/ImageIteratorDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageIteratorDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageIteratorDemo.dir/clean

CMakeFiles/ImageIteratorDemo.dir/depend:
	cd /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData /opt/hamzstlib/Kitware/install/VTKData/vtk-examples-master/src/Cxx/ImageData/CMakeFiles/ImageIteratorDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageIteratorDemo.dir/depend

