% Numerical Mathematics and Computing, Fourth Edition
% Ward Cheney & David Kincaid
% Brooks/Cole Publ. Co.
% (c) 1999
% ISBN/ISSN:  0-534-35184-0
%
% file: sin_plot.m
%
% This file obtains a plot of sin(x), along with plots
% of the first three partial sums of the Taylor series.
% M-files 's1.m', 's2.m', and 's3.m' define the partial
% sums.

 fplot('[s1(x),s2(x),s3(x),sin(x)]',[-pi,pi]);
 xlabel ('x axis')
 ylabel ('y axis')
 title ('Partial sums of the Taylor series for sin(x)')
 print -dps myplot   % 'print' command saves the plot in 'myplot.ps'



