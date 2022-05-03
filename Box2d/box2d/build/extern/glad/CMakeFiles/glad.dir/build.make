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
CMAKE_SOURCE_DIR = /opt/hamzstlib/Physics/box2d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/hamzstlib/Physics/box2d/build

# Include any dependencies generated for this target.
include extern/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include extern/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include extern/glad/CMakeFiles/glad.dir/flags.make

extern/glad/CMakeFiles/glad.dir/src/gl.c.o: extern/glad/CMakeFiles/glad.dir/flags.make
extern/glad/CMakeFiles/glad.dir/src/gl.c.o: ../extern/glad/src/gl.c
extern/glad/CMakeFiles/glad.dir/src/gl.c.o: extern/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/hamzstlib/Physics/box2d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object extern/glad/CMakeFiles/glad.dir/src/gl.c.o"
	cd /opt/hamzstlib/Physics/box2d/build/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/glad/CMakeFiles/glad.dir/src/gl.c.o -MF CMakeFiles/glad.dir/src/gl.c.o.d -o CMakeFiles/glad.dir/src/gl.c.o -c /opt/hamzstlib/Physics/box2d/extern/glad/src/gl.c

extern/glad/CMakeFiles/glad.dir/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/gl.c.i"
	cd /opt/hamzstlib/Physics/box2d/build/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /opt/hamzstlib/Physics/box2d/extern/glad/src/gl.c > CMakeFiles/glad.dir/src/gl.c.i

extern/glad/CMakeFiles/glad.dir/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/gl.c.s"
	cd /opt/hamzstlib/Physics/box2d/build/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /opt/hamzstlib/Physics/box2d/extern/glad/src/gl.c -o CMakeFiles/glad.dir/src/gl.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/gl.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

bin/libglad.a: extern/glad/CMakeFiles/glad.dir/src/gl.c.o
bin/libglad.a: extern/glad/CMakeFiles/glad.dir/build.make
bin/libglad.a: extern/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/hamzstlib/Physics/box2d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../bin/libglad.a"
	cd /opt/hamzstlib/Physics/box2d/build/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /opt/hamzstlib/Physics/box2d/build/extern/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/glad/CMakeFiles/glad.dir/build: bin/libglad.a
.PHONY : extern/glad/CMakeFiles/glad.dir/build

extern/glad/CMakeFiles/glad.dir/clean:
	cd /opt/hamzstlib/Physics/box2d/build/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : extern/glad/CMakeFiles/glad.dir/clean

extern/glad/CMakeFiles/glad.dir/depend:
	cd /opt/hamzstlib/Physics/box2d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/hamzstlib/Physics/box2d /opt/hamzstlib/Physics/box2d/extern/glad /opt/hamzstlib/Physics/box2d/build /opt/hamzstlib/Physics/box2d/build/extern/glad /opt/hamzstlib/Physics/box2d/build/extern/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/glad/CMakeFiles/glad.dir/depend

