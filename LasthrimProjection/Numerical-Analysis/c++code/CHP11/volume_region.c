/****************************************************************/
/* Module : volume_region.c					*/
/* Section: 11.2 				                */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Compute volume of a complicated region in       */
/*              3-space by Monte Carlo technique.		*/
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
  const long MAXNUM = 2147483647;
  const int n = 5000,
            iprt = 1000;
  double r[n+1][3+1];
  int i, j, m;
  double vol, x, y, z;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= 3; j++)   
      r[i][j] = (double)rand()/(double)MAXNUM;    
  m = 0;
  vol = 0;
  for (i = 1; i <= n; i++)
    {
      x = r[i][1];
      y = r[i][2];
      z = r[i][3];
      if ( ( x*x + sin(y) <= z) && (x - z + exp(y) <= 1))
	m++;
      if ( (i%iprt) == 0)
	{
	  vol = (double)m/(double)i;
	  printf("i = %d, vol = %.3f\n", i, vol);
	}
    }
  return 0;
}

