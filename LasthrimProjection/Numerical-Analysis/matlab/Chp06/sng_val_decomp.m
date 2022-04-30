% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: sng_val_decomp.m
%
% Singular Value Decompostion for matrix A

A = [1 3 -2;2 7 5;-2 -3 4; 5 -3 -2];
[U,SV,V] = svd(A)
pause
D = U' * A * V      %U' is the transpose of the matrix U
A = U * D * V'      % gives us A back
