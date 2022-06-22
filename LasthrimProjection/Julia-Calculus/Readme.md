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

For plotting multiple plots at once (translations example):
```
using Plots, LaTeXStrings
pyplot()

f(x) = sqrt(x)
g(x) = sqrt(x-3)
h(x) = sqrt(x)+2
i(x) = sqrt(x-3)+2

p1 = plot(f, -8, 8)
p2 = plot(g, -8, 8)
p3 = plot(h, -8, 8)
p4 = plot(i, -8, 8)

s1 = L"y = \sqrt{x}";
s2 = L"y = \sqrt{x-3}";
s3 = L"y = \sqrt{x}+2";
s4 = L"y = \sqrt{x-3}+2";

plot(p1, p2, p3, p4, layout = (2, 2), xaxis = "x", yaxis = s1, label=[s1 s2 s3 s4], 
title=["Original function" "Translated 3 units to the right" "Translated upward by 2 units" "Translated 3 units to the right then 2 units upward"],
titleloc = :bottom, titlefont = font(8))
```

## Lasthrim' Galleries for Julia-Calculus

| Modified Axes | Complex Plot | Translations (Multiple Plots) | Right Side Triangle |
| ------------- | ------------- | ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/sin18x.png?raw=true" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/Complex.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/sqrtx.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/rightsidetriangle.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-Calculus/plotmodifiedaxes.jl">plotmodifiedaxes.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-Calculus/ch0-5-plotimaginary2.jl">ch0-5-plotimaginary2.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-Calculus/ch0-6-plottranslations2.jl">ch0-6-plottranslations2.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-Calculus/ch0-7-plotrighttriangle.jl">ch0-7-plotrighttriangle.jl</a> |

| Unit Circle | Rosenbrock Function | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/unitcirclewitharrow.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/rosenbrock2.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-Calculus/ch0-7-plotunitcircle4witharrow.jl">ch0-7-plotunitcircle4witharrow.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-Calculus/rosenbrockfunction2.jl">rosenbrockfunction2.jl</a> | 

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
### Root(im)

![Julia](https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/root(im).png)

### Julia Learning Source

https://computationalthinking.mit.edu/Spring21/

https://diffeq.sciml.ai/stable/basics/plot/

https://discourse.julialang.org/t/how-to-solve-this-ax-b-faster/81693

https://docs.julialang.org/en/v1/manual/getting-started/

https://docs.juliaplots.org/latest/input_data/#Functions

https://github.com/barche/Trilinos.jl

https://github.com/goropikari/PlotsGallery.jl

https://github.com/JuliaGraphs/GraphPlot.jl

https://github.com/orgs/JuliaParallel/repositories?type=all

https://mth229.github.io/graphing.html

https://stackoverflow.com/questions/70551977/how-to-plot-complex-numbers-in-julia

https://uilis.unsyiah.ac.id/oer/files/original/aa4c33bd9eeba8b979b3033a615b60c8.pdf

https://www.math.csi.cuny.edu/~verzani/tmp/julia/graphing.html

http://www2.math.uu.se/~xinca341/euclidean-plane-geometry-with-julia.html

#### Polygon

https://juliagraphics.github.io/Luxor.jl/v0.9.1/polygons.html#Regular-polygons-(%22ngons%22)-1

#### PyPlot

https://gist.github.com/floswald/d62488c28af2e803da6d

https://www.juliapackages.com/p/implicit3dplotting

# Source of summarization
1. Calculus 9th Edition, Varberg-Purcell-Rigdon, Pearson Education International
