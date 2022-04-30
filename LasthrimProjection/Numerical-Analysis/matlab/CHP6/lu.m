#
# Numerical Mathematics and Computing, Third Edition
# Ward Cheney & David Kincaid
# Brooks/Cole Publ. Co.
# (c) 1994
# ISBN 0-534-20112-1
#
# file: lu.m
#
# LU factorization

>> A = [ 6,  -2,  2,   4,
        12,  -8,  6,  10,
         3, -13,  9,   3,
        -6,   4,  1, -18]

>> [P, L, U] = lu(A)

P =

    1.0000         0         0         0
    0.2500    1.0000         0         0
   -0.5000         0    1.0000         0
    0.5000   -0.1818    0.0909    1.0000


L =

   12.0000   -8.0000    6.0000   10.0000
         0  -11.0000    7.5000    0.5000
         0         0    4.0000  -13.0000
         0         0         0    0.2727


U =

     0     1     0     0
     0     0     1     0
     0     0     0     1
     1     0     0     0



