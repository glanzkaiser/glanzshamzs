/****************************************************************/
/* MODULE: spline3.c						*/
/* Section: 7.2							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Description: Interpolates sin x at 10 equidistant knots using*/
/*              natural cubic spline                            */
/* Programmer: Hidajaty Thajeb					*/
/* Comment:							*/ 
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void spline3_coef (int, float*, float*, float*);
float spline3_eval(int, float*, float*, float*, float);


int main()
{
  const int n = 9;
  const float a = 0;
  const float b = 1.6875;
  float t[n+1], y[n+1], z[n+1];
  int  i;
  float e, h, x;
 
  h = (b - a)/n;
  for (i = 0; i <= n; i++)
    { 
      t[i] = a + i*h;
      y[i] = sin(t[i]);
    }
   spline3_coef(n, t, y, z);
  for (i = 0; i <= 4*n; i++)
    {
      x = a + i*h/4;
      e = fabs(sin(x) - spline3_eval(n, t, y, z, x));
      printf(" i =%6d  x =%10f  d = %3e\n", i, x, e);
    }
  return 0;
}

//----------------------------------------------------
void spline3_coef (int n, float *t, float *y, float *z)
{
 float h[n], b[n], u[n], v[n];
 int i;
  
 for (i = 0; i <= n - 1; i++)
   {
     h[i] = t[i+1] - t[i];
     b[i] = (y[i+1] - y[i])/h[i];
   }
 u[1] = 2*(h[0] + h[1]);
 v[1] = 6*(b[1] - b[0]);
 for (i = 2; i <= n - 1; i++)
   {
     u[i] = 2*(h[i] + h[i-1]) - (h[i-1]*h[i-1])/u[i-1];
     v[i] = 6*(b[i] - b[i-1]) - (h[i-1]*v[i-1])/u[i-1];
   }
 z[n] = 0;
 for (i = n - 1; i >= 0; i--)
   z[i] = (v[i] - h[i]*z[i+1])/u[i]; 
 z[0] = 0;
}

//-------------------------------------------------------------
float spline3_eval(int n, float *t, float *y, float *z, float x)
{
  int i;
  float h, tmp;

  for (i = n -1; i >= 0; i--)
    if (x - t[i] >= 0)
      break;

  h = t[i+1] - t[i];
  tmp = (z[i]/2) + (x - t[i])*(z[i+1] - z[i])/(6*h);
  tmp = -(h/6)*(z[i+1] + 2*z[i]) + (y[i+1] - y[i])/h + (x - t[i])*tmp;
  return (y[i] + (x - t[i])*tmp);
}









