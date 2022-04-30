/****************************************************************/
/* Module : amrk.c                                              */
/* Section: 9.3                                                 */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*                                                              */
/* Programmer: Hidajaty Thajeb                                  */
/* Description: Adam-Moulton method for systems of ODEs         */
/*                                                              */
/* Comment: (n+1) is the number of components of the vector     */
/*          RK_order is the order of Runge-Kutta method         */
/*          The two-dimensional arrays are stored differently   */
/*          from that of the corresponding f90 code/pseudocode. */
/*          e.g: Z[i][m] in the book/f90 corresponds to         */
/*               Z[m][i] in the C code.                         */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RK_order 4

/* define prototypes */
void xpsys(float *, float *);
void amrk(int, float, float *, int);
void amsys(int *, int, float, float *, float **, float **);
void rksys(int *, int, float, float **, float **);

void xpsys(float *X, float *f)
{
  f[0] = 1.0;
  f[1] = X[2];
  f[2] = X[1] - X[3] - 9 * X[2] * X[2] + pow (X[4],3) + 6 * X[5] + 2 * X[0];
  f[3] = X[4];
  f[4] = X[5];
  f[5] = X[5] - X[2] + exp(X[1]) - X[0];

}

void amrk(int n, float h, float *X, int nsteps)
{
  int i, k, m;
  float **Z, **F, est;

  F = calloc((RK_order + 1), sizeof(float *));
  Z = calloc((RK_order + 1), sizeof(float *));

  for (i = 0; i <= RK_order; i++)
  {
    F[i] = calloc((n+1), sizeof(float));
    Z[i] = calloc((n+1), sizeof(float));
  }

  m = 0;

  for (i = 0; i <= n; i++)
     Z[m][i] = X[i];

   for (k = 1; k <= 3; k++)
   {
     rksys(&m, n, h, Z, F);
     printf("k = %d\n", k);
     for (i = 0; i <= n; i++)
       printf("Z[%d][%d] = %f\n", m, i, Z[m][i]);
    }

    for (k = 4; k <= nsteps; k++)
    {
      /* since after 40 steps, the result is NaN, add these 2 lines to exit */
      /* the program */
      if (k > 40)
	exit (1);
      amsys(&m, n, h, &est, Z, F);
      printf("k = %d,  est = %f\n", k, est);
      for (i = 0; i <= n; i++)
	 printf("Z[%d][%d] = %f\n", m, i, Z[m][i]);
     }

     for (i = 0; i <= n; i++)
       X[i] = Z[m][i];

     for (i = 0; i <= RK_order; i++)
     {
       free(F[i]);
       free(Z[i]);
     }

    free (F);
    free (Z);

}

void amsys (int *m, int n, float h, float *est, float **Z, float **F)
{

  float *S, *Y;

  float A[] = {0, 55, -59, 37, -9};
  float B[] = {0, 9, 19, -5, 1};

  int i, j, k, mp1;

  float d, dmax, factor_24h;

  S = calloc( (n+1), sizeof(float) );
  Y = calloc( (n+1), sizeof(float) );

  mp1 = (1 + *m) % 5;
  xpsys (Z[*m], F[*m]);

  for (i = 0; i <= n; i++)
    S[i] = 0;

  for (k = 1; k <= 4; k++)
  {
    j = (*m - k + 6) % 5;

    for (i = 0; i <= n; i++)
      S[i] += A[k] * F[j][i];
  }

  factor_24h = h / 24.0;

  for (i = 0; i <= n; i++)
      Y[i] = Z[*m][i] + S[i] * factor_24h;

  xpsys (Y, F[mp1]);

  for (i = 0; i <= n; i++)
    S[i] = 0;

  for (k = 1; k <= 4; k++)
  {
    j = (mp1 - k + 6) % 5;

    for (i = 0; i <= n; i++)
       S[i] += B[k] * F[j][i];
  }

  for (i = 0; i <= n; i++)
    Z[mp1][i] = Z[*m][i] + S[i] * factor_24h;

  *m = mp1;

  dmax = 0;

  for (i = 0; i <= n; i++)
  {
    d = fabs(Z[mp1][i] - Y[i]) / fabs(Z[mp1][i]);

    if (d > dmax)
    {
      dmax = d;
      j = i;
    }
  }

  *est = 19 * dmax / 270.0;

  free (S);
  free (Y);
}


void rksys(int *m, int n, float h, float **Z, float **F)
{
  /*modified from rk4sys */

  int i, k, mp1;
  float **G, *Y, factor_h6;

  G = calloc((RK_order), sizeof(float *));
  Y = calloc((n+1), sizeof(float));

  for (i = 0; i < RK_order; i++)
    G[i] = calloc((n+1), sizeof(float));

  mp1 = (1 + *m) % 5;

  xpsys(Z[*m], F[*m]);

  for (i = 0; i <= n; i++)
    Y[i] = Z[*m][i] + 0.5 * h * F[*m][i];

  xpsys(Y, G[1]);

  for (i = 0; i <= n; i++)
    Y[i] = Z[*m][i] + 0.5 * h * G[1][i];

  xpsys(Y, G[2]);

  for (i = 0; i <= n; i++)
    Y[i] = Z[*m][i] + h * G[2][i];

  xpsys (Y, G[3]);

  factor_h6 = h / 6.0;

  for (i = 0; i <= n; i++)
    Z[mp1][i] = Z[*m][i] + (factor_h6) * (F[*m][i] + 2 * G[1][i] + 2 * G[2][i] + G[3][i]);

  *m = mp1;

  for (i = 0; i < RK_order; i++)
    free (G[i]);

  free (Y);
  free (G);

}


void main()
{
  const int n = 5, nsteps = 100;
  int i;
  float a = 0, b= 1.0, h;
  float X[] = {1.0, 2.0, -4.0, -2.0, 7.0, 6.0};

  h = (b - a) / nsteps;
  amrk(n, h, X, nsteps);
}
