      SUBROUTINE ZAXPYC(N,ZA,ZX,INCX,ZY,INCY)
*     .. Scalar Arguments ..
      COMPLEX*16 ZA
      INTEGER INCX,INCY,N
*     ..
*     .. Array Arguments ..
      COMPLEX*16 ZX(*),ZY(*)
*     ..
*
*  Purpose
*  =======
*
*     constant times conjugate transpose of a vector plus a vector.
*

*     .. Local Scalars ..
      INTEGER I,IX,IY
*     ..
*     .. External Functions ..
      DOUBLE PRECISION DCABS1
      EXTERNAL DCABS1
*     .. Intrinsic Functions ..
      INTRINSIC DCONJG
*     ..
      IF (N.LE.0) RETURN
      IF (DCABS1(ZA).EQ.0.0d0) RETURN
      IF (INCX.EQ.1 .AND. INCY.EQ.1) GO TO 20
*
*        code for unequal increments or equal increments
*          not equal to 1
*
      IX = 1
      IY = 1
      IF (INCX.LT.0) IX = (-N+1)*INCX + 1
      IF (INCY.LT.0) IY = (-N+1)*INCY + 1
      DO 10 I = 1,N
          ZY(IY) = ZY(IY) + ZA*DCONJG( ZX(IX) )
          IX = IX + INCX
          IY = IY + INCY
   10 CONTINUE
      RETURN
*
*        code for both increments equal to 1
*
   20 DO 30 I = 1,N
          ZY(I) = ZY(I) + ZA*DCONJG( ZX(I) )
   30 CONTINUE
      RETURN
      END
