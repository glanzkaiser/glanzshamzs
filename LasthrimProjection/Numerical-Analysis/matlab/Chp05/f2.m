% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  f2.m
%
% This file is invoked by the file 'num_int2.m'.

function y=f2(x)
if x==0
   y = 1;
else
   y = sin(x)/x;
end
