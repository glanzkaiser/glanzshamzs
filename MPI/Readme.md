# About 
The message passing interface (MPI) is a standardized means of exchanging messages between multiple computers running a parallel program across distributed memory.

In parallel computing, multiple computers -- or even multiple processor cores within the same computer -- are called nodes.  Each node in the parallel arrangement typically works on a portion of the overall computing problem. The challenge then is to synchronize the actions of each parallel node, exchange data between nodes and provide command and control over the entire parallel cluster. The message passing interface defines a standard suite of functions for these tasks.

MPI is not endorsed as an official standard by any standards organization such as IEEE or ISO, but it is generally considered to be the industry standard and it forms the basis for most communication interfaces adopted by parallel computing programmers. The older MPI 1.3 standard (dubbed MPI-1) provides over 115 functions. The later MPI 2.2 standard (or MPI-2) offers over 500 functions and is largely backward compatible with MPI-1. However, not all MPI libraries provide a full implementation of MPI-2. 

It is a set of API declarations on message passing (such as send, receive, broadcast, etc.), and what behavior should be expected from the implementations. 

MPI is a way to program on distributed memory devices. This means that the parallelism occurs where every parallel process is working in its own memory space in isolation from the others.

You can think of it as: every bit of code you've written is executed independently by every process. The parallelism occurs because you tell each process exactly which part of the global problem they should be working on based entirely on their process ID.

# Compiler Wrappers
mpicc (and similarly mpic++, mpif90, etc.) is a program that wraps over an existing compiler to set the necessary command-line flags when compiling code that uses MPI. Typically, it adds a few flags that enable the code to be the compiled and linked against the MPI library.

# MPI Configuration in GFreya OS

To get the list of compiler/ linker flags to put into, type

                mpiCC --showme:compile
                mpiCC --showme:link
  
Set the Environment variables: 
1. Add ../openmpi/lib to LD_LIBRARY_PATH 
2. Add ../openmpi/bin to PATH 

Where [../openmpi/] is your openMPI install directory

#### Check that your system didn't come with another OpenMPI already installed. If so, you may accidentally be mixing and matching two different versions. For example those who install OpenFOAM-9 will have OpenMPI-2.1.1 in the ThirdParty-9 ./Allwmake, thus you need to set the path to this OpenMPI instead of using the OpenMPI of the newest version (as of May 30th 2022 it is OpenMPI-4.1.4)

# Run the Hello World
There are two examples here:

1. For mpi_hello_world.c, type:

        make
    
2. For example.c, type

        mpicc example.c && mpiexec -n 4
        ./a.out
If you get the output right then you can use MPI

![openmpi](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/MPI/images/blfs-prob-38-4.png)
#### mpiexec is a command used to execute the example program with 4 processes, each of which is an independent instance of the program at run time and assigned ranks (i.e. numeric IDs) 0, 1, 2, and 3. The name mpiexec is recommended by the MPI standard, although some implementations provide a similar command under the name mpirun. The MPI_COMM_WORLD is the communicator that consists of all the processes. 

# MPI in the Future
1. Nearly all of the projects in the Exascale Computing Project build explicitly on MPI; MPI has been shown to scale to the largest machines as of the early 2020s and is widely considered to stay relevant for a long time to come. 
2. Architectures are changing, with greater internal concurrency (multi-core), better fine-grained concurrency control (threading, affinity), and more levels of memory hierarchy. Multithreaded programs can take advantage of these developments more easily than single-threaded applications. This has already yielded separate, complementary standards for symmetric multiprocessing, namely OpenMP. MPI-2 defines how standard-conforming implementations should deal with multithreaded issues, but does not require that implementations be multithreaded, or even thread-safe. MPI-3 adds the ability to use shared-memory parallelism within a node. Implementations of MPI such as Adaptive MPI, Hybrid MPI, Fine-Grained MPI, MPC and others offer extensions to the MPI standard that address different challenges in MPI. 
 

# Source
https://en.wikipedia.org/wiki/Message_Passing_Interface
