# About
This src folder contains the C++ (.cpp) files for building demo in Project Chrono after you have built it as a whole.

Project Chrono is a physics-based simulation infrastructure based on a platform-independent, open-source design.

# Set Environment Variable
Set the variable Chrono_DIR to specify the location of the ChronoConfig.cmake, after you build Project Chrono-7.0.3 or from the develop branch of their github, you will have the cmake folder under the build folder.

Set:

#### $Chrono_DIR = "/opt/hamzstlib/Physics/chrono-7.0.3/build/cmake"

# Test it
At this directory type:
    
    mkdir build && cd build
    cmake ..
    make
    ./myexe
    
# Edit CMakeLists.txt
You can edit the CMakeLists.txt to adjust with your target file, the default target is my_example.cpp

# citybus.cpp Still Not Works
OpenMP is not installed?

# Source
https://api.projectchrono.org/tutorial_install_project.html

https://api.projectchrono.org/tutorial_root.html
