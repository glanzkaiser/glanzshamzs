# About
To understand more about Anasazi and how to modify the source code then build it and see the computation result

# Anasazi (an Eigensolvers)
Anasazi is an extensible and interoperable framework for large-scale eigenvalue algorithms. The motivation for this framework is to provide a generic interface to a collection of algorithms for solving large-scale eigenvalue problems. Anasazi is interoperable because both the matrix and vectors (defining the eigenspace) are considered to be opaque objects—only knowledge of the matrix and vectors via elementary operations is necessary. An implementation of Anasazi is accomplished via the use of interfaces. Current interfaces available include Epetra and so any libraries that understand Epetra matrices and vectors (such as AztecOO) may also be used in conjunction with Anasazi.

The generalized eigenvalue problems:
```
Ax = λBx
```

# How Anasazi work with other Trilinos' Packages
1. Uses Teuchos (RCP, LAPACK wrappers
2. Can use the operators and multivectors of Epetra/Tpetra
3. Can use the preconditioners of Ifpack/Ifpack2
4. Can use the linear solvers of Amesos, Belos, and AztecOO
5. Can (potentially) be used by Zoltan to reorder a graph

# Capabilities
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

# Sources

https://trilinos.github.io/pdfs/Klinvex-TUG-2014-Anasazi.pdf
