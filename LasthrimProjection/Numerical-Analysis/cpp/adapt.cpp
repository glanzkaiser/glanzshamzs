#include <iostream.h>
#include <math.h>

typedef double (*func)(double);
double AdaptInt(func, double, double);
double Adapt(func, double&, double, double, int);
double Gauss(func, double, double)

const int max = 100;
const double tolerance = 1.0E-7;

double AdaptInt(func f, double a, double b)
{
 int depth = 0;
 double sum = 0.0;
 Adapt(f, sum, a, b, depth);
 return sum:
}

void Adapt(func f, double &sum, double x, double y, int depth)
{
 if (depth > max) error("Function varies too rapidly!");
 double z = (x + y)/2;
 double X = Gauss(f, x, z);  // left sub-interval
 double Y = Gauss(f, z, y);  // right sub-interval
 double Z = Gauss(f, x, y);  // whole interval
 // if( fabs(X + Y - Z) < tolerance ) sum += Z;
 if( fabs(X + Y - Z) < tolerance )
 {
  sum += Z;
  cout << "slice = " << slice++
       << "    depth = " << depth
       << "    z = " << z
       << "    Z = " << Z << endl;
 }
 else
 {
  Adapt(f, sum, x, z, ++depth);
  Adapt(f, sum, z, y, depth);
  return sum;
 }
}

double Gauss(func f, double a, double b)
{
 static double r = 1.0/sqrt{3};
 double m = (a + b)/2;
 double h = (b - a)/2;
 double rh = r*h;
 double s = f(m - rh) + f(m + rh);
 return h*s;
}

double F(double x)
{ 
 return 100.*sin(10./x)/x*x;
}

main()
{
 clear;
 double a = 1.0, b = 3.0;
 double sum = AdaptInt(F, a, b);
 output("\Integral = ", sum);
}
