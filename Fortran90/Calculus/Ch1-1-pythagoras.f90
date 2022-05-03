program pythagoras

! Calculate the hypothenuse of a right-side triangle.
!
! Declare variables
! variables = length of adjacent and opposite

  implicit none    ! Require all variables to be explicitly declared

  integer :: ierr
  character(1) :: yn
  real :: adjacent, opposite, hypothenuse

  interactive_loop: do

!   Prompt the user for length of side 1 and side 2
!   and read them.

    write (*,*) 'Enter adjacent:'
    read *, adjacent
    write (*,*) 'Enter opposite:'
    read *, opposite

!   If the length of side 1 and side 2 could not be read from input,
!   then cycle through the loop.

    if (ierr /= 0) then
      write(*,*) 'Error, invalid input.'
      cycle interactive_loop
    end if

!   Compute area.  The ** means "raise to a power."

    hypothenuse = (adjacent**2 + opposite*2)**(1/2)
    
!   Write the input variables (adjacent,opposite)
!   and output (hypothenuse) to the screen.

    write (*,'(1x,a7,f6.2,5x,a7,f6.2,5x,a5,f6.2)') &
      'length of adjacent=',adjacent,'opposite=',opposite,'hypothenuse=',hypothenuse
    yn = ' '
    yn_loop: do
      write(*,*) 'Perform another calculation? y[n]'
      read(*,'(a1)') yn
      if (yn=='y' .or. yn=='Y') exit yn_loop
      if (yn=='n' .or. yn=='N' .or. yn==' ') exit interactive_loop
    end do yn_loop

  end do interactive_loop

end program pythagoras
