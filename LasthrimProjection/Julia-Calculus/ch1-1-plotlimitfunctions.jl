using Plots, LaTeXStrings
pyplot()
#gr()

f(x) = sin.(55/x)
g(x) = cos.(1/x + 10)
h(x) = x^(1/3)
i(x) = 36.93836*(tan.(1/x))
j(x) = log(x)
#1.709975946676697
#f(x) = (x^3 - 1) / (x-1)

# Plot the functions
plot(f,-23,-1, label=L"f(x) = \sin \frac{55}{x}", legend=:outerright)
plot!(g,-1,5, label=L"g(x) = \cos \frac{1}{x}+10", legend=:outerright)
plot!(h,5,15, label=L"h(x) = \sqrt[3]{x}", legend=:outerright)
plot!(i,14,23, label=L"i(x) = 36.93836\tan \frac{1}{x}", legend=:outerright)
plot!(j,13,23, label=L"j(x) = \log(x)", legend=:outerright)

# Plot the axis x=0 and y=0
plot!([0], seriestype="vline", color=:black, label="")
plot!([0], seriestype="hline", color=:black, label="")

# Put the scatters
scatter!([-1], [f(-1)], color = "white", label="", markersize = 2)
scatter!([-1], [g(-1)], color = "white", label="", markersize = 2)
scatter!([5], [g(5)], color = "white", label="", markersize = 2)
scatter!([5], [h(5)], color = "white", label="", markersize = 2)
scatter!([15], [h(15)], color = "red", label="", markersize = 2)
scatter!([14], [i(14)], color = "white", label="", markersize = 2)
scatter!([14], [j(14)], color = "blue", label="", markersize = 2)

t11 = L"$\lim_{x \rightarrow -1^{-}} f(x)$ does not exist"
t12 = L"$\lim_{x \rightarrow -1^{+}} g(x) = -0.91113$"
t21 = L"$\lim_{x \rightarrow 5^{-}} g(x) = -0.71426$"
t22 = L"$\lim_{x \rightarrow 5^{+}} h(x) = 1.70997$"
t23 = L"$\lim_{x \rightarrow 5} h(x)$ does not exist"
t31 = L"$\lim_{x \rightarrow 15} h(x) = 2.46621$"
t32 = L"$\lim_{x \rightarrow 14} j(x) = 2.63906$"

# Descriptions
annotate!([(-8.85,1.35, (t11, 6, :black)),
           (8.85,-0.911, (t12, 6, :black)),
	   (10.85,-0.61, (t21, 6, :black)),
	   (8.85,1.66, (t22, 6, :black)),           
	   (8.85,1.33, (t23, 6, :black)),	   
	   (24.85,2.46, (t31, 6, :black)),           
	   (8.85,2.93, (t32, 6, :black))])

