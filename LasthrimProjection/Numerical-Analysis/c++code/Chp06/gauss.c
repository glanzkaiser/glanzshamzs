/****************************************************************/
/* MODULE: gauss.c 						*/
/* Section: 6.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

void gauss(int, float** , int* );
void solve(int, float ** , int* , float* , float*);

int main()
{
  const int m = 4;
  float* a[m+1];
  float x[m+1];
  float b[m+1] = {0.0, -19.0, -34.0, 16.0, 26.0};
  int l[m+1];
  int i, j, n;

  for (i = 0; i <= m; i++)
    a[i] = new float[m+1];

  a[1][1] = 3.0;
  a[1][2] = -13.0;
  a[1][3] = 9.0;
  a[1][4] = 3.0;
  a[2][1] = -6.0;
  a[2][2] = 4.0;
  a[2][3] = 1.0;
  a[2][4] = -18.0;
  a[3][1] = 6.0;
  a[3][2] = -2.0;
  a[3][3] = 2.0;
  a[3][4] = 4.0;
  a[4][1] = 12.0;
  a[4][2] = -8.0;
  a[4][3] = 6.0;
  a[4][4] = 10.0;

  printf("Matrix A (4x4) = \n");
  for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= m; j++)
	printf("%4.0lf", a[i][j]);
      printf("\n");
    }
  gauss(m, a, l);
  printf("Matrix A after forward elimination = \n");
   for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= m; j++)
	printf("%4.0lf", a[i][j]);
      printf("\n");
    }
   solve(m, a, l, b, x);
   printf("Vector X = \n");
   for (i = 1; i <= m; i++)
     printf("%4.0lf\n", x[i]);

   for (i = 0; i <= m; i++)
    delete [] a[i];
   return 0;
} 

//-------------------------------------------------------
void solve (int n, float* a[], int* l, float* b, float* x)
{
  int i, j, k;
  float sum;
  
  for (k = 1; k <= n - 1; k++)
    for (i = k + 1; i <= n; i++)
      b[l[i]] -= a[l[i]][k] * b[l[k]];
  x[n] = b[l[n]] / a[l[n]][n];
  for (i = n - 1; i >= 1; i--)
    {
      sum = b[l[i]];
      for (j = i + 1; j <= n; j++)
	sum -= a[l[i]][j] * x[j];
      x[i] = sum / a[l[i]][i];
      }   
}

//-----------------------------------
void gauss(int n, float* a[], int* l)
{
  float* s;
  int i, j, k, temp_i, temp_k;
  float r, rmax, smax, xmult;
  
  s = new float [n+1];

  for (i = 1; i <= n; i++)
    {
      l[i] = i;
      smax = 0.0;
      for (j = 1; j <= n; j++)
	smax = max(smax, fabs(a[i][j]));
      s[i] = smax;
    }

  for (k = 1; k <= n - 1; k++)
    {
      rmax = 0.0;
      for (i = k; i <= n; i++)
	{
	  r = fabs(a[l[i]][k] / s[l[i]]);
	  if (r > rmax)
	    {
	      rmax = r;
	      j = i;
	    }
	}
      temp_k = l[j];
      l[j] = l[k];
      l[k] = temp_k;

      for (i = k + 1; i <= n; i++)
	{
	  xmult = a[l[i]][k] / a[l[k]][k];
	  a[l[i]][k] = xmult;
	  for (j = k + 1; j <= n; j++)
	    a[l[i]][j] -= xmult * a[l[k]][j];
	}
    }
    delete [] s; 
} 








