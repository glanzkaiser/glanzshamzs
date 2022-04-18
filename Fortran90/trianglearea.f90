program area
    implicit none
    real :: A, B, C, S

    ! area of a triangle
    read *, A, B, C
    S = (A + B + C)/2
    A = sqrt(S*(S-A)*(S-B)*(S-C))
    print *,"area =",A
    stop
end program area
