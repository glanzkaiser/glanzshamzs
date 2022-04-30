% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  fun2.m
%
% This M-file is invoked by the file 'lin_prog2.m'.

function [f,g] = fun2(y)
f = 15*y(1) + 18*y(2);    %function to be minimized
g(1) = -5*y(1) - 3*y(2) + 2;  % inequality constraint
g(2) = -3*y(1) - 6*y(2) +3;   % inequality constraint 

