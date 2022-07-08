using Plots, LaTeXStrings
pyplot()

g(x, a) = a * x^3 * (1 - x);

f(x) = x^3 * (1 - x)

fig = plot(ratio=1, xlims=(0, 1), ylims=(0, 1)); # produces an empty plot
    
for a in (0.51, 2, 3.2, 3.8) 
    plot!(fig, 0:0.01:1, x -> g(x, a), label=L"a = %$a", legend=:outerright) # the loop fills in the plot with this
end

plot!(f, ls=:dash, label=L"y = x^{3} (1 - x)", legend=:outerright)

# plot!(x -> x, ls=:dash, label=L"y = x^{3} (1 - x)", legend=:outerright)
