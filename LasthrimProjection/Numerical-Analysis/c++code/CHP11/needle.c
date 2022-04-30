/****************************************************************/
/* Module : needle.c	        			        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Buffon's needle problem simulation              */
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  const int n = 5000,
         iprt = 1000,
       MAXNUM = 2147483647;
  double r[n+1][2+1];
  int i, m;
  float pi, prob, t, v, w;

  m = 0;
  pi = 4.0*atan(1.0);
  t = 2/pi;
  for (i = 1; i <= n; i++)
    {
      r[i][1] = (double)rand()/MAXNUM;
      r[i][2] = (double)rand()/MAXNUM;
    }
  for (i = 1; i <= n; i++)
    {
      w = r[i][1];
      v = (pi/2)*r[i][2];
      if (w <= sin(v))
	m++;
      if ( (i%iprt) == 0)
	{
	  prob = (float)m/(float)i;
	  printf("i = %d, prob = %f, 2/pi = %f\n", i, prob, t);
	}      
    }  
  return 0;
}
