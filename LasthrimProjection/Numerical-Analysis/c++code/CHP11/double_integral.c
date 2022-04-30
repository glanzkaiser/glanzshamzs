/****************************************************************/
/* Module : double_integral.c					*/
/* Section: 11.2					        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Integral over a disk in XY-space by Monte Carlo */
/*		method.						*/
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline double sqr(double x) { return x*x; }
inline double f(double x, double y) { return sin(sqrt(log(x + y + 1))); }
void _random(double* x, int n);

int main()
{
  const int n = 5000,
            iprt = 1000;
  double* r[2+1];
  int i, j;
  double sum, vol, x, y, pi;
  
  for (i = 1; i <= 2; i++)
    {
      r[i] = new double[n+1];
      _random(r[i], n);
    }
  pi = 4.0*atan(1.0);
  j = 0;
  sum = 0;
  for (i = 1; i <= n; i++)
    {
      x = r[1][i];
      y = r[2][i];
      if ( sqr(x - 0.5) + sqr(y - 0.5) <= 0.25 )
	{
	  j++;
	  sum += f(x, y);
	  if ( (j%iprt) == 0)
	    {
	      vol = atan(1.0)*sum/(double)j;
	      printf("j = %d, vol = %.7f\n", j, vol);
	    }
	}
    }
   vol = atan(1.0)*sum/(double)j;
   printf("j = %d, vol = %.7f\n", j, vol);
  return 0;
}

//--------------------------------
void _random(double* x, int n)
{
  const long long k = 16807;
  const long long j = 2147483647;
  long long seed;
  int i;

  seed = 40699;
  for (i = 1; i <= n; i++)
    {
      seed = (seed*k)%j;
      x[i] = (long double)seed/(long double)j;
    }
}
