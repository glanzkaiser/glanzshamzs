/****************************************************************/
/* MODULE: penta.c                                              */
/* Section:                                                     */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*                                                              */
/* Description: Solve pentagonal matrices                       */
/*                                                              */
/* Programmer: Hidajaty Thajeb                                  */
/* Comment: none                                                */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void penta(int matrix_size, float *E, float *A, float *D, float *C, float *F, float *B, float *X);

/****************************************************************/

void penta(int matrix_size, float *E, float *A, float *D, float *C, float *F, float *B, float *X) { int i; float xmult;
  for (i = 2; i < matrix_size; i++)
  {
    xmult = A[i-1]/D[i-1];
    D[i] -= xmult * C[i-1];
    C[i] -= xmult * F[i-1];
    B[i] -= xmult * B[i-1];
    xmult = E[i-1] / D[i-1];
    A[i] -= xmult * C[i-1];
    D[i+1] -= xmult * F[i-1];
    B[i+1] -= xmult * B[i-1];
  }
  xmult = A[matrix_size-1]/D[matrix_size-1];
  D[matrix_size] -= xmult * C[matrix_size -1];
  X[matrix_size] = (B[matrix_size] - xmult * B[matrix_size-1]) / D[matrix_size];
  X[matrix_size-1] = (B[matrix_size-1] - C[matrix_size-1] * X[matrix_size])/D[matrix_size-1];

  for (i = matrix_size -2; i>=1; i--)
   X[i] = (B[i]- F[i]* X[i+2] - C[i] * X[i+1]) / D[i];

} /* penta */

void main()
{
 float *A, *B, *C, *D, *E, *F, *X;
 int i, matrix_size;

matrix_size = 10; /* assume square matrix */

A = calloc((matrix_size+1), sizeof(float));
B = calloc((matrix_size+1), sizeof(float));
X = calloc((matrix_size+1), sizeof(float));
E = calloc((matrix_size+1), sizeof(float));

D = calloc((matrix_size+1), sizeof(float));
C = calloc((matrix_size+1), sizeof(float));
F = calloc((matrix_size+1), sizeof(float));


/* setup matrix to test result */
   for (i = 1; i <= matrix_size; i++)
    {
      E[i] = 0.25; A[i] = 0.25; C[i] = 0.25; F[i] = 0.25;
      D[i] = 1.0;  B[i] = 2.0;
    }
      B[1] = 1.5;       B[matrix_size] = 1.5;
      B[2] = 1.75;      B[matrix_size -1] = 1.75;

  penta(matrix_size, E, A, D, C, F, B, X);
  printf(" Result from module PENTA\n");
  for (i = 1; i <= matrix_size; i++)
   {
    printf( "%14f\n", X[i]);
   }
  printf("\n");
  for (i = 1; i <= matrix_size; i++)
   {
    D[i] = 2.0;
    A[i] = 0.5;
    C[i] = 0.5;
    B[i] = 3.0;
   }
  free(A);
  free(C);
  free(D);
  free(E);
  free(F);
  free(X);
  free(B);
}


