using Plots, LaTeXStrings, Plots.PlotMeasures 
gr()
# pyplot()

f(x) = log(1/(x^2))

l1 = L"f(x) = log \frac{1}{x^2}"
l2 = L"L = log \frac{1}{0.7^2}"

# xlims defines the most left and right bound for x axis
# ylims defines the top and bottom bound for y axis
# xticks defines the increments of the x axis' ticks
# yticks defines the increments of the y axis' ticks


plot(f, xaxis = "", xlims=(-10,10), ylims=(-10,10), xticks=nothing, yticks=nothing, yaxis = "", label=l1,
	left_margin = 12mm, bottom_margin = 10mm, legend=:outertop)

plot!([2.03], seriestype="hline", color=:black, label="")
plot!([-0.97], seriestype="hline", color=:black, label="")
plot!([2.03], seriestype="vline", color=:black, label="")
plot!([-0.37], seriestype="vline", color=:black, label="")
plot!([-10,0.7],[f(0.7),f(0.7)], linecolor=:green,label=l2,legend=:outertop, linestyle=:dash)
plot!([0.7,0.7],[-10,f(0.7)], label="", linecolor=:green, linestyle=:dash)

scatter!([0.7], [f(0.7)], color = "red", label="", markersize = 3)

annotate!([(-11,f(1.9), ( L"L - \varepsilon", 10, :black)),
         (-11,f(0.23), ( L"L + \varepsilon", 10, :black)),
	 (0.776,-11.37, ("c", 10, :green)),
	 (-11,f(0.7), ("L", 10, :green)),
	 (9.736,-10.77, ("x", 10, :black)),
	 (-9.176,8.97, ("f(x)", 10, :black))])
