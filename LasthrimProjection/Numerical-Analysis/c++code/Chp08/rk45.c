/****************************************************************/
/* Module : rk45.c 						*/
/* Section: 8.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description:	Runge-Kutta-Fehlberg method for solving an 	*/
/*              initial value problem.                          */
/* Comment:                                                     */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline float f(float t, float x) { return 2.0 + (x - t - 1.0)*(x - t - 1.0); }
void rk45(float (float, float), float&, float&, float, float&);

int main()
{
  const int n = 72;
  float a = 1.0, b = 1.5625, x = 2.0;
  int k; 
  float t, h, epsilon;

  h = (b - a)/n;
  t = a;
  printf("0 x(%1.3f) = %1.5f\n", t, x);

  for (k = 1; k <= n;  k++)
  {
    rk45(f, t, x, h, epsilon);
    printf("k = %d: x(%1.5f) = %1.5f, e = %f\n", k, t, x, epsilon);
  }
  return 0;
}

//--------------------------------------------------------------------------
void rk45(float f(float, float), float& t, float& x, float h, float& epsilon)
{

  float c20 = 0.25, c21 = 0.25;
  float c30 = 0.375, c31 = 0.09375, c32 = 0.28125;
  float c40,c41, c42,c43;
  float c51, c52 = -8.0, c53, c54;
  float c60 = 0.5, c61, c62 = 2, c63, c64;
  float c65 = -0.275;
  float a1, a2 = 0, a3, a4, a5 = -0.2;
  float b1, b2 = 0, b3, b4, b5= -0.18, b6;
  float K1, K2, K3, K4, K5, K6, x4;

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


  K1 = h*f(t, x);
  K2 = h*f(t + c20*h, x + c21*K1);
  K3 = h*f(t + c30*h, x + c31*K1 + c32*K2);
  K4 = h*f(t + c40*h, x + c41*K1 + c42*K2 + c43*K3);
  K5 = h*f(t + h, x + c51*K1 + c52*K2 + c53*K3 + c54*K4 );
  K6 = h*f(t + c60*h, x + c61*K1 + c62*K2 + c63*K3 + c64*K4 + c65*K5);

  x4 = x + a1*K1 + a3*K3 + a4*K4 + a5*K5;
  x += b1*K1 + b3*K3 + b4*K4 + b5*K5 + b6*K6;
  t += h;
  epsilon = fabs(x - x4);

}






