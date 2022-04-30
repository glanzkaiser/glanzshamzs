% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: p_inv2.m
%
% Finding the Pseudoinverse of matrix A in case of loss in rank:
% Input 5 by 3 matrix A. In evaluation of singular value we like
% any value whose mangitude is less than the tolerance to be
% treates as zero.  Here we set the tolerance to 0.001.
% Finally we verify the penrose Properties of A+.

 A = [-85 -55 -115;-35 97 -167;79 56 102;63 57 69;45 -8 97.5]
 tol = 0.001
 Aplus = pinv(A, tol)
 pause
 penrose1 = A * Aplus * A
 penrose2 = Aplus * A * Aplus
 penrose3 = (A * Aplus) - (A * Aplus)'
 penrose4 = (Aplus * A) - (Aplus * A)'

