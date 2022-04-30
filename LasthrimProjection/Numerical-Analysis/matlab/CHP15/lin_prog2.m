% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  lin_prog2.m
%
% Solving linear programming problem:
% Minimize the function fun2(x) subject to given constraints.
% The function fun2(x) and the constraints are defined in 
% the M-file 'fun2.m'. 
% (Matlab Optimization Toolbox is used.)

 type fun2
 y0 = [0, 0];              % make a starting guess
 vlb = y0;                 % set a lower bound for the solution 
 xmin = constr('fun2',y0, vlb)
 fmin = fun2(xmin)
 
