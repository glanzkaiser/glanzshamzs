% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  fun1.m
%
% This M-file is invoked by the file 'lin_prog1.m'.


function [f,g] = fun1(x)
f = -2*x(1) - 3*x(2);               %function to be minimized
g(1) = 5*x(1) + 3*x(2) - 15;        %inequality constraint
g(2) = 3*x(1) + 6*x(2) - 18;        %inequality constraint
