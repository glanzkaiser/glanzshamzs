/****************************************************************/
/* Module : hyperbol.c 						*/
/* Section: 13.2						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* 1993								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pi;

/* define prototypes */
float f(float x);
float true_solution(float t, float x);


float f(float x)
{
  return(sin(pi * x));
}

float true_solution(float t, float x)
{
  return(sin(pi * x) * cos (pi * t));
}


void main()
{
  const int n = 10, m = 20;
  int i, j;
  float *U, *V, *W;
  float h = 0.1, k = 0.05;
  float t, x, rho;

  U = calloc((n+1), sizeof(float));
  V = calloc((n+1), sizeof(float));
  W = calloc((n+1), sizeof(float));

  U[0] = U[n] = 0;
  V[0] = V[n] = 0;
  W[0] = W[n] = 0;

  rho = (k * k) / (h * h);

  pi = 4.0 * atan(1.0);

  for (i = 1; i <= n - 1; i++)
  {
     x = i * h;
     W[i] = f(x);
     V[i] = 0.5 * (rho * ( f(x-h) + f(x+h) ) + 2 * (1 - rho) * f(x) );
  }

  for (j = 2; j <= m; j++)
  {
    printf("j = %d\n", j);
    for (i = 1; i <= n - 1; i++)
    {
      U[i] = rho * (V[i+1] + V[i-1]) + 2 * (1 - rho) * V[i] - W[i];
      printf("init U[%d] = %f\n", i, U[i]);
    }

    for (i = 1; i <= n - 1; i++)
    {
      W[i] = V[i];
      V[i] = U[i];
      t = j * k;
      x = i * h;
      U[i] = true_solution(x,t) - V[i];
      printf("final U[%d] = %f\n", i, U[i]);
    }

  }

  free(U);
  free(V);
  free(W);

}









