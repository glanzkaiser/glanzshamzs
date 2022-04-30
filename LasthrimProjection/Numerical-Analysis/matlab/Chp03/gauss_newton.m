% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  gauss_newton.m
%
% Newton's Mehtod for Solving Nonlinear System
% of Equations:
% Matlab 'fsolve' uses an advanced algorithm called
% the Gauss-Newton method.
% The M-file in which the function 'Fun' is defined
% is called 'Fun.m'.
% (Matlab Optimization Toolbox is used.)
  
 X0 = [0, 0, 0];
 X = fsolve('Fun', X0)