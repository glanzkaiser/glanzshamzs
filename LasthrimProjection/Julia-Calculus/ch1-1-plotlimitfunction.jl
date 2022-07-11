using Plots, LaTeXStrings
pyplot()

#f(x) = sin.(x)/(x)
f(x) = (x^3 - 1) / (x-1)

plot(f,-30,30, label=L"\frac{x^3 - 1}{x-1}", legend=:outertop)
plot!([0], seriestype="vline", color=:green, label="")
plot!([0], seriestype="hline", color=:green, label="")

annotate!([(30.3,23.3, ("x", 10, :black)), 
           (3.03,933.07, ("y", 10, :black))])
