#include "standard.h"
#include "vecmat.h"

main()
{ int n = 2;
  vector u(n),v(n);
  input("Enter a vector\n", u);
  newline;
  output("Vector is:\n ", u);
  input("Enter a vector\n", v);
  newline;
  output("Vector is:\n ", v);
  output("5*u+7*v:\n ", u+v);
}
