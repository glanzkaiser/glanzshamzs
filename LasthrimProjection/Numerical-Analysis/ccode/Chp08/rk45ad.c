/****************************************************************/
/* Module : rk45ad.c 						*/
/* Section: 8.3							*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/* 								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: The module RK45 is contained in RK45.C.		*/
/* 	    Compile and link this file and rk45.c to create an	*/
/* 	    executable file.					*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define sign(fp) (( (fp) >= (0)) ? (1) : (-1))

#ifndef max
#define max(a,b) (( (a) >= (b)) ? (a) : (b))
#endif

/* define prototypes */

float f(float, float);
void rk45 (float f(float, float), float *, float *, float, float *);
int rk45ad (float f(float, float), float *, float *, float, float, int, float,
             float, float, float, int);

int rk45ad (float f(float, float), float *pt, float *px, float h, float tb,
           int itmax, float emin, float emax, float hmin, float hmax, int iflag)
{
  float delta = 5.0e-6;
  float d, xsave, tsave;
  int k;

  printf ("n    h		t 		x\n");
  printf ("0 %14e %14e %14e\n", h, *pt, *px);

  iflag = 1;
  k = 0;

  while (k <= itmax)
  {
    k++;

    if (fabs(h) < hmin)
      h = sign(h) * hmin;
    if (fabs(h) > hmax)
      h = sign(h) * hmax;

    d = fabs(tb - *pt);

    if (d <= fabs(h) )
    {
      iflag = 0;

      if (d <= ( delta * max( fabs(tb), fabs(*pt) )))
	return(1);
      h = sign(h) * d;
    }

    xsave = *px;
    tsave = *pt;

    rk45(f, pt, px, h, &epsilon);

    printf("k=%d h=%14e t=%14e x=%14e epsilon=%14e\n", k, h, *pt, *px, epsilon);

    if (iflag == 0)
      return(1);

    if ( epsilon < emin)
      h *= 2;

    if ( epsilon > emax)
    {
      h *= 0.5;
      *px = xsave;
      *pt = tsave;
      k--;
    }

  }
  return(0);
}


void main()
{
  const int itmax = 100;
  float t = 1.0, x = 2.0, h = 7.8125e-3, tb = 1.5625;
  float epsmin = 1.0e-8, epsmax = 1.0e-4, hmin = 1.0e-6, hmax = 1.0;
  int iflag;

  rk45ad (f, &t, &x, h, tb, itmax, epsmin, epsmax, hmin, hmax, iflag);

}
