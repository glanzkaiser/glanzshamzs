using Plots, LaTeXStrings
pyplot()

# write pi or π is the same

f(x) = 3*sin.(pi*x/5)
g(x) = 5*cos.(pi*x/5)
h(x) = 2*sin.((pi*x/5) - 3)
i(x) = f(x) - g(x) + h(x)

p1 = plot(f, -5, 5)
p2 = plot(g, -5, 5)
p3 = plot(h, -5, 5)
p4 = plot(i, -5, 5)

s1 = L"y(t) = 3 sin(\pi t/5)";
s2 = L"y(t) = 5 cos(\pi t/5)";
s3 = L"y(t) = 2 sin((\pi t/5) - 3)";
s4 = L"y(t) = 3 sin(\pi t/5) - 5 cos(\pi t/5) + 2 sin((\pi t/5) - 3)";

plot(p1, p2, p3, p4, layout = (4, 1), xaxis = "t", yaxis = "y(t)", label="", 
title=[s1 s2 s3 s4],
titleloc = :bottom, titlefont = font(8))
