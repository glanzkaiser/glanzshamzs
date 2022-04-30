! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 11.1
!
! file:  elips_err.f90
!
! generates 1000 random points nonuniformly distributed inside
! the ellipse x*x + 4 y*y = 4
 
program ellipse_erroneous
      integer, parameter :: n=1000
      real, dimension (n):: x,y
      real, dimension (n,2):: r
      integer :: i
      real :: u,v
      call random_number(r)
      do i=1, n
        u = 4*r(i,1) - 2
        v = ( (2.*r(i,2) - 1)/2. ) * sqrt(4.-u*u)
        x(i) = u
        y(i) = v
       end do
       do i = 1,n
         print*, x(i), y(i)
      end do
end program ellipse_erroneous







