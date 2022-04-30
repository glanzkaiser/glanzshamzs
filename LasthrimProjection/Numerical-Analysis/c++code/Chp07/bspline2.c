/****************************************************************/
/* MODULE: BSPLINE.C                                            */
/* Section: 7.4                                                 */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* 1999                                                         */
/* Description: Quadratic b-spline function                     */
/* Programmer: Asha Nallana                                     */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bspline2_coef(int, float*, float*, float*, float*);
float bspline2_eval(int, float*, float*, float*, float);

int main()
{
  const int n = 19;
  int i;
  float t[n+1] = {0.0, 0.2, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 
		  5.0, 5.2, 5.5, 6.0, 6.2, 6.5, 7.0, 7.5, 8.0};   
  float y[n+1] = {0.0, -0.8, -0.34, 0.59, 0.23, 0.1, 0.28, 1.03, 1.5, 1.44, 
		  0.74, -0.82, -1.27, -0.92, -0.92, -1.04, -0.79, -0.06, 1.0, 0.0};
  float x[n+1] = {0.0, 0.6, 1.5, 1.7, 1.9, 2.1, 2.3, 2.6, 2.8, 3.0, 3.6, 4.7, 5.2,
		  5.7, 5.8, 6.0, 6.4, 6.9, 7.6, 8.0};
  float a[n+2], h[n+2]; 
  float z[n+1];

  bspline2_coef(n,t,y,a,h);
  printf("evaluation of bspline\n");
  for (i = 1; i <= n; i++)
    printf("\t%f\n", bspline2_eval(n, t, a, h, x[i]));
  return 0;
}

//--------------------------------------------------------------
void bspline2_coef(int n, float *t, float *y, float *a, float *h)
{
  int i;
  float delta, gamma, p, q, r;

  for (i = 1; i <= n; i++)
    h[i] = t[i] - t[i-1];

  h[0] = h[1];
  h[n+1] = h[n];
  delta = -1.0;
  gamma = 2*y[0];
  p = delta*gamma;
  q = 2;
  for (i = 1; i <= n; i++)
    {
      r = h[i+1]/h[i];
      delta = -r*delta;
      gamma = -r*gamma + (r + 1)*y[i];
      p += gamma*delta;
      q += delta*delta;
    }
  a[0] = -(p/q);
  for( i = 1; i <= n + 1; i++)
     a[i] = ((h[i-1] + h[i])*y[i-1] - h[i]*a[i-1]) / h[i-1];   
}

//---------------------------------------------------------------
float bspline2_eval(int n, float* t, float* a, float* h, float x)
{
 int i;
 float d,e;

 for (i = n - 1; i >= 0; i--)
   if(x - t[i] >= 0) 
     break;

 i += 1;
 d = ( a[i+1]*(x - t[i-1]) + a[i]*(t[i] - x + h[i+1]) ) / (h[i] + h[i+1]);
 e = ( a[i]*(x - t[i-1] + h[i-1]) + a[i-1]*(t[i-1] - x + h[i]) ) / (h[i-1] + h[i]);
 return (d*(x - t[i-1]) + e*(t[i] - x)) / h[i];
}






