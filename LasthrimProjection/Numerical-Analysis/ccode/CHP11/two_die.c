/****************************************************************/
/* Module : two_dice.c	        			        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Two dice problem simulation                     */
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
  const int n = 500;
  const int iprt = 100;
  float ***R, prob;
  int i, j, i1, i2, k, m = 0;


  R = calloc((n+1), sizeof(float **));

  for (i = 1; i <= n; i++)
  {
    R[i] = calloc((25), sizeof(float *));
    for (j = 1; j <= 24; j++)
       R[i][j] = calloc((3), sizeof(float));
  }

  for (i = 1; i <= n; i++)
    for (j = 1; j <= 24; j++)
      for (k = 1; k <= 2; k++)
        R[i][j][k] = (float) rand() / (float) RAND_MAX;


  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= 24; j++)
    {
      i1 = (int)(6 * R[i][j][1] + 1);
      i2 = (int)(6 * R[i][j][2] + 1);

      if (i1 + i2 == 12)
      {
        m++;
        break;
      }
    }

    if (!(i % iprt))
    {
      prob =  (float) m / (float) i;
      printf("i = %d, prob = %f\n", i, prob);
    }
  }

}
