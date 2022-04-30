/****************************************************************/
/* MODULE: jacobi.c 						*/
/* Section: 6.5							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Description:  Iterative solution of linear equations using 	*/
/*		 Jacobi method. 				*/
/*								*/
/* Programmer: Tatyana Asriyan					*/
/* Comment: example 1, page 306					*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void jacobi(int, float**, float* , float* );
void cp_vector(int, float* , const float* );
bool epsilon_comp(int, const float* );
float* sub_vector(int, const float* , const float* );

int main()
{
  const int n = 3;
  float *A[n+1];
  float b[n+1];
  float x[n+1];
  int i, j;

  for (i = 0; i <= n; i++)
    A[i] = new float[n+1];

  A[1][1] = 2; A[1][2] = -1; A[1][3] = 0;
  A[2][1] = -1;A[2][2] = 3;  A[2][3] = -1;
  A[3][1] = 0; A[3][2] = -1; A[3][3] = 2;
  b[1] = 1; b[2] = 8; b[3] = -5;
  x[1] = 0; x[2] = 0; x[3] = 0;
  printf("Let A be:\n");
  for (i = 1; i <= n; i++)
    {
      for(j = 1; j <= n; j++)
	printf("%2.0f", A[i][j]);
      printf("\n");
    }
  printf("Let b be:\n");
  for (i = 1; i <= n; i++)
    printf("%2.0f\n", b[i]);

  printf("Jacobi iteration:\n");
  jacobi(n, A, b, x);

  for (i = 0; i <= n; i++)
    delete [] A[i];
  return 0;
}

//------------------------------------------------
void jacobi(int n, float* A[], float* b, float* x)
{
  const int k_max = 100;
  const float delta = 0.0000000001;

  float y[n+1];
  int i, j, k;
  float diag, sum;

  for (k = 1; k <= k_max; k++)
    {
      cp_vector(n, y, x);
      for (i = 1; i <= n; i++)
	{
	  sum = b[i];
	  diag = A[i][i];
	  if (fabs(diag) < delta)
	    {
	      printf("diagonal element too small\n");
	      return;
	    }
	  for (j = 1; j <= n; j++)
	    if (j != i)
	      sum -= A[i][j]*y[j];
	  x[i] = sum/diag;
	   printf("%d:\tx[%d] = %2.4f\n", k, i, x[i]);
	}
      if (epsilon_comp(n, sub_vector(n, x, y)))
      	{
	  printf("k = %d\n", k);
	  for (i = 1; i <= n; i++)
	    printf("x[%d] = %2.4f\n", i, x[i]);
	  return;
	}
    }
  printf("maximum iterations reached\n");
  return;
}

//--------------------------------------------
void cp_vector(int size, float* y, const float* x)
{
  int i;

  for (i = 1; i <= size; i++)
    y[i] = x[i];
}

//---------------------------------------------
float* sub_vector(int size, const float* x, const float* y)
{
  int i;
  float* d;

  d = new float[size+1];
  for (i = 1; i <= size; i++)
    d[i] = x[i] - y[i];
  return d;  
}
//--------------------------------------------
bool epsilon_comp(int size, const float* x)
{
  const float epsilon = 0.00005;
  int i, count;
  
  count = 0;
  for (i = 1; i <= size; i++)
    if (x[i] < epsilon)
      count++;
  if (count == size)
      return true;
  else
    return false;
}
