% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: num_int1.m
%
% numerical approximation for the integral of the
% function exp(-x*x), function is defined in
% the M-file 'f1.m'
%
% quad carries out an adaptive Simpson's algorithm

type f1
q1=quad('f1',0,1)
fplot('f1',[0,1])
title('plot of function exp(-x*x)')



