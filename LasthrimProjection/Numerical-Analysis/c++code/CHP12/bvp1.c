/****************************************************************/
/* Module : bvp1.c 						*/
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
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tri(int matrix_size, float *A, float *D, float *C, float *B, float *X);

inline float u(float x)
{
  return (exp(x) - 3 * sin(x));
}

inline float v(float x)
{
  return (-1.0);
}

inline float w(float x)
{
  return (1.0);
}


void main()
{
  const int n = 99;
  const float ta = 1.0,
              tb = 2.0,
	      alpha = 1.09737491,
	      beta = 8.63749661;
  float a[n+1], 
        b[n+1], 
        c[n+1],
        d[n+1], 
        y[n+1];
  int i;
  float error, h, t, x;
 
  h = (tb - ta) / n;
  for (i = 1 ; i < n ; i++)
  {
    t = ta + i * h;
    a[i] = - (1.0 + (h/2) * w(t));
    d[i] = 2.0 + h * h * v(t);
    c[i] = -(1.0 - (h/2) * w(t));
    b[i] = - h * h * u(t);
  }

  b[1] -= a[1] * alpha;
  b[n-1] -= c[n-1] * beta;
  for (i = 1; i < n; i++)
    a[i] = a[i+1];
  tri(n-1, a, d, c, b, y);
  error = exp(ta) - 3.0 * cos(ta) - alpha;
  printf("ta%13c solution%9c error\n");
  printf("%.7f %14.7f %14.2f\n", ta, alpha, error);
  for (i =9 ; i < n ; i+=9)
  {
    t = ta + i * h;
    error = exp(t) - 3.0 * cos(t) - y[i];
    printf("%.7f %14.7f %14.4e\n", t, y[i], error);
  }
  error = exp(tb) - 3.0 * cos(tb) - beta;
  printf("%.7f %14.7f %14.2f\n", tb, beta, error);
}

//------------------------------------------------------------------------
void tri( int n, float *a, float *d, float *c, float *b, float *x)
{
 int i;
 float xmult;

  for (i = 2; i <= n; i++)
  {
    xmult = a[i-1]/d[i-1];
    d[i] -= xmult * c[i-1];
    b[i] -= xmult * b[i-1];
  }
  x[n] = b[n]/d[n];
  for (i = n - 1; i >= 1; i--)
   x[i] = (b[i]- c[i]* x[i+1]) / d[i];

}






