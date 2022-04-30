% Numerical Mathematics and Computing, Third Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
%
%
% file:  lin_prog1.m
% Solving linear program problem:
% Maximizing the function fun1(x) subject to given constraints.
% Here we select a starting guess and set the lower bound for 
% the solution. Matlab optimization function 'consts' perfoms
% minimization of f(x) and hence to maximize we calculate -f(x).
% The function fun1(x) and the constraints are defined in the 
% M-file 'fun1.m'.
% (Matlab Optimization Toolbox is used.)
 
type fun1
x0 = [1,1];
vlb = [0, 0];            % Set a lower bound for x
xmin = constr('fun1', x0, vlb)
fmax = -fun1(xmin)

