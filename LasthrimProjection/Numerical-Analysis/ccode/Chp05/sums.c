/****************************************************************/
/* Module : sums.c 						*/
/* Section: 5.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Comment: Upper amd lower sums programming experiment for an  */
/* 	    integral						*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F (float x);

float F (float x)
{
  return (1.0/ exp(x * x));
}

void main()
{
  int n = 1000;
  int i;
  float a = 0, b= 1.0;
  float h, sum, sumL, sumU, x;

  h = (b - a) /n;
  sum = 0;
  for (i = n ; i >=1 ; i--)
  {
    x = a + i * h;
    sum += F(x);
  }
  sumL = sum * h;
  sumU = sumL + h * (F(a) - F(b));
  printf(" Lower sum = %15lf, Upper sum = %15lf\n", sumL, sumU);
}








