/****************************************************************/
/* Module : coarse_check.c 					*/
/* Section: 11.1						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Coarse check on the random-number generator     */
/*								*/
/* Comment:*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void _random(double* , int );

int main()
{
  const int n = 10000;
  int i, m;
  double per;
  double r[n+1];

  m = 0;
  _random(r, n);
  for (i = 1; i <= n; i++)
    {
      if (r[i] <= 0.5)
	m = m + 1;
      if ( (i%1000) == 0)
	{
	  per = 100*(double)m/(double)n;
	  printf("\ti = %d, per = %.7f\n",i, per);
	}
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
