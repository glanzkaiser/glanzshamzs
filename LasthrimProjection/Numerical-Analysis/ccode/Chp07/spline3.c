/****************************************************************/
/* MODULE: spline3.c						*/
/* Section: 7.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Description: Interpolates sin x at 10 equidistant knots using*/
/*              natural cubic spline                            */
/* Programmer: Hidajaty Thajeb					*/
/* Comment:							*/ 
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*******************************************************/

void spline3_coef (int n, float *T, float *Y, float *Z)
{
 float *H, *B, *U, *V;
 int i;
  
 U = calloc((n+1), sizeof(float));
 V = calloc((n+1), sizeof(float));
 B = calloc((n+1), sizeof(float));
 H = calloc((n+1), sizeof(float));

 for (i = 0; i < n; i++)
 {
  H[i] = T[i+1] -T[i];
  B[i] = (Y[i+1] - Y[i]) / H[i];
 }

U[1] = 2.0 * (H[0] +H[1]);
V[1] = 6.0 * (B[1] -B[0]);

 for (i = 2; i <n; i++)
 {
  U[i] = 2.0 * (H[i] + H[i+1]) - (H[i-1] * H[i-1]) /U[i-1];
  V[i] = 6.0 * (B[i] -B[i-1]) - (H[i-1] * V[i-1]) /U[i-1];
 }

 Z[n] = 0;
 
 for (i = n-1; i>= 1; i--)
   Z[i] = (V[i] - H[i] * Z[i+1]) / U[i];
 
 Z[0] = 0;

free(U);
free(V);
free(B);
free(H);

}

/**********************************************************/

float spline3_eval(int n, float *T, float *Y, float *Z, float x)
{
  int i;
  float h, tmp;

  for (i = n -1; i >= 1; i--)
  {
    if (x - T[i] >= 0)
      break;

  }

  h = T[i+1] -T[i];
  tmp = (Z[i] * 0.5) + (x - T[i]) * (Z[i+1] -Z[i])/ (6.0 * h);
  tmp = - (h /6.0) * (Z[i+1] + 2.0 * Z[i]) + (Y[i+1] -Y[i]) / h + (x - T[i]) * tmp;
  return (Y[i] + (x -T[i]) * tmp);
}


/*************************************************************/

void main()
{
 float a = 0, b = 1.6875;
 float *T, *Y, *Z;
 int  i;
 float d, h, x;
 int n = 9;

    T = calloc((n+1), sizeof(float));
    Y = calloc((n+1), sizeof(float));
    Z = calloc((n+1), sizeof(float));

    h = (b -a)/n;

    for (i = 0; i <= n; i++)
    { 
      T[i] = a + i* h;
      Y[i] = sin (T[i]);
    }
  spline3_coef(n, T, Y, Z);
 
  for (i = 0; i <= 4 * n; i++)
  {
    x = a + i * h/4;
    d = sin(x) - spline3_eval(n,T, Y, Z, x);
    printf(" i=%6d  x =%10f  d=%10f\n", i, x, d);
   }
 
  free(T);
  free(Y);
  free(Z);

}






