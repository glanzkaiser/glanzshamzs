using Plots, LaTeXStrings
pyplot() 
#gr()

f(x) = abs(x-1)/(x-1)
g(x) = abs(x-1)/(x-1)
h(x) = (x^2 - abs(x-1) - 1)/abs(x-1)
i(x) = (1/(x-1))-(1/abs(x-1))

p1 = plot(f, -8, 8)
p2 = plot(g, -8, 8)
p3 = plot(h, -8, 8)
p4 = plot(i, -8, 8)

l1 = L"\lim_{x \rightarrow 1} \frac{|x-1|}{x-1}"
l2 = L"\lim_{x \rightarrow 1^-} \frac{|x-1|}{x-1}"
l3 = L"\lim_{x \rightarrow 1^-} \frac{x^2 - |x-1| - 1}{|x-1|}"
l4 = L"\lim_{x \rightarrow 1^-} \frac{1}{x-1}-\frac{1}{|x-1|}"

plot(p1, p2, p3, p4, layout = (2, 2), xaxis = "x", yaxis = "y", label="", legend=:outertop,
title=[l1 l2 l3 l4],
titleloc = :bottom, titlefont = font(8))
