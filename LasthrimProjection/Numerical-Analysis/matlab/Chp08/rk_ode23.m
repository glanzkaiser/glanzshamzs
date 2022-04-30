% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: rk_ode23.m
%
% Here we first set the initial conditions, and the
% final t value.  Next we invoke the second/third
% Runge-Kutta solver ode23 to simulate the numerical
% solution.  Finally plot the solution over the 
% interval of interest.
% M-file defining the ODE is 'ode23file1.m'.

type ode23file1
t = 1; x = 2;
tb = 1.5625;
[t,x] = ode23('ode23file1', [t tb], x)
plot(t,x)
