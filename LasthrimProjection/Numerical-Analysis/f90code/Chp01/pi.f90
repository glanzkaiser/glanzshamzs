!
! Numerical Mathematics and Computing, Third Edition
! Ward Cheney & David Kincaid
! Brooks/Cole Publ. Co.
! ISBN 0-534-20112-1
! Copyright (c) 1994.  All rights reserved.
! For educational use with the Cheney-Kincaid textbook.
! Absolutely no warranty implied or expressed.
!
! Section 1.1
!
! File: pi.f
!
! Simple code to illustrate programming in double precision
! computes pi

program p
      integer, parameter :: dp=kind(1d0)
      real (kind=dp)  pi
      pi = 4.0_dp *atan(1.0_2) 
      print*, " the computed value of pi "
      print *,pi
end program p

                                                                       
