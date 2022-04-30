/****************************************************************/
/* MODULE: sch.c                                                */
/* Section: 7.4							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Description: Schoenberg's Process                            */
/* Programmer: Hidajaty Thajeb                                  */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline float f(float x) { return 1.0/(x*x + 1.0); }
void sch_coef (float (float ), float, float, int, float*);
float sch_eval(float, float, int, float*, float);

int main()
{
  const int n = 9;
  const float a = 0;
  const float b = 1.6875;
  float d[n+4];
  int  i;
  float e, h, x;
 
  sch_coef(f, a, b, n, d);
  h = (b - a)/n;
  for (i = 0; i <= 4*n; i++)
    {
      x = a + i*h/4;
      e = fabs(sin(x) - sch_eval(a, b, n, d, x));
      printf(" i =%6d  x =%10f  d = %3e\n", i, x, e);
    }
  return 0;
}

//------------------------------------------------------
void sch_coef (float f(float ), float a, float b, int n, float *d)
{
 float h;
 int i;

 h = (b - a)/n;

 for (i = 2; i <= n + 2 ; i++)
   d[i] = f(a + (i-2)*h);

 d[1] = 2*d[2] - d[3];
 d[n+3] = 2*d[n+2] - d[n+1];
}

//--------------------------------------------------------
float sch_eval(float a, float b, int n, float *d, float x)
{
  int k;
  float c, e, h, p, w;

  h = (b - a)/n;
  k = (int) ((x - a)/h + 5/2);
  p = x - a - (k - 5/2)*h;
  c = (d[k+1]*p + d[k]*(2*h - p))/(2*h);
  e = (d[k]*(p + h) + d[k-1]*(h - p))/(2*h); 
  return (c*p + e*(h - p))/h;
}





