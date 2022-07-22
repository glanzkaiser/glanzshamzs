using Plots, LaTeXStrings
gr()
#pyplot()

f(x) = 3*(x^2)

l1 = L"3x^2"
l2 = L"\sqrt{\frac{11.97}{3}}"
l3 = L"\sqrt{\frac{12.03}{3}}"

# xlims defines the most left and right bound for x axis
# ylims defines the top and bottom bound for y axis
# xticks defines the increments of the x axis' ticks
# yticks defines the increments of the y axis' ticks

plot(f, xaxis = "x", xlims=(1.98,2.05), ylims=(11.85,12.15), xticks = 1.9:0.01:3., yticks = 11:0.05:13., yaxis = "y", label=l1, legend=:outertop)

plot!([12.03], seriestype="hline", color=:black, label="")
plot!([11.97], seriestype="hline", color=:black, label="")
plot!([sqrt(11.97/3),sqrt(11.97/3)],[0,11.97], label="", linecolor=:green, linestyle=:dash)
plot!([sqrt(12.03/3),sqrt(12.03/3)],[0,12.03], label="", linecolor=:green, linestyle=:dash)

annotate!([(1.985,12.04, ("y=12.03", 7, :black)),
         (1.985,11.98, ("y=11.97", 7, :black)),
	 (1.996,11.82, (l2, 7, :green)),
	 (2.004,11.82, (l3, 7, :green))])
