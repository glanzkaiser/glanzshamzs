#include <iostream.h>
#include <math.h>
#define sign(x) ( (x)<0 ? -1 : 1)

enum state { ITERATING, SUCCESS, MAXITERATION, SAMESIGN };

typedef double (*func)(double);
state Bisection(func, double, double, double&);
state IntervalHalving(func, double, double, double&, int&);

const double epsi  = 5.E-6;
const int    nmax  = 21;

state Bisection(func f, double a, double b, double &c)
{
 if( sign(f(a)) == sign(f(b)) ) return SAMESIGN;
 int n = 0;
 return IntervalHalving(f, a, b, c, n);
}

state IntervalHalving(func f, double a, double b, double &c, int &n)
{ 
 double error, fc;
 error = (b - a)/2;
 c = a + error;
 fc = f(c);
 cout << n << "\t" << c << "\t" << fc << "\t" << error << "\n";
 if( fabs(error) < epsi ) return SUCCESS;
 if( ++n == nmax )        return MAXITERATION;
 sign(f(a)) == sign(fc) ? a = c : b = c;
 return IntervalHalving(f, a, b, c, n);
}


inline double F(double x) { return x*x*x - 2*sin(x); }

main()
{ 
 double a, b, root;
 cout << "Lower estimate a = ";
 cin  >> a;
 cout << "Upper estimate b = ";
 cin  >> b;
 
 state st = Bisection(F, a, b, root);

 switch(st)
 {
  case SUCCESS:       cout << "Root = " << root; break;
  case MAXITERATION:  cout << "Maximun number of iterations!"; break;
  case SAMESIGN:      cout << "Function has same signs at ends of interval!";
                                break;
  default:            cout << "Very peculiar!";
 }
}
