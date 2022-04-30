/****************************************************************/
/* Module : rec_simpson.c					*/
/* Section: 5.4							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

inline float f(float x) { return (cos (2 * x) / exp(x)); }
float simpson (float (float ), float, float, float, int, int);

void main()
{
  const float epsilon = 0.00005;
  int level = 0;
  int maxlevel = 20;
  float xmin = 0.0;
  float pi;
  float xmax;
  float result;
  
  pi = 4.0 * atan(1.0);
  xmax = 2.0 * pi;
  result = simpson(f, xmin, xmax, epsilon, level, maxlevel);
  printf("\n\nApproximate integral = %2.20lf\n\n", result);
}

//---------------------------------------------------------------------------------
float simpson (float f(float), float a, float b, float epsilon, int level, int level_max)
{
  float c, d, e, h;
  float one_simpson, 
        two_simpson, 
        simpson_result,
        left_simpson,
        right_simpson;

  level++;
  h = b - a;
  c = 0.5 * (a + b);

  one_simpson = h * (f(a) + 4 * f(c) + f(b)) / 6.0;
  d = 0.5 * (a + c);
  e = 0.5 * (c + b);
  two_simpson = h * (f(a) + 4 * f(d) + 2 * f(c) + 4 * f(e) + f(b)) / 12.0;
  if (level >= level_max)
  {
    simpson_result = two_simpson;
    printf("maximum level reached\n");
  }
  else
  {
    if ((fabs(two_simpson - one_simpson))  < 15.0 * epsilon)
      simpson_result = two_simpson + (two_simpson - one_simpson) / 15.0;
    else
      {
	left_simpson = simpson(f, a, c, epsilon/2, level, level_max);
	right_simpson = simpson(f, c, b, epsilon/2, level, level_max);
	simpson_result = left_simpson + right_simpson;
      }
   }
}





