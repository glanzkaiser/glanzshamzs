% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file:  p_inv1.m
%
% Evaluating minimal solution using Pseudoinverse of A in Ax=b:
% Input a random matrix A and a random vector b. Find the 
% Pseudoinverse of A based on singular value decomposition method.
% Compute the minimal solution and the residual vector.  Finally,
% chech the orthogonality condition: (transpose of A)*r = 0.0.
 
 A = randn(20, 3)
 b = randn(20, 1)
 pause
 Aplus = pinv(A)
 xmin = Aplus*b
 pause
 r = A*xmin - b
 A'*r            %where A' is the transpose of the matrix A

