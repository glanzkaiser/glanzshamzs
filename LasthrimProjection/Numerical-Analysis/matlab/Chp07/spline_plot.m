% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: spline_plot.m
%
% Plotting the cubic spline curve for the following data
% Matlab uses not-a-knot end condition for this procedure

xdata = [0.0 0.6 1.5 1.7 1.9 2.1 2.3 2.6 2.8 3.0 3.6 ...
         4.7 5.2 5.7 5.8 6.0 6.4 6.9 7.6 8.0]
ydata = [-0.8 -0.34 0.59 0.59 0.23 0.1 0.28 1.03 1.5 ...
         1.44 0.74 -0.82 -1.27 -0.92 -0.92 -1.04 -0.79 -0.06 1.0 0.0]
xspline = 0:0.1:8
yspline = spline(xdata, ydata, xspline)
plot(xdata, ydata,'o', xspline, yspline,'-')
title('Cubic spline curve')
xlabel('x axis'), ylabel('y axis')
