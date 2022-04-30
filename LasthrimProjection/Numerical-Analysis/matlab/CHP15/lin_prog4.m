% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN: 0-534-35184-0
%
% file:  lin_prog4.m
% 
% Solving the linear programming problem:
% Minimize the function fun4(y) subject to given constraints.
% Here we select a starting guess, and choose a lower bound for
% the solution.
% M-file 'fun4.m' defines the objective function and the 
% inequality constraints.
% (Matlab Optimization Toolbox is used.)


 type fun4
 y0 = [0, 0, 0, 0];         % make a starting guess
 vlb = y0;                  % set lower bound for solution  =  0.0
 ymin = constr('fun4',y0,vlb)
 fmin = fun4(ymin)

