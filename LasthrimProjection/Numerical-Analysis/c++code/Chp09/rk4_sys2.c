/****************************************************************/
/* Module : rk4_sys2.c 						*/
/* Section: 9.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

void rk4sys2(int , float , float*, int); /* used in chp 12 */
void xp_system(float*, float* );

int main(void)
{
  const int n = 2,
            nsteps = 100;
  const float a = 0,
              b = 1;
  float x[] = {0, 1, 0};
  float h;

  h = (b - a)/nsteps;
  rk4sys2(n, h, x, nsteps);
}

//------------------------------------------------
void xp_system(float* x, float* f)
{
  f[0] = 1;
  f[1] = x[1] - x[2] + x[0]*(2 - x[0]*(1 + x[0]));
  f[2] = x[1] + x[2] - x[0]*x[0]*(4 - x[0]);
}

//-------------------------------------------------
void rk4sys2(int n, float h, float *x, int nsteps)
{
  int i,k;
  float y[n+1], *f[RK_order+1];

  for (i = 0; i <= RK_order; i++)
    f[i] = new float[n+1];

  for (k = 0; k < nsteps; k++)
  {
    xp_system(x, f[1]);
    for (i = 0; i < n; i++)
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
    for (i = 0; i <= n; i++)
      printf("k = %2d, x[1] = %f, x[2] = %f \n", k, x[1], x[2]);
  }

  for (i = 0; i <= RK_order; i++)
    delete [] f[i];
}
