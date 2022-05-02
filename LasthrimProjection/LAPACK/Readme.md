LAPACK (Linear Algebra PACKage) is a BSD-licenced FORTRAN 77 library that provides routines for solving the most commonly occurring problems in numerical linear algebra, such as:
1. linear equations
2. least squares solutions of linear systems of equations
3. eigenvalue problems
4. singular value problems.

To link your Fortran application against LAPACK at the end type: -llapack -lblas

# To Compile
There is an example of solving simple linear equations type this in your console:

gfortran -o solution solvinglinearequations.f90 -llapack -lblas
(for using shared libraries)
or

gfortran -o solution solvinglinearequations.f90 /opt/hamzstlib/lib/liblapack.a /opt/hamzstlib/lib/libblas.a
(for using static libraries)
The path of /opt/hamzstlib is assuming you are using GFreya OS, if you read the book or create your own OS the path needs to be adjusted due to your installation path for LAPACK and BLAS.

# To Do Lists
LAPACK' Linear Equation Routines
| Status  | Routine |Description |
| ------------- | ------------- | -------------|
| :sunflower: | geqrf | Computes the QR factorization of a general m-by-n matrix. |
| :sunflower: | gerqf | Computes the RQ factorization of a general m-by-n matrix. |
| Content Cell  | getrf | Computes the LU factorization of a general m-by-n matrix. |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |
| Content Cell  | Content Cell  | Content Cell |


	getri 	Computes the inverse of an LU-factored general matrix.
	getrs 	Solves a system of linear equations with an LU-factored square coefficient matrix, with multiple right-hand sides.
	hetrf 	Computes the Bunch-Kaufman factorization of a complex Hermitian matrix.
	orgqr 	Generates the real orthogonal matrix Q of the QR factorization formed by geqrf.
	ormqr 	Multiplies a real matrix by the orthogonal matrix Q of the QR factorization formed by geqrf.
	ormrq 	Multiplies a real matrix by the orthogonal matrix Q of the RQ factorization formed by gerqf.
+1 	potrf 	Computes the Cholesky factorization of a symmetric (Hermitian) positive-definite matrix.
+1 	potri 	Computes the inverse of a Cholesky-factored symmetric (Hermitian) positive-definite matrix.
	potrs 	Solves a system of linear equations with a Cholesky-factored symmetric (Hermitian) positive-definite coefficient matrix, with multiple right-hand sides.
	sytrf 	Computes the Bunch-Kaufman factorization of a symmetric matrix.
	trtrs 	Solves a system of linear equations with a triangular coefficient matrix, with multiple right-hand sides.
	ungqr 	Generates the complex unitary matrix Q of the QR factorization formed by geqrf.
	unmqr 	Multiplies a complex matrix by the unitary matrix Q of the QR factorization formed by geqrf.
	unmrq 	Multiplies a complex matrix by the unitary matrix Q of the RQ factorization formed by gerqf.
