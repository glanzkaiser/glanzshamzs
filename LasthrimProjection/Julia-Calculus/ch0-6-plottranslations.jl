using Plots
pyplot()

f(x) = abs(x)
g(x) = abs(x-3)
h(x) = abs(x)+2
i(x) = abs(x-3)+2

p1 = plot(f, -108, 108)
p2 = plot(g, -108, 108)
p3 = plot(h, -108, 108)
p4 = plot(i, -108, 108)

plot(p1, p2, p3, p4, layout = (2, 2), label=["y = |x|" "y = |x-3|" "y = |x|+2" "y = |x-3|+2"])
