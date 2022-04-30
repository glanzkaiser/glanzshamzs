% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  runge_fun.m
%
% This is the degree-8 interpolating polynomial for 
% the function 1/(1+x^2) on the interval [-5,5], using
% Chebyshev notes.

a = -5, b = 5, n = 8

for i=1:n+1
  x(i) = 0.5*(a + b) + 0.5*(a - b)*cos( ((i-1)/n)*pi )
  y(i) = 1.0/(1.0 + x(i).^2)
end
p = polyfit(x, y, n)
z = linspace(a, b, 4*n+1)
f = polyval(p, z)
plot(x, y, 'o', z, f, '-')

