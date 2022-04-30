/****************************************************************/
/* Module : romberg.c 						*/
/* Section: 5.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Compute an integral using romberg array, tested */
/*		using 3 distinct functions			*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline float f(float x) { return (4.0/ (1.0 + x * x)); }
void romberg(float f(float ), float a, float b, int n, float** r);

void main()
{
  int n = 5;
  int i;
  float a = 0.0;
  float b = 1.0;
  float *r[n+1];

  for (i = 0; i <= n; i++)
    r[i] = new float[n+1];
  printf("The function is f(x) = 4/(1 + x*x)\n");
  romberg(f, a, b, n, r);
}

//------------------------------------------------------------------
void romberg(float f(float ), float a, float b, int n, float* r[])
{
  int i, j, k;
  float h, sum;

  h = b - a;
  r[0][0] = 0.5 * h * (f(a) + f(b));   
  printf("r[0][0] = %3.13lf\n", r[0][0]);
  for (i = 1; i <= n; i++)
  { 
     h *= 0.5;
     sum = 0.0;
     for (k = 1; k <= pow(2,i) - 1; k+=2)
       sum += f(a + k * h); 
     r[i][0] = 0.5 * r[i-1][0] + sum * h;  
      printf("r[%d][0] = %3.13lf\n", i, r[i][0]);
     for (j = 1; j <= i; j++)
     {
       r[i][j] = r[i][j-1] + (r[i][j-1] - r[i-1][j-1]) / (pow(4,j)-1); 
       printf("r[%d][%d] = %3.13lf\n", i,j, r[i][j]);
     }
   }
}









