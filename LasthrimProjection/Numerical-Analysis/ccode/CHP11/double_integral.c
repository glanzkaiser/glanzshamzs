/****************************************************************/
/* Module : double_integral.c					*/
/* Section: 11.2					        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Integral over a disk in XY-space by Monte Carlo */
/*		method.						*/
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

#define sq(X) (X) * (X)
#define n 5000
#define iprt 1000

float F(float x, float y);


float F(float x, float y)
{
  return (sin (sqrt(log(x + y + 1))));
}


void main()
{
  int i, j= 1 ;
  float R[n+1][3], sum = 0, vol, x, y, pi4;

  pi4 = atan(1.0);

  for (i = 0; i <= n; i++)
    for (j = 0; j <= 2; j++)
       R[i][j] = (float) rand() / (float) RAND_MAX;
                             /* generate random # for 0..1 */
  for (i = 1; i <= n; i++)
  {
    x = R[i][1];
    y = R[i][2];

    if ( sq(x - 0.5) + sq(y - 0.5)  <= 0.25 )
    {
      j++;
      sum += F(x,y);
      if (!(j % iprt))
      {
         vol = pi4 * sum / (float) j;
         printf("j = %d, vol = %f\n", j, vol);
      }
    }
  }

  vol = pi4 * sum / (float) j;
  printf("j = %d, vol = %f\n", j, vol);
}



