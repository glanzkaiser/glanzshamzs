# About
Julia is a high-level, high-performance, dynamic programming language. While it is a general-purpose language and can be used to write any application, many of its features are well suited for numerical analysis and computational science.

Julia is garbage-collected, uses eager evaluation, and includes efficient libraries for floating-point calculations, linear algebra, random number generation, and regular expression matching. Many libraries are available, including some (e.g., for fast Fourier transforms) that were previously bundled with Julia and are now separate.

# Notable Uses
Julia has attracted some high-profile users, from investment manager BlackRock, which uses it for time-series analytics, to the British insurer Aviva, which uses it for risk calculations. Since 2015, the Federal Reserve Bank of New York has used Julia to make models of the United States economy (including estimating COVID-19 shocks in 2021), noting that the language made model estimation "about 10 times faster" than its previous MATLAB implementation. 

Julia was selected by the Climate Modeling Alliance as the sole implementation language for their next generation global climate model. This multi-million dollar project aims to build an earth-scale climate model providing insight into the effects and challenges of climate change.

Julia is used by NASA, e.g. for modeling spacecraft separation dynamics (15,000 times faster than before with Simulink/MATLAB and the Brazilian INPE for space mission planning and satellite simulation. Another effort is working on an embedded project to control a satellite in space using Julia for attitude control.

# Achievement
Julia joins C, C++, and Fortran as high-level languages in which petaFLOPS computations have been achieved. 

# Download Julia 
With GFreya OS type:
```
wget https://julialang-s3.julialang.org/bin/linux/x64/1.7/julia-1.7.2-linux-x86\_64.tar.gz
```

# Adjust Environment Variables
Type
```
vim ~/export
```
then:
1. Add export JULIA_DIR="$hamzstlib/julia-1.7.2
2. Add JULIA_DIR/bin to PATH

# Run the Example
For the test.c, it is a C code to calculate the square root of a number but calculated using Julia library:
```
test -fPIC -I$JULIA_DIR/include/julia -L$JULIA_DIR/lib -Wl,-rpath,$JULIA_DIR/lib test.c -ljulia
```

# Install Packages
in Julia you can easily install the packages when entering Julia interpreter by typing:\\
```
julia
]
add TaylorSeries
```
You can browse for the package that you want here:

https://juliapackages.com/packages
		
To remove packages, use rm, from Julia REPL type:
```
rm TaylorSeries
```

If you want to know all the installed packages for Julia in GFreya OS are in
#### ~/.julia/packages 

If you want to know which directory is Julia in type:\\
```
pwd()
```

To move the working directory in Julia REPL type:
```
cd("/opt/hamzstlib/glanzshamzs/glanzshamzs/Julia/Plots")
```

# Test Julia file (Plot with Julia)

To try Julia file (.jl) open Julia first:
```
julia

```

Check if the current working directory contains the file you want to try then type
```
include("trigonometrysincos.jl")
```

# Homework
1. Plot even and odd functions
2. Sketch graph 2/(x-1)
3. Plot absolute value function and greatest integer function

https://discourse.julialang.org/t/how-to-solve-this-ax-b-faster/81693

https://github.com/barche/Trilinos.jl

https://github.com/orgs/JuliaParallel/repositories?type=all
