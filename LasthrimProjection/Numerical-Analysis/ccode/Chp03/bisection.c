/****************************************************************/
/* Module : bisection.c 					*/
/* Section: 3.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: Non-recursive version of bisection			*/
/*								*/
/****************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float f (float x)
{
  return (pow(x,3) - 3*x + 1);
}


float g (float x)
{
  return (pow(x,3) - 2*sin(x));

}


void bisection (float f(float),float a, float b, int m)
{
  float c, fa, fb, fc, width;
  int n;

  fa = f(a);
  fb = f(b);
  if (fa * fb > 0)
   {
    printf("Function has the same signs at a and b\n");
    printf("%9e %9e %9e %9e\n", a,b,fa,fb);
   }

  else
   {
     width = b - a;

     for (n = 0; n < m; n++)
     {
       width *= 0.5;
       c = a + width;
       fc = f(c);
       if (fa * fc < 0)
       {
	 b = c;
	 fb = fc;
       }
       else
       {
	 a = c;
	 fa = fc;
       }

       printf("%4d%14e%14e%14e\n",n,c,fc,width);
     }

   }
}


void main()
{
  float fa = 0, fb = 1.0, ga = 0.5, gb = 2.0;
  const int m = 20;

  printf(" First function: F\n");
  printf(" a = %f  b = %f\n", fa, fb);
  printf("\n step       c             f(c)          width\n");
  bisection(f,fa,fb,m);

  printf("\n Second function: G\n");
  printf(" a = %f  b = %f\n", ga, gb);
  printf("\n step      c             g(c)          width\n");
  bisection(g,ga,gb,m);

}










