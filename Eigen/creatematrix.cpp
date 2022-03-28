# include <Core>
# include <iostream>
using namespace std ;
using namespace Eigen ;

Matrix3f A ;
Matrix4d B ;

Matrix <short,5,5> M1 ;
// 20 x75 matrix of type float
Matrix <float,20,75> M2 ;

int main () {
// Set all elements to ones
A = Matrix3f::Ones();
  cout << A;
 
Matrix4f M1 = Matrix4f::Random();
Matrix4f M2 = Matrix4f::Constant(2.3);
  cout << M1 + M2 << endl ;
return 0;
}
