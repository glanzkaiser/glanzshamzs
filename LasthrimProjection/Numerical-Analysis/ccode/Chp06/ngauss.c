/****************************************************************/
/* MODULE: ngauss.c 						*/
/* Section: 6.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed	*/
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*                                                              */
/* Description: Naive Gaussian elimination			*/
/* Programmer: Hidajaty Thajeb					*/
/* Programmer's comment: 					*/
/* Double is used for the vectors/matrices instead of   	*/
/* float; so, one should expect to obtain  			*/
/* double-precision answers.					*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void forward_elim(int, double **, double *, double *);
void back_subst(int, double **, double * , double *);

/*******************************************************/

void forward_elim (int matrix_size, double **A, double *B, double *X)
{
 int i,j,k;
 double xmult;

 for (k = 1; k < matrix_size; k++)
 {
  for (i = k +1; i <= matrix_size; i++)
   {
     xmult = A[i][k]/A[k][k];
     A[i][k] = xmult;
     for (j = k + 1; j <= matrix_size; j++)
       A[i][j] -= xmult * A[k][j];
     B[i] -= xmult * B[k];
    }
  }
X[matrix_size] = B[matrix_size]/A[matrix_size][matrix_size];

}

/**********************************************************/

void back_subst (int matrix_size, double **A, double *B, double *X)
{
  int i,j;

  double sum;

  for (i = matrix_size-1; i >= 1; i--)
  {
    sum = B[i];
    for (j = i+1; j <= matrix_size; j++)
      sum -= A[i][j] * X[j];
    X[i] = sum/A[i][i];
   }
}


/*************************************************************/

void main()
{
 double **A, *B, *X;
 int i,j, matrix_size;

  for (matrix_size = 4; matrix_size < 16; matrix_size++)
  {
    A = calloc((matrix_size+1), sizeof (double *));
    X = calloc((matrix_size+1), sizeof(double));
    B = calloc((matrix_size+1), sizeof(double));

    for (i = 0; i <= matrix_size; i++)
      A[i] = calloc((matrix_size+1),  sizeof(double));

    for (i = 1; i <=matrix_size; i++)
    {
      for (j = 1; j <= matrix_size; j++)
        A[i][j] = pow(i+1, j-1);
      B[i] = ((pow (i+1, matrix_size)) - 1)/ i;
    }
  forward_elim (matrix_size, A, B, X);
  back_subst (matrix_size, A,B,X);
  printf(" Size of square matrix = %d\n", matrix_size);
  printf(" Vector X =\n");
  for (i = 1; i <= matrix_size; i++)
    printf( "%14f\n", X[i]);
  printf( "=================\n");

  for (i = 0; i <= matrix_size; i++)
    free(A[i]);
  free(A);
  free(X);
  free(B);
    } 
}


