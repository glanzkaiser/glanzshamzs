/****************************************************************/
/* Module : coef.c 						*/
/* Section: 4.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Newton interpolation polynomial for sin(x) at 	*/
/* equidistant points (9 intervals). Evaluate sin(x)-P(x) at 37 */
/* points							*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float eval(int n, float *X, float *Y, float t); /* define prototype */ 


void coef (int n, float *X, float *Y, float *A)
{
 int i, j;
 for (i = 0; i <= n; i++)
   A[i] = Y[i];
 for (j = 1; j <= n; j++)
   {
     for (i = n; i >= j; i--)
       A[i] = (A[i] - A[i-1]) / (X[i] - X[i-j]);
   }
}

float eval(int n, float *X, float *A, float t)
{
  int i;
  float temp;
  temp = A[n];
  for (i = n-1; i >=0 ; i--)
     temp = temp * (t - X[i]) + A[i];
  return (temp);
}

void main()
{
  int n = 9;
  int i;
  float h, t, d;
  float *X, *Y, *A;

  X = calloc((n+1), sizeof(float));
  Y = calloc((n+1), sizeof(float));
  A = calloc((n+1), sizeof(float));

  h = 1.6875/n;
  for (i = 0; i <= n; i++)
  { 
    X[i] = i * h;
    Y[i] = sin(X[i]);
  }
  coef(n, X, Y, A);
  for (i = 0; i <= n; i++) 
    printf(" A[%d] = %10.5e\n", i, A[i]);
  for (i = 0; i <= 4 * n; i++)
  {
     t = i * h * 0.25 ;
     d = sin(t) - eval(10, X, A, t);
     printf("i=%2d t=%15f d=%10.5e\n", i, t, d);
  }
  free(X);
  free(Y);
  free(A);
}
