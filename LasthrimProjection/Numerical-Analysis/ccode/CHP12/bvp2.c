/****************************************************************/
/* Module : bvp2.c 						*/
/* Section: 12.2						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: The module rk4sys is located in "rk4sys.c". 	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALPHA 1.09737491
#define BETA 8.63749661

void rk4sys(int , float, float *, int);
void main(void);

void main(void)
{
  const int n = 99, m = 4;
  int i;
  float a = 1.0, b= 2.0;
  float *X1, *X3;
  float X[] = {1.0, ALPHA, 0, ALPHA, 1.0};
  float error, h, p, q, t;

  X1 = calloc((n+1), sizeof(float));
  X3 = calloc((n+1), sizeof(float));

  h = (b - a) / n;
  t = a;

  for (i = 1 ; i <= n ; i++)
  {
    rk4sys(m, h, X, 1);
    X1[i] = X[1];
    X3[i] = X[3];
    t = a + i * h;
  }

  p = (BETA - X3[n]) / (X1[n] - X3[n]);
  q = 1 - p;
  for (i = 1; i <= n; i++)
    X1[i] = p * X1[i] + q * X3[i];

  error = exp(a) - 3.0 * cos(a) - ALPHA;
  printf("a = %14f, ALPHA= %14f, error= %14f\n", a, ALPHA, error);
  for (i=9; i <= n ; i+=9)
  {
    t = a + i * h;
    error = exp(t) - 3.0 * cos(t) - X1[i];
    printf("t = %14f, X1[%d] = %14f, error= %14f\n", t, i, X1[i], error);  
  }

  free(X);
  free(X1);
  free(X3);

}

/****************************************************************/
/* Module : xpsys.c 						*/
/* Section: 12.2						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* 1993								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: The module rk4sys is located in "RK4SYS.C". 	*/
/*								*/
/****************************************************************/

#include <math.h>

void xpsys (float *X, float *F)
{
  F[0] = 1.0;
  F[1] = X[2];
  F[2] = exp(X[0]) - 3.0 * sin(X[0]) + X[2] - X[1];
  F[3] = X[4];
  F[4] = exp(X[0]) - 3.0 * sin(X[0]) + X[4] -X[3];
}

/****************************************************************/
/* Module : rk4sys.c 						*/
/* Section: 9.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: rk4sys and the main program			*/
/*								*/
/* Comment: (n+1) is the number of components of the vector	*/
/*          RK_order is the order of Runge-Kutta method		*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RK_order 4

/* define prototypes */


void rk4sys(int, float, float *, int);

void rk4sys(int n, float h, float *X, int nsteps)
{
  int i,k;
  float *Y, **F;

  F = calloc((RK_order+1), sizeof(float *));
  Y = calloc((n+1), sizeof(float));

  for (i = 0; i <= RK_order; i++)
    F[i] = calloc((n+1), sizeof(float));

  for (k = 0; k < nsteps; k++)
  {
    xpsys(X, F[1]);
    for (i = 0; i <= n; i++)
      Y[i] = X[i] + 0.5 * h * F[1][i];
    xpsys(Y, F[2]);
    for (i = 0; i <= n; i++)
      Y[i] = X[i] + 0.5 * h * F[2][i];
    xpsys(Y, F[3]);
    for (i = 0; i <= n; i++)
      Y[i] = X[i] + h * F[3][i];
    xpsys(Y, F[4]);
    for (i = 0; i <= n; i++)
      X[i] = X[i] + (h/6) * (F[1][i] + 2 * F[2][i] + 2 * F[3][i] + F[4][i]);
    for (i = 0; i <= n; i++)
      printf("k = %2d, X[%d] = %14f\n", k, i, X[i]);
  }

  for (i = 0; i <= RK_order; i++)
    free(F[i]);

  free(F);
  free(Y);

}

















