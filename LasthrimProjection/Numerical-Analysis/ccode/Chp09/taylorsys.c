/****************************************************************/
/* Module : taylorsys.c 					*/
/* Section: 9.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
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
  int n = 2, nsteps = 100;
  int i, k;
  float a = 0, b= 1.0, h;
  float X[3][5] = { {0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 0} };

  h = (b - a) / nsteps;

  for (k = 1; k <= nsteps; k++)
  {
    X[1][1] = X[1][0] - X[2][0] + X[0][0] * (2 - X[0][0] * (1 + X[0][0]) );
    X[2][1] = X[1][0] + X[2][0] + X[0][0] * X[0][0] * (-4 + X[0][0]);
    X[1][2] = X[1][1] - X[2][1] + 2 - X[0][0] * (2 + 3 * X[0][0]);
    X[2][2] = X[1][1] + X[2][1] + X[0][0] * (-8 + 3 * X[0][0]);
    X[1][3] = X[1][2] - X[2][2] - 2 - 6 * X[0][0];
    X[2][3] = X[1][2] + X[2][2] - 8 + 6 * X[0][0];
    X[1][4] = X[1][3] - X[2][3] - 6;
    X[2][4] = X[1][3] + X[2][3] + 6;

    for (i = 0; i <= n; i++)
    {
      X[i][0] += h * (X[i][1] + 0.5 * h * ( X[i][2] + h/3 * (X[i][3] + 0.25 * h * X[i][4]))) ;
      printf("k = %d X[%d][0] = %f\n", k, i, X[i][0]);
    }

  }
}



