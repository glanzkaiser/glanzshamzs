The Basic Linear Algebra Subprograms (BLAS) is a common library including high-quality routines for performing basic operations on vectors and matrices. The first FORTRAN version was released in 1979. As the routines are efficient and portable, they are often used in linear algebra software, like LAPACK. Most implementations are written in C, C++, or FORTRAN 77.

To link your Fortran application against BLAS at the end type: -lblas

# To Compile
There is an example of vector multiplication with scalar, to test it type this in your console:

gfortran -o example vectorscalarmultiplication.f90 -lblas

(for using shared libraries)

or

gfortran -o example vectorscalarmultiplication.f90 /opt/hamzstlib/lib/libblas.a

(for using static libraries)

The path of /opt/hamzstlib is assuming you are using GFreya OS, if you read the book or create your own OS the path needs to be adjusted due to your installation path for LAPACK and BLAS.

# To Do Lists
## BLAS' Level 1
:sunflower: = Done
:writing_hand: = On Progress

| Status  | Routine |Description |
| ------------- | ------------- | -------------|
|:writing_hand:|  asum   |	Sum of vector magnitudes
|:sunflower:   |  axpy   |	Scalar-vector product
|:writing_hand:| 	copy   |	Copy vector
|:writing_hand:|	dot    |	Dot product
|:writing_hand:|	sdsdot |	Dot product with double precision
|:writing_hand:|	dotc   |	Dot product conjugated
|:writing_hand:| 	dotu   |	Dot product unconjugated
|:writing_hand:|	nrm2   |	Vector 2-norm (Euclidean norm)
|:writing_hand:|	rot    |	Plane rotation of points
|:writing_hand:|	rotg   |	Generate Givens rotation of points
|:writing_hand:| 	rotm   |	Modified Givens plane rotation of points
|:writing_hand:| 	rotmg  |	Generate modified Givens plane rotation of points
|:writing_hand:|	scal   |	Vector-scalar product
|:writing_hand:| 	swap   |	Vector-vector swap
|:writing_hand:| 	iamax  |	Index of the maximum absolute value element of a vector
|:writing_hand:| 	iamin  |	Index of the minimum absolute value element of a vector

## BLAS' Level 2
| Status  | Routine |Description |
| -------------| ----- | -------------|
|:writing_hand:|  gbmv |	Matrix-vector product using a general band matrix
|:writing_hand:| 	gemv |	Matrix-vector product using a general matrix
|:writing_hand:| 	ger  |	Rank-1 update of a general matrix
|:writing_hand:|	gerc |	Rank-1 update of a conjugated general matrix
|:writing_hand:|	geru |	Rank-1 update of a general matrix, unconjugated
|:writing_hand:| 	hbmv |	Matrix-vector product using a Hermitian band matrix
|:writing_hand:|	hemv |	Matrix-vector product using a Hermitian matrix
|:writing_hand:| 	her  |	Rank-1 update of a Hermitian matrix
|:writing_hand:| 	her2 |	Rank-2 update of a Hermitian matrix
|:writing_hand:|	hpmv |	Matrix-vector product using a Hermitian packed matrix
|:writing_hand:|	hpr  |	Rank-1 update of a Hermitian packed matrix
|:writing_hand:|  hpr2 |	Rank-2 update of a Hermitian packed matrix
|:writing_hand:|	sbmv |	Matrix-vector product using symmetric band matrix
|:writing_hand:|	spmv |	Matrix-vector product using a symmetric packed matrix
|:writing_hand:|  spr  |	Rank-1 update of a symmetric packed matrix
|:writing_hand:| 	spr2 |	Rank-2 update of a symmetric packed matrix
|:writing_hand:|	symv |	Matrix-vector product using a symmetric matrix
|:writing_hand:|	syr  |	Rank-1 update of a symmetric matrix
|:writing_hand:|	syr2 |	Rank-2 update of a symmetric matrix
|:writing_hand:|  tbmv |	Matrix-vector product using a triangular band matrix
|:writing_hand:|	tbsv |	Solution of a linear system of equations with a triangular band matrix
|:writing_hand:|	tpmv |	Matrix-vector product using a triangular packed matrix
|:writing_hand:|	tpsv |	Solution of a linear system of equations with a triangular packed matrix
|:writing_hand:| 	trmv |	Matrix-vector product using a triangular matrix
|:writing_hand:|	trsv |	Solution of a linear system of equations with a triangular matrix

## BLAS' Level 3
| Status  | Routine |Description |
| -------------| -----  | -------------|
|:writing_hand:|  gemm  |	Computes a matrix-matrix product with general matrices.
|:writing_hand:|	hemm  |	Computes a matrix-matrix product where one input matrix is Hermitian and one is general.
|:writing_hand:|	herk  |	Performs a Hermitian rank-k update.
|:writing_hand:|	her2k |	Performs a Hermitian rank-2k update.
|:writing_hand:| 	symm 	| Computes a matrix-matrix product where one input matrix is symmetric and one matrix is general.
|:writing_hand:|	syrk 	| Performs a symmetric rank-k update.
|:writing_hand:|	syr2k |	Performs a symmetric rank-2k update.
|:writing_hand:|	trmm 	| Computes a matrix-matrix product where one input matrix is triangular and one input matrix is general.
|:writing_hand:|	trsm 	| Solves a triangular matrix equation (forward or backward solve).
