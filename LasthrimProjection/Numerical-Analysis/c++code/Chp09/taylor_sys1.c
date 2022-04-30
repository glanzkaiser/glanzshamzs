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
/* Programmer: Hidajaty Thajeb					*/
/* Description: Taylor series method for systems of ODEs.	*/
/*								*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>


void main()
{
  const int nsteps = 100;
  const float a = 0.0, b = 1.0;
  int k;
  float h, t, x, y, x1, y1, x2, y2, x3, y3, x4, y4;

  x = 1.0;
  y = 0.0;
  t = a;
  printf("0 t = %1.2f, x = %1.2f, y = 1.2f\n", t, x, y);
  h = (b - a) / nsteps;
  for (k = 1; k <= nsteps; k++)
    {
      x1 = x - y + t*(2 - t*(1 + t));
      y1 = x + y + t*t*(-4 + t);
      x2 = x1 - y1 + 2 - t*(2 + 3*t);
      y2 = x1 + y1 + t*(-8 + 3*t);
      x3 = x2 - y2 - 2 - 6*t;
      y3 = x2 + y2 - 8 + 6*t;
      x4 = x3 - y3 - 6;
      y4 = x3 + y3 + 6;
      x = x + h*(x1 + h/2*(x2 + h/3*(x3 + h/4*x4)));
      y = y + h*(y1 + h/2*(y2 + h/3*(y3 + h/4*y4)));
      t += h;
      printf("k = %d, t = %1.3f, x = %1.7f, y = %1.7f\n", k, t, x, y);
    }
}



