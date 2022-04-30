% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: min_val2.m
%
% Find local minimum values for the function
% q2(x) = x^2 + sin(53x) on the intervla [-2 , 2]:
% M-file defining the function is called q2.m
% (Matlab Optimization Toolbox is used.)

 xmin = fmin('q2',-2,2)  
 ymin = q2(xmin)
 fplot('q2',[-2 2])
 title('q(x) = x^2 + sin(53x)')
 xlabel('x axis'), ylabel('y axis')