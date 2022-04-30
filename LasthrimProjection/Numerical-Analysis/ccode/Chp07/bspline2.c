/****************************************************************/
/* MODULE: BSPLINE.C                                            */
/* Section: 7.4                                                 */
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* 1993                                                         */
/* Description: Quadratic b-spline function                     */
/* Programmer: Asha Nallana                                     */
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*******************************************************/

void bspline2_coef(int n, float *t, float *y, float *a, float *h)
{
 int i;
 float delta, gamma, p,q, r;

 for (i=1; i<=n; i++)
  h[i] = t[i] - t[i-1];

 h[0] = h[1];
 h[n+1] = h[n];
 delta = -1.0;
 gamma = 2.0 * y[0];
 p = delta * gamma;
 q = 2.0;


 for (i = 1; i <= n; i++)
 {
  r = h[i+1]/h[i];
  delta = -r * delta;
  gamma = -r * gamma + (r + 1.0)*y[i];
  p += gamma*delta;
  q += delta*delta;
 }

 printf("coefficients  of a are  \n");
  a[0] = -(p/q);
  printf("a[0] = %f \n ",a[0]);

 for( i = 1; i <= n+1; i++)
 {
  a[i] = ((h[i-1] + h[i])*y[i-1] - h[i]*a[i-1])/h[i-1];
  printf("a[%d] = %f \n ",i,a[i]);
 }
}


/**********************************************************/


float bspline2_eval(int n, float *t, float*a, float*h, float x)
{
 int i;
 float d,e;

 for (i = n-1; i>= 1; i--)
   if(x - t[i] >= 0.0) break;

 i += 1;
 d = (a[i+1]*(x - t[i-1]) + a[i]*(t[i] - x + h[i+1]))/(h[i] + h[i+1]);
 e = (a[i]*(x- t[i-1] + h[i-1]) + a[i-1]*(t[i-1] - x + h[i]))/(h[i-1] + h[i]);
 return ( ((d*(x - t[i-1])) + (e*(t[i] - x))) / h[i] );
}


main()
{
 int i,n = 4;
 float *t, *y, *a, *h, *z;

 t = calloc((n), sizeof(float));
 y = calloc((n), sizeof(float));
 z = calloc((11), sizeof(float));
 a = calloc((n+1), sizeof(float));
 h = calloc((n+1), sizeof(float));

 t[0] = 1.0; t[1] = 2.0; t[2] = 3.0; t[3] = 4.0; t[4] = 5.0;
 y[0] = 0.0; y[1] = 1.0; y[2] = 0.0; y[3] = 1.0; y[4] = 0.0;

 bspline2_coef(n,t,y,a,h);
 z[1] = bspline2_eval(n,t,a,h,1.);
 z[2] = bspline2_eval(n,t,a,h,2.);
 z[3] = bspline2_eval(n,t,a,h,3.);
 z[4] = bspline2_eval(n,t,a,h,4.);
 z[5] = bspline2_eval(n,t,a,h,5.);
 z[6] = bspline2_eval(n,t,a,h,1.25);
 z[7] = bspline2_eval(n,t,a,h,2.5);
 z[8] = bspline2_eval(n,t,a,h,3.75);
 z[9] = bspline2_eval(n,t,a,h,4.5);
 z[10] = bspline2_eval(n,t,a,h,5.75);

 printf("evaluation of bspline at 1,2,3,4,5,1.25,2.5,3.75,4.5,5.75 \n");

 for (i=1; i<=10; i++)
 printf("%f \n ",z[i]);
}



