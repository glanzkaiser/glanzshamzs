% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  ls_fit.m
%
% Fitting a linear least square polynomial to 
% the given data.  This Matlab program evaluates
% a and b for the Linear Least Squares.
% 'polyfit' fits a polynomial of degree n, here
% n = 1. 

% evaluating a and b for Linear Least Squares:
 xdata = [1.0 2.0 2.5 3.0]
 ydata = [3.7 4.1 4.3 5.0]
 ls = polyfit(xdata, ydata, 1)
 pause

% evaluating the value of the function phi:
 d =ls(1)*xdata + ls(2) - ydata
 phi = sum(d.^2)	
 pause

% plotting the linear least square on a finer data range:
 x = 1:0.1:3
 y = polyval(ls, x)
 plot(xdata, ydata, 'o', x, y, '-')
 title('Linear least squares fit')
 xlabel('x axis'), ylabel('y axis')

