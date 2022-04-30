From kincaid@math.utexas.edu Fri Jul 30 16:39:33 1993
Received-Date: Fri, 30 Jul 93 16:39:33 -0500
Received: from chebyshev.ma.utexas.edu by fireant.ma.utexas.edu (5.61/5.51)
	id AA03791; Fri, 30 Jul 93 16:39:33 -0500
Posted-Date: Fri, 30 Jul 1993 16:39:32 -0500
Message-Id: <9307302139.AA02383@chebyshev.ma.utexas.edu>
Received: by chebyshev.ma.utexas.edu (5.61/5.51)
	id AA02383; Fri, 30 Jul 93 16:39:33 -0500
From: kincaid@cs.utexas.edu (David R. Kincaid)
Date: Fri, 30 Jul 1993 16:39:32 -0500
X-Mailer: Mail User's Shell (7.2.3 5/22/91)
To: vona@chebyshev.ma.utexas.edu
Subject: newspl2.f
Status: R

! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 7.4
!
! file : newspl2.f
! interpolates table using a quadratic b-spline function 
! (bspline2_coef, bspline2_eval)

program main
      integer, parameter :: n = 19 , m  = 79
      real, dimension (0:n):: t,y
!      real, dimension (1:10)::z
      real, dimension (0:n+1) ::a
      real, dimension (0:n+1):: h 
      real, dimension (0:m) :: p,s
data t/0.0,0.6,1.5,1.7,1.9,2.1,2.3,2.6,2.8,3.0,3.6,4.7,5.2,5.7,5.8,6.0,6.4,&
6.9,7.6,8.0/
data y/-0.8,-0.34,0.59,0.59,0.23,0.1,0.28,1.03,1.5,1.44,0.74,-0.82,-1.27,&
-0.92,-0.92,-1.04,-0.79,-0.06,1.0,0.0/
      interface
      subroutine bspline2_coef(n,t,y,a,h)              
      integer, intent(in) :: n                         
      real, dimension (0:n), intent(in):: t, y         
      real, dimension (0:n+1), intent(out):: a         
      real, dimension (0:n+1), intent(out):: h          
      end subroutine bspline2_coef
      function bspline2_eval(n,t,a,h,x)                 
      real, dimension (0:n+1), intent(in) :: a          
      real, dimension (0:n+1), intent(in) :: h          
      real, dimension (0:n), intent(in) :: t            
      integer, intent(in) :: n                          
      real, intent(in) :: x                             
      end function bspline2_eval
      end interface


!      t(0)=0.0; t(1)=0.6; t(2)=1.5; t(3)=1.7; t(4)=1.9; t(5)=2.1; t
!      y(0)=0.0; y(1)=1.0; y(2)=0.0; y(3)=1.0; y(4)=0.0
      w = 8.0/m
      call bspline2_coef(n,t,y,a,h) 
      do i = 0,m
         p(i) = i * w
         s(i) = bspline2_eval(n,t,a,h,p(i))
         print *, p(i), s(i)
      end do
!      print *,"coefficients a", a
!      print*, "evaluation of bspline at 1,2,3,4,5,1.25,2,5.3,75,4.5,5.75"
!      print*, z
end program main

subroutine bspline2_coef(n,t,y,a,h)              
      integer, intent(in) :: n                         
      real, dimension (0:n), intent(in):: t, y         
      real, dimension (0:n+1), intent(out):: a         
      real, dimension (0:n+1), intent(out):: h          
      integer :: i
      real :: delta, gamma, p,q
      do i = 1,n
      h(i) = t(i) - t(i-1)
      end do
      h(0) = h(1) 
      h(n+1) = h(n) 
      delta = -1.0
      gamma = 2.0*y(0)
      p = delta*gamma
      q = 2.0
      do  i = 1,n      
         r  = h(i+1)/h(i)
         delta = -r*delta
         gamma = -r*gamma + (r + 1.0)*y(i)
         p = p + gamma*delta 
         q = q + delta*delta 
      end do
      a(0) = -p/q 
      do i = 1,n+1
         a(i) = ((h(i-1)+h(i))*y(i-1)-h(i)*a(i-1))/h(i-1)
      end do
end subroutine bspline2_coef
  
function bspline2_eval(n,t,a,h,x)                 
      real, dimension (0:n+1), intent(in) :: a          
      real, dimension (0:n+1), intent(in) :: h          
      real, dimension (0:n), intent(in) :: t            
      integer, intent(in) :: n                          
      real, intent(in) :: x                                               
      integer :: i
      do i = n-1,0,-1      
         if ( x - t(i) >= 0.0) exit
      end do
      i = i + 1
!      print *,"i,x",i,x
       d  =(a(i+1)*(x - t(i-1)) + a(i)*(t(i) - x + h(i+1)))/(h(i) + h(i+1)) 
 e = (a(i)*(x - t(i-1) + h(i-1)) + a(i-1)*(t(i-1) - x + h(i)))/(h(i-1) + h(i))
      bspline2_eval = ((d*(x - t(i-1)) + e*(t(i) - x)))/h(i)      
end function bspline2_eval

                                                                       





