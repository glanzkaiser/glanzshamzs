! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 4.1
!
! file: 
!
! interpolating polynomial at 13 points on serpentine curve 
!

program main
      integer, parameter :: n = 12, npts = 500
      real, dimension(0:n):: x,y,a
      real :: h,pi,theta,t,t1,t2,poly
      integer ::i
      
      interface
      subroutine coef(n,x,y,a) 
      integer, intent(in)::n
      real, dimension(0:n), intent(in):: x,y
      real, dimension(0:n), intent(out):: a 
      end subroutine coef
      function eval(n,x,a,t)
      integer, intent(in):: n
      real, dimension(0:n), intent(in):: x,a     
      real, intent(in):: t
      end function eval
      end interface

      t1 = -1.15
      t2 =  1.15
      pi = acos(-1.)
      h = pi/(n+2)
      theta = - (n/2)*h
      do i = 0,n
       if (i == n/2) theta = theta + h
       x(i) = 0.5 /tan(theta)
       y(i) = sin ( 2.*theta )
!      print *, i, theta, x(i), y(i)
       theta = theta + h
      end do
      call coef(n,x,y,a) 
!     print *, 'passed call coef'
      h = (t2-t1)/npts
      do i = 0,npts
         t = t1 + i*h
         poly = eval(n,x,a,t)
         print *, t, poly
      end do
end program main
     
subroutine coef(n,x,y,a) 
      integer, intent(in)::n
      real, dimension(0:n), intent(in):: x,y
      real, dimension(0:n), intent(out):: a 
      integer :: i
      do i = 0,n
        a(i) = y(i)
      end do
      do j = 1,n
       do i = n,j,-1
        a(i) = (a(i)-a(i-1)) / (x(i)-x(i-j))
       end do
      end do
end subroutine coef 
  
function eval(n,x,a,t)
      integer, intent(in):: n
      real, dimension(0:n), intent(in):: x,a     
      real, intent(in):: t
      real :: temp
      integer :: i
      temp = a(n)
      do i = n-1,0,-1     
       temp = temp * (t-x(i)) + a(i)
      end do
      eval = temp
end function eval
