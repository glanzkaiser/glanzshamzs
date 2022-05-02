program main
    implicit none (type, external)
    external :: sscal

    integer, parameter :: N = 7

    real :: x(N) = [ 1., 8., 8., 2., 5., 6., 7. ]
    real :: a    = 5.

    print '("a = ", f0.1)', a
    print '("X = [ ", 7(f0.1, " "), "]")', x

    call sscal(N, a, x, 1)

    print '(/, "X = a * X")'
    print '("X = [ ", 7(f0.1, " "), "]")', x
end program main
