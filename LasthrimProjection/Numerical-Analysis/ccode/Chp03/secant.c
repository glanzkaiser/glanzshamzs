/****************************************************************/
/* Module : secant.c 						*/
/* Section: 3.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
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

#define prototypes
float f (float);
void swap( float *, float *);

float f (float x)
{
  return (pow(x,5) + pow(x,3) + 3);

}

void swap(float *a, float *b)
{
   float interchg;

   interchg = *b;
   *b = *a;
   *a = interchg;

}

void secant( float f(float), float a, float b, int m)
{

  int n;
  float fa,fb,temp;

  fa = f(a);
  fb = f(b);

  if ( fabs(fa) > fabs(fb))
  {
    swap (&a,&b);
    swap (&fa,&fb);

  }

   printf("   n	      Xn	  f(x)\n\n");
   printf("   0%14e%14e\n",a, fa);
   printf("   1%14e%14e\n",b, fb);

   for (n=2 ; n <= m; n++)
   {
     if ( fabs(fa) > fabs(fb))
     {
       swap(&a,&b);
       swap(&fa,&fb);
     }

     temp = (b -a) /(fb - fa);
     b = a;
     fb = fa;
     a = a - fa * temp;
     fa = f(a);
     printf("%4d%14e%14e\n",n,a,fa);
   }

}


void main(void)
{
  float a,b;
  const int m = 8;
  a = -1.0;
  b = 1.0;
  secant(f,a,b,m);

}

