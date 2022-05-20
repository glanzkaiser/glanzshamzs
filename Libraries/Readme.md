# About
Collection of static (.a) and shared library for science and engineering packages.

# How to Create Libraries
## BLAS
Enter the src folder that contain the routine files in fortran (.f)

For shared library type:

#### gfortran -shared -O2 *.f -o libblas.so -fPIC

For static library type:

#### gfortran -O2 -c *.f
#### ar cr libblas.a *.o
 
 (the first compiles code into object files, and the second archives the object files into a static archive)
 
## LAPACK
Enter the src folder that contain the routine files in fortran (.f)

For shared library type:

#### gfortran -shared -O2 *.f -o liblapack.so -fPIC

For static library type:

#### gfortran -O2 -c *.f
#### ar cr liblapack.a *.o
 
 (the first compiles code into object files, and the second archives the object files into a static archive)

# Details

| Name | Version |
| ------------- | ------------- | 
| BLAS    | 3.10.0
| LAPACK  | 3.10.1
