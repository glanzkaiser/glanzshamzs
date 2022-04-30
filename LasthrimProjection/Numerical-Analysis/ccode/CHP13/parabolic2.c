/****************************************************************/
/* Module : parabol2.c 						*/
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

void tri(int, float *, float *, float *, float *, float *);

void main()
{
  const int n = 10, m = 20;
  int i, j;
  float  *C, *D, *U, *V, pi, temp, neg_pi_square;
  float h = 0.1, k = 0.005;
  float r, s, t;

  C = calloc((n), sizeof(float));
  D = calloc((n), sizeof(float));
  U = calloc((n), sizeof(float));
  V = calloc((n), sizeof(float));

  pi = 4.0 * atan(1.0);
  neg_pi_square = -pi * pi;

  temp = pi * h; /* since this doesn't change, it 's more efficient */

  s = h * h / k;
  r = 2 + s;

  for (i = 1; i <= n - 1; i++)
  {
     D[i] = r;
     C[i] = -1.0;
     U[i] = sin(temp * i);
     printf("U[%d] = %f\n", i , U[i]);
  }

  for (j = 1; j <= m; j++)
  {
    for (i = 1; i <= n - 1; i++)
     {
       D[i] = r;
       V[i] = s * U[i];
     }

     tri(n-1, C, D, C, V, V);

     for (i = 1; i <= n - 1; i++)
       printf("V[%d] = %f\n", i, V[i]);

     t = j * k;

     for (i = 1; i <= n - 1; i++)
     {
       U[i] = exp (neg_pi_square * t) * sin(temp * i) - V[i];
       printf("U[%d] = %f\n", i, U[i]);
     }

     for (i = 1; i <= n - 1 ; i++)
       U[i] = V[i];
  }

  free(C);
  free(D);
  free(U);
  free(V);
}








/****************************************************************/
/* MODULE: tri.c                                                */
/* Section:                                                     */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed	*/
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*                                                              */
/* Description: Solve tridiagonal matrices                      */
/*                                                              */
/* Programmer: Hidajaty Thajeb                                  */
/* Comment: none                                                */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tri( int matrix_size, float *A, float *D, float *C, float *B, float *X);

/****************************************************************/

void tri( int matrix_size, float *A, float *D, float *C, float *B, float *X)
{
 int i;
 float xmult;

  for (i = 2; i <= matrix_size; i++)
  {
    xmult = A[i-1]/D[i-1];
    D[i] -= xmult * C[i-1];
    B[i] -= xmult * B[i-1];
  }
  X[matrix_size] = B[matrix_size]/D[matrix_size];
  for (i = matrix_size -1; i>=1; i--)
   X[i] = (B[i]- C[i]* X[i+1]) / D[i];

} /* tri */








