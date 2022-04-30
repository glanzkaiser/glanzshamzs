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