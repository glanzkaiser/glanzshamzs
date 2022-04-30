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

void xpsys(float *, float *);
void rk4sys(int, float, float *, int);

void xpsys(float *X, float *f)
{
  f[0] = 1.0;
  f[1] = X[1] -X[2] + X[0] * (2 - X[0] *(1 + X[0]));
  f[2] = X[1] + X[2] - X[0] * X[0] * (4 -X[0]);
}

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

void main()
{
  const int n = 2;
  const int nsteps = 100;
  int i;
  float a = 0, b= 1.0, h;
  float X[]= {0, 1.0, 0};

  h = (b - a) / nsteps;
  rk4sys(n, h, X, nsteps);

}


