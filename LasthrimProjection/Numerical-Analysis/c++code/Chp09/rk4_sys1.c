/****************************************************************/
/* Module : rk4_sys1.c 						*/
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

void xp_sys(int, float, float*, float*);
void rk4sys(int, float, float, float*, int);
void rk4sys2(int , float , float , float*, int); /* used in chp 12 */

void main()
{
  const int n = 2;
  const int nsteps = 100;
  const float a = 0, b= 1.0;
  float x[n+1];
  float h, t;
  
  t = 0.0;
  x[0] = 0.0; /* dummy */
  x[1] = 1.0;
  x[2] = 0.0;
  h = (b - a) / nsteps;
  rk4sys(n, h, t, x, nsteps);

}

//--------------------------------------------
void xp_sys(int n, float t, float* x, float* f)
{
  f[1] = x[1] - x[2] + t * (2 - t *(1 + t));
  f[2] = x[1] + x[2] - t * t * (4 - t);
}

//-------------------------------------------------------
void rk4sys(int n, float h, float t, float *x, int nsteps)
{
  int i, j;
  float y[n+1], *K[RK_order+1];

  for (i = 0; i <= RK_order; i++)
    K[i] = new float[n+1]; 

  printf("0 t = %1.2f, x[1] = %1.2f, x[2] = %1.2f\n", t, x[1], x[2]);
  for (j = 1; j <= nsteps; j++)
    {
      xp_sys(n, t, x, K[1]);
      for (i = 1; i <= n; i++)
	y[i] = x[i] + 0.5 * h * K[1][i];
      xp_sys(n, t+0.5*h, y, K[2]);
      for (i = 1; i <= n; i++)
	y[i] = x[i] + 0.5 * h * K[2][i];
      xp_sys(n, t+0.5*h, y, K[3]);
      for (i = 1; i <= n; i++)
	y[i] = x[i] + h * K[3][i];
      xp_sys(n, t+h, y, K[4]);
      for (i = 1; i <= n; i++)
	x[i] = x[i] + (h/6) * (K[1][i] + 2 * K[2][i] + 2 * K[3][i] + K[4][i]);
      t = t + h;
      printf("j = %2d, t = %1.2f, x = %1.7f,  y = %1.7f\n", j, t, x[1], x[2]);
    }

  for (i = 0; i <= RK_order; i++)
    delete [] K[i]; 
}

//----------------------------------------------------------
void rk4sys2(int n, float h, float t, float *x, int nsteps)
{
  int i, j;
  float y[n+1], *K[RK_order+1];

  for (i = 0; i <= RK_order; i++)
    K[i] = new float[n+1]; 

  printf("0 t = %1.2f, x[1] = %1.2f, x[2] = %1.2f\n", t, x[1], x[2]);
  for (j = 1; j <= nsteps; j++)
  {
    xp_sys(n, t, x, K[1]);
    for (i = 1; i <= n; i++)
      y[i] = x[i] + 0.5 * h * K[1][i];
    xp_sys(n, t+0.5*h, y, K[2]);
    for (i = 1; i <= n; i++)
      y[i] = x[i] + 0.5 * h * K[2][i];
    xp_sys(n, t+0.5*h, y, K[3]);
    for (i = 1; i <= n; i++)
      y[i] = x[i] + h * K[3][i];
    xp_sys(n, t+h, y, K[4]);
    for (i = 1; i <= n; i++)
      x[i] = x[i] + (h/6) * (K[1][i] + 2 * K[2][i] + 2 * K[3][i] + K[4][i]);
    t = t + h;
    printf("j = %2d, t = %1.2f, x = %1.7f\n", j, t, x[1]);
    printf("j = %2d, t = %1.2f, y = %1.7f\n", j, t, x[2]);
      }

  for (i = 0; i <= RK_order; i++)
    delete [] K[i]; 
}


