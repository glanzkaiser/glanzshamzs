% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  Fun.m
%
% This M-file is invoked by the file 'gauss_newton.m'.

function F = Fun(X)
F(1) = X(1) + X(2) + X(3) - 3;
F(2) = X(1)^2 + X(2)^2 + X(3)^2 - 5;
F(3) = exp(X(1)) + X(1)*X(2) - X(1)*X(3) -1;
