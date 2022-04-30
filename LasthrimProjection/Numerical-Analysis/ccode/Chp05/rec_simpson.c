/****************************************************************/
/* Module : rec_simpson.c					*/
/* Section: 5.4							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Compute an integral by simpson's rule, using	*/
/*		recursion					*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F (float x);


float F (float x)
{
  return (cos (2 * x) / exp(x));
}


float simpson (float f(float), float a, float b, float eps, int level, int maxlevel)
{

  float c, d, e, h;
  float one_simpson, two_simpson;

  level++;
  h = b - a;
  c = 0.5 * (a + b);

  one_simpson = h * (f(a) + 4 * f(c) + f(b)) / 6.0;
  d = 0.5 * (a + c);
  e = 0.5 * (c + b);
  two_simpson = h * (f(a) + 4 * f(d) + 2 * f(c) + 4 * f(e) + f(b)) / 12.0;

  if (level >= maxlevel)
  {
    printf("Error: exceeds maxlevel\n");
    return (two_simpson);
  }
  else
  {
    if ((fabs(two_simpson - one_simpson))  <= 15.0 * eps)
       return (two_simpson);
    else
       return( (simpson (f, a, c, 0.5 * eps, level, maxlevel)) +
              (simpson (f, c, b, 0.5 * eps, level, maxlevel)) );
  }
}


void main()
{
  int level = 0, maxlevel = 20;
  int i;
  float F(float), pi, result;
  float xmin = 0, xmax, epsilon = 0.00005;

  pi = 4.0 * atan(1.0);
  xmax = 2.0 * pi;
  result = simpson(F, xmin, xmax, epsilon, level, maxlevel);
  printf("Approximate integral = %f\n", result);
}




