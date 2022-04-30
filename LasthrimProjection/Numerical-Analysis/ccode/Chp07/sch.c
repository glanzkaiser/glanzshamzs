/****************************************************************/
/* MODULE: sch.c                                                */
/* Section: 7.4							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Description: Schoenberg's Process                            */
/* Programmer: Hidajaty Thajeb                                  */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
  return (1.0 /(x * x + 1.0));
}

/*******************************************************/

void sch_coef (float a, float b, int n, float *D)
{
 float h;
 int i;

 h = (b - a) / n;

 for (i = 2; i <= n + 2 ; i++)
   D[i] = f(a + (i-2) * h);

 D[1] = 2.0 * D[2] - D[3];
 D[n+3] = 2.0 * D[n+2] - D[n+1];

}

/**********************************************************/

float sch_eval(float a, float b, int n, float *D, float x)
{
  int k;
  float c, e, h, p, w;

  h = (b -a)/n;
  k = (int) ((x -a)/h + 2.5);
  p = x -a - (k -2.5) * h;
  c = (D[k+1] * p + D[k] * (2 * h - p))/ (2 * h);
  e = (D[k] * (p + h) + D[k-1] * (h -p)) / (2 * h);
 
  return ( (c * p + e * (h - p)) / h);
}


/*************************************************************/

void main()
{

 float *D, *X, *Y, *Z, *E;
 int  j;
 float h;
 float a = -5.0, b= 5.0;
 int n = 20, m = 100;
 
 D = calloc((n+4), sizeof(float));
 X = calloc((m+1), sizeof(float));
 Y = calloc((m+1), sizeof(float));
 Z = calloc((m+1), sizeof(float));
 E = calloc((m+1), sizeof(float));

  sch_coef(a, b, n,D);
  printf("Here are the coefficients of D[i] for i = 1 to %d\n", n+3);
  for (j = 1; j <= n+3; j++)
     printf("D[%d]=%10f\n", j, D[j]);

  h = (b - a)/(float) m;
  for (j = 0; j <= m; j++)
  {
    X[j] = a + h * j;
    Y[j] = f(X[j]);
    Z[j] = sch_eval(a, b, n, D, X[j]);
    E[j] = Y[j] - Z[j];
    printf("X[%d]=%11f Y[%d]=%11f Z[%d]=%11f E[%d]= %11f\n",j,X[j],j,Y[j],j,Z[j],j,E[j]);

  }
  free(D);
  free(X);
  free(Y);
  free(Z);
  free(E);
}
