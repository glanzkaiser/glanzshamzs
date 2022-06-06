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

#### The result of Anasazi' LOBPCGEpetra example:
![image](https://user-images.githubusercontent.com/72222484/172039555-c4493757-3b21-4988-b404-653f0ab2fdff.png)

## How to Create the CMakeLists.txt
I followed the flow of the CMakeLists.txt here:

```
https://github.com/trilinos/Trilinos/blob/master/demos/simpleBuildAgainstTrilinos/CMakeLists.txt
```

I modify and adjust it after I asked at Trilinos' github issue forum. Thus, it can be compiled for the example above.

## How to Try Another Example (.cpp file)
If you want to try another .cpp file for Anasazi then edit the CMakeLists.txt and adjust these:
```
find_package(Trilinos REQUIRED COMPONENTS Teuchos Tpetra Anasazi)
```
(add with the corresponding solver / package)


```
add_executable(Anasazi ${CMAKE_CURRENT_SOURCE_DIR}/LOBPCGEpetraExSimple.cpp)
```
(change the cpp name with the file you want to test)

#### The result of Anasazi' BlockDavidson-Epetra example (from single compiling):
![image](https://user-images.githubusercontent.com/72222484/172170950-2898e56a-3049-402a-a538-e4962da09230.png)


#### The result of Anasazi' BlockDavidson-Epetra example (from all compiling):
![image](https://user-images.githubusercontent.com/72222484/172170991-dbc425bc-4a24-47a6-a5de-3b5f38dee8e1.png)


#### The result of Anasazi' BlockKrylovSchur-Epetra example (from single compiling):
It is slower in term of time

![image](https://user-images.githubusercontent.com/72222484/172185659-a6231197-15e2-4a85-8e70-50edbc200122.png)


#### The result of Anasazi' BlockKrylovSchur-Epetra example (from all compiling):
It is faster in term of time

![image](https://user-images.githubusercontent.com/72222484/172185549-84dfc717-4e90-4153-9de5-b3043fd8cd3e.png)

# Source
https://trilinos.github.io/pdfs/anasazi-ug-public.pdf

https://github.com/trilinos/Trilinos/blob/64d50199f342860b00d16cb78cb5730de66438b9/packages/anasazi/epetra/example/LOBPCG/LOBPCGEpetraExSimple.cpp
