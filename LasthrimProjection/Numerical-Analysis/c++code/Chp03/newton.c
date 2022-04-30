/****************************************************************/
/* Module : newton.c 						*/
/* Section: 3.2							*/
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

inline float f(float x) { return ( ((x-2) * x + 1) * x - 3 ); }
inline float deriv_f(float x) {  return ( (3 * x - 4) * x + 1 ); }
void newton(float f(float ), float df(float ), float, int, float, float );

int main()
{
  const int n_max = 6;
  const float epsilon = 0.0000005;
  const float delta = 0.0000001;
  float x;

  x = 4.0;
  newton(f, deriv_f, x, n_max, epsilon, delta);
  return 0;
}

//-----------------------------------------------------------------------------------------------
void newton( float f(float), float deriv_f(float), float x, int n_max, float epsilon, float delta)
{
  int n;
  float d,fx, fp;
  inline float abs(float );

  fx = f(x);
  printf("   n	   x          f(x)\n");
  printf("   0%14f%14.1f\n", x, fx);

  for (n = 1; n <= n_max; n++)
  {
    fp = deriv_f(x);
    if (abs(fp) < delta)
      {
	printf("near root\n");
	return;
      }
    d = fx / fp;
    x = x - d;
    fx = f(x);
    printf("%4d%14f%14.7f\n",n, x, fx);
    if (abs(d) < epsilon)
      {
	printf("convergence\n");
	return;
      }
  }
}

//----------------------
float abs(float x)
{
  return x < 0 ? -x : x;
}





