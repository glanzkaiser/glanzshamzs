% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  ode23file2.m
%
% This M-file is invoked by the file 'RK2_ODE23.m'.

function xprime = ode23file2(t,X)
xprime = zeros(2,1);
xprime(1) = X(1) - X(2) + t*(2 - t*(1 +t));
xprime(2) = X(1) + X(2) - t*t*(4 - t);