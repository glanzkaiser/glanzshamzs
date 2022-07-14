using Plots, LaTeXStrings
pyplot()

f(x) = -x
g(x) = x
h(x) = 1+x
#f(x) = (x^3 - 1) / (x-1)

plot(f,-10,-1, label=L"-x", legend=:outerright)
plot!(g,0,1, label=L"x", legend=:outerright)
plot!(h,1,10, label=L"1+x", legend=:outerright)

plot!([0], seriestype="vline", color=:black, label="")
plot!([0], seriestype="hline", color=:black, label="")
