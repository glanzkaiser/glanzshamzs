% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: lin_prog3.m
%
% Solving the linear programming problem: 
% Minimize function fun3(y) subject to given equality constraints.
% Here we select a starting guess, and choose a lower bound
% for the solution.  We also indicate there are three equality 
% constraints by setting option(13) = 3. 
% M-file 'fun3.m' defines the function and the given constraints.
% (Matlab Optimization Toolbox is used.)

 type fun3
 y0 = [0,0,0,0,0,0,0,0,0];   
 options(13) = 3;            
 vlb = y0;                   
 ymin = constr('fun3',y0,options,vlb)
 fmin = fun3(ymin)

