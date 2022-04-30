/****************************************************************/
/* Module : cone.c					        */
/* Section: 11.2					        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Ice cream cone example                          */
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

#define n 5000
#define iprt 1000

#define sq(X) (X) * (X)

void main()
{
  int i, j, m = 0 ;
  float **R, vol = 0, x, y, z;

  R = calloc((n+1), sizeof(float *));
  for (i = 1; i <= n; i++)
    R[i] = calloc((4), sizeof(float));

  for (i = 1; i <= n; i++)
    for (j = 1; j <= 3; j++)
       R[i][j] = (float) rand() / (float) RAND_MAX;

  for (i = 1; i <= n; i++)
  {
    x = 2 * R[i][1] - 1;
    y = 2 * R[i][2] - 1;
    z = 2 * R[i][3];

    if ( (sq (x) + sq(y) <= sq(z)) && (sq(x) + sq(y) <= z * (2 - z)))
      m++;
    if (!(i % iprt))
    {
      vol = 8 * (float) m / (float) i;
      printf("i = %d, vol = %f\n", i, vol);
    }
  }

  for (i = 0; i <= n; i++)
    free(R[i]);
  free(R);

}
