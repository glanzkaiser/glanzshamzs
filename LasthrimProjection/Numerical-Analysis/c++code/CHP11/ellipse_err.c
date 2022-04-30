/****************************************************************/
/* Module : ellipse.c 	  				        */
/* Section: 11.1						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Illustrates correct use of procedure Random     */
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/*                                                              */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void _random(double*, int);

int main()
{
  const int n = 1000;
  double x[n+1],
         y[n+1],
         *r[2+1];
  int i;

  for (i = 1; i <= 2; i++)
    {
      r[i] = new double[n+1];
      _random(r[i], n);
    }
  for (i = 1; i <= n; i++)
    {
      x[i] = 4*r[1][i] - 2;
      y[i] = ((2*r[2][i] - 1)/2)*sqrt(4 - x[i]*x[i]);
      printf("x[%d] = %.7f, y[%d] = %.7f\n", i, x[i], i, y[i]);
    }
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
