/****************************************************************/
/* Module : amrkad.c                                            */
/* Section: 9.3                                                 */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* 1993                                                         */
/* Programmer: Asha Nallana                                     */
/* Description: Adam-Moulton method for systems of ODEs         */
/*                                                              */
/* Comment: (n+1) is the number of components of the vector     */
/*          RK_order is the order of Runge-Kutta method         */
/*          The two-dimensional arrays are stored differently   */
/*          from that of the corresponding f90 code/pseudocode. */
/*          e.g: Z[i][m] in the book/f90 corresponds to         */
/*               Z[m][i] in the C code.                         */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RK_order 4
#define sign(fp) (( (fp) >= (0)) ? (1) : (-1))

#ifndef max
#define max(x,y) (((x) > (y)) ? (x) : (y))
#endif

/* define prototypes */

void xpsys(float *, float *);
void amrkad(int, float, float *, float, float,int, float,float,float,float, int)
;
void amsys(int *, int, float, float *, float **, float **);
void rk4sys(int *, int, float, float **, float **);




void xpsys(float *X, float *f)

/* Function to find out the X prime of the system of equations */

{
  f[0] = 1.0;
  f[1] = X[2];
  f[2] = X[1] - X[3] - 9 * X[2] * X[2] + pow (X[4],3) + 6 * X[5] + 2 * X[0];
  f[3] = X[4];
  f[4] = X[5];
  f[5] = X[5] - X[2] + exp(X[1]) - X[0];
}


void amrkad(int n, float t, float *X, float h, float tb, int itmax, float emin,
float emax, float hmin, float hmax, int iflag)

/* A control procedure that calls runge-kutta procedure 3 times and then
   calls adam-moulton method to do the remaining steps for different step
   sizes of h which is calculated adaptively */

{
  int i, m, k, irk, iam, nstep;
  float **Z, **F, dt, epsi,est;
  epsi = 1.0e-6;

  F = calloc((RK_order + 1), sizeof(float *));
  Z = calloc((RK_order + 1), sizeof(float *));

  for (i = 0; i <= RK_order; i++)
  {
    F[i] = calloc((n+1), sizeof(float));
    Z[i] = calloc((n+1), sizeof(float));
  }

  m = 0;
  irk = 3;   /* counter for the runge-kutta steps taken */
  iam = 0;    /* counter for the adam-moulton steps taken */
  iflag = 3;  /* some initial value for iflag */
  nstep = 0;  /* counter for the number of steps taken */

  printf("\n initial values: nstep = %d,t = %f, h = %f \n ", nstep,t,h);
  for (i=0; i<=n; i++)
     printf("X[%d] = %10f   ",i,X[i]);

  for (i=0; i<=n; i++)

  for (i=0; i<=n; i++)
     Z[m][i] = X[i];

  if (fabs(tb-t) < fabs(4.0*h) )
     h *= 0.25;

  do
    {
     if (fabs(h) < hmin)
       {
        h = sign(h)*hmin;
        iflag = 2;
       }

     if (fabs(h) > hmax)
       {
        h = sign(h)*hmax;
        iflag = 2;
       }

     dt  = fabs(tb - t);
     if (dt < fabs(h) )
       {
        iflag = 0;
        if (dt <= epsi*max(fabs(tb),fabs(t)))  exit(0);
        h = sign(dt)*h;
        irk = 1;
        iam = 0;
        if ( (fabs(h) < hmin) || (fabs(h) > hmax) )
          {
           iflag = 2;
           exit(0);
          }
       }

     if (iam == 0)
       {
        for (k = 1; k<= irk; k++)
           {
            rk4sys(&m,n,h,Z,F);
            nstep += 1;
            t += h;
            printf(" \n\n RK:  nstep = %d,t = %f, h = %f \n", nstep,t,h);

           printf("Values of X are \n");
            for (i=0; i<= n; i++)
            printf("X[%d] = %10f  ", i, Z[m][i]);
           }

         if(nstep > itmax || irk == 1)  exit(0);
       }

     amsys(&m,n,h,&est,Z,F);
     nstep += 1;
     t += h;
     printf("\n\n AM : nstep = %d,t = %f, h = %f, est = %f \n", nstep,t,h,est);
     for (i=1; i<=n; i++)
     printf(" X[%d] = %10f  ", i,Z[m][i]);

     if ( nstep > itmax || iflag == 0 ) exit(0);

     if(emin <= est && est <= emax)
       {
        irk = 0;
        iam = 1;

       }
     else
       {
        t -=4.0*h;
        nstep = nstep-4;
        m = 0;
        irk = 3;
        iam = 0;

        if (est < emin)
           h *= 2.0;

        if (est > emax)
           h *= 0.5;
        if ( (fabs(h) < hmin) || (fabs(h) > hmax) )
          {
           iflag = 2;
           exit(0);
          }
       }
   }while(1);

  iflag = 1;

 for (i= 0; i<= n; i++)
     X[i] = Z[m][i];

 free(F);
 free(Z);

}



