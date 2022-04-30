/****************************************************************/
/* Module : hyperbol.c 						*/
/* Section: 13.2						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* 1994								*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: 							*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415927

float f(float x);
float true_solution(float t, float x);


inline float f(float x)
{
  return(sin(pi*x));
}

inline float true_solution(float x, float t)
{
  return(sin(pi*x) * cos (pi*t));
}


int main()
{
  const int n = 10, m = 20;
  const float h = 0.1, k = 0.05;
  float u[n+1],
        v[n+1],
        w[n+1];
  int i, j;
  float t, x, ro;

  u[0] = 0; v[0] = 0; w[0] = 0;  
  u[n] = 0; v[n] = 0; w[n] = 0;
  ro = (k/h) * (k/h);
  for (i = 1; i <= n - 1; i++)
    {
      x = i * h;
      w[i] = f(x);
      v[i] = 0.5*ro*(f(x - h) + f(x + h)) + (1 - ro)*f(x);
    }  
  for (j = 2; j <= m; j++)
    {
      printf("numerical solution\n");
      for (i = 1; i <= n - 1; i++)
	{
	  u[i] = ro*(v[i+1] + v[i-1]) + 2*(1 - ro)*v[i] - w[i];
	  printf("%d:\tu[%d] = %2.6f\n", j, i, u[i]);
	}
      printf("true solution: \n");
      for (i = 1; i <= n - 1; i++)
	{
	  w[i] = v[i];
	  v[i] = u[i];
	  t = j * k;
	  x = i * h;
	  u[i] = true_solution(x,t) - v[i];	
	  printf("%d:\tu[%d] = %2.6f\n", j, i, u[i]);
	}
    }  
 return 0;
}









