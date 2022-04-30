/****************************************************************/
/* Module : deriv.c 						*/
/* Section: 4.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

inline float f(float x) { return (sin(x)); }
void deriv  (float f(float ), float x, int n, float h, float** d);

int main()
{
  
  const int n = 10;
  const float h = 1.0;
  float x;
  float* d[n+1];
  int i, j;

  x = 1.2309594154;
  for (i = 0; i <= n; i++)
      d[i] = new float[n+1];

  deriv(f, x, n, h, d);
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++)
    printf("d[%d][%d] = %2.10f\n", i, j, d[i][j]); 

  for (i = 0; i <= n; i++)
    delete [] d[i]; 
  return 0;
}

//--------------------------------------------------------------
void deriv  (float f(float ), float x, int n, float h, float** d)
{
  int i, j;
 
  for (i = 0; i <= n; i++)
  {
    d[i][0] = ( f(x+h) - f(x-h) )/(2.0*h);
    for (j = 0; j <= i - 1; j++)
    {
       d[i][j+1] = d[i][j] + (d[i][j] - d[i-1][j])/(pow(4,j+1) - 1); 
    }
    h *= 0.5;
  }
}









