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
## LAPACK' Linear Equation Routines
:sunflower: = Done
:writing_hand: = On Progress

| Status  | Routine |Description |
| ------------- | ------------- | -------------|
|:sunflower:| geqrf | Computes the QR factorization of a general m-by-n matrix. |
|:sunflower:| gerqf | Computes the RQ factorization of a general m-by-n matrix. |
|:writing_hand:| getrf | Computes the LU factorization of a general m-by-n matrix. |
|:writing_hand:|	getri  |	Computes the inverse of an LU-factored general matrix.
|:writing_hand:|	getrs  |	Solves a system of linear equations with an LU-factored square coefficient matrix, with multiple right-hand sides.
|:writing_hand:|	hetrf  |	Computes the Bunch-Kaufman factorization of a complex Hermitian matrix.
|:writing_hand:|	orgqr  |	Generates the real orthogonal matrix Q of the QR factorization formed by geqrf.
|:writing_hand:|	ormqr  |	Multiplies a real matrix by the orthogonal matrix Q of the QR factorization formed by geqrf.
|:writing_hand:|	ormrq  |  Multiplies a real matrix by the orthogonal matrix Q of the RQ factorization formed by gerqf.
|:writing_hand:| 	potrf  |	Computes the Cholesky factorization of a symmetric (Hermitian) positive-definite matrix.
|:writing_hand:| 	potri  |	Computes the inverse of a Cholesky-factored symmetric (Hermitian) positive-definite matrix.
|:writing_hand:|	potrs  |	Solves a system of linear equations with a Cholesky-factored symmetric (Hermitian) positive-definite coefficient matrix, with multiple right-hand sides.
|:writing_hand:|	sytrf  |	Computes the Bunch-Kaufman factorization of a symmetric matrix.
|:writing_hand:|	trtrs  |	Solves a system of linear equations with a triangular coefficient matrix, with multiple right-hand sides.
|:writing_hand:|	ungqr  |	Generates the complex unitary matrix Q of the QR factorization formed by geqrf.
|:writing_hand:|	unmqr  |	Multiplies a complex matrix by the unitary matrix Q of the QR factorization formed by geqrf.
|:writing_hand:|	unmrq  | Multiplies a complex matrix by the unitary matrix Q of the RQ factorization formed by gerqf.

## LAPACK' Singular Value and Eigenvalue Problem Routines
| Status  | Routine |Description |
| ------------- | ------------- | -------------|
|:writing_hand:| 	gebrd |	Reduces a general matrix to bidiagonal form.
|:writing_hand:| 	gesvd |	Computes the singular value decomposition of a general rectangular matrix.
|:writing_hand:| 	heevd |	Computes all eigenvalues and, optionally, all eigenvectors of a complex Hermitian matrix using divide and conquer algorithm.
|:writing_hand:| 	hegvd |	Computes all eigenvalues and, optionally, all eigenvectors of a complex generalized Hermitian definite eigenproblem using divide and conquer algorithm.
|:writing_hand:|	hetrd |	Reduces a complex Hermitian matrix to tridiagonal form.
|:writing_hand:|	orgbr |	Generates the real orthogonal matrix Q or PT determined by gebrd.
|:writing_hand:|	orgtr |	Generates the real orthogonal matrix Q determined by sytrd.
|:writing_hand:|	ormtr |	Multiplies a real matrix by the orthogonal matrix Q determined by sytrd.
|:writing_hand:|	syevd |	Computes all eigenvalues and, optionally, all eigenvectors of a real symmetric matrix using divide and conquer algorithm.
|:writing_hand:|	sygvd |	Computes all eigenvalues and, optionally, all eigenvectors of a real generalized symmetric definite eigenproblem using divide and conquer algorithm.
|:writing_hand:|	sytrd |	Reduces a real symmetric matrix to tridiagonal form.
|:writing_hand:|	ungbr |	Generates the complex unitary matrix Q or PT determined by gebrd.
|:writing_hand:|	ungtr |	Generates the complex unitary matrix Q determined by hetrd.
|:writing_hand:|	unmtr |	Multiplies a complex matrix by the unitary matrix Q determined by hetrd.
