/****************************************************************/
/* Module : needle.c	        			        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Buffon's needle problem simulation              */
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

void main()
{
  const int n = 5000;
  const int iprt = 1000;
  float **R, w, v, prob, pi2;
  int i, j, m = 0;

  R = calloc((n+1), sizeof(float *));
  for (i = 1; i <= n; i++)
    R[i] = calloc((3), sizeof(float));

  pi2 = 2 * atan(1.0);

  for (i = 1; i <= n; i++)
    for (j = 1; j <= 2; j++)
      R[i][j] = (float) rand() / (float) RAND_MAX;

  for (i = 1; i <= n; i++)
  {
    w = R[i][1];
    v = pi2 * R[i][2];
    if (w <= sin(v))
      m++;
    if (!(i % iprt))
    {
      prob = (float) m / (float) i;
      printf("i = %d, prob = %f, 2/pi = %f\n", i, prob, 1/pi2);
    }
  }
}
