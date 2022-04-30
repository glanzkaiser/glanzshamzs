% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  spline_sin_plot.m
%
% Plotting the cubic spline curve for sin function:
% First, the original data of 9 points are generated, 
% next, a finer subdivision of the interval [a,b] on the
% x-axis is made and the corresponding y-values are 
% obtained from the procedure spline.  Finally,
% the original data points and the spline curve are plotted.  
% To plot Matlab uses not-a-knot end condition.

 a = 0, b = 1.6875, n = 9
 xdata = linspace(a, b, n+1)
 ydata = sin(xdata)
 xspline = linspace(a, b, 4*n+1)
 yspline = spline(xdata, ydata, xspline)
 plot(xdata, ydata, 'o', xspline, yspline, '-')
 xlabel('x axis'), ylabel('y axis')
 title('Natural cubic spline interpolation for y = sin(x)')







