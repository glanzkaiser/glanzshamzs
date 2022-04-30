/****************************************************************/
/* Module : loaded_die.c				        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Loaded die problem simulation                   */
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

void main()
{
  const int n = 5000;
  int i, j;
  float Y[] = {0, 0.2, 0.34, 0.56, 0.72, 0.89, 1.0};
  float M[] = {0, 0, 0, 0, 0, 0, 0};
  float *R, x, y;

  R = calloc((n+1), sizeof(float));

  for (i = 0; i <= n; i++)
     R[i] = (float) rand() / (float) RAND_MAX;

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= 6; j++)
    {
      if ( R[i] < Y[j])
      {
        M[j]++;
        break;
      }
    }
  }

  for (i = 1; i <= 6; i++)
    printf("M[%d] = %f\n", i, M[i]);
}
