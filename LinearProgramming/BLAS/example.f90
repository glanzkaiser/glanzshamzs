program main
    implicit none (type, external)
    external :: sscal

    integer, parameter :: N = 3

    real :: x(N) = [ 5., 6., 7. ]
    real :: a    = 5.

    print '("a = ", f0.1)', a
    print '("X = [ ", 3(f0.1, " "), "]")', x

    call sscal(N, a, x, 1)

    print '(/, "X = a * X")'
    print '("X = [ ", 3(f0.1, " "), "]")', x
end program main
