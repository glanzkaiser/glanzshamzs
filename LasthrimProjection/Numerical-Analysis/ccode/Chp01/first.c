/****************************************************************/
/* Module : first.c 						*/
/* Section: 1.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*         							*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Compute derivative of sin(x) using definition of*/
/*		limit.						*/
/* Comment: Short programming experiment			*/
/*								*/
/****************************************************************/

#include <math.h>
#include <stdio.h>


void main()
{
  const int n = 25;
  int i;
  float error, x, h, y;

  x = 0.5;
  h = 1.0;
  printf(" i          h           y            error\n");
  printf("-----------------------------------------------\n");
  for (i = 1; i <= n; i++)
  {
    h *= 0.25;
    y = (sin (x + h) - sin (x)) / h;
    error = fabs(cos(x) - y);
    printf("%d %14e %14e %14e\n", i, h, y, error);
  }

}










