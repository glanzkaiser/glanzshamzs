/****************************************************************/
/* Module : RK4.c 						*/
/* Section: 8.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
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

float f(float t, float x); /* define prototype */


float f(float t, float x)
{
  return (2 + (x - t - 1) * (x - t - 1));
}


void rk4(float f(float, float), float t, float x, float h, int n)
{
  int k;
  float F1, F2, F3, F4, ta;

  ta = t;

  for (k = 1; k <= n; k++)
  {
    F1 = h * f(t,x);
    F2 = h * f(t + 0.5 * h, x + F1 * 0.5);
    F3 = h * f(t + 0.5 * h, x + F2 * 0.5);
    F4 = h * f(t + h, x + F3);
    x += (F1 + 2 * (F2 + F3) + F4) / 6;

    t = ta + k * h;

    printf("k = %d t = %f x = %f\n", k, t, x);
  }

}


void main()
{
  const int n = 72;
  const float a = 1.0, b = 1.5625;
  float h,t, x = 2.0;

  h = (b - a) / n;
  t = a;

  rk4 (f, t, x, h, n);

}






