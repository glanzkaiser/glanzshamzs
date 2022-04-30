% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: rkf2_ode45.m
%
% Solving ODE system using Matlab 'ode45' procedure,
% which is the Runge-Kutta-Fehlberg routine.
% the M-file defining the ODE is 'ode45file2'.

type ode45file2
ta = 1; tb = 1.5;
t = ta
X = [2 -4 -2 7 6]
options = odeset('RelTol',1e-5,'AbsTol',1e-6)
[t, X] = ode45('ode45file2', [ta, tb], X, options)
plot(t,X)
