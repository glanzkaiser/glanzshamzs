/****************************************************************/
/* MODULE: penta.c                                              */
/* Section:                                                     */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

void penta(int, float*, float*, float*, float*, float*, float*, float*);

int main()
{
  const int m = 10; /* assume square matrix */
  float a[m+1], b[m+1], c[m+1], d[m+1], e[m+1], f[m+1], x[m+1];
  int i;

  /* setup matrix to test result */
  for (i = 1; i <= m; i++)
    {
      e[i] = 0.25;
      a[i] = 0.25;
      c[i] = 0.25;
      f[i] = 0.25;
      d[i] = 1.0;
      b[i] = 2.0;
    }

   b[1] = 1.5;  
   b[m] = 1.5;
   b[2] = 1.75;      
   b[m - 1] = 1.75;
  penta(m, e, a, d, c, f, b, x);
  printf(" Result from module PENTA\n");
  for (i = 1; i <= m; i++)
    printf( "%14f\n", x[i]);   
  printf("\n");
  return 0;
}

//------------------------------------------------------------------------------------
void penta(int n, float *e, float *a, float *d, float *c, float *f, float *b, float *x) 
{ 
  int i; 
  float xmult;
  for (i = 2; i < n; i++)
  {
    xmult = a[i-1]/d[i-1];
    d[i] -= xmult * c[i-1];
    c[i] -= xmult * f[i-1];
    b[i] -= xmult * b[i-1];
    xmult = e[i-1] / d[i-1];
    a[i] -= xmult * c[i-1];
    d[i+1] -= xmult * f[i-1];
    b[i+1] -= xmult * b[i-1];
  }
  xmult = a[n-1]/d[n-1];
  d[n] -= xmult * c[n-1];
  x[n] = (b[n] - xmult * d[n-1]) / d[n];
  x[n-1] = (b[n-1] - c[n-1] * x[n])/d[n-1];

  for (i = n - 2; i >= 1; i--)
   x[i] = (b[i]- f[i] * x[i+2] - c[i] * x[i+1]) / d[i];

} /* penta */




