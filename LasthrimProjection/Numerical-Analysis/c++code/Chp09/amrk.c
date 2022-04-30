/****************************************************************/
/* Module : amrk.c                                              */
/* Section: 9.3                                                 */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

void xp_sys(int, float*, float*);
void amrk(int, float, float*, int);
void am_sys(int&, int, float, float&, float**, float**);
void rk_sys(int&, int, float, float**, float**);

int main()
{
  const int n = 5, nsteps = 100;
  const float a = 0.0, b = 1.0;
  int i;
  float h;
  float x[] = {1.0, 2.0, -4.0, -2.0, 7.0, 6.0};

  h = (b - a)/nsteps;
  amrk(n, h, x, nsteps);
  return 0;
}

//-----------------------------
void xp_sys(int n, float *x, float *f)
{
  f[0] = 1.0;
  f[1] = x[2];
  f[2] = x[1] - x[3] - 9*pow(x[2],2) + pow(x[4],3) + 6*x[5] + 2*x[0];
  f[3] = x[4];
  f[4] = x[5];
  f[5] = x[5] - x[2] + exp(x[1]) - x[0];
}

//--------------------------------------------
void amrk(int n, float h, float *x, int nsteps)
{
  int i, k, m;
  float *z[RK_order+1], *f[RK_order+1], est;

  for (i = 0; i <= n; i++)
  {
    f[i] = new float[n+1];
    z[i] = new float[n+1];
  }

  m = 0;
  printf("h = %1.2f\n", h);
  printf("0 ");
  for (i = 0; i <= n; i++)
    printf("x[%d] = %1.3f ", i, x[i]);
  for (i = 0; i <= n; i++)
     z[m][i] = x[i];

   for (k = 1; k <= 3; k++)
   {
     rk_sys(m, n, h, z, f);
     printf("k = %d\n", k);
     for (i = 0; i <= n; i++)
       printf("z[%d][%d] = %f\n", i, m, z[m][i]);
    }

    for (k = 4; k <= nsteps; k++)
    {
      if (k > 40)
	exit (1);
      am_sys(m, n, h, est, z, f);
      printf("k = %d,  est = %f\n", k, est);
      for (i = 0; i <= n; i++)
	 printf("z[%d][%d] = %f\n", i, m, z[m][i]);
     }

     for (i = 0; i <= n; i++)
       x[i] = z[m][i];

     for (i = 0; i <= RK_order; i++)
     {
       delete [] z[i];
       delete [] f[i];
     }
}

//------------------------------------------------------------------
void am_sys (int& m, int n, float h, float& est, float* z[], float* f[])
{

  float s[n+1], y[n+1];
  float a[] = {0, 55, -59, 37, -9};
  float b[] = {0, 9, 19, -5, 1};
  int i, j, k, mp1;
  float d, dmax;

  mp1 = (1 + m)%5;
  xp_sys (n, z[m], f[m]);
  for (i = 0; i <= n; i++)
    s[i] = 0;
  for (k = 1; k <= 4; k++)
  {
    j = (m - k + 6)%5;
    for (i = 0; i <= n; i++)
      s[i] += a[k]*f[j][i];
  }
  for (i = 0; i <= n; i++)
      y[i] = z[m][i] + h*s[i]/24;
  xp_sys (n, y, f[mp1]);
  for (i = 0; i <= n; i++)
    s[i] = 0;
  for (k = 1; k <= 4; k++)
  {
    j = (mp1 - k + 6)%5;
    for (i = 0; i <= n; i++)
       s[i] += b[k]*f[j][i];
  }
  for (i = 0; i <= n; i++)
    z[mp1][i] = z[m][i] + h*s[i]/24;
  m = mp1;
  dmax = 0;
  for (i = 0; i <= n; i++)
  {
    d = fabs(z[m][i] - y[i]) / fabs(z[m][i]);
    if (d > dmax)
    {
      dmax = d;
      j = i;
    }
  }
  est = 19*dmax/270.0;
}

//-----------------------------------------------------
void rk_sys(int& m, int n, float h, float* z[], float* f[])
{
  /*modified from rk4sys */
  int i, k, mp1;
  float *g[RK_order+1], y[n+1];

  for (i = 0; i <= RK_order; i++)
    g[i] = new float[n+1];

  mp1 = (1 + m)%5;
  xp_sys(n, z[m], f[m]);
  for (i = 0; i <= n; i++)
    y[i] = z[m][i] + h/2*f[m][i];
  xp_sys(n, y, g[1]);
  for (i = 0; i <= n; i++)
    y[i] = z[m][i] + h/2*g[1][i];
  xp_sys(n, y, g[2]);
  for (i = 0; i <= n; i++)
    y[i] = z[m][i] + h*g[2][i];
  xp_sys (n, y, g[3]);
  for (i = 0; i <= n; i++)
    z[mp1][i] = z[m][i] + h*(f[m][i] + 2*g[1][i] + 2*g[2][i] + g[3][i])/6;
  m = mp1;
  for (i = 0; i <= RK_order; i++)
    delete [] g[i];
}



