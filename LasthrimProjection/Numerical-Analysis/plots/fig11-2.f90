! cheney & kincaid, numerical mathematics and computing, 3rd ed, 1993
! section 11.1
!
! file:  elips.f90
!
! generates 1000 random points uniformly distributed inside
! the ellipse x*x + 4 y*y = 4
 
program ellipse
      integer, parameter :: n=1000, npts=2500
      real, dimension (n):: x,y
      real, dimension (npts,2):: r
      integer :: i,j
      real :: u,v
      call random_number(r)
      j = 1
      do i=1, npts
         u = 4*r(i,1) - 2
         v = 2*r(i,2) - 1
         if (u*u + 4.*v*v <= 4) then
            x(j) = u
            y(j) = v
            if (j == n) exit
            j = j + 1
         endif
       end do
       do j = 1,n
          print*, x(j), y(j)
      end do
end program ellipse







