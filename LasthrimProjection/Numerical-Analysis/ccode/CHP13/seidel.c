/****************************************************************/
/* Module : seidel.c 						*/
/* Section: 13.3						*/
/* Cheney-Kincaid, Numerical Mathematics and Computing, 3rd ed, */
/* Brooks/Cole Publ. Co.                                        */
/* ISBN 0-534-20112-1                                           */
/* Copyright (c) 1994.  All rights reserved.                    */
/* For educational use with the Cheney-Kincaid textbook.        */
/* Absolutely no warranty implied or expressed.                 */   
/*       							*/
/* Programmer: Hidajaty Thajeb					*/
/* Description: 						*/
/* Comment: The function BNDY is eliminated for it's equivalent */
/*	    to the function TRUE_SOLUTION.			*/
/*								*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* define prototypes */
float f(float x, float y);
float g(float x, float y);
/* float bndy(float x, float y); */
float ustart(float x, float y);
float true_solution(float x, float y);

float f(float x, float y)
{
  return(-25);
}

float g(float x, float y)
{
  return(0);
}


float ustart(float x, float y)
{
  return(1);
}

float true_solution(float x, float y)
{
  return(0.5 * (cosh (5*x) + cosh(5*y)) / cosh(5) );
}

/* float bndy(float x, float y)  ..REDUNDANT
* {
*   return(true_solution(x,y));
* }
*/

void seidel(float ax, float ay, int nx, int ny, float h, int itmax, float **U)
{
  int i, j, k;
  float v, x, y;

  for (k = 1; k <= itmax; k++)
  {
    for (j = 1; j < ny; j++)
    {
      y = ay + j * h;
      for (i = 1; i < nx; i++)
      {
        x = ax + i * h;
        v = U[i+1][j] + U[i-1][j] + U[i][j+1] + U[i][j-1];
        U[i][j] = (v - h * h * g(x,y) ) / (4 - h* h * f(x,y) );
      }
    }
  }

}

void main()
{
  const int nx = 8, ny = 8, itmax = 20;
  int i, j;
  float ax = 0, bx = 1, ay = 0, by = 1;
  float **U;
  float h, x, y;

  U = calloc((nx+1), sizeof(float *));
  for (i= 0; i <= ny; i++)
    U[i] = calloc((ny+1), sizeof(float));

  h = (bx - ax) / nx;

  for (j = 0; j <= ny; j++)
  {
    y = ay + j * h;
    U[0][j] = true_solution(ax,y); /* changed from bndy */
    U[nx][j] = true_solution(bx,y);
  }

  for (i = 0; i <= nx; i++)
  {
    x = ax + i * h;
    U[i][0] = true_solution(x, ay); /* changed from bndy */
    U[i][ny] = true_solution(x, by);
  }

  for (j = 1; j < ny ; j++)
  {
    y = ay + j * h;
    for (i = 1; i < nx; i++)
    {
      x = ax + i * h;
      U[i][j] = ustart(x,y);
    }
  }

  for (i = 0; i<= nx; i++)
  {
    for (j = 0; j<= ny; j++)
      {
      printf("U[%d][%d] = %f\n", i,j,U[i][j]);
    }
  }

  seidel(ax, ay, nx, ny, h, itmax, U);
  printf("itmax = %d\n", itmax);

  for (i = 0; i < nx; i++)
  {
    for (j = 0; j < ny; j++)
      printf("U[%d][%d] = %f\n", i, j, U[i][j]);

  }

  for (j = 0; j <= ny; j++)
  { 
    y = ay + j * h;
    for (i = 0; i <= nx; i++)
    {
      x = ax + i* h;
      U[i][j] = fabs(true_solution(x,y) - U[i][j]);
      printf("diff: U[%d][%d] = %f\n", i, j, U[i][j]);

    }

  }

  for (i=0; i <= nx; i++)
    free(U[i]);
  free(U);

}









