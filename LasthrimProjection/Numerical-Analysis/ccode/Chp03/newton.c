/****************************************************************/
/* Module : newton.c 						*/
/* Section: 3.2							*/
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float f (float x)
{
  return ( ((x-2) * x + 1) * x - 3 );

}

float deriv_f (float x)
{
  return ( (3 * x - 4) * x + 1 );

}

void newton( float f(float), float deriv_f(float), float x, int m)
{
  int n;
  float fx;

  fx = f(x);
  printf("   n	   x          f(x)\n");
  printf("   0%14e%14e\n", x, fx);

  for (n = 1; n <= m; n++)
  {
    x = x - fx/ deriv_f(x);
    fx = f(x);
    printf("%4d%14e%14e\n",n, x, fx);

  }

}

void main()
{
  float x = 4.0;
  const int m = 20;

  newton(f, deriv_f, x, m);

}




