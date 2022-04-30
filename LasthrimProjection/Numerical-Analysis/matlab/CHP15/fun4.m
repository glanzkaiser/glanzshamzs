% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  fun4.m
%
% This M-file is invoked by the file 'lin_prog4.m'.

function [f,g] = fun4(y)
f = y(4);                                    % objective function
g(1) = 2*y(1) + 3*y(2) - 5*y(3) - y(4) - 4;  % inequality constraint
g(2) = y(1) - y(2) - y(4) - 2;               % inequality constraint
g(3) = y(1) + 2*y(2) - 3*y(3) - y(4) -7;     % inequality constraint
g(4) = -2*y(1) - 3*y(2) + 5*y(3) - y(4) +4;  % inequality constraint
g(5) = -y(1) + y(2) -y(4) + 2;               % inequality constraint
g(6) = -y(1) - 2*y(2) + 3*y(3) - y(4) + 7;   % inequality constraint
