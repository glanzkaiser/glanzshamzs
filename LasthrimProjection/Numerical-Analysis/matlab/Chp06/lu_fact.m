% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: lu_fact.m

% LU decomposition of the matrix A, where the matrix P is
% a permutation matrix corresponding to the pivoting strategy 
% used.

 A = [ 6,  -2,  2,   4,
       12,  -8,  6,  10,
        3, -13,  9,   3,
       -6,   4,  1, -18]

 [L, U, P] = lu(A)





