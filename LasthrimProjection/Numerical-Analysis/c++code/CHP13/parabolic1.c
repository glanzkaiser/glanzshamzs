/****************************************************************/
/* Module : parabol1.c 						*/
/* Section: 13.1						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  const int n = 10, m = 20;
  const float h = 0.1,
              k = 0.005,
              pi = 3.1415927;
  const float u0 = 0, 
              v0 = 0,
              un = 0,
              vn = 0;
  float u[n+1], v[n+1];
  int i, j;
  float t;

  for (i = 1; i <= n - 1; i++)
    {
      u[i] = sin(pi*i*h);
      printf("u[%d] = %2.6f\n ", i, u[i]);
    }
  for (j = 1; j <= m; j++)
    {
      for (i = 1; i <= n - 1; i++)
	{
	  v[i] = (u[i-1] + u[i+1])/2;
	  printf("v[%d] = %2.6f\n", i, v[i]);
	}
      t = j * k;
      for (i = 1; i <= n - 1; i++)
	{
	  u[i] = exp(-(pi*pi)*t) * sin(pi*i*h) - v[i];
	  printf("u[%d] = %2.6f\n", i, u[i]);
	}
      for (i = 1; i <= n - 1; i++)
	u[i] = v[i];
    }
  return 0;
}




