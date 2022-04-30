/****************************************************************/
/* Module : sums.c 						*/
/* Section: 5.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Comment: Upper amd lower sums programming experiment for an  */
/* 	    integral						*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline float f(float x) {return (1.0/ exp(x * x)); }

int main()
{
  const int n = 1000;
  const float a = 0.0;
  const float b = 1.0;
  int i;
  float h, sum, sum_lower, sum_upper, x;

  h = (b - a) / n;
  sum = 0;
  for (i = n ; i >=1 ; i--)
  {
    x = a + i * h;
    sum += f(x);
  }
  sum_lower = sum * h;
  sum_upper = sum_lower + h * (f(a) - f(b));
  printf(" Lower sum = %2.5lf, Upper sum = %2.5lf\n", sum_lower, sum_upper);
  return 0;
}







