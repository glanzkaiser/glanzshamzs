# About
Open Multi-processing (OpenMP) is a technique of parallelizing a section(s) of C/C++/Fortran code. 
OpenMP is also seen as an extension to C/C++/Fortran languages by adding the parallelizing features to them. 
In general, OpenMP uses a portable, scalable model that gives programmers a simple and flexible interface for developing parallel applications for platforms that ranges from the normal desktop computer to the high-end supercomputers.

# Threads and Process
A process is created by the OS to execute a program with given resources(memory, registers); 
generally, different processes do not share their memory with another. 
A thread is a subset of a process, and it shares the resources of its parent process but has its own stack to keep track of function calls. 
Multiple threads of a process will have access to the same memory.

## Check the GCC version of the compiler
  
  gcc --version
  
## Check whether the OpenMP features are configured into our compiler or not

  echo |cpp -fopenmp -dM |grep -i open

## Setting the number of threads
  
  export OMP_NUM_THREADS=8

For hardware with 8 cores processors.
n OpenMP, Before running the code, we can initialise the number of threads to be executed using the following command. 
Here, we set the number of threads to be getting executed to be 8 threads.

# Run the Test

  gcc -o test -fopenmp test.c
  ./test

# Source: 
https://www.geeksforgeeks.org/openmp-introduction-with-installation-guide/
