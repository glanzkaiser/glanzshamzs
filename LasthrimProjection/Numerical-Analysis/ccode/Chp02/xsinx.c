/****************************************************************/
/* Module : xsinx.c 						*/
/* Section: 2.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Example of programming f(x) = x - sin(x) using  */
/*		the function f.					*/
/* Comment: Use double instead of float.			*/
/*								*/
/****************************************************************/

#include <math.h>
#include <stdio.h>

float F(float); /* define prototype */


float F(float x)
{
  int n;
  float s, t;

  if ( fabs(x) >= 1.9) 
    s = x - sin(x);

  else
  {
    t = x * x * x /6.0;
    s = t;
    for (n = 1; n <= 9; n++)
    {
      t = -t * x * x / (float) ((2 * n + 2) * (2 * n + 3));
      s += t;
    }
  }

 return (s);

}

void main()
{
  double dx, dy, dz;
  float y, x;
  int n;

  dx = (double) 1.0/ (double) 15.0;
  dy = sin(dx);
  dz = dx - dy;
  printf("dx = %lf  dy = %lf  dz = %lf\n", dx, dy, dz);

  x = 16.0;
  for (n = 1; n <= 52; n++)
  {
    x *= 0.25;
    y = F(x);
    printf("n = %d  x = %1.14f  y = %1.14f\n" , n, x, y);
  }

  x = sin(1.0);
  y = F(1.0);
  printf("x = sin(1.0) = %1.14f  y = %1.14f\n", x, y);

}












