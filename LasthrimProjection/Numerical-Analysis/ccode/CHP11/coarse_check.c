/****************************************************************/
/* Module : coarse_check.c 						*/
/* Section: 11.1						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
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
#include <time.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

void main()
{
  const int n = 10000;
  int i, m = 0;
  float per, *R;

  srand(time(NULL)); /* randomize the seed (optional) */

  R = calloc((n+1), sizeof(float));

  for (i = 0; i <= n; i++)
    R[i] = (float) rand()/ (float) RAND_MAX;

  for (i = 1; i <= n; i++)
  {
    if (R[i] <= 0.5)
      m++;
    if (!(i % 1000))
    {
      per = 100 * (float) m/ (float) i;
      printf(" i = %d, per = %f\n", i, per);
    }
  }

  free(R);
}
