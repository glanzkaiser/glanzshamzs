/****************************************************************/
/* Module : shielding.c	        			        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Neutron shielding problem simulation            */
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

void main()
{
  const int n = 5000;
  const int iprt = 1000;
  float **R, pi, x, per;
  int i, j, m = 0;

  srand (time(NULL)); /* Use different seeds to generate random #s */

  pi = 4 * atan(1.0);

  R = calloc((n + 1), sizeof(float *));

  for (i = 1; i <= n; i++)
    R[i] = calloc((8), sizeof(float));

  for (i = 1; i <= n; i++)
    for (j = 1; j <= 7; j++)
      R[i][j] = (float) rand() / (float) RAND_MAX;

  for (i = 1; i <= n; i++)
  {
    x = 1;
    for (j = 1; j <= 7; j++)
    {
      x += cos(pi * R[i][j]);
      if (x <= 0)
        break;
      if (x >= 5)
      {
        m++;
        break;
      }
    }

    if (!(i % iprt))
    {
      per = 100 * (float) m / (float) i;
      printf("i = %d, percent = %f\n", i, per);
    }
  }
}
