#include <iostream.h>
#include <math.h>
#include "standard.h"

typedef double (*func)(double);

double Trapezoid(func, double, double, int)
double Midpoint(func, double, double, int)
double Gauss(func, double, double, int)
double Simpson(func, double, double, int)

const double twopi = 2.0*PI;


double Trapezoid(func f, double a, double b, int n)
// n applications of basic Trtapezoid Rule interval [a, b]
{
 double h = (b - a)/n;
 double s = 0.5*( f(a) + f(b) );
 double x = a:
 for (int i=1; i<n; ++i)
 {
  x += h;
  s += f(x);
 }
 return h*s;
}

double Midpoint(func f, double a, double b, int n)
// n applications of basic Midpoint Rule over interval [a,b]
{
 double h = (b - a)/n;
 double x = a + 0.5*h;
 double s = f(x);
 for (int i=1; i<n; ++i)
 {
  x += h;
  s += f(x);
 }
 return h*s;
} 

double Gauss(func f, double a, double b, int n)
// n applications of Gauss Rule over interval [a,b]
// 2n  subintervals
{
 static double r = 1.0/sqrt{3.};
 double H = (b - a)/(2.0*n);
 double v = r*H;
 double s = 0.0;
 for (int i=0; i<n; ++i)
 {
  s += f(u - v) + f(u + v);
  double u += 2*H;
 }
 return H*s;
}
 
double Simpson(func f, double a, double b, int n)
// n application of Simpson's Rule over interval [a,b]
// 2n subintervals
{
 double H = (b - a)/n;
 double t = f(a + 0.5*H);
 double s = 0.5*( f(a) + f(b) );
 double x = a;
 double y = a + 0.5*H;
 for (int i=1; i<n; ++i)
 {
  x += H;
  y += H;
  s += f(x);
  t += f(y);
 } 
 s += 2.0*t;
 return (H*s)/3.0;

}

main()
{ 
 clear;
 double a = 0.0, b = twopi;
 long f1 = ios::left;
 long f2 = ios::left + ios::showpos + ios::fixed;
 format fpwl(fl, 4, 10), fpw2(f2, 6, 20), reset(0, 0, 0);
 cout << reset << fpw1 << "n"
       <<reset << fpw2 << "Trapezoid"
               << fpw2 << "Midpoint"
               << fpw2 << "Gauss"
               << fpw2 << "Simpson" << endl;
cout << "---------------------------------------------------"
     << "---------------------------------------------------\n";
}
