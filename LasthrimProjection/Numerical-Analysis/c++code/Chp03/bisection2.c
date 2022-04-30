/****************************************************************/
/* Module : bisection2.c 					*/
/* Section: 3.1							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Tatyana Asriyan					*/
/* Description: 						*/
/* Comment: Non-recursive version of bisection			*/
/*								*/
/****************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

inline float f(float x) { return (pow(x,3) - 3*x + 1); }
inline float g(float x) { return (pow(x,3) - 2*sin(x)); }
inline void bisection(float f(float), float, float, int, float );

int main()
{
  const int n_max = 20;
  const float epsilon = 0.0000005;
  int n;
  float a, b;
  
  a = 0.0;
  b = 1.0;
  printf("%4s%14s%14s%14s\n","n", "c", "f(c)", "error");
  bisection(f,a,b,n_max,epsilon);

  a = 0.5;
  b = 2.0;
  printf("%4s%14s%14s%14s\n","n", "c", "g(c)", "error");
  bisection(g,a,b,n_max,epsilon);
  return 0;
}

//-----------------------------------------------------------------------
void bisection (float f(float),float a, float b, int n_max, float epsilon)
{
  int n;
  float c, fa, fb, fc, error;
  int sign(float );

  fa = f(a);
  fb = f(b);
  
  if (sign(fa) == sign(fb))
    {
      printf(" a = %.4f, b = %.4f, f(a) = %.4f, f(b) = %.4f\n\n", a, b, f(a), f(b));
      printf("Function has the same signs at a and b\n");
      return;
    }
  error = b - a;
  for (n = 0; n <= n_max; n++)
    {
      error = error / 2;
      c = a + error;
      fc = f(c);
      printf("%4d%14f%14.2e%14.2e\n", n, c, fc, error); 
      if (fabs(error) < epsilon)
	{
	  printf("convergence\n");
	  return;
	}
      if (sign(fa) != sign(fc))
	{
	  b = c;
	  fb = fc;
	}
      else
	{
	  a = c;
	  fa = fc;
	}

    }
}

//--------------------------
int sign(float x)
{
  return x < 0 ? 1 : 0;
}


