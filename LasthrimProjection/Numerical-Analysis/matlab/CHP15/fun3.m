% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  fun3.m
%
% This M-file is invoked by the file 'lin_prog3.m'.

function [f,g] = fun3(y)
f = y(4) + y(5) + y(6) + y(7) + y(8) + y(9);      %function to be minimized
g(1)= 2*y(1) + 3*y(2) - 5*y(3) - y(4) + y(5) -4;  %equality constraint
g(2)= y(1) - y(2) - y(6) + y(7) -2;               %equality constraint
g(3)= y(1) + 2*y(2) - 3*y(3) - y(8) + y(9) -7;    %equality constraint

