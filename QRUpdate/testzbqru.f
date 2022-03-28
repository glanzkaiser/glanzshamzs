*     QR UPDATE EXAMPLE PROGRAM TEXT
*
*     .. Parameters ..
      IMPLICIT NONE
      COMPLEX*16         ONE, ZERO
      PARAMETER          ( ONE = ( 1.0D+0, 0.0D+0 ),
     $                   ZERO = ( 0.0D+0, 0.0D+0 ) )
      INTEGER          NIN, NOUT
      PARAMETER        ( NIN = 5, NOUT = 6 )
      INTEGER          MMAX, NMAX
      PARAMETER        ( MMAX = 200, NMAX = 100 )
      INTEGER          LDA, LDB, LDQ, LZWORK
      PARAMETER        ( LDA = NMAX, LDB = MMAX, LDQ = MMAX+NMAX,
     $                   LZWORK = 64*NMAX )
*     .. Local Scalars .. 
      INTEGER          I, INFO, J, M, N
*     .. Local Arrays ..
      COMPLEX*16       A(LDA, NMAX), B(LDB, NMAX), Q(LDQ,MMAX+NMAX),
     $                 ZWORK(LZWORK), TAU(NMAX)
*     .. External Subroutines ..
      EXTERNAL         ZBQRU, ZLASET
*     .. Executable Statements ..
      WRITE ( NOUT, FMT = 99999 )
*     Skip the heading in the data file and read the data.
      READ ( NIN, FMT = '()' )
      READ ( NIN, FMT = * )  M, N
      IF( M.LE.0 .OR. M.GT.MMAX ) THEN
         WRITE ( NOUT, FMT = 99991 ) M
      ELSE IF( N.LE.0 .OR. N.GT.NMAX ) THEN
         WRITE ( NOUT, FMT = 99992 ) N
      ELSE
         READ ( NIN, FMT = * ) ( ( A(I,J), J = 1,N ), I = 1,N )
         READ ( NIN, FMT = * ) ( ( B(I,J), J = 1,N ), I = 1,M )
         CALL ZBQRU( M, N, A, LDA, B, LDB, TAU, ZWORK, LZWORK, INFO )
         IF ( INFO.NE.0 ) THEN
            WRITE ( NOUT, FMT = 99998 ) INFO
         ELSE
            WRITE ( NOUT, FMT = 99996 )
            DO 10  I = 1, N
               WRITE (NOUT, FMT = 99993) ( A(I,J), J = 1,N )
10          CONTINUE
            CALL ZLASET( 'All', M+N, M+N, ZERO, ONE, Q, LDQ )
            CALL ZBQRU_APPQ( 'Right', 'N', M+N, M, N, B, LDB, TAU,
     $                       Q, LDQ, Q(1,N+1), LDQ, ZWORK, LZWORK,
     $                       INFO )
            IF ( INFO.NE.0 ) THEN
               WRITE ( NOUT, FMT = 99997 ) INFO
            ELSE
               WRITE ( NOUT, FMT = 99995 )
               DO 20  I = 1, M+N
                  WRITE (NOUT, FMT = 99993) ( Q(I,J), J = 1,M+N )
20             CONTINUE
            END IF
         END IF
      END IF
*
99999 FORMAT (' ZBQRU EXAMPLE PROGRAM RESULTS')
99998 FORMAT (' INFO on exit from ZBQRU = ',I2)
99997 FORMAT (' INFO on exit from ZBQRU_APP = ',I2)
99996 FORMAT (/' Updated factor R ')
99995 FORMAT (/' Unitary matrix Q ')
99993 FORMAT (20(1X,F9.4))
99992 FORMAT (/' N is out of range.',/' N = ',I5)
99991 FORMAT (/' M is out of range.',/' M = ',I5)
99990 FORMAT (/' Residual: || ... ||_F = ',G7.2)
      END
