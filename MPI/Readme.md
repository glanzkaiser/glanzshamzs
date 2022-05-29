# About 
The message passing interface (MPI) is a standardized means of exchanging messages between multiple computers running a parallel program across distributed memory.

In parallel computing, multiple computers -- or even multiple processor cores within the same computer -- are called nodes.  Each node in the parallel arrangement typically works on a portion of the overall computing problem. The challenge then is to synchronize the actions of each parallel node, exchange data between nodes and provide command and control over the entire parallel cluster. The message passing interface defines a standard suite of functions for these tasks.

MPI is not endorsed as an official standard by any standards organization such as IEEE or ISO, but it is generally considered to be the industry standard and it forms the basis for most communication interfaces adopted by parallel computing programmers. The older MPI 1.3 standard (dubbed MPI-1) provides over 115 functions. The later MPI 2.2 standard (or MPI-2) offers over 500 functions and is largely backward compatible with MPI-1. However, not all MPI libraries provide a full implementation of MPI-2. 

It is a set of API declarations on message passing (such as send, receive, broadcast, etc.), and what behavior should be expected from the implementations. 

MPI is a way to program on distributed memory devices. This means that the parallelism occurs where every parallel process is working in its own memory space in isolation from the others.

You can think of it as: every bit of code you've written is executed independently by every process. The parallelism occurs because you tell each process exactly which part of the global problem they should be working on based entirely on their process ID.
