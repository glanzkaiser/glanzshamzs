 #include <stdio.h>
 #include <lapacke.h>
 #include "lapacke_example_aux.h"
  
 /* Main program */
 int main (int argc, const char * argv[])
 {
    /* Locals */
    double A[5][3] = {1,1,1,2,3,4,3,5,2,4,2,5,5,4,3};
    double b[5][2] = {-10,-3,12,14,14,12,16,16,18,16};
    lapack_int info,m,n,lda,ldb,nrhs;
  
    /* Initialization */
    m = 5;
    n = 3;
    nrhs = 2;
    lda = 3;
    ldb = 2;
  
    /* Print Entry Matrix */
    print_matrix_rowmajor( "Entry Matrix A", m, n, *A, lda );
    /* Print Right Rand Side */
    print_matrix_rowmajor( "Right Hand Side b", n, nrhs, *b, ldb );
    printf( "\n" );
  
    /* Executable statements */
    printf( "LAPACKE_dgels (row-major, high-level) Example Program Results\n" );
    /* Solve least squares problem*/
    info = LAPACKE_dgels(LAPACK_ROW_MAJOR,'N',m,n,nrhs,*A,lda,*b,ldb);
  
    /* Print Solution */
    print_matrix_rowmajor( "Solution", n, nrhs, *b, ldb );
    printf( "\n" );
    exit( 0 );
 } 

/* End of LAPACKE_dgels Example */

