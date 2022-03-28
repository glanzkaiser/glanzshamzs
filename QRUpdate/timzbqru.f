C
C     Benchmark Tests for ZBQRU
C
      IMPLICIT NONE
      COMPLEX*16         ONE, ZERO
      PARAMETER          ( ONE = ( 1.0D+0, 0.0D+0 ),
     $                   ZERO = ( 0.0D+0, 0.0D+0 ) )
      INTEGER          NIN, NOUT
      PARAMETER        ( NIN = 5, NOUT = 6 )
      INTEGER          NBMAX, MMAX, NMAX
      PARAMETER        ( NBMAX = 128, MMAX = 500, NMAX = 2000 )
      INTEGER          LDA, LDB, LDC, LDQ, LZWORK
      PARAMETER        ( LDA = NMAX, LDB = MMAX, LDC = MMAX + NMAX,
     $                   LDQ = NMAX+MMAX, LZWORK = NBMAX*(NMAX+MMAX) )
      INTEGER          I, INFO, J, M, N
      INTEGER          ISEED(4)
      DOUBLE PRECISION T1, T2
*     .. Local Arrays ..
      COMPLEX*16       A(LDA, NMAX), B(LDB, NMAX), C(LDC,NMAX),
     $                 ZWORK(LZWORK), TAU(NMAX)
C     $                 Q(LDQ, NMAX+MMAX), 

      DOUBLE PRECISION DLARAN, DSECND, DLARND
      EXTERNAL         ZGEQRF, DLARAN, DLARND, DSECND, ZBQRU
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
            A(I,J) = DCMPLX( DLARAN(ISEED), DLARAN(ISEED) )
    5    CONTINUE
   10 CONTINUE
      DO 210 J = 1, N
         DO 25 I = 1, M
            B(I,J) = DCMPLX( DLARAN(ISEED), DLARAN(ISEED) )
   25    CONTINUE
  210 CONTINUE
      T1 = DSECND()
      CALL ZBQRU( M, N, A, LDA, B, LDB, TAU, ZWORK, LZWORK, INFO )
      T2 = DSECND()
      WRITE ( NOUT, FMT = * ) 'Time for ZBQRU: ', T2 - T1
C      CALL ZLASET( 'All', M+N, M+N, ZERO, ONE, Q, LDQ )
C      T1 = DSECND()
C      CALL DBQRU_APPQ( 'Right', 'N', M+N, M, N, B, LDB, TAU,
C     $                 Q, LDQ, Q(1,N+1), LDQ, DWORK, LDWORK,
C     $                 INFO )
C      T2 = DSECND()
C      WRITE ( NOUT, FMT = * ) 'Time for update Q: ', T2 - T1      
      
      DO 310 J = 1, N
         DO 35 I = 1, M+J
            C(I,J) = DCMPLX( DLARAN(ISEED), DLARAN(ISEED) )
   35    CONTINUE
  310 CONTINUE

      T1 = DSECND()
      CALL ZGEQRF( M+N, N, C, LDC, TAU, ZWORK, LZWORK, INFO )
      T2 = DSECND()
      WRITE ( NOUT, FMT = * ) 'Time for ZGEQRF: ', T2 - T1     

      STOP
      END
