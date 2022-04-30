
ostream& operator<<(ostream &s, tridiag &equ)
{ 
 int n = equ.getnum();
 const long tril = ios::left + ios::fixed;
 format trifmt(tril, 4, 10);
 for (int i = 0; i<n; ++i)
    s << trifmt << equ[i][B];
 return s;
}

istream& operator>>(istream &s, tridiag &equ)
{
 int n = equ.getnum();
 cout << "Enter " << n << " equations:\n";
 for (int i = 0; i<n; ++i) 
 {
  cout << "L" << i << " = ";
  s >> equ[i][L];
  cout << "D" << i << " = ";
  s >> equ[i][D];
  cout << "U" << i << " = ";
  s >> equ[i][U];
  cout << "B" << i << " = ";
  s >> equ[i][B];
 }
 return s;
}
