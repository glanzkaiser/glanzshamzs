/****************************************************************/
/* Module : cone.c					        */
/* Section: 11.2					        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Ice cream cone example                          */
/* Comment: The results might be slightly different from the    */
/*          book answers due to the different random values	*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  const int MAXNUM = 2147483647,
            n = 5000,
            iprt = 1000;
  double r[n+1][3+1];
  int i, j, m;
  double vol, x, y, z;

  m = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= 3; j++)
      r[i][j] = (double)rand()/(double)MAXNUM;
  for (i = 1; i <= n; i++)
    {
      x = 2*r[i][1] - 1;
      y = 2*r[i][2] - 1;
      z = 2*r[i][3];
      if ( (x*x + y*y <= z*z) && (x*x + y*y <= z*(2 - z)))
	m++;
      if ( (i%iprt) == 0)
	{
	  vol = 8*(double)m/(double)i;
	  printf("i = %d, vol = %.1f\n", i, vol);
	}        	   
    }   
  return 0;
}
