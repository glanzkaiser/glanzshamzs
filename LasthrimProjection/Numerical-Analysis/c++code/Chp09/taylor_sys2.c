/****************************************************************/
/* Module : taylor_sys1.c 					*/
/* Section: 9.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*       							*/
/* Programmer: Tatyana Asriyan					*/
/* Description: Taylor series method for systems of ODEs.	*/
/*								*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  const int n = 2;
  const int nsteps = 100;
  const float a = 0.0, b = 1.0;
  float x[n+1];
  float d[n+1][4+1];
  int i, k;
  float h, t;

  t = 0.0;
  x[1] = 1.0;
  x[2] = 0.0;
  printf("0 t = %1.2f, x[1] = %1.2f, x[2] = %1.2f\n", t, x[1], x[2]);
  h = (b - a)/nsteps;
  for (k = 1; k <= nsteps; k++)
    {
      d[1][1] = x[1] - x[2] + t*(2 - t*(1 + t));
      d[2][1] = x[1] + x[2] + t*t*(-4 + t);
      d[1][2] = d[1][1] - d[2][1] + 2 - t*(2 + 3*t);
      d[2][2] = d[1][1] + d[2][1] + t*(-8 + 3*t);
      d[1][3] = d[1][2] - d[2][2] - 2 - 6*t;
      d[2][3] = d[1][2] + d[2][2] - 8 + 6*t;
      d[1][4] = d[1][3] - d[2][3] - 6;
      d[2][4] = d[1][3] + d[2][3] + 6;
      for (i = 1; i <= n; i++)
	x[i] = x[i] + h*(d[i][1] + h/2*(d[i][2] + h/3*(d[i][3] + h/4*d[i][4])));
      t += h;
      printf("k = %d, t = %1.3f, x[1] = %1.7f, x[2] = %1.7f\n", k, t, x[1], x[2]);
    }
  return 0;
}
