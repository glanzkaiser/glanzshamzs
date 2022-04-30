/****************************************************************/
/* Module : loaded_die.c				        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Loaded die problem simulation                   */
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void _random(double* , int );

int main()
{
  const int n = 5000;
  double y[] = { 0.0, 0.2, 0.34, 0.56, 0.72, 0.89, 1.0 },
        m[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
        r[n+1];
  int i, j;
  
   _random(r, n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= 6; j++)
      if (r[i] <= y[j])
	{
	  m[j] = m[j] + 1;
	  break;
	}
  for (i = 1; i <= 6; i++)
    printf("m[%d] = %.1f\n", i, m[i]);
  return 0;
}

//--------------------------------------------
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
