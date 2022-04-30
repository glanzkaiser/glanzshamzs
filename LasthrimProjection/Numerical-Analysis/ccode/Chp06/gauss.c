/****************************************************************/
/* MODULE: gauss.c 						*/
/* Section: 6.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Description: Gaussian elimination with scaled partial 	*/
/*		pivoting					*/
/*								*/
/* Programmer: Hidajaty Thajeb					*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a > b) ? a : b

void forward_elim(int, float **, int *);
void solve(int, float **, int *, float * , float *);

/*******************************************************/

void forward_elim (int matrix_size, float **A, int *L)
{
 int i,j,k, tempi, tempk;
 float *S;
 float xmult, smax, rmax, ratio;

 S = calloc((matrix_size+1), sizeof(float));

 for (i = 1; i <= matrix_size; i++)
 {
     L[i] = i;
     smax = 0.0;
     for (j = 1; j <= matrix_size; j++)
       smax = max (smax, fabs(A[i][j]));
     S[i] = smax;
 }

  for (k = 1; k < matrix_size; k++)
  {
    rmax = 0.0;
    for (i = k ; i <= matrix_size; i++)
     { 
       tempi = L[i];
       ratio = fabs(A[tempi][k]/ S[tempi]);
       if (ratio > rmax) 
       {
        rmax = ratio;
        j = i;
       }
     }

   tempk = L[j];
   L[j] = L[k];
   L[k] = tempk;

   for (i = k+1; i <= matrix_size; i++)
   { 
     tempi = L[i];
   
     xmult = A[tempi][k] /A[tempk][k];
     A[tempi][k] = xmult;
     for (j = k+1; j<= matrix_size; j++)
       A[tempi][j] -= xmult * A[tempk][j];
     /*A[tempi][k] = xmult;*/
   }  
  }

}/* forward_elim */

/**********************************************************/

void solve (int matrix_size, float **A, int *L, float *B, float *X)
{
  int i,j, k, tempi, tempk, tempn;

  float sum;

  for (k = 1; k < matrix_size ; k++)
  {
    tempk = L[k];
    for (i = k+1; i <= matrix_size; i++)
    {
      tempi = L[i];
      
      B[tempi] -= A[tempi][k] * B[tempk];
    }
  }
 tempn = L[matrix_size];
 X[matrix_size] = B[tempn] / A[tempn][matrix_size];

 for (i = matrix_size -1; i>= 1; i--)
 {  
   tempi = L[i];
   sum = B[tempi];
   for (j = i+1; j <= matrix_size ; j++)
     sum -= A[tempi][j] * X[j];
   X[i] = sum / A[tempi][i];
 }
}


void main()
{
 float **A, *B, *X;
 int *L;
 int i,j, matrix_size;

matrix_size = 4; /* assume square matrix */

A = calloc((matrix_size+1), sizeof (float *));
B = calloc((matrix_size+1), sizeof(float));
X = calloc((matrix_size+1), sizeof(float));
L = calloc((matrix_size+1), sizeof(float));

   for (i = 0; i <= matrix_size; i++)
      A[i] = calloc((matrix_size+1),  sizeof(float));

/* setup matrix to test result */
A[1][1] = 2.0; A[1][2] = 3.0; A[1][3] = -4.0; A[1][4] = 1.0;
A[2][1] = 1.0; A[2][2] = -1.0; A[2][3] = 0; A[2][4] = -2.0;
A[3][1] = 3.0; A[3][2] = 3.0; A[3][3] = 4.0; A[3][4] = 3.0;
A[4][1] = 4.0; A[4][2] = 1.0; A[4][3] = 0; A[4][4] = 4.0;
B[1] = -2.0; B[2] = -7.0; B[3] = 20.0; B[4] = 13.0;

  forward_elim (matrix_size, A, L);
  printf(" Matrix A after forward_elimination\n");
  for (i = 1; i <= matrix_size; i++)
   {
    for (j = 1; j <= matrix_size; j++)
      printf( "%14f ", A[i][j]);
    printf("\n");
   }
  solve (matrix_size, A, L,B,X);
  printf(" Size of square matrix = %d\n", matrix_size);
  printf(" Vector X =\n");
  for (i = 1; i <= matrix_size; i++)
    printf( "%14f\n", X[i]);

  for (i = 0; i <= matrix_size; i++)
    free(A[i]);
  free(A);
  free(X);
  free(B);
  free(L);
} 









