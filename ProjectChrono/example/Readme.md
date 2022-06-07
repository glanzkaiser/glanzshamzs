# About
How to run single example from one single C++ (.cpp) file in Project Chrono

## 1. Set the Environment Variable
You will have to set the variable Chrono_DIR to specify the location of the ChronoConfig.cmake script.

For GFreya OS, type:
```
vim ~/export
export Chrono_DIR=/opt/hamzstlib/Physics/chrono/build/cmake
source ~/export
```

## 2. Adjust the find_package function at CMakeLists.txt
Find the Chrono package and any REQUIRED or OPTIONAL modules by invoking the find_package function in CONFIG mode:

```
find_package(Chrono
             COMPONENTS Irrlicht
             OPTIONAL_COMPONENTS PardisoMKL
             CONFIG)
```

The following Chrono modules' names are case insensitive: 
* Cascade, Cosimulation, FEA, Irrlicht, Matlab, Parallel, Postprocess, Python, Vehicle.

## 3. Run the CMake command
At the directory with the .cpp file and the CMakeLists.txt file, type:
```
cmake .
make -j4
./myexe
```

# Status
:sunflower: = Done

:writing_hand: = On Progress

| Example | Details |
| -------------     | ------------- | 
| citybus           | :writing_hand:
| gears             | :sunflower:
| pendulum          | :sunflower:
