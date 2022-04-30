/****************************************************************/
/* Module : taylor.c 						*/
/* Section: 8.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment:							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  const int n = 100;
  float a = 1.0, b = 2.0, x = -4.0;
  int k;
  float h, t, x1, x2, x3, x4;

  h = (b - a)/n;
  t = a;
  printf("0 x(%1.3f) = %1.5f\n", t, x);

  for (k = 1; k <= n; k++)
  {
    x1 = 1 + x*x + t*t*t;
    x2 = 2*x*x1 + 3*t*t;
    x3 = 2*x*x2 + 2*x1*x1 + 6*t;
    x4 = 2*x*x3 + 6*x1*x2 + 6;
    x += h*(x1 + h/2*(x2 + h/3*(x3 + h/4*x4)));
    t = a + k*h;
    printf("k = %d: x(%1.3f) = %1.5f\n", k, t, x);
  }
  return 0;
}









