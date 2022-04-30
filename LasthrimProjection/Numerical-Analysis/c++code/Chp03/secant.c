/****************************************************************/
/* Module : secant.c 						*/
/* Section: 3.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: Secant algorithm				*/
/* Comment:							*/
/*								*/
/****************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

inline float f(float x) { return (pow(x,5) + pow(x,3) + 3.0); }
void secant(float (float ), float, float, int, float );

int main()
{
  const int n_max = 8;
  const float epsilon = 0.00000000005;
  float a, b;

  a = 1.0;
  b = - 1.0;
  secant(f,a,b,n_max, epsilon);
  return 0;
}

//--------------------------
void swap(float& a, float& b)
{
   float interchg;

   interchg = b;
   b = a;
   a = interchg;

}

//--------------------------------------------------
void secant( float f(float), float a, float b, int n_max, float epsilon)
{
  int n;
  float temp_a, temp_b, fa, fb, d;
  void swap(float&, float& );

  fa = f(a);
  fb = f(b);

  temp_a = a;
  temp_b = b;
  if ( fabs(fa) > fabs(fb))
  {
    swap (temp_a,temp_b);
    swap (fa,fb);
  }

   printf("   n	      Xn	  f(Xn)\n");
   printf("   0%14e%14f\n",temp_a, fa);
   printf("   1%14e%14f\n",temp_b, fb);

   for (n = 2 ; n <= n_max; n++)
   {
     if ( fabs(fa) > fabs(fb))
     {
       swap(temp_a,temp_b);
       swap(fa,fb);
     }

     d = (temp_b - temp_a) / (fb - fa);
     temp_b = temp_a;
     fb = fa;
     d = d * fa;
     if (fabs(d) < epsilon)
       {
	 printf("convergence\n");
	 return;
       }
     temp_a = temp_a - d;
     fa = f(temp_a);
     printf("%4d%14e%14.7f\n",n,temp_a,fa);
   }

}



