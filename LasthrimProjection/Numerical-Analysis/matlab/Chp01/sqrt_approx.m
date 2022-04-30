% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  sqrt_approx.m
%
% Computing the following approxiamation using
% variable precision arithmetic.  Here Matlab 'vpa'
% command forces the calculations to be done with
% forty decimal digits.

h = 1e-5
vpa(1 + h/2. - h^2/8., 40)
vpa(1 - h/2. - h^3/16., 40)