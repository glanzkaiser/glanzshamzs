/****************************************************************/
/* Module : bisection1.c 					*/
/* Section: 3.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

inline float f(float x) { return (pow(x,3) - 3*x + 1); }
inline float g(float x) { return (pow(x,3) - 2*sin(x)); }
void bisection(float f(float),float , float , int );

void main()
{
  const int n_max = 20;
  int n;
  float a, b;
  
  a = 0.0;
  b = 1.0;
  printf("first function: f\n");
  bisection(f,a,b,n_max);

  a = 0.5;
  b = 2.0;
  printf("second function: g\n");
  bisection(g,a,b,n_max);
  return 0;
}

//--------------------------------------------------------
void bisection (float f(float),float a, float b, int n_max)
{
  int n;
  float c, u, v, w;
  
  u = f(a);
  v = f(b);
  printf("a = %1.4f, b = %1.4f, f(a) = %1.4f, f(b) = %1.4f\n", a, b, u, v);

  if ((u*v) >= 0)
    return;
  else
   {
     printf("%4s%14s%14s\n","n", "c", "f(c)");
     for (n = 0; n <= n_max; n++)
     {
       c = (a + b)/2;
       w = f(c);
       printf("%4d%14e%14e\n", n, c, w); 
       if ((w*u) == 0)
	 break;
       else
	 {
	   if ((w*u) < 0)
	     {
	       b = c;
	       v = w;
	     }
	   else
	     {
	       a = c;
	       u = w;
	     }
	 } 
     } 
   } 
} 













