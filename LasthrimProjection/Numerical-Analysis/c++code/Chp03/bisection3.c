/****************************************************************/
/* Module : bisection3.c 					*/
/* Section: 3.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
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

inline float f(float x) { return (pow(x,3) - 3*x + 1); }
inline float g(float x) { return (pow(x,3) - 2*sin(x)); }
inline int sign(float x){ return x < 0 ? 1 : 0; }
void bisection(float f(float ), float , float , float , float , int , float, int );

int main()
{
  const int n_max = 20;
  const float epsilon = 0.0000005;
  int n;
  float a, b, fa, fb;

  n = 0;
  a = 0.0;
  b = 1.0;
  fa = f(a);
  fb = f(b);
  printf("    n      c             f(c)          error\n");
  bisection(f,a,b,fa,fb,n_max,epsilon,n);

  a = 0.5;
  b = 2.0;
  fa = g(a);
  fb = g(b);
  printf("   n       c             g(c)          error\n");
  bisection(g,a,b,fa,fb,n_max,epsilon,n);
  return 0;
}

//----------------------------------------------------------------------------
void bisection (float f(float),float a,float b,float fa,float fb,int n_max, float epsilon, int n)
{
  float c,fc,error;
  inline int sign(float );
  
  error = (b - a) / 2;
  c = a + error;
  fc = f(c);
  printf("%4d%14e%14e%14e\n",n,c,fc,error);
  if (fabs(error) < epsilon)
    {
      printf("convergence\n");
      return;
    }
  n = n + 1;
  if (n <= n_max)
    {
      if (sign(fa) != sign(fc))
	bisection(f,a,c,fa,fc,n_max,epsilon,n);
      else
	bisection(f,c,b,fc,fb,n_max,epsilon,n);
    }
 }













