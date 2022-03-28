      SUBROUTINE ZBQRU( M, N, A, LDA, B, LDB, TAU, WORK, LWORK, INFO )
      IMPLICIT NONE
*
*     .. Scalar Arguments ..  
      INTEGER            INFO, LDA, LDB, LWORK, M, N
*     ..
*     .. Array Arguments ..
      COMPLEX*16         A( LDA, * ), B( LDB, * ), TAU( * ), WORK( * )
*     ..
*
*  Purpose
*  =======
*
*  Given an upper triangular n-by-n matrix A and an m-by-n matrix B,
*  ZBQRU computes a QR factorization of 
*
*     [ A ]
*     [ B ] = Q * R.
*
*
*  Arguments
*  =========
*
*  M       (input) INTEGER
*          The number of rows of the matrix B.  M >= 0.
*
*  N       (input) INTEGER
*          The number of rows of the matrix A.  N >= 0.
*
*  A       (input/output) COMPLEX*16 array, dimension (LDA,N)
*          On entry, the upper triangular N-by-N matrix A.
*          On exit, the upper triangular N-by-N matrix R of the QR
*          decomposition. 
*
*  LDA     (input) INTEGER
*          The leading dimension of the array A.  LDA >= max(1,N).
*
*  B       (input/output) COMPLEX*16 array, dimension (LDB,N)
*          On entry, the M-by-N matrix B.
*          On exit, the elements of this array, together with the array
*          TAU, represent the unitary matrix Q as a product of n
*          elementary reflectors (see Further Details).
*
*  LDB     (input) INTEGER
*          The leading dimension of the array B.  LDB >= max(1,M).
*
*  TAU     (output) COMPLEX*16 array, dimension (N)
*          The scalar factors of the elementary reflectors (see Further
*          Details).
*
*  WORK    (workspace/output) COMPLEX*16 array, dimension (MAX(1,LWORK))
*          On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
*
*  LWORK   (input) INTEGER
*          The dimension of the array WORK.  LWORK >= max(1,N).
*          For optimum performance LWORK >= N*NB, where NB is
*          the optimal blocksize.
*
*          If LWORK = -1, then a workspace query is assumed; the routine
*          only calculates the optimal size of the WORK array, returns
*          this value as the first entry of the WORK array, and no error
*          message related to LWORK is issued by XERBLA.
*
*  INFO    (output) INTEGER
*          = 0:  successful exit
*          < 0:  if INFO = -i, the i-th argument had an illegal value
*
*  Further Details
*  ===============
*
*  The matrix Q is represented as a product of elementary reflectors
*
*     Q = H(1) H(2) . . . H(n).
*
*  Each H(i) has the form
*
*     H(i) = I - tau * v * v'
*
*  where tau is a complex scalar, and v is a complex vector with 
*  v(1:i-1) = 0, v(i) = 1, v(i+1:n) = 0; v(n+1:n+m) is stored on exit
*  in B(:,i), and tau in TAU(i).
*
*  =====================================================================
*
*     .. Local Scalars ..
      LOGICAL            LBLOCK, LQUERY
      INTEGER            I, J, JB, JC, JCB, LWKOPT, MBLOCK,
     $                   NB, UPD
*     ..
*     .. External Subroutines ..
      EXTERNAL           ZBQRU_LARF, ZBQRU_LARFB, ZBQRU_LARFT,
     $                   ZLARFG, XERBLA
*     ..
*     .. External Functions ..
      INTEGER            ILAENV
      EXTERNAL           ILAENV
*     ..
*     .. Intrinsic Functions ..
      INTRINSIC          MAX, MIN
*     ..
*     .. Executable Statements ..
*
*     Block parameters.
*     Tune these parameters to get optimal performance
*     The default settings you find below are just a
*     heuristics and should be fairly OK.
*     NB = panel block size
      NB = ILAENV( 1, 'ZGEQRF', ' ', M, N, -1, -1 )
C      PRINT*, 'NB = ', NB
*     MBLOCK = minimal M for which the block algorithm is used
      MBLOCK = NB/2
*
*     Test the input arguments
*
      INFO = 0
      LWKOPT = N*NB
      WORK( 1 ) = LWKOPT
      LQUERY = ( LWORK.EQ.-1 )
      IF( M.LT.0 ) THEN
         INFO = -1
      ELSE IF( N.LT.0 ) THEN
         INFO = -2
      ELSE IF( LDA.LT.MAX( 1, N ) ) THEN
         INFO = -4
      ELSE IF( LDB.LT.MAX( 1, M ) ) THEN
         INFO = -6
      ELSE IF( LWORK.LT.MAX( 1, N ) .AND. .NOT.LQUERY ) THEN
         INFO = -9
      END IF
      IF( INFO.NE.0 ) THEN
         CALL XERBLA( 'ZBQRU', -INFO )
         RETURN
      ELSE IF( LQUERY ) THEN
         RETURN
      END IF
*
*     Quick return if possible
*
      IF( M.EQ.0 .OR. N.EQ.0 ) THEN
         WORK( 1 ) = 1
         RETURN
      END IF
*
      LBLOCK = ( M.GE.MBLOCK ).AND.( LWORK.GE.NB*N )
C      PRINT*, 'LBLOCK = ', LBLOCK
*
      DO 100  J = 1, N, NB
         JB = MIN( N-J+1, NB )
*
*        Factorize panel.
*
         DO 10 I = J, J+JB-1
            CALL ZLARFG( M+1, A( I, I ), B( 1, I ), 1, TAU( I ) )
            CALL ZBQRU_LARF( 'Left', M, J+JB-I-1, B( 1, I ), 1,
     $                       DCONJG( TAU( I ) ), A( I, I+1 ), LDA,
     $                       B( 1, I+1), LDB, WORK )
   10    CONTINUE
*
         UPD = N - J - JB + 1
         IF ( UPD.GT.0 ) THEN
            IF ( LBLOCK ) THEN
*
*              Use block algorithm
*
               CALL ZBQRU_LARFT( M, JB, B(1,J), LDB, TAU(J), WORK, N )
               CALL ZBQRU_LARFB( 'Left', 'Conjugate Transpose', M, UPD, 
     $                           JB, B(1,J), LDB, WORK, N, A(J,J+JB), 
     $                           LDA, B(1,J+JB), LDB, WORK(JB+1), N )
            ELSE
*
*              Use block-oriented algorithm
*
               JC = J + JB
               JCB = N - ( J+JB ) + 1
               DO 20 I = J, J+JB-1
                  CALL ZBQRU_LARF( 'Left', M, UPD, B( 1, I ), 1,
     $                             DCONJG( TAU( I ) ), A( I, J+JB ),
     $                             LDA, B( 1, J+JB ), LDB, WORK )
   20          CONTINUE
            END IF
         END IF
         
  100 CONTINUE
*
      IF ( LBLOCK ) THEN
         WORK( 1 ) = MAX( 1, N*NB )
      ELSE
         WORK( 1 ) = MAX( 1, N )
      END IF
      RETURN
*
*     End of ZBQRU
*
      END
