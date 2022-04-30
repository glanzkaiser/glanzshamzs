/****************************************************************/
/* Module : deriv.c 						*/
/* Section: 4.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Compute derivative using center differences and */
/*		Richardson extrapolation			*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F (float x);

void deriv  (float f(float), float x, int n, float h, float **D)
{
  int i, j;
  unsigned powerof4;

  for (i = 0; i <= n; i++)
  {
    D[i][0] = ( f(x+h) - f(x-h) ) / (2.0 * h);

    powerof4 = 1;
    for (j = 0; j < i; j++)
    {
       powerof4 <<= 2; /* this value is equivalent to pow(4,j+1) */
       D[i][j+1] = D[i][j] + (D[i][j] - D[i-1][j]) / (powerof4 -1); 
    }

    h *= 0.5;
  }
}

float F (float x)
{
  return (sin(x));
}

void main()
{
  int n = 10;
  int i, j;
  float h = 1.0;
  float **D, pi3, F(float);

  D = calloc((n+1), sizeof(float *));
  for (i=0; i<=n; i++)
    D[i] = calloc((n+1), sizeof(float));
  pi3 = 4.0 * atan(1.0)/3.0;
  deriv(F, pi3, n, h, D); /* to allow multiple functions to be called */

  /**********************************************************************/
  /* Programmer's comment:						*/
  /* if only one function will be called, there's no need to pass the	*/
  /* function as argument. In that case, the procedure deriv will have	*/
  /* this format: void deriv(float, int, float, float **)		*/
  /*									*/
  /**********************************************************************/

  for (i = 0; i < n; i++)
    for (j = 0; j <= i; j++)
      printf(" D[%d][%d] = %14f\n", i, j, D[i][j]);

  for (i=0; i<=n; i++)
    free(D[i]);
  free(D);
}







