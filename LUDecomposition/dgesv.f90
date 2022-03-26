Program DirectSolve

! LAPACK
! Perform a direct solve for the equation A*x=b, using LU decomposition.
! A is a general, double precision matrix.
implicit none
! declarations, NB double precision

integer, parameter :: N = 3
integer, parameter :: LDA = N ! leading dimension of A
integer, parameter :: LDB = N ! leading dimension of B
integer, parameter :: NRHS = 1 ! no. of RHS, i.e columns in b
integer, dimension(N) :: IPIV
integer :: INFO
integer :: ii
logical, parameter :: verbose = .false.
real(kind=8), dimension(LDA,N) :: A ! LDAxN matrix
real(kind=8), dimension(LDB,NRHS) :: B ! LDBxNRHS matrix

! insert values into matrix A:
! ( 1 3 -2)
! ( 3 5 6)
! ( 2 4 3)
A(1,1) = 1.0d+0
A(1,2) = 3.0d+0
A(1,3) = -2.0d+0
A(2,1) = 3.0d+0
A(2,2) = 5.0d+0
A(2,3) = 6.0d+0
A(3,1) = 2.0d+0
A(3,2) = 4.0d+0
A(3,3) = 3.0d+0

! insert values into matrix B:
! ( 5)
! ( 7)
! ( 8)
B(1,1) = 5.0d+0
B(2,1) = 7.0d+0
B(3,1) = 8.0d+0

! solve (using LU decomposition) using LAPACK's DGESV routine.
! NB the known vectors B will be exchanged, in place, with the
! solution vectors X, on exit.
call dgesv(N, NRHS, A, LDA, IPIV, B, LDB, INFO)

! check the value of info
if (INFO .ne. 0) then
  write(*,*) 'ERROR calling DGETRF'
  stop
endif

! Print the result vector X.
! It should be:
! (-15)
! ( 8)
! ( 2)
do ii=1,LDB
  write(*,*) B(ii,1)
end do

if (verbose) then
! Also print out A, the encoding of the LU decomposition:
  write (*,*) ''
  write (*,*) 'LU decomposition as encoded in matrix A:'
  do ii=1,N
  write(*,*) A(ii,:) ! all cols for a given row
  end do
  
  write (*,*) ''
  write (*,*) '..and the IPIV vector:'
  write (*,*) IPIV
end if

end Program DirectSolve
