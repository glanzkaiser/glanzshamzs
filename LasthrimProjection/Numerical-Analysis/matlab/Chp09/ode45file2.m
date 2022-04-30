% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  ode45file2.m
%
% This M-file is invoked by the file 'RKF2_ODE45.m'.

function xprime = ode45file2(t,X) 
xprime = zeros(5,1);
xprime(1) = X(2);
xprime(2) = X(1) - X(3) - 9*X(2)^2 + X(4)^3 + 6*X(5) + 2*t;
xprime(3) = X(4);
xprime(4) = X(5);
xprime(5) = X(5) - X(2) + exp(X(1)) - t;