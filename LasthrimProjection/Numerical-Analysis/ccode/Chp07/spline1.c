/****************************************************************/
/* MODULE: spline1.c						*/
/* Section: 7.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*        							*/
/* Description: Interpolates a table using a first-degree spline*/
/*		function					*/
/* Programmer: Hidajaty Thajeb					*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************/

float spline1(int n, float *T, float *Y, float x)
{
  int i;

  for (i = n -1; i >= 1; i--)
  {
    if (x - T[i] >= 0)
      break;

  }
  printf(" i=%6d  x =%10f x-T[%d]=%10f\n", i, x, i, x-T[i]);

  return (Y[i] + (x -T[i]) *  ((Y[i+1] - Y[i]) / (T[i+1] -T[i]) ) );
}


/*************************************************************/

void main()
{

 float *T, *Y;
 float Z[12];
 int  i;

 int n = 4;

    T = calloc((n+2), sizeof(float));
    Y = calloc((n+2), sizeof(float));
    T[1] = 1.0;
    T[2] = 2.0;
    T[3] = 3.0;
    T[4] = 4.0;
    T[5] = 5.0;
    Y[1] = 0;
    Y[2] = 1.0;
    Y[3] = 0;
    Y[4] = 1.0;
    Y[5] = 0;

    Z[1] = spline1(n, T, Y, 1.0);
    Z[2] = spline1(n, T, Y, 2.0);
    Z[3] = spline1(n, T, Y, 3.0);
    Z[4] = spline1(n, T, Y, 4.0);
    Z[5] = spline1(n, T, Y, 5.0);
    Z[6] = spline1(n, T, Y, -0.5);
    Z[7] = spline1(n, T, Y, 1.25);
    Z[8] = spline1(n, T, Y, 2.75);
    Z[9] = spline1(n, T, Y, 3.5);
    Z[10] = spline1(n, T, Y, 4.25);
    Z[11] = spline1(n, T, Y, 5.5);

    for (i = 1; i< 12; i++)
      printf("Z[%d]=%10f\n", i, Z[i]);

  free(T);
  free(Y);

}












