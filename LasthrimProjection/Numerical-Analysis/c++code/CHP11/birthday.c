/****************************************************************/
/* Module : birthday.c 						*/
/* Section: 11.3						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*       							*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Simulation of birthday problem.                 */
/*								*/
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>

float probably(int, int );
int main()
{
 
  const int npts = 1000;
  int i;
  printf("Birthday Problem Simulation with n persons\n");
  printf("\tn \tsimulation results\n");
  printf("\t%d \t%.3f\n", 5, probably(5, npts));
  printf("\t%d \t%.3f\n", 10, probably(10, npts));
  printf("\t%d \t%.3f\n", 15, probably(15, npts));
  printf("\t%d \t%.3f\n", 20, probably(20, npts));
  printf("\t%d \t%.3f\n", 22, probably(22, npts));
  printf("\t%d \t%.3f\n", 23, probably(23, npts));
  printf("\t%d \t%.3f\n", 25, probably(25, npts));
  printf("\t%d \t%.3f\n", 30, probably(30, npts));
  printf("\t%d \t%.3f\n", 35, probably(35, npts));
  printf("\t%d \t%.3f\n", 40, probably(40, npts));
  printf("\t%d \t%.3f\n", 45, probably(45, npts));
  printf("\t%d \t%.3f\n", 50, probably(50, npts));
  printf("\t%d \t%.3f\n", 55, probably(55, npts));
  return 0;
}

//--------------------------------------------------
float probably(int n, int npts)
{
  int i;
  float sum;
  bool birthday(int );

  sum = 0;
  for (i = 1; i <= npts; i++)
    if (birthday(n))
      sum++;
  return sum/(float)npts;  
}

//--------------------------------------------------
int birthday(int n)
{
  const int MAXNUM = 2147483647;
  double r[n+1];
  bool days[365+1];
  int i, number;

  for (i = 1; i <= n; i++)
    r[i] = (double)rand()/MAXNUM;
  for (i = 1; i <= 365; i++)
    days[i] = false;
  for (i = 1; i <= n; i++)
    {
      number = (int)(365*r[i] + 1);
      if (days[number])	
	 return true;
      days[number] = true;
    }
  return false;
}


