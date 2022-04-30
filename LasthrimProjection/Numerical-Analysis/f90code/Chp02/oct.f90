!
! Numerical Mathematics and Computing, Third Edition
! Ward Cheney & David Kincaid
! Brooks/Cole Publ. Co.
! ISBN 0-534-20112-1
! Copyright (c) 1994.  All rights reserved.
! For educational use with the Cheney-Kincaid textbook.
! Absolutely no warranty implied or expressed.
!
! Section 2.1
!
! File: oct.f90
!
! Print octal representation of a floating-point number
!
subroutine oct(i) 
   integer :: i
   write(6,600) i
600 format(o20) 
end subroutine oct 
