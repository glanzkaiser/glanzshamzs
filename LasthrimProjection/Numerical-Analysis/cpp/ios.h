class ios {
protected:
 streambuf *buf;
 long x_flags;
 int x_width;
 int x_precision;
 int state;          // status of stream
// ...........
public:
 ios(streambuf*);
 ~ios();
 enum { 
   left       = 0x0002,  // left-adjust output
   right      = 0x0004,  // right-adjust output
   showpoint  = 0x0100,  // force decimal point
   showpos    = 0x0400,  // prefix '+' to positive numbers
   fixed      = 0x1000,  // require 'fixed point' notation
 };
 long flags(long);
 int width(int);
 int precision(int);
}
