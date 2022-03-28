C
C     Benchmark Tests for DBQRU
C
      IMPLICIT NONE
      DOUBLE PRECISION ZERO, ONE, TWO
      PARAMETER        ( ZERO = 0.0D0, ONE = 1.0D0, TWO = 2.0D0 )
      INTEGER          NIN, NOUT
      PARAMETER        ( NIN = 5, NOUT = 6 )
      INTEGER          NBMAX, MMAX, NMAX
      PARAMETER        ( NBMAX = 128, MMAX = 3, NMAX = 4000 )
      INTEGER          LDA, LDB, LDC, LDQ, LDWORK
      PARAMETER        ( LDA = NMAX, LDB = MMAX, LDC = MMAX + NMAX,
     $                   LDQ = NMAX+MMAX, LDWORK = NBMAX*(NMAX+MMAX) )
      INTEGER          I, INFO, J, M, N
      INTEGER          ISEED(4)
      DOUBLE PRECISION T1, T2
*     .. Local Arrays ..
      DOUBLE PRECISION A(LDA, NMAX), B(LDB, NMAX), C(LDC,NMAX),
     $                 DWORK(LDWORK), Q(LDQ, NMAX+MMAX), TAU(NMAX)

      DOUBLE PRECISION DLARAN, DSECND, DLARND
      EXTERNAL         DGEQRF, DLARAN, DLARND, DSECND, DBQRU
      ISEED(1) = 0
      ISEED(2) = 0
      ISEED(3) = 0
      ISEED(4) = 1
      M = MMAX
      N = NMAX
      PRINT*, 'M = ', M
      PRINT*, 'N = ', N
      DO 10 J = 1, N
         DO 5 I = 1, J
            A(I,J) = DLARAN(ISEED)
    5    CONTINUE
   10 CONTINUE
      DO 210 J = 1, N
         DO 25 I = 1, M
            B(I,J) = DLARAN(ISEED)
   25    CONTINUE
  210 CONTINUE
      CALL DLASET( 'All', M+N, M+N, ZERO, ONE, Q, LDQ )
      T1 = DSECND()
      CALL DBQRU( M, N, A, LDA, B, LDB, TAU, DWORK, LDWORK, INFO )
      T2 = DSECND()
      WRITE ( NOUT, FMT = * ) 'Time for DBQRU: ', T2 - T1
C      T1 = DSECND()
C      CALL DBQRU_APPQ( 'Right', 'N', M+N, M, N, B, LDB, TAU,
C     $                 Q, LDQ, Q(1,N+1), LDQ, DWORK, LDWORK,
C     $                 INFO )
C      T2 = DSECND()
C      WRITE ( NOUT, FMT = * ) 'Time for update Q: ', T2 - T1      
      
      DO 310 J = 1, N
         DO 35 I = 1, M+J
            C(I,J) = DLARAN(ISEED)
   35    CONTINUE
  310 CONTINUE

      T1 = DSECND()
      CALL DGEQRF( M+N, N, C, LDC, TAU, DWORK, LDWORK, INFO )
      T2 = DSECND()
      WRITE ( NOUT, FMT = * ) 'Time for DGEQRF: ', T2 - T1     

      STOP
      END
