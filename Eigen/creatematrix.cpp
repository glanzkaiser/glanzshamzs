# include <Core>
# include <iostream>
using namespace std ;
using namespace Eigen ;

// Matrix3f is a 3x3 matrix of floats. 
// Matrix4d is 4x4 matrix of doubles.

Matrix3f A ;
Matrix4d B ;

Matrix <short,5,5> M1 ;
// 20 x75 matrix of type float
Matrix <float,20,75> M2 ;

int main () {
// Set all elements to ones
A = Matrix3f::Ones();
  cout << "Matrix A: \n" << A << endl;
 
B = Matrix4d::Identity();
  cout << "Matrix B: \n" << B << endl;
 
Matrix4f M1 = Matrix4f::Random();
Matrix4f M2 = Matrix4f::Constant(2.3);
  cout << "Matrix M1: \n" << M1 << endl ;
  cout << "Matrix M2: \n" << M2 << endl ;
  cout << "M1 + M2: \n" << M1 + M2 << endl ;
return 0;
}
