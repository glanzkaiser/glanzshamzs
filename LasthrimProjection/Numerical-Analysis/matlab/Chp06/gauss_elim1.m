% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
%
% file: gauss_elim1.m
% solving system of linear equation

A = [ 6  -2  2   4
     12  -8  6  10
      3 -13  9   3
     -6   4  1 -18]
b = [16
     26
    -19
    -34]
x = A\b
