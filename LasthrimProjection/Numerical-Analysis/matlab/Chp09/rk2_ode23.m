% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  rk2_ode23.m
%
% Solving ODE using Runge-Kutta method
% The ODE is defined in the M-file 'ode23file2'.
% Matlab 'ode23' is the second/third Runge-Kutta 
% solver which simulates the numerical solution 
% for the ODE over the interval of interest.

type ode23file2
pause
ta = 0; tb =1;
t = ta
X = [1, 0]
options = odeset('RelTol',1e-5,'AbsTol',1e-6)
[t, X] = ode23('ode23file2', [ta, tb], X, options)
plot(t, X)