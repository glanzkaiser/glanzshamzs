/****************************************************************/
/* MODULE: ngauss.c 						*/
/* Section: 6.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed	*/
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*                                                              */
/* Description: Naive Gaussian elimination			*/
/* Programmer: Hidajaty Thajeb					*/
/* Programmer's comment: 					*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void naive_gauss(int , float** , float* , float* );

int main()
{
  const int m = 10;
  float* a[m+1];
  float b[m+1], x[m+1];
  int i, j, n;
  int temp_i, temp_j;
  for (i = 0; i <= m; i++)
    a[i] = new float[m+1];

  for (n = 4; n <= 10; n++)
    {
      for (i = 1; i <= n; i++)
	{
	  for (j = 1; j <= n; j++)
	    {
	      temp_i = i + 1;
	      temp_j = j - 1;
	      a[i][j] = pow(temp_i, temp_j);
	    }
	  b[i] = (pow(temp_i, n) - 1) / i;
	}
      naive_gauss(n, a, b, x);
      printf("n = %2d, x[%2d] = %2.7f\n", n, i-1, x[i-1]);
    }

   for (i = 0; i <= m; i++)
    delete [] a[i];
   return 0;
}

//-----------------------------------------------------
void naive_gauss(int n, float* a[], float* b, float* x)
{
  int i, j, k;
  float sum, xmult;
  
  for (k = 1; k <= n - 1; k++)
    {
      for (i = k + 1; i <= n; i++)
	{
	  xmult = a[i][k] / a[k][k];
	  a[i][k] = xmult;
	  for (j = k + 1; j <= n; j++)
	    a[i][j] -= xmult * a[k][j];
	  b[i] -= xmult * b[k];
	}
    }
  x[n] = b[n] / a[n][n];
  for (i = n - 1; i >= 1; i--)
    {
      sum = b[i];
      for (j = i + 1; j <= n; j++)
	sum -= a[i][j] * x[j];
      x[i] = sum / a[i][i];
    }
}





