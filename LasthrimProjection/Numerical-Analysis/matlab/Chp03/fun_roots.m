% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: fun_roots.m 
% 
% Finding the roots of fuctions f and g
fzero('x^3 - 3*x + 1', 0.5)
pause
fzero('x^3 - 2*sin(x)', 1.5)
pause

% Alternative to find roots of the polynomial
% function f

p = [1 0 -3 1]
r = roots (p)
pause

% A general approach for finding roots of the
% function g, after creating M-file 'G.m'

type G
azero = fzero('G',1.0)
pause

% To make sure that we find zeros in a given interval

tol = 1e-5        %tolerance for the convergence
trace = 1         % display some information at each iteration
azero = fzero('G',[0.5 2],tol,trace)

