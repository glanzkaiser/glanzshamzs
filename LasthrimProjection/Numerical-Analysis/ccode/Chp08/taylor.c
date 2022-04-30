
/****************************************************************/
/* Module : taylor.c 						*/
/* Section: 8.1							*/
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

void main()
{
  const int n = 100;
  const float a = 1.0, b = 2.0;
  int k;
  float h,t, x_one, x_two, x_three, x_four, x = -4.0;

  h = (b - a) / n;
  t = a;
  printf("0 t = %f x = %f\n", t, x);

  for (k = 1; k <= n; k++)
  {
    x_one = 1 + x * x + t * t * t;
    x_two = 2 * x * x_one + 3 * t * t;
    x_three = 2 * x * x_two + 2 * x_one * x_one + 6 * t;
    x_four = 2 * x * x_three + 6 * x_one * x_two + 6;
    x += h * (x_one + 0.5 * h * (x_two + h/3 * (x_three + 0.25 * h * x_four)));

    t = a + k * h;

    printf("k = %d t = %f x = %f\n", k, t, x);
  }
}









