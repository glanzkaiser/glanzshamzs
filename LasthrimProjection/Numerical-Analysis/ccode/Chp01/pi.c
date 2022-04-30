/****************************************************************/
/* Module : pi.c 						*/
/* Section: 1.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*                                                              */
/* Programmer: Hidajaty Thajeb					*/
/* Description: Simple code to illustrate programming in double */
/*		precision.					*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <math.h>
#include <stdio.h>


void main()
{

  double pi;

  pi = 4.0 * atan( (double) (1.0));

  printf("The computed value of pi = %1.14lf\n", pi);


}










