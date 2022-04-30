% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  ode45file1.m
%
% This M-file is invoked by the file 'RKF_ode45.m'.

function xprime = ode45file1(t,x) 
xprime = 3.0 + 5.0*sin(t) + 0.2*x;
