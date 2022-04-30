!
! Numerical Mathematics and Computing, Third Edition
! Ward Cheney & David Kincaid
! Brooks/Cole Publ. Co.
! ISBN 0-534-20112-1
! Copyright (c) 1994.  All rights reserved.
! For educational use with the Cheney-Kincaid textbook.
! Absolutely no warranty implied or expressed.
!
! Section 11.2
!
! File: volume_region.f90
!
! Volume of a complicated region in three-space by Monte Carlo
      
program volume_region
      integer, parameter :: n = 5000, iprt = 1000
      real, dimension(n,3) :: r
      integer ::i,m
      real x, y, z, vol
      call random_number(r)
      do i = 1,n
         x = r(i,1); y = r(i,2); z = r(i,3)
         if((x*x+sin(y) <= z) .and. (x-z+exp(y) <= 1.0)) m = m + 1
         if(mod(i,iprt) == 0) then
            vol = real(m)/real(i)
            print *,i,vol
         end if
      end do
end program volume_region
  
