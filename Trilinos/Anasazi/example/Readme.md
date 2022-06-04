# About 
The example here is to introduce how to create an Anasazi executable (.exe) from the C++ source file (.cpp) by using modified CMakeLists.txt that will generate Makefile for building the executable / for compiling.

You can then edit the cpp file or take another cpp file from Trilinos repository and compile it to see the result of your own modification.

## Run the Example
Type
```
cmake -Wno-dev .
make -j4
```

## See the result by typing
```
./Anasazi
```
