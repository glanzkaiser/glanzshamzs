/****************************************************************/
/* Module : euler.c 						*/
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
 
inline float f(float t, float x){ return(1 + x*x + t*t*t); }

int main()
{
  const int n = 100;
  float a = 1.0, b = 2.0, x = -4.0;
  int k;
  float h, t;

  h = (b - a)/n;
  t = a;
  printf("0 x(%1.3f) = %1.5f\n", t, x);

  for (k = 1; k <= n; k++)
    {
      x += h * f(t, x);
      t += h;
      printf("k = %d: x(%1.3f) = %1.5f\n", k, t, x);
    }
  return 0;
}









