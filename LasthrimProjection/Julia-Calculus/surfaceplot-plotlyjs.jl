using Plots, LaTeXStrings, Plots.PlotMeasures 
plotlyjs()

x = collect(-5:0.5:5)
y = collect(-5:0.5:5)

z(x, y) = 2*x - 3*y + 2

plot(x, y, z, st = :surface, camera = (10, 10))
