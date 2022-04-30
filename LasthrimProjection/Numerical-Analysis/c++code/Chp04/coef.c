/****************************************************************/
/* Module : coef.c 						*/
/* Section: 4.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

float eval(int, float*, float*, float );
void coef (int, float*, float*, float* );

int main()
{
  const int n = 9;
  float x[n+1], y[n+1], a[n+1];
  int j, k;
  float e, h, p, t;
 
  h = 1.6875/n;
  for (k = 0; k <= n; k++)
  { 
    x[k] = k*h;
    y[k] = sin(x[k]);
  }
  coef(n, x, y, a);
  for (k = 0; k <= n; k++) 
    printf(" a[%d] = %10.7e\n", k, a[k]);

  for (j = 0; j <= 4*n; j++)
  {
     t = j*h/4;
     p = eval(10, x, a, t);
     e = fabs(sin(t) - p);
     printf("j = %2d, t = %2f, p = %10.6e, e = %10.5e \n", j, t, p, e);
  }
  return 0;
}

//---------------------------------------------
void coef (int n, float* x, float* y, float* a)
{
 int i, j;
 for (i = 0; i <= n; i++)
   a[i] = y[i];
 for (j = 1; j <= n; j++)  
     for (i = n; i >= j; i--)
       a[i] = (a[i] - a[i-1]) / (x[i] - x[i-j]);   
}

//--------------------------------------------
float eval(int n, float *x, float *a, float t)
{
  int i;
  float temp;
  temp = a[n];
  for (i = n - 1; i >= 0 ; i--)
     temp = temp*(t - x[i]) + a[i];
  return (temp);
}


