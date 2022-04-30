! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 7.2
!
! file: 2spline3.f
!
! natural cubic spline function for serpentine curve at 13 points using
! spline3_coef(n,t,y,z) and spline3_eval(n,t,y,z,x)

program main
      integer, parameter :: n = 12 , npts = 1000
      real, dimension(0:n):: y,z
      real, dimension(0:n):: t
      real :: h,t1,t2,pi,theta
      integer ::i
      real :: p,s
      
      interface
      subroutine spline3_coef(n,t,y,z)
      integer, intent(in)::n
      real, dimension(0:n), intent(in):: t,y
      real, dimension(0:n), intent(out):: z
      end subroutine spline3_coef
      function spline3_eval(n,t,y,z,x)
      integer, intent(in)::n
      real, dimension(0:n), intent(in)::t,y,z
      real, intent(in):: x
      end function spline3_eval
      end interface
      
      t1 = -2.1906
      t2 =  2.1906
      pi = acos(-1.)
      h = pi/(n+2)
      do j = -1,-n/2,-1
       theta = j*h
       i = -j - 1
       t(i) = 0.5 /tan(theta)
       y(i) = sin ( 2.*theta )
      end do
      do j = n/2+1,1,-1
       theta = j*h
       i =  n - j +1
       t(i) = 0.5 /tan(theta)
       y(i) = sin ( 2.*theta )
      end do

      do i= 0,n
       print *, t(i), y(i)
      end do
      print *, ' ' 

      call spline3_coef(n,t,y,z)     

      h = (t2-t1)/npts
      do i = 0,npts
         p = t1 + i*h
         s = spline3_eval(n,t,y,z,p)
         print *, p, s
      end do
end program main
     
subroutine spline3_coef(n,t,y,z) 
      integer, intent(in)::n
      real, dimension(0:n), intent(in)::  t,y
      real, dimension(0:n-1) :: h,b
      real, dimension(n-1)::u,v
      real, dimension(0:n), intent(out):: z 
      integer :: i
      do i = 0,n-1
        h(i) = t(i+1) - t(i)
        b(i) = (y(i+1) -y(i))/h(i)    
      end do
      u(1) = 2.0*(h(0) + h(1))
      v(1) = 6.0*(b(1) - b(0))
      do i = 2,n-1
        u(i) = 2.0*(h(i) + h(i-1)) - h(i-1)**2/u(i-1)     
        v(i) = 6.0*(b(i) - b(i-1)) - h(i-1)*v(i-1)/u(i-1) 
      end do
      z(n) = 0.0  
      do i = n-1,1,-1     
        z(i) = (v(i) - h(i)*z(i+1))/u(i)
      end do
      z(0) = 0.0
end subroutine spline3_coef 
  
function spline3_eval(n,t,y,z,x)
      integer, intent(in):: n
      real, dimension(0:n), intent(in):: t,y,z       
      real, intent(in):: x
      real :: h, temp
      integer :: i
      do i = n-1,1,-1     
        if( x - t(i) >= 0.0) exit    
      end do
      h = t(i+1) - t(i)     
      temp = 0.5*z(i) + (x - t(i))*(z(i+1) - z(i))/(6.0*h) 
     temp = (y(i+1) - y(i))/h - h*(z(i+1) + 2.0*z(i))/6.0 + (x- t(i))*temp     
      spline3_eval = y(i) + (x - t(i))*temp  
end function spline3_eval
