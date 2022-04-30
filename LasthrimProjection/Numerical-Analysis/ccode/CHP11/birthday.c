/****************************************************************/
/* Module : birthday.c 						*/
/* Section: 11.3						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*       							*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Simulation of birthday problem.                 */
/*								*/
/* Comment:                                                     */
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef RAND_MAX
#define RAND_MAX 2147483648
#endif

#define false 0
#define true 1

int birthday(int n);
float probably(int n, int npts);

int birthday(int n)
{
  float *R;
  int days[366];
  int i, number;

  R = (float *)malloc((n+1) * sizeof(float));

  for (i = 1; i <= n; i++)
    R[i] = (float) rand() / (float) RAND_MAX;

  for (i = 1; i <= 365; i++)
    days[i] = false;

  for (i = 1; i <= n; i++)
  {
    number = (int) (365 * R[i] + 1);
    if (days[number])
      {
        free (R);
        return (true);
      }
    days[number] = true;
  }
  free(R);
  return(false);
}


float probably(int n, int npts)
{
   int i;
   float sum = 0;

   for (i = 1; i <= npts; i++)
   {
     if (birthday(n))
       sum++;
   }

   return (sum / (float) npts);

}


void main()
{
  const int n = 23;
  const int npts = 1000;
  int i;
  printf("Birthday Problem Simulation with n persons\n");
  printf("No. of persons = %d, No. of iterations = %d\n", n, npts);
  for (i = 1; i <= 10; i++)
    printf("Probability: %f\n", probably(n, npts));
}
