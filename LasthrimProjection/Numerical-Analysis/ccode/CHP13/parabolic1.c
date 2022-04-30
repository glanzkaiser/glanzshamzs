/****************************************************************/
/* Module : parabol1.c 						*/
/* Section: 13.1						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
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

void main()
{
  const int n = 10, m = 20;
  int i, j;
  float *U, *V, pi, t, temp, neg_pi_square;
  float h = 0.1, k = 0.005;

  U = calloc((n+1), sizeof(float));
  V = calloc((n+1), sizeof(float));

  U[0] = U[n] = 0;
  V[0] = V[n] = 0;

  pi = 4.0 * atan(1.0);
  neg_pi_square = -pi * pi;

  temp = pi * h; /* since this doesn't change, it 's more efficient */

  for (i = 1; i <= n - 1; i++)
  {
     U[i] = sin(temp * i);
     printf("U[%d] = %f\n", i , U[i]);
  }

  for (j = 1; j <= m; j++)
  {
     for (i = 1; i <= n - 1; i++)
     {
       V[i] = (U[i-1]  + U[i+1]) * 0.5;
       printf("V[%d] = %f\n", i, V[i]);
     }

     t = j * k;

     for (i = 1; i <= n - 1; i++)
     {
       U[i] = exp (neg_pi_square * t) * sin(temp * i) - V[i];
       printf("U[%d] = %f\n", i, U[i]);
     }

     for (i = 1; i <= n - 1 ; i++)
       U[i] = V[i];
  }
  free(U);
  free(V);
}








