program circle

! Calculate the circumference and the area of a circle.
!
! Declare variables and constants.
! constants=pi
! variables=radius squared

  implicit none    ! Require all variables to be explicitly declared

  integer :: ierr
  character(1) :: yn
  real :: radius, circumference, area
  real, parameter :: pi = 3.141592653589793

  interactive_loop: do

!   Prompt the user for radius and height
!   and read them.

    write (*,*) 'Enter radius:'
    read *, radius

!   If radius could not be read from input,
!   then cycle through the loop.

    if (ierr /= 0) then
      write(*,*) 'Error, invalid input.'
      cycle interactive_loop
    end if

!   Compute area.  The ** means "raise to a power."

    area = pi * (radius**2)
    circumference = 2*pi * (radius)

!   Write the input variables (radius, height)
!   and output (area) to the screen.

    write (*,'(1x,a7,f6.2,5x,a7,f6.2,5x,a5,f6.2)') &
      'radius=',radius,'circumference=',circumference,'area=',area

    yn = ' '
    yn_loop: do
      write(*,*) 'Perform another calculation? y[n]'
      read(*,'(a1)') yn
      if (yn=='y' .or. yn=='Y') exit yn_loop
      if (yn=='n' .or. yn=='N' .or. yn==' ') exit interactive_loop
    end do yn_loop

  end do interactive_loop

end program circle
