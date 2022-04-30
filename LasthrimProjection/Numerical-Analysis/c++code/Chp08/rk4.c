/****************************************************************/
/* Module : RK4.c 						*/
/* Section: 8.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Implementation of classical Rundge-Kutta method	*/
/*              of order 4                                      */
/* Comment:							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

inline float f(float t, float x) { return 2 + (x - t - 1)*(x - t - 1); }
void rk4(float(float, float), float, float, float, int);

int main()
{
  const int n = 72;
  float a = 1.0, b = 1.5625, x = 2.0;
  float h, t;

  h = (b - a)/n;
  t = a;
  rk4(f, t, x, h, n);
  return 0;
}

//---------------------------------------------
void rk4(float f(float, float), float t, float x, float h, int n)
{
  int j;
  float K1, K2, K3, K4, ta;

  printf(" 0, x(%1.3f) = %1.5f\n", t, x);
  ta = t;
  for (j = 1; j <= n; j++)
  {
    K1 = h*f(t,x);
    K2 = h*f(t + h/2, x + K1/2);
    K3 = h*f(t + h/2, x + K2/2);
    K4 = h*f(t + h, x + K3);
    x += (K1 + 2*(K2 + K3) + K4)/6;
    t = ta + j*h;
    printf("j = %d: x(%1.4f) = %1.9f\n", j, t, x);
  }
}




