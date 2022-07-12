using Plots,LaTeXStrings,Colors
gr()

f(x) = floor(x)
x = 0:1:4
y = f.(x)
plot(x[1:2], [y[1], y[1]], label=L"f(x) = \lfloor x \rfloor", legend=:topleft,legend_foreground_color=:white, legend_font_color=:blue3, color=:blue3, showaxis=false, tickfontcolor=:white)
# axis and 
hline!((0,0), color=:black, label="")
vline!((0,0), color=:black, label="")
for i in x
	if i!= 0
		annotate!(i,-0.2, (i, 7))
	end
end
for i in y
	if i != 0
		annotate!(-.2, i, (i, 7))
	end
end
annotate!(-.2, -.2, ("0", 7))
for i in 2:length(x)-1
	plot!(x[i:i+1], [y[i], y[i]], label="", color=:blue3, lw=2)
	scatter!(x[i], y[i], marker=:circle, markersize=8, label="")
end
scatter!(x[1:end-1], y[1:end-1], markersize=3, markercolor=:blue4, label="")
scatter!(x[2:end], y[1:end-1], markersize=3, markercolor=:white, label="")
