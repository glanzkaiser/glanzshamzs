implicit real*8 (a-h,o-z)
parameter(maxn=200,m=80,k=maxn+1)
parameter(zero=0.0d0,one=1.0d0)
real*8 a(k,maxn),aa(k,maxn),x(k,m),b(k,m)
integer ip(maxn)
C ===========================================================
C Define the matrix
C ===========================================================
n=maxn
call inita(a,k,n)
do i=1,n
do j=1,n
aa(j,i)=a(j,i)
end do
end do
C ===========================================================
C LU decomposition
C ===========================================================
call dgetrf(n,n,a,k,ip,info)
C ===========================================================
C Define the vectors
C ===========================================================
do jm=1,m
do jn=1,n
10
x(jn,jm)=jn+jm
end do
end do
call dgemm('N','N',n,m,n,one,aa,k,x,k,zero,b,k)
C ===========================================================
C Solution
C ===========================================================
call dgetrs('N',n,m,a,k,ip,b,k,info)
if(info.ne.0) then
write(6,*) 'error in dgetrs info = ',info
stop
end if
C ===========================================================
C Check result
C ===========================================================
call check(a,b,k,n,m)
end
