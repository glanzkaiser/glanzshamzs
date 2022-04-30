#include <iostream.h>
#include <math.h>

enum state { ITERATING, SUCCESS, MAXITERATION, TOOFLAT };

typedef double (*func)(double);
state Newton(func, func, double&);

const double epsi  = 5.0E-6;
const double delta = 5.0E-10;
const int nmax = 11;

inline double F(double x)  { return x*x*x - 2*x*x + x - 3;}
inline double FP(double x) { return 3*x*x - 4*x + 1;}

state Newton(func f, func fp, double &x)
// f(x), fp(x) = f'(x), x

{
 double fx, fpx, d;
 int n = 0; state st = ITERATING;

 fx = f(x); fpx = fp(x);
 cout << n << "\t" << x << "\t" << fx << "\n";

 while(st == ITERATING)
 {
  if(++n == nmax) st = MAXITERATION;
  if(fabs(fpx) < delta) st = TOOFLAT;
  x += ( d = - fx/fpx );
  fx = f(x); fpx = fp(x);
  cout << n << "\t" << x << "\t" << fx << "\n";
  if(fabs(d) < epsi) st = SUCCESS;
 } 
 return st;
}

main()
{
 double root;
 cout << "Initial estimate = ";
 cin  >> root;
 
 state st = Newton(F, FP, root);

 switch(st) 
 { 
  case SUCCESS:      cout << "Root = " << root; break;
  case TOOFLAT:      cout << "Function too flat!"; break;
  case MAXITERATION: cout << "Maximum iteartions!"; break;
  default:           cout << "Very peculiar!";
 }
}

