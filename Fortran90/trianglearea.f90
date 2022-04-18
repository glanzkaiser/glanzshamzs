program area
    implicit none
    real :: A, B, C, S

    ! area of a triangle
    print *, "A(length of the first side):"
    read *, A
    print *, "B(length of the first side):"
    read *, B
    print *, "C(length of the first side):"
    read *, C
    S = (A + B + C)/2
    A = sqrt(S*(S-A)*(S-B)*(S-C))
    print *,"area =",A
    stop
end program area
