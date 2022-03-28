      SUBROUTINE DBQRU_LARF( SIDE, M, N, V, INCV, TAU, C, INCC, D, LDD,
     $                       WORK )
      IMPLICIT NONE
*
*  -- LAPACK auxiliary routine (version 3.1) --
*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd..
*     November 2006
*
*     .. Scalar Arguments ..
      CHARACTER          SIDE
      INTEGER            INCC, INCV, LDD, M, N
      DOUBLE PRECISION   TAU
*     ..
*     .. Array Arguments ..
      DOUBLE PRECISION   C( * ), D( LDD, * ), V( * ), WORK( * )
*     ..
*
*  Purpose
*  =======
*
*  If SIDE = 'L', DBQRU_LARF applies a real elementary reflector H to
*  a real (m+1) by n matrix
*                            [ C ]
*                            [ D ],
*  where C is a row vector and D is an m by n matrix, from the left.
*
*  If SIDE = 'R', BQRU_DLARF applies a real elementary reflector H to
*  a real m by (n+1) matrix
*                            [ C  D ]
*  where C is a column vector and D is an m by n matrix, from the right.
*
*  H is represented in the form
*
*                      [1]   [1]'
*        H = I - tau * [v] * [v]
*
*  where tau is a real scalar and v is a real vector.
*
*  If tau = 0, then H is taken to be the identity matrix.
*
*  Arguments
*  =========
*
*  SIDE    (input) CHARACTER*1
*          = 'L': form  H * C
*          = 'R': form  C * H
*
*  M       (input) INTEGER
*          The number of rows of the matrix D.
*
*  N       (input) INTEGER
*          The number of columns of the matrix D.
*
*  V       (input) DOUBLE PRECISION array, dimension
*                     (1 + (M-1)*abs(INCV)) if SIDE = 'L'
*                  or (1 + (N-1)*abs(INCV)) if SIDE = 'R'
*          The vector v in the representation of H. V is not used if
*          TAU = 0.
*
*  INCV    (input) INTEGER
*          The increment between elements of v. INCV <> 0.
*
*  TAU     (input) DOUBLE PRECISION
*          The value tau in the representation of H.
*
*  C       (input) DOUBLE PRECISION array, dimension
*                     (1 + (N-1)*abs(INCC)) if SIDE = 'L'
*                  or (1 + (M-1)*abs(INCC)) if SIDE = 'R'
*          A vector to be updated.
*
*  INCC    (input) INTEGER
*          The increment between elements of C. INCV <> 0.
*
*  D       (input/output) DOUBLE PRECISION array, dimension (LDD,N)
*          On entry, the m by n matrix D.
*          On exit, D is overwritten by the matrix H * D if SIDE = 'L',
*          or D * H if SIDE = 'R'.
*
*  LDD     (input) INTEGER
*          The leading dimension of the array D. LDD >= max(1,M).
*
*  WORK    (workspace) DOUBLE PRECISION array, dimension
*                         (N) if SIDE = 'L'
*                      or (M) if SIDE = 'R'
*
*  =====================================================================
*
*     .. Parameters ..
      DOUBLE PRECISION   ONE, ZERO
      PARAMETER          ( ONE = 1.0D+0, ZERO = 0.0D+0 )
*     ..
*     .. External Subroutines ..
      EXTERNAL           DAXPY, DGEMV, DGER
*     ..
*     .. External Functions ..
      LOGICAL            LSAME
      EXTERNAL           LSAME
*     ..
*     .. Executable Statements ..
*
      IF( LSAME( SIDE, 'L' ) ) THEN
*
*        Form  H * C
*
         IF( TAU.NE.ZERO ) THEN
*
*           w := [C' D'] * [1]
*                          [v]
*
            CALL DGEMV( 'Transpose', M, N, ONE, D, LDD, V, INCV, ZERO,
     $                  WORK, 1 )
            CALL DAXPY( N, ONE, C, INCC, WORK, 1 )
*
*           C := C - tau * w'
*
            CALL DAXPY( N, -TAU, WORK, 1, C, INCC )
*
*           D := D - tau * v * w'
*               
            CALL DGER( M, N, -TAU, V, INCV, WORK, 1, D, LDD )
         END IF
      ELSE
*
*        Form  C * H
*
         IF( TAU.NE.ZERO ) THEN
*
*           w := [C D] * [1]
*                        [v]
*
            CALL DGEMV( 'No transpose', M, N, ONE, D, LDD, V, INCV,
     $                  ZERO, WORK, 1 )
            CALL DAXPY( M, ONE, C, INCC, WORK, 1 )
*
*           C := C - tau * w
*
            CALL DAXPY( M, -TAU, WORK, 1, C, INCC )
*
*           D := D - tau * w * v'
*
            CALL DGER( M, N, -TAU, WORK, 1, V, INCV, D, LDD )
         END IF
      END IF
      RETURN
*
*     End of DBQRU_LARF
*
      END
