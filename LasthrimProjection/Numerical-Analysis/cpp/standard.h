#ifndef STANDARD
#define STANDARD
/************************/
/*    STANDARD.H        */
/************************/
/*                      */
/* Some standard things */
/*                      */
/************************/

#include <iostream.h>
// #include <iomanip.h>
// #include <conio.h>
#include <math.h>

const char tab  = '\t';
const char bell = '\7';
const char *const sep = ", ";

define clear        clrscr()
define newline      cout<<endl
define statement(s) cout<<(s)
define output(s, n) cout<<(s)<(n)
define input(s, n)  cout<<(s)<<bell;cin>>(n)
define sign(x)      ((x)<0? -1:1)            // typeof(sign(x)) = typeof(x)

const double PI       = 3.141592653589793;
const double EXP      = 2.718281828459045;
const double GAMMA    = 0.577215664901533;
const double GOLDMEAN = 0.618033988749895;
const double LN2      = 0.693147180559945;
const double LN10     = 2.302585092994046;

typedef unsigned char byte;
typedef unsigned char word;
typedef unsigned long longword;

enum bool (FALSE, TRUE)
enum state (ITERATING, SUCCESS, MAXITERATION, NEARZERO, SAMESIGN);

void error(char*);                  //runtime error termination
bool getyes(const char*);           //boolean choice
void pressanykey();                 //pause until key pressed

//equality of two floating point numbers x and y
void equal(double, double, double, double)

// roots of quadratic equation: a*x*x + b*x + c = 0
void quadroots(double, double, double, double&, double&);

class format {                                  //three parameter manipulator
private:
         long lb;
         int pr, wd;
         ios& iosfun(ios&, long, int, int);     //formats stream output
public:
         format(long l, int p, int w) : lb(l), pr(p), wd(w) { }
         friend ostream& operator<<(ostream&, format&);
};

// for putting (color) strings in given places
int scrput(int r, int c, char*, int color);
int scrput(int r, int c, char*);
int center(int r, char*, int color);
int center(int r, char*)

//  inline functions

inline ostream& operator<<(ostream &s, format &f)
{      f.iosfunc(s, f.lb, f.pr, f.wd); return s; }

inline int scrput(int row, int col, char *s)
{       return scrput(row, col, s, LIGHTGRAY);
}

inline int center(int row, char *s)
{      return center(row, s, LIGHTGRAY);
}

inline double round(double x) { return floor(x + 0.5); }



void error(char *errmsg)
{
 cerr << "\nRunttime Error ...\n";
 cerr << errmsg;
 cerr << "\n... Quitting Program!\n";
 exit();
}

bool getyes(const char *str)
{cout << str;                       //cputs(str);
 for (;;)
 { 
  int c = getch();
  if( c == 'Y' || c == 'y')
    return TRUE;
  if( c == 'N' || c == 'n')
    return FALSE;
 }
}

void pressanykey()
{ 
 int x = wherex();                 // store position of cursor
 int y = wherey();
 gotoxy(1,25)                      //cursor to bottom left
 insline();                        //insert blank line
 textcolor(WHITE);                 //bold for message
 cputs("Press ANY KEY to continue: ");
 normvideo();
 putch(bell);                      // beep
 getch();                          //await key press
 delline();                        //delete message
 gotoxy(x, y);                     //restore cursor
}

bool equal(double x, double y, double delta, double epsi)
{double fx = fabs(x), fy = fabs(y);
 if( fx < delta )                  // x = 0
  {
  if( fy < delta ) return TRUE; // y = 0 also
  else return FALSE;
  }
  else if( fabs(x - y) < epsi*fx ) return TRUE;
  else return FALSE;
}

void quadroots(double a, double b, double c, double &x1, double &x2)
{
 double d = b*b -4*a*c;
 if( d < 0 ) error("Discriminant negative in quadroots(...)");
 double s = -(b + sign(b)*sqrt(d))/2;
 x1 = s/a;
 x2 = c/s;
}

#endif //STANDARD
