#include "standard"
#include "vecmat.h"

main()
{ int n = 2;
  matrix M(n);
  vector v(n);
  input("Enter a matrix\n", M);
  input("Enter a vector\n", v);
  vector u = M*v;
  output("Product matrix-vector is:\n ", u);
}
