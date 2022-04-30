/****************************************************************/
/* Module : two_dice.c	        			        */
/* Section: 11.3			                        */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Two dice problem simulation                     */
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
  double r[n+1][24+1][2+1];
  int i, j, i1, i2, m;
  float prob;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= 24; j++)
      {
	r[i][j][1] = (double)rand()/MAXNUM;
	r[i][j][2] = (double)rand()/MAXNUM;
      }
  m = 0;
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= 24; j++)
	{
	  i1 = (int)(6*r[i][j][1] + 1);
	  i2 = (int)(6*r[i][j][2] + 1); 
	  if ( (i1 + i2) == 12)
	    {
	      m++;
	      break;
	    }
	}
      if ( (i%1000) == 0)
	{
	  prob = (float)m/(float)i;
	  printf("i = %d, prob = %f\n", i, prob);
	}
    }
  return 0;
}
