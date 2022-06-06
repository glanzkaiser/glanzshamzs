# About

Amesos is a Greek term meaning direct.

Amesos is the Direct Sparse Solver Package in Trilinos. The goal of Amesos is to make AX=B as easy as it sounds, at least for direct methods. Amesos provides clean and consistent interfaces to the following third party libraries:
* LAPACK
* UMFPACK version 4.4
* TAUCS version 2.2
* PARDISO version 1.2.3 (outdated)
* SuperLU version 4.1
* SuperLU_DIST version 2.5
* DSCPACK version 1.0
* SCALAPACK version 1.7
* MUMPS version 4.7.3 (experimental support for version 4.9)

Amesos comes with a serial direct solver, called KLU, and a parallel direct solver, called Paraklete, which can be used to solve sparse linear systems. Each interface can be enabled at configure time. 

# Sources

https://trilinos.github.io/pdfs/AmesosReferenceGuide.pdf

https://trilinos.github.io/pdfs/PARA06-amesos.pdf

http://trilinos.org/oldsite/packages/amesos/slides-overview.html

https://trilinos.github.io/amesos.html

http://trilinos.org/docs/dev/packages/amesos/doc/html/index.html
