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

# Source
https://github.com/trilinos/Trilinos/blob/64d50199f342860b00d16cb78cb5730de66438b9/packages/anasazi/epetra/example/LOBPCG/LOBPCGEpetraExSimple.cpp
