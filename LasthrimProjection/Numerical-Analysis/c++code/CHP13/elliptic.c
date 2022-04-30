/****************************************************************/
/* Module : elliptic.c 						*/
/* Section: 13.3						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 4th ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1999.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*       							*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void seidel(float, float, int, int, float, int, float** );

inline float f(float x, float y) { return - 25; }
inline float g(float x, float y) { return 0; }
inline float true_solution(float x, float y) { return 0.5*(cosh(5*x) + cosh(5*y))/cosh(5); }
inline float bndy(float x, float y)    { return true_solution(x, y); }
inline float ustart(float x, float y)  { return  1; }


int main()
{
  const int nx = 8,
            ny = 8,
	    itmax = 20;
  float ax = 0,
        bx = 1,
        ay = 0,
        by = 1;
  float* u[nx+1];
  int i, j;
  float h, x, y;

  for (i = 0; i <= nx; i++)
    u[i] = new float[ny+1];
  
  h = (bx - ax)/nx;
  for (j = 0; j <= ny; j++)
    {
      y = ay + j*h;
      u[0][j] = bndy(ax, y);
      u[nx][j] = bndy(bx, y);
    }
  for (i = 0; i <= nx; i++)
    {
      x = ax + i*h;
      u[i][0] = bndy(x, ay);
      u[i][ny] = bndy(x, by);
    }

  for (j = 1; j <= ny - 1; j++)
    {
      y = ay + j*h;
      for (i = 1; i <= nx - 1; i++)
	{
	  x = ax + i*h;
	  u[i][j] = ustart(x,y);
	  printf("u[%d][%d] = %2.6f\n", i, j, u[i][j]);
	}
    }

  seidel(ax, ay, nx, ny, h, itmax, u);
  printf("itmax = %d\n", itmax);
  for (i = 1; i <= nx - 1; i++)
    for (j = 1; j <= ny - 1; j++)
      printf("u[%d][%d] = %2.6f\n", i, j, u[i][j]);

  for (j = 0; j <= ny; j++)
    {
      y = ay + j*h;
      for (i = 0; i <= nx; i++)
	{
	  x = ax + i*h;
	  u[i][j] = fabs(true_solution(x,y) - u[i][j]);
	}
    }
   printf("itmax = %d\n", itmax);
   for (i = 1; i <= nx - 1; i++)
    for (j = 1; j <= ny - 1; j++)
      printf("u[%d][%d] = %2.6f\n", i, j, u[i][j]);
   return 0;
}

//----------------------------------------------------------------------------
void seidel(float ax, float ay, int nx, int ny, float h, int itmax, float* u[])
{
  int i, j, k;
  float x, y, v;

  for (k = 1; k <= itmax; k++)
    {
      for (j = 1; j <= ny - 1; j++)
	{
	  y = ay + j*h;
	  for (i = 1; i <= nx - 1; i++)
	    {
	      x = ax + i*h;
	      v = u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1];
	      u[i][j] = (v - h*h*g(x,y)) / (4 - h*h*f(x,y));
	    }
	}
    }
}








