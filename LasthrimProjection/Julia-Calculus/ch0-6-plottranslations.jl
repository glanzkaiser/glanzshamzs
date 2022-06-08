Using plots
pyplot()

f(x) = abs(x)
g(x) = abs(x-3)
h(x) = abs(x)+2
i(x) = abs(x-3)+2

plot(f, g, h, i, layout = (2, 2), label=["y = |x|" "y = |x-3|" "y = |x|+2" "y = |x-3|+2"],
    title=["1" "2" "3" "4"])
