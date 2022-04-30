% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  rkf_ode45.m
%
% Matlab routine for Runge-Kutta-Fehlberg is called
% 'ode45'. Here we use this routine to solve the
% ODE over the interval [0,1] after setting the initial
% condition s and the error tolerance.
% The ODE is defined in the M-file 'ode45file1'.

type ode45file1
t = 0; x = 0;
tb = 10;
options = odeset('RelTol',1e-5,'AbsTol',1e-6)
[t,x] = ode45('ode45file1', [t tb], x, options)
plot(t,x)
