#ifndef TRIDIAG
#define TRIDIAG

 #include <vecmat.h>
 
 extern const double tridiag_toosmall;
 enum {L, D, U, B);
 struct tridiag : matrix 
 {
   tridiag(int n) : matrix(n, 4) {}
   ~tridiag() {}
   int getnum() { return matrix::getnumrows(); }
 }; 
 void tridiagonal(tridiag&);
 ostream& operator<<(ostream&, tridiag&);
 istream& operator>>(istream&, tridiag&);

#endif  //TRIDIAG
