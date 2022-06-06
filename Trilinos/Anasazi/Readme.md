# About
To understand more about Anasazi and how to modify the source code then build it and see the computation result.

Solving linear system of equations is responsible for 70%–80% of the total computational time in many problems in computational science and engineering such as continuum and quantum mechanics, multi-physics, geophysics, optimization, linear programing, circuit design etc.

There exist several direct methods for the solution of a linear system of equations, including LU factorization, QR factorization, and singular value decomposition. The fastest method is LU factorization, also known as Gaussian elimination, which is by far the most used algorithm for the direct solution of a system of linear equations. While other methods such as QR factorization may offer added stability minimizing the effect of round-off error, they are simply non-competitive in terms of computational efficiency. The main principle of the LU factorization algorithm is to decompose the original matrix A into the product of a lower triangular matrix L with an upper triangular matrix U .

# Anasazi (an Eigensolvers)
Anasazi is an extensible and interoperable framework for large-scale eigenvalue algorithms. The motivation for this framework is to provide a generic interface to a collection of algorithms for solving large-scale eigenvalue problems. Anasazi is interoperable because both the matrix and vectors (defining the eigenspace) are considered to be opaque objects—only knowledge of the matrix and vectors via elementary operations is necessary. An implementation of Anasazi is accomplished via the use of interfaces. Current interfaces available include Epetra and so any libraries that understand Epetra matrices and vectors (such as AztecOO) may also be used in conjunction with Anasazi.

The generalized eigenvalue problems:
```
Ax = λBx
```

Matrices and vectors used in computation are treated as opaque objects; only elementary operations on matrices and vectors need to be provided through the interface. 

After providing the interface implementation, a user may access any of Anasazi’s suite of algorithms, including the implementation of the Locally-Optimal Block Preconditioned Conjugate Gradient, a Block Krylov-Schur, a Block Davidson, and an Implicit Riemannian Trust-Region methods, respectively.

## How Anasazi work with other Trilinos' Packages
1. Uses Teuchos (RCP, LAPACK wrappers
2. Can use the operators and multivectors of Epetra/Tpetra
3. Can use the preconditioners of Ifpack/Ifpack2
4. Can use the linear solvers of Amesos, Belos, and AztecOO
5. Can (potentially) be used by Zoltan to reorder a graph

## Capabilities
Anasazi supports the following solver/matrix combinations:

![Anasazi](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/Trilinos/Anasazi/images/Anasazi1.png)

    “Gen.” = generalized eigenvalue system
    “Prec:” = can use a preconditioner
    BKS = Block Krylov Schur
    LOBPCG = Locally Optimial Block Preconditioned Conjugate Gradient
    RTR = Riemannian Trust-Region method

## TraceMin
In 2014, there is a new class of solvers referred to as the “TraceMin family”
```
Ax = λBx
```
with
* A is real, symmetric
* B is symmetric positive semidefinite (SPD)
* TraceMin will converge to the smallest eigenpairs

![image](https://user-images.githubusercontent.com/72222484/171991341-b69c00d2-3306-4032-bbd2-0eef6f191d6c.png)

## Epetra for Anasazi
1. Epetra provides the basic building blocks needed for serial and parallel linear algebra. 
2. The Epetra Map class describes the distribution of rows, columns, and vector entries to processes. This class supports both 1D (row-based or column-based) and 2D (nonzero-based) matrix distributions, and plays a key role in enabling the 2D distributions useful for large graphs with skewed degree distributions. 
3. The Epetra Import and Epetra Export functions perform communication needed to share data among processes. 
4. Sparse matrices can be stored by Epetra CrsMatrix; users may use their own matrix layouts through the virtual Epetra RowMatrix class. Epetra features a multi-vector class Epetra MultiVector that is, in essence, a collection of vectors; this class enables block-based linear and eigensolvers to be efficiently implemented in Trilinos.
5. An extension of Epetra called Epetra64 is also available, which enables Epetra classes to be used for graphs
with more than two billion global vertices or edges.

# Directory Structure
You have to remember the directory paths for the
1. Trilinos source code (/sources/Hamzstlab/Trilinos)
2. Trilinos installation directory (/opt/hamzstlib/include)
3. Trilinos build directory (/sources/Hamzstlab/trilinosbuild6)

The Anasazi source is located in the directory /sources/Hamzstlab/Trilinos/packages/anasazi and contains the subdirectories
```
cmake  doc  epetra  src  src-rbgen  test  testmatrices  thyra  tpetra
```
![image](https://user-images.githubusercontent.com/72222484/171992103-9e096b83-4aba-430b-819d-e3426e871821.png)

To build Trilinos with Anasazi you can see:
https://github.com/glanzkaiser/glanzshamzs/tree/main/Trilinos
(adjust with your own path and system)

If you are building at /trilinosbuild6 then you will see the built example for Epetra and Anasazi (I build again at trilinosbuild2 and it has no examples there)

![image](https://user-images.githubusercontent.com/72222484/171992306-d24f3a42-5379-41f6-8c50-e113d763734f.png)

* The subdirectories BlockDavidson, BlockKrylovSchur, and LOBPCG contain the executables associated with the C++ examples located in /sources/Hamzstlab/Trilinos/packages/anasazi/epetra/example


# Sources

https://trilinos.github.io/pdfs/Klinvex-TUG-2014-Anasazi.pdf

https://trilinos.github.io/pdfs/anasazi-ug-public.pdf

https://cug.org/proceedings/cug2016_proceedings/includes/files/pap121s2-file1.pdf

https://www.researchgate.net/profile/Maciej-Paszynski/publication/272409243_Computational_cost_of_isogeometric_multi-frontal_solvers_on_parallel_distributed_memory_machines/links/5dd79bc1458515dc2f4201d0/Computational-cost-of-isogeometric-multi-frontal-solvers-on-parallel-distributed-memory-machines.pdf?origin=publication_detail
