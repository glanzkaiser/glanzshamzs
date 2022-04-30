! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 7.2
!
! file: 2spline3.f
!
! two cubic splines interpolants (non continuous derivative).
! spline3_coef(n,t,y,z) and spline3_eval(n,t,y,z,x)

program main
      integer, parameter :: n = 7 , m = 499
      real, dimension(0:n):: y,z
      real, dimension(0:n):: t
      real :: h
      integer ::i
      data t/0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0/
      data y/1.0,1.5,1.6,1.5,0.9,2.2,2.8,3.1/
     real, dimension(0:m) :: p,s
      
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

      do i = 0, n
         print *, t(i), y(i)
      end do
      print *, ' '

      n1 = 4
      call spline3_coef(n1,t,y,z)     
      h = 4./m
      do i = 0, m
         p(i) = i * h
         s(i) = spline3_eval(n1,t,y,z,p(i))
         print *, p(i), s(i)
      end do
     
      n2 = 3
      call spline3_coef(n2,t(4),y(4),z)     
      h = 3./m
      do i = 0, m
         p(i) = t(4) + i * h
         s(i) = spline3_eval(n2,t(4),y(4),z,p(i))
         print *, p(i), s(i)
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
