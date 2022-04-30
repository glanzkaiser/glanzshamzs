/****************************************************************/
/* Module : trapezoid.c						*/
/* Section: 5.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
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

float F (float x);

float F (float x)
{
  return (1.0/ exp(x * x));
}

void main()
{
  int n = 60;
  int i;
  float a = 0, b= 1.0;
  float h, sum, x;

  h = (b - a) /n;
  sum = 0.5 * (F(a) + F(b));
  for (i = 1 ; i < n ; i++)
  {
    x = a + i * h;
    sum += F(x);
  }
  sum = sum * h;
  printf("Sum = %15lf\n", sum);
}








