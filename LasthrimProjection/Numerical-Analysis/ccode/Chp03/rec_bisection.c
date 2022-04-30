/****************************************************************/
/* Module : rec_bisection.c 					*/
/* Section: 3.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*      							*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: Using recursion					*/
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


float bisection (float f(float),float a,float b,float fa,float fb,int m,int n)
{
  float c,fc,width;

  if (fa * fb > 0)
   {
    printf("\n function has the same signs at a and b");
    printf(" \n %9e %9e %9e %9e ", a,b,fa,fb);
    return(1);
   }

  else
   {
     width = (b - a) * 0.5;
     c = a + width;
     fc = f(c);
     n++;
     printf("\n %4d%14e%14e%14e ",n,c,fc,width);
     if (n < m)
     {
       if (fa * fc < 0)
	 return bisection(f,a,c,fa,fc,m,n);
       else
	 return bisection(f,c,b,fc,fb,m,n);

     }
     return (0); /* because it's a function */

    }

 }


void main()
{
  float a = 0;
  float b = 1.0;
  int n = 0;
  float fa,fb,ga,gb;
  const int m = 20;

  fa = f(a);
  fb = f(b);
  printf("\n    n      c             f(c)          width");
  bisection(f,a,b,fa,fb,m,n);

  a =0.5;
  b =2.0;
  ga = g(a);
  gb = g(b);
  n = 0;
  printf("\n\n   n       c             g(c)          width");
  bisection(g,a,b,ga,gb,m,n);

}










