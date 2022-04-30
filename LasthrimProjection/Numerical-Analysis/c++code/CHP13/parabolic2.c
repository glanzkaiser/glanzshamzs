/****************************************************************/
/* Module : parabol2.c 						*/
/* Section: 13.1						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tri(int, float *, float *, float *, float *, float *);

void main()
{
  const int n = 10, m = 20;
  const float h = 0.1, 
              k = 0.005,
              pi = 3.1415927;
  float c[n], d[n], u[n], v[n];
  int i, j;
  float r, s, t;

  s = h * h / k;
  r = 2 + s;

  for (i = 1; i <= n - 1; i++)
  {
     d[i] = r;
     c[i] = -1.0;
     u[i] = sin(pi*i*h);
     printf("u[%d] = %2.6f\n", i , u[i]);
  }

  for (j = 1; j <= m; j++)
  {
    for (i = 1; i <= n - 1; i++)
     {
       d[i] = r;
       v[i] = s * u[i];
     }

     tri(n-1, c, d, c, v, v);
     for (i = 1; i <= n - 1; i++)
       printf("v[%d] = %2.6f\n", i, v[i]);
     t = j * k;
     for (i = 1; i <= n - 1; i++)
     {
       u[i] = exp(-(pi*pi)*t) * sin(pi*i*h) - v[i];
       printf("u[%d] = %2.6f\n", i, u[i]);
     }
     for (i = 1; i <= n - 1 ; i++)
       u[i] = v[i];
  }
}

//--------------------------------------------------------------------------
void tri( int matrix_size, float *A, float *D, float *C, float *B, float *X)
{
 int i;
 float xmult;

  for (i = 2; i <= matrix_size; i++)
  {
    xmult = A[i-1]/D[i-1];
    D[i] -= xmult * C[i-1];
    B[i] -= xmult * B[i-1];
  }
  X[matrix_size] = B[matrix_size]/D[matrix_size];
  for (i = matrix_size -1; i>=1; i--)
   X[i] = (B[i]- C[i]* X[i+1]) / D[i];

} /* tri */








