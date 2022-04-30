From kincaid@math.utexas.edu Fri Jul 30 16:39:00 1993
Received-Date: Fri, 30 Jul 93 16:38:59 -0500
Received: from chebyshev.ma.utexas.edu by fireant.ma.utexas.edu (5.61/5.51)
	id AA03786; Fri, 30 Jul 93 16:38:59 -0500
Posted-Date: Fri, 30 Jul 1993 16:38:59 -0500
Message-Id: <9307302138.AA02377@chebyshev.ma.utexas.edu>
Received: by chebyshev.ma.utexas.edu (5.61/5.51)
	id AA02377; Fri, 30 Jul 93 16:38:59 -0500
From: kincaid@cs.utexas.edu (David R. Kincaid)
Date: Fri, 30 Jul 1993 16:38:59 -0500
X-Mailer: Mail User's Shell (7.2.3 5/22/91)
To: vona@chebyshev.ma.utexas.edu
Subject: 2spline3.f
Status: R

! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 7.2
!
! file: 2spline3.f
!
! natural cubic spline function for sin(x) at 10 equidistant points 
! also evaluates sin(x) - S(x) at 37 equidistant points using
! spline3_coef(n,t,y,z) and spline3_eval(n,t,y,z,x)

program main
      integer, parameter :: n = 19 , m = 799
      real, dimension(0:n):: y,z
      real, dimension(0:n):: xc
      real :: h
      integer ::i
data xc/0.0,0.6,1.5,1.7,1.9,2.1,2.3,2.6,2.8,3.0,3.6,4.7,5.2,5.7,5.8,6.0,6.4,&
6.9,7.6,8.0/
data y/-0.8,-0.34,0.59,0.59,0.23,0.1,0.28,1.03,1.5,1.44,0.74,-0.82,-1.27,&
-0.92,-0.92,-1.04,-0.79,-0.06,1.0,0.0/
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

      call spline3_coef(n,xc,y,z)     
      h = 8.0/m
      do i = 0, m
         p(i) = i * h
         s(i) = spline3_eval(n,xc,y,z,p(i))
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
                                                                   


