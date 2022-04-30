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
! File: cone.f90
!
! Ice cream cone example

program cone
      integer, parameter :: n = 5000, iprt = 1000
      real, dimension(n,3) :: r
      integer ::  i,m
      real :: x, y, z, vol
      m = 0
      call random_number(r)
      do i = 1,n
         x = 2.0*r(i,1) - 1.0 
         y = 2.0*r(i,2) - 1.0 
         z = 2.0*r(i,3)
         if( x*x + y*y <= z*z .and. x*x + y*y <= z*(2.0 - z) )  m = m + 1
         if( mod(i,iprt) == 0 )  then 
            vol = 8.0*real(m)/real(i) 
            print *,i,vol 
         end if    
      end do
end program cone
  
