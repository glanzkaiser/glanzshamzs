/****************************************************************/
/* Module : shielding.c	        			        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Neutron shielding problem simulation            */
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
  const int n = 5000,
         iprt = 1000,
       MAXNUM = 2147483647;
  double r[n+1][7+1];
  int i, j, m;
  float x, per, pi;

  m = 0;
  pi = 4.0*atan(1.0);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= 7; j++)
      r[i][j] = (double)rand() /MAXNUM;
  for (i = 1; i <= n; i++)
    {
      x = 1;
      for (j = 1; j <= 7; j++)
	{
	  x += cos(pi*r[i][j]);
	  if (x <= 0)
	    break;
	  if (x >= 5)
	    {
	      m++;
	      break;
	    }
	}
      if ( (i%iprt) == 0)
	{
	  per = 100*(float)m/(float)i;
	  printf("i = %d, per = %f\n", i, per);
	}
    }
  return 0;
}
