# About
Compilation of Julia code for Calculus learning for Undergraduate degree.

#### based on Lasthrim Projection book 

# Example to Plot with Julia (Using Julia file and Type directly at REPL)

To try Julia file (.jl) open Julia REPL first:
```
julia

```

Check if the current working directory contains the file you want to try then type
```
include("ch0-5-plotimaginary.jl")
```
![Julia](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/Julia/images/plotimaginary.png)

If you want to try to plot any kind of function then type
```
Using Plots
pyplot()
f(x) = log(x^3)
plot(f, -51, 51)
```
![Julia](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/Julia/images/Logfunction.png)

For plotting complex numbers with Polar coordinate type:
```
using PyPlot
nums = ComplexF64.([1,2,4],[2,2,-1])
polar.(Base.vect.(0.0,angle.(nums)),Base.vect.(0.0,abs.(nums)),marker="o")
```
![Julia](https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/Complex.png)
#### (More details on how to set up and install Julia can be seen at the glanzshamzs/Julia directory)

# Basic Plotting with Julia
The most basic usage for plotting a function follows this pattern:
```
plot(function_object, from, to)
```

example
```
Using Plots
pyplot()
plot(sin, 0, 2pi)
```


### Julia Learning Source

https://docs.julialang.org/en/v1/manual/getting-started/

https://docs.juliaplots.org/latest/input_data/#Functions

https://mth229.github.io/graphing.html

https://github.com/JuliaGraphs/GraphPlot.jl

https://www.math.csi.cuny.edu/~verzani/tmp/julia/graphing.html

https://stackoverflow.com/questions/70551977/how-to-plot-complex-numbers-in-julia

# Source of summarization
1. Calculus 9th Edition, Varberg-Purcell-Rigdon, Pearson Education International
