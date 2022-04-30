/****************************************************************/
/* Module : test_random.c        			        */
/* Section: 11.1			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Example to compute and print n random numbers   */
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

#define n 10

void main()
{
  double X[n+1];
  int i;

  srand(time(NULL)); /* use a random seed */
  for (i = 1; i <= n; i++)
  {
    X[i] = (float) rand() / (float) RAND_MAX;
    printf("X[%d] = %f\n", i, X[i]);
  }

}
