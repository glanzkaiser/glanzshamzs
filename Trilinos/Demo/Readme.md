# About
The CMakeLists.txt can be used to check Trilinos installation is correct at your system

## 1. Build the Example
```
cmake .
make
```
## 2. Run the application test(s):
```
ctest
```
* NOTE: That test will not pass unless Trilinos is propertly built with MPI and MPI is working.

Since I do not use MPI then the test is failed.

![test](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/Trilinos/Demo/image/Trilinosdemo.png)
