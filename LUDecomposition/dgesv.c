#include <stdio.h>
#include <lapacke.h>

int main (int argc, const char * argv[])
{
  double a[3*3] = {1,3,2,3,5,4,-2,6,3};
  double b[3*1] = {5,7,8};
  lapack_int info,n,lda,ldb,nrhs,ipiv[3];
  int ii;

  n = 3;
  nrhs = 1;
  lda = 3;
  ldb = 3;
  info = LAPACKE_dgesv(LAPACK_COL_MAJOR,n,nrhs,a,lda,ipiv,b,ldb);
  for(ii=0; ii<n; ii++)
  {
  printf("%lf\n",b[ii]);
  }
  return(info);
}
