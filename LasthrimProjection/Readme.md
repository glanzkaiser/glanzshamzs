# From Freya
(PRIORITY) Make Examples  for BLAS and LAPACK
using
gfortran -o solg example.f90 -lblas
gfortran -o solg solvinglinearequations.f90 -llapack -lblas

Compile files in the order they are needed:
gfortran -o maths area.f90 maths.f90

Create BLAS  / LAPACK examples in:
  1. Gaussian elimination
  2. Invers of matrix
  3. Multiplication, addition, subtraction of matrices
(I will add more, finish those three first -Freya)

# Lasthrim Reference

https://github.com/NaysanSaran/visualMath

https://docs.juliaplots.org/stable/

https://mitmath.github.io/18S096SciML/lecture2/ml

https://github.com/tonygallen/JPUG/blob/master/Plotting%20Tutorial.ipynb

https://www.analyticsvidhya.com/blog/2017/10/comprehensive-tutorial-learn-data-science-julia-from-scratch/

https://gist.github.com/gizmaa/7214002

https://numpy.org/numpy-tutorials/content/tutorial-svd.html

https://docs.scipy.org/doc/scipy/tutorial/optimize.html

https://www.youtube.com/watch?v=RNKVHQzvaRM

