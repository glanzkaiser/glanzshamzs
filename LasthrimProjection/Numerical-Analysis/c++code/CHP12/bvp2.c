/****************************************************************/
/* Module : bvp2.c 						*/
/* Section: 12.2						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

#define RK_order 4

void xp_system(float* x, float* f);
void rk4sys2(int , float , float*, int);

int main()
{
  const int n = 99, m = 4;
  const float a = 1.0,
              b = 2.0,
              alpha = 1.09737491,
              beta = 8.63749661;
  float x[m+1],
        x1[n+1],
        x3[n+1];
  int i;
  float error, h, p, q, t;

  x[0] = 1;
  x[1] = alpha;
  x[2] = 0;
  x[3] = alpha;
  x[4] = 1;
  h = (b - a)/n;

  for (i = 1; i <= n; i++)
    {
      rk4sys2(m, h, x, 1);
      x1[i] = x[1];
      x3[i] = x[3];
    }
  p = (beta - x3[n])/(x1[n] - x3[n]);
  q = 1 - p;
  for (i = 1; i <= n; i++)
    x1[i] = p*x1[i] + q*x3[i];
  error = exp(a) - 3*cos(a) - alpha;
  printf("\n\tt-Value%8c Solution%9c Error\n");
  printf("\t%.7f %14.7f %14.2f\n", a, alpha, error);
  for (i = 9; i < n; i += 9)
    {
      t = a + i*h;
      error = exp(t) - 3*cos(t) - x1[i];
      printf("\t%.7f %14.7f %14.2e\n", t, x1[i], error);
    }
  t = a + i*h;
  error = exp(t) - 3*cos(t) - x1[i];
  printf("\t%.7f %14.7f %14.2f\n", t, x1[i], error);
 return 0;
}

//---------------------------------------------------
void xp_system(float* x, float* f)
{
  f[0] = 1;
  f[1] = x[2];
  f[2] = exp(x[0]) - 3*sin(x[0]) + x[2] - x[1];
  f[3] = x[4];
  f[4] = exp(x[0]) - 3*sin(x[0]) + x[4] - x[3];
}

//-------------------------------------------------
void rk4sys2(int n, float h, float* x, int nsteps)
{
  int i,k;
  float y[n+1], *f[RK_order+1];

  for (i = 0; i <= RK_order; i++)
    f[i] = new float[n+1];

  for (k = 0; k < nsteps; k++)
  {
    xp_system(x, f[1]);
    for (i = 0; i <= n; i++)
      y[i] = x[i] + 0.5 * h * f[1][i];
    xp_system(y, f[2]);
    for (i = 0; i <= n; i++)
      y[i] = x[i] + 0.5 * h * f[2][i];
    xp_system(y, f[3]);
    for (i = 0; i <= n; i++)
      y[i] = x[i] + h * f[3][i];
    xp_system(y, f[4]);
    for (i = 0; i <= n; i++)
      x[i] = x[i] + (h/6) * (f[1][i] + 2 * f[2][i] + 2 * f[3][i] + f[4][i]);
  }

  for (i = 0; i <= RK_order; i++)
    delete [] f[i];
}