void rk4sys(int *m, int n, float h, float **Z, float **F)
{
  /*modified from rk4sys */

  int i, k, mp1;
  float **G, *Y, factor_h6;

  G = calloc((RK_order), sizeof(float *));
  Y = calloc((n+1), sizeof(float));

  for (i = 0; i < RK_order; i++)
    G[i] = calloc((n+1), sizeof(float));

  mp1 = (1 + *m) % 5;

  xpsys(Z[*m], F[*m]);

  for (i = 0; i <= n; i++)
    Y[i] = Z[*m][i] + 0.5 * h * F[*m][i];

  xpsys(Y, G[1]);

  for (i = 0; i <= n; i++)
    Y[i] = Z[*m][i] + 0.5 * h * G[1][i];

  xpsys(Y, G[2]);

  for (i = 0; i <= n; i++)
    Y[i] = Z[*m][i] + h * G[2][i];

 xpsys (Y, G[3]);

  factor_h6 = h / 6.0;

  for (i = 0; i <= n; i++)
    Z[mp1][i] = Z[*m][i] + (factor_h6) * (F[*m][i] + 2 * G[1][i] + 2 * G[2][i] +
 G[3][i]);

  *m = mp1;

  for (i = 0; i < RK_order; i++)
    free (G[i]);


  free (Y);
  free (G);

}



void amsys (int *m, int n, float h, float *est, float **Z, float **F)

/* Function for the adam-moulton method and to compute the error of a single
   step */
{
  float *S, *Y;

  float A[] = {0, 55, -59, 37, -9};
  float B[] = {0, 9, 19, -5, 1};

  int i, j, k, mp1;

  float d, dmax, factor_24h;

  S = calloc( (n+1), sizeof(float) );
  Y = calloc( (n+1), sizeof(float) );

  mp1 = (1 + *m) % 5;
  xpsys (Z[*m], F[*m]);


  for (i = 0; i <= n; i++)
    S[i] = 0;

  for (k = 1; k <= 4; k++)
  {
    j = (*m - k + 6) % 5;

    for (i = 0; i <= n; i++)
      S[i] += A[k] * F[j][i];
  }

  factor_24h = h / 24.0;

  for (i = 0; i <= n; i++)
      Y[i] = Z[*m][i] + S[i] * factor_24h;

  xpsys (Y, F[mp1]);

  for (i = 0; i <= n; i++)
    S[i] = 0;

  for (k = 1; k <= 4; k++)
  {
    j = (mp1 - k + 6) % 5;

    for (i = 0; i <= n; i++)
       S[i] += B[k] * F[j][i];
  }

  for (i = 0; i <= n; i++)
    Z[mp1][i] = Z[*m][i] + S[i] * factor_24h;

  *m = mp1;

  dmax = 0;

  for (i = 0; i <= n; i++)
  {
    d = fabs(Z[mp1][i] - Y[i]) / fabs(Z[mp1][i]);

    if (d > dmax)
    {
      dmax = d;
      j = i;
    }
  }

  *est = 19 * dmax / 270.0;

  free (S);
  free (Y);
}



void main()
{
  const int n = 5, itmax = 100;
  float ta = 0.0, tb = 1.0,emin = 1.0e-8, emax = 1.0e-2, hmin = 1.0e-4;
  float t,h, hmax = 1.0;
  float X[] = {1.0,2.0,-4.0,-2.0,7.0,6.0};
  int i,iflag;

  t = ta;
  h = (tb - ta) / itmax;

  printf("ta = %f, h = %f \n", ta,h);
  for(i=1; i<=n; i++)
     printf("X[%d] = %10f  ",i,X[i]);

  amrkad(n,t,X,h,tb,itmax,emin,emax,hmin,hmax,iflag);
  printf(" \n iflag = %d \n", iflag);
}


 

