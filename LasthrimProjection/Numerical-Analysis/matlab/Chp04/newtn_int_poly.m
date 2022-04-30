% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: newtn_int_poly.m

% Newton interpolating polynomial for y=sin(x)

 a = 0, b = 1.6875, n = 9

% making 10 equdistant points in the interval [0,1.6875]
 X = linspace(a, b, n+1)

 Y = sin(X);

% polynomial fit of n degree 
 p = polyfit(X, Y, n);
 Z = linspace(a, b, 4*n+1)
 F = polyval(p, Z)
 E = sin(Z) - polyval(p, Z)
pause

 plot(X, Y, 'o', Z, F, '-')

 xplot = [a: .05: b];
 polyf = polyval(p, xplot);
 plot(xplot, polyf, '-')

%including the original 10 points in plot:
 plot(X, Y, 'o', xplot, polyf, '-')
 title('polynomial interpolation')

