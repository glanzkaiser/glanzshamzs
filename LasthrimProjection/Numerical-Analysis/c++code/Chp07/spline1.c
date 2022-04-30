/****************************************************************/
/* MODULE: spline1.c						*/
/* Section: 7.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*        							*/
/* Description: Interpolates a table using a first-degree spline*/
/*		function					*/
/* Programmer: Hidajaty Thajeb					*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

float spline1(int, float*, float*, float );

int main()
{
  const int n = 18;
  int  i;
  float t[n+3] = {0.0, 0.0, 0.6, 1.5, 1.7, 1.9, 2.1, 2.3, 2.6, 2.8, 3.0, 
		  3.6, 4.7, 5.2, 5.7, 5.8, 6.0, 6.4, 6.9, 7.6, 8.0};

  float y[n+3] = {0.0, -0.8, -0.34, 0.59, 0.59, 0.23, 0.1, 0.28, 1.03,
                  1.5, 1.44, 0.74, -0.82, -1.27, -0.92, -0.92, -1.04,
                  -0.79, -0.06, 1.0, 0.0};
  float S[10]  = {0.0, spline1(n, t, y, 0.00), spline1(n, t, y, 1.00), spline1(n, t, y, 2.00), 
		       spline1(n, t, y, 3.00), spline1(n, t, y, 4.00), spline1(n, t, y, 5.00), 
		       spline1(n, t, y, 6.00), spline1(n, t, y, 7.00), spline1(n, t, y, 8.00)};
  
  for (i = 1; i < 10; i++)
    printf("S(%d) = %10f\n", i, S[i]);
  return 0;
}

//-----------------------------------------------
float spline1(int n, float* t, float* y, float x)
{
  int i;
  for (i = n - 1; i >= 0; i--)
    if (x - t[i] >= 0)
      break;
  printf(" i=%6d  x =%10f x-t[%d]=%10f\n", i, x, i, x-t[i]);
  return y[i] + (x - t[i]) * ((y[i+1] - y[i]) / (t[i+1] - t[i]));
}















