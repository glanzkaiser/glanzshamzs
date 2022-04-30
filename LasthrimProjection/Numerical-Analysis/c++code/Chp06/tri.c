/****************************************************************/
/* MODULE: tri.c                                                */
/* Section:                                                     */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed	*/
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

void tri( int, float*, float*, float*, float*, float*);

int main()
{
  const int m = 10; /* assuming square matrix */
  float  a[m+1], b[m+1], c[m+1], d[m+1], e[m+1], f[m+1], x[m+1];      
  int i;

 /* setup matrix to test result */
  for (i = 1; i <= m; i++)
   {
      d[i] = 2.0;
      a[i] = 0.5;
      c[i] = 0.5;
      b[i] = 3.0;
    }
  b[1] = 2.5;
  b[m] = 2.5;
  tri (m, a, d, c, b, x);
   printf(" Result from module tri (1)\n");
  for (i = 1; i <= m; i++)
   {
    printf( "%14f\n", x[i]);
    d[i] = 2.0;
    c[i] = 0.5;
    b[i] = 3.0;
   }

   printf("\n Result from module tri (2)\n");
   b[1] = 2.5;
   b[m] = 2.5;
   tri (m, c, d, c, b, x);
   for (i = 1; i <= m; i++)
     printf( "%14f\n", x[i]);
   return 0;
}

//---------------------------------------------------------------
void tri( int n, float *a, float *d, float *c, float *b, float *x)
{
 int i;
 float xmult;

  for (i = 2; i <= n; i++)
  {
    xmult = a[i-1]/d[i-1];
    d[i] -= xmult * c[i-1];
    b[i] -= xmult * b[i-1];
  }
  x[n] = b[n]/d[n];
  for (i = n - 1; i >= 1; i--)
   x[i] = (b[i]- c[i]* x[i+1]) / d[i];

} /* tri */






