% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: min_val1.m
%
% Minimizing the multivariate function
% q1(x,y) = x^2+y^2-2x-2y+4 close to the  point (0.5,0.5):
% M-file defining the function is called q1.m
% (Matlab Optimization Toolbox is used.)

 type q1
 xmin = fmins('q1',[0.5, 0.5])
 ymin = q1(xmin)  

