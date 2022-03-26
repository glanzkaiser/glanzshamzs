#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

extern "C" {
  void daxpy_(int* n,double* alpha,double* dx,int* incx,double* dy,int* incy);
  double dnrm2_(int* n,double* x, int* incx);

  void dgetrf_(int* M, int *N, double* A, int* lda, int* IPIV, int* INFO);
  void dgetrs_(char* C, int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO);
  void dgesv_(int *n, int *nrhs, double *a, int *lda, int *ipiv, double *b, int *ldb, int *info);
}

void print(const char* head, int m, int n, double* a){
  cout << endl << head << endl << "---------" << endl;
  for(int i=0; i<m; ++i){
    for(int j=0; j<n; ++j){
      cout << a[i+j*m]<< ' ';
    }
    cout << endl;
  }
  cout << "---------" << endl;
}

int main() {
  int dim;
  std::cout << "Enter Dimensions of Matrix : \n";
  std::cin >> dim;

  vector<double> a(dim*dim);
  vector<double> b(dim);
  srand(1);              // seed the random # generator with a known value
  double maxr = (double)RAND_MAX;
  for (int r = 0; r < dim; r++) {  // set a to a random matrix, i to the identity
    for (int i = 0; i < dim; i++) {
      a[r + i*dim] = rand() / maxr;
    }
    b[r] = rand() / maxr;
  }

  int info;
  int one = 1;
  char N = 'N';
  vector<int> ipiv(dim);

  vector<double> a1(a);
  vector<double> b1(b);
  dgesv_(&dim, &one, a1.data(), &dim, ipiv.data(), b1.data(), &dim, &info);
  print("B1",5,1,b1.data());

  vector<double> a2(a);
  vector<double> b2(b);
  dgetrf_(&dim, &dim, a2.data(), &dim, ipiv.data(), &info);
  dgetrs_(&N, &dim, &one, a2.data(), &dim, ipiv.data(), b2.data(), &dim, &info);
  print("B2",5,1,b2.data());

  double d_m_one = -1e0;
  daxpy_(&dim,&d_m_one,b2.data(),&one,b1.data(),&one);
  cout << endl << "diff = " << dnrm2_(&dim,b1.data(),&one) << endl;

  return 0;
}
