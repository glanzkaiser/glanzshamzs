using Plots, LaTeXStrings
pyplot()

function Area(f, a, b, n)
xs = a:(b-a)/n:b
deltas = diff(xs)
cs = xs[1:end-1]
sum(f(cs[i]) * deltas[i] for i in 1:length(deltas))
end

f(x) = x^2
Area(x -> x^2, 0, 1, 50_000)

plot(f,0,1, label=L"y = x^2", legend=:outertop)
annotate!([(0.77,0.95, ("Area = ", 11, :black)),
	  (0.77,0.85, (Area(x -> x^2, 0, 1, 50_000), 11, :black))])
