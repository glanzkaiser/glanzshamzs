% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: num_int3.m
%
% numerical approximation for the integral of 
% the function cos(2*x)/exp(x) on the interval
% [0,1]. Function is defined in M-file 'f3.m'

% quad8 carries out an adaptive recursive
% Newton-Cotes 8 panel rule.

type f3
q3=quad8('f3',0,2*pi)
fplot('f3',[0,1])
title('plot of function cos(2*x)/exp(x)')


