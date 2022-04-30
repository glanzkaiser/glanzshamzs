% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: num_int2.m
%
% numerical approximation for the integral of the
% function sin(x)/x over the interval [0,1]

% quad8 carries out an adaptive recursive 
% Newton-Cotes 8 panel rule.

type f2
q2=quad8('f2',0,1)
fplot('f2',[0,2*pi])
title('plot of function sin(x)/x')



