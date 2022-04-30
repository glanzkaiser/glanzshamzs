#include <iostream.h>
#include <math.h>

enum state { ITERATING, SUCCESS, MAXITERATION, TOOFLAT };

typedef double (*func)(double);
state Secant(func, double&, double);
void  Swap(double&, double&);

const double epsi  = 5.0E-6;
const double delta = 5.0E-10;
const int nmax = 25;

void Swap(double &x, double &y)
{
 double t = x;
 x = y;
 y = t;
}

state Secant(func f, double &a, double b)
{
 double fa, fb, d, t;
 state st = ITERATING;
 int n = 1;
 fa = f(a); fb = f(b);
 cout << "0" <<"\t" << a << "\t" << fa <<"\n";
 cout << "1" <<"\t" << b << "\t" << fb <<"\n";

 while (st == ITERATING)
 {
  if( fabs(fa) > fabs(fb) )
  { 
   Swap(a, b); Swap(fa, fb);   //smaller function values
  }
  t = (fb -fa)/(b - a);
  if( fabs(t) < delta ) st = TOOFLAT;  //function too flat
  else
  { 
   b = a; fb = fa;
   a += (d = -fa/t);
   fa = f(a);
   if( ++n == nmax )    st = MAXITERATION;
   if( fabs(d) < epsi ) st = SUCCESS;
   cout << n <<"\t" << a << "\t" << fa <<"\n";
  }
 }
 return st;
}

inline double F(double x) { return x*x*x*x*x + x*x*x + 3; }

main()
{ 
 double a, b;
 cout << "Estimate x0 = ";
 cin  >> a;
 cout << "Estimate x1 = ";
 cin  >> b;
 
 state st = Secant(F, a, b);

 switch(st)
 { 
  case SUCCESS:       cout << "Root = " << a; break;
  case TOOFLAT:       cout << "Function too flat!"; break;
  case MAXITERATION:  cout << "Maximum number of iteations!"; break;
  default:            cout << "Very peculiar!";
  }
}

