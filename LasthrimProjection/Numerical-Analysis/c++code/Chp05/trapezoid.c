/****************************************************************/
/* Module : trapezoid.c						*/
/* Section: 5.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Compute an integral using trapezoid rule	*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline float f(float x) { return (1.0/ exp(x * x)); }

int main()
{
  const int n = 60;
  const float a = 0.0;
  const float b = 1.0;
  int i;
  float h, sum, x;

  h = (b - a) / n;
  sum = 0.5 * (f(a) + f(b));
  for (i = 1 ; i < n ; i++)
  {
    x = a + i * h;
    sum += f(x);
  }
  sum = sum * h;
  printf("Sum = %2.5lf\n", sum);
  return 0;
}










