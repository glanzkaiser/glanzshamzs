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
      D[i] = 2.0;
      A[i] = 0.5;
      C[i] = 0.5;
      B[i] = 3.0;
    }
  B[1] = 2.5;
  B[matrix_size] = 2.5;
  tri (matrix_size, A, D, C, B, X);
   printf(" Result from module tri (1)\n");
  for (i = 1; i <= matrix_size; i++)
   {
    printf( "%14f\n", X[i]);
    D[i] = 2.0;
    C[i] = 0.5;
    B[i] = 3.0;
   }

   printf("\n Result from module tri (2)\n");
   B[1] = 2.5;
   B[matrix_size] = 2.5;
   tri (matrix_size, C, D, C, B, X);
   for (i = 1; i <= matrix_size; i++)
     printf( "%14f\n", X[i]);

  free(A);
  free(C);
  free(D);
  free(E);
  free(F);
  free(X);
  free(B);
}






