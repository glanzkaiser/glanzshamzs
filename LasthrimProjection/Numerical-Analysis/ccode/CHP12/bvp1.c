/****************************************************************/
/* Module : bvp1.c 						*/
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
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float u (float x);
float v (float x);
float w (float x);
void tri (int matrix_size, float *A, float *D, float *C, float *B, float *X);

float u (float x)
{
  return (exp(x) - 3 * sin(x));
}

float v (float x)
{
  return (-1.0);
}

float w (float x)
{
  return (1.0);
}

void tri (int matrix_size, float *A, float *D, float *C, float *B, float *X)
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

void main()
{
  int n = 99;
  int i;
  float ta = 1.0, tb= 2.0, alpha = 1.09737491, beta=8.63749661;
  float *A, *B, *C, *D;
  float error, h, t, u(float), v(float),w(float), x;

  A = calloc((n+1), sizeof(float));
  B = calloc((n+1), sizeof(float));
  C = calloc((n+1), sizeof(float));
  D = calloc((n+1), sizeof(float));

  h = (tb - ta) / n;
  for (i = 1 ; i < n ; i++)
  {
    t = ta + i * h;
    A[i] = -1.0 - 0.5 * h * w(t);
    D[i] = 2.0 + h * h * v(t);
    C[i] = -1.0 + 0.5 * h * w(t);
    B[i] = -h * h * u(t);
  }

  B[1] -= A[1] * alpha;
  B[n-1] -= C[n-1] * beta;
  for (i= 1; i < n; i++)
    A[i] = A[i+1];
  tri(n-1, A, D, C, B, B);
  error = exp(ta) - 3.0 * cos(ta) - alpha;
  printf("ta = %14f, alpha= %14f, error= %14f\n", ta, alpha, error);
  for (i=9; i < n ; i+=9)
  {
    t = ta + i * h;
    error = exp(t) - 3.0 * cos(t) - B[i];
    printf("t = %14f, B[%d] = %14f, error= %14f\n", t, i, B[i], error);  
  }
  error = exp(tb) - 3.0 * cos(tb) - beta;
  printf("tb = %14f, beta = %14f, error = %14f\n", tb, beta, error);

  free(A);
  free(B);
  free(C);
  free(D);

}








