% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: np_ls_fit.m
% 
% Method of Least Squares for a non-polynomial fit:
% First we creat a regression matrix X. Next, coefficients
% a, b, and c are calculated by the command X/ydata.
% The function phi is evaluated, and finally the Least 
% Squares fit is plotted.

  xdata = [0.24 0.65 0.95 1.24 1.73 2.01 2.23 2.52 2.77 2.99]'
  ydata = [0.23 -0.26 -1.10 -0.45 0.27 0.10 -0.29 0.24 0.56 1.00]'
  X = [log(xdata) cos(xdata) exp(xdata)]
  z = X\ydata 
  pause
  d = z(1)*log(xdata) + z(2)*cos(xdata) + z(3)*exp(xdata) - ydata
  phi = sum(d.^2)
  pause

% To plot we evaluate the model at equidistant finer mesh and
% overlay the original points:
  xi = (0.24: 0.1 :2.99)
  yi = z(1)*log(xi) + z(2)*cos(xi) + z(3)*exp(xi)
  plot(xdata, ydata, 'o', xi, yi, '-'), grid on
  title('Nonpolynomial least squares fit')
  xlabel('x axis'), ylabel('y axis')
