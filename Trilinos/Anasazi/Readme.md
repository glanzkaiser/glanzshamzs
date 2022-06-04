# About
To understand more about Anasazi and how to modify the source code then build it and see the computation result

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

# Sources

https://trilinos.github.io/pdfs/Klinvex-TUG-2014-Anasazi.pdf

https://trilinos.github.io/pdfs/anasazi-ug-public.pdf
