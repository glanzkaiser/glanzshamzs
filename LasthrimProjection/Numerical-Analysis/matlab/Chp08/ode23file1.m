% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  ode23file1.m
%
% This M-file is invoked by the file 'RK_ode23.m'.

function xprime = ode23file1(t,x) 
xprime = 2.0 + (x - t -1.0)^2;
