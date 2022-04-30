! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 11.1
!
! file:  circle_err.f90
!
! generates 1000 random points nonuniformly distributed inside
! the circle x*x + y*y = 1
 
program circle_erroneous
      integer, parameter :: n=1000
      real, dimension (n):: x,y
      real, dimension (n,2):: r
      integer :: i
      real :: pi
      pi = acos(-1.)
      call random_number(r)
      do i=1, n
        x(i) = r(i,1) * cos(2.*pi*r(i,2))
        y(i) = r(i,1) * sin(2.*pi*r(i,2))
       end do
       do i = 1,n
         print*, x(i), y(i)
      end do
end program circle_erroneous







