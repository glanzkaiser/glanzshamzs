/****************************************************************/
/* Module : rk45.c 						*/
/* Section: 8.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description:	Runge-Kutta-Fehlberg method for solving an 	*/
/*              initial value problem.                          */
/* Comment: The main module that calls rk45 is in the file      */
/*	    called mainrk45.c					*/
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>


#include <math.h>

float f(float t, float x)
{
  return (2 + (x - t - 1) * (x - t - 1));
}

#include <stdio.h>

float f(float t, float x); /* define prototypes */
void rk45(float f(float, float), float *t, float *x, float h, float *epsilon);


void main()
{
  const float a = 1.0, b = 1.5625;
  float x = 2.0, t, h, e;
  const int n = 72;
  int i;

  h = (b - a) / (float) n;
  t = a;
  for (i = 1; i <= n;  i++)
  {
    rk45(f, &t, &x, h, &e);
    printf("t = %f, x = %f, e = %f\n" , t, x, e);
  }
}

void rk45(float f(float, float), float* t, float* x, float h, float* epsilon)
{

  float c20 = 0.25, c21 = 0.25;
  float c30 = 0.375, c31 = 0.09375, c32 = 0.28125;
  float c40,c41, c42,c43;
  float c51, c52 = -8.0, c53, c54;
  float c60 = 0.5, c61, c62 = 2, c63, c64;
  float c65 = -0.275;
  float a1, a2 = 0, a3, a4, a5 = -0.2;
  float b1, b2 = 0, b3, b4, b5= -0.18, b6;
  float F1, F2, F3, F4, F5, F6, x4;

  c40 = (float) 12/ (float) 13;
  c41 = (float) 1932/(float) 2197;
  c42 = (float) -7200/(float) 2197;
  c43 = (float) 7296/(float) 2197;
  c51 = c53 = (float) 439/ (float) 216;
  c54 = (float) -845/(float) 4104;
  c61 = (float) -8/(float) 27;
  c63 = (float) -3544/(float) 2565;
  c64 = (float) 1859/(float) 4104;
  a1 = (float) 25/(float) 216;
  a3 = (float) 1408/(float) 2565;
  a4 = (float) 2197/(float) 4104;
  b1 = (float) 16/(float) 135;
  b3 = (float) 6656/(float) 12825;
  b4 = (float) 28561/(float) 56430;
  b6 = (float) 2/(float) 55;


  F1 = h * f(*t, *x);
  F2 = h * f(*t + c20 * h, *x + c21 * F1);
  F3 = h * f(*t + c30 * h, *x + c31 * F1 + c32 * F2);
  F4 = h * f(*t + c40 * h, *x + c41 * F1 + c42 * F2 + c43 * F3);
  F5 = h * f(*t + h, *x + c51 * F1 + c52 * F2 + c53 * F3 + c54 * F4 );
  F6 = h * f(*t + c60 * h, *x + c61 * F1 + c62 * F2 + c63 * F3 + c64 * F4 + c65 * F5);

  x4 = *x + a1 * F1 + a3 * F3 + a4 * F4 + a5 * F5;
  *x += b1 * F1 + b3 * F3 + b4 * F4 + b5 * F5 + b6 * F6;
  *t += h;
  *epsilon = fabs(*x - x4);

}






