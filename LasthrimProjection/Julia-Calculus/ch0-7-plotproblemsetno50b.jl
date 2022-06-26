using Plots, LaTeXStrings
pyplot()

# write pi or π is the same

f(x) = 3*cos.(pi*x/5 - 2)
g(x) = cos.(pi*x/5)
h(x) = cos.(pi*x/5 - 3)
i(x) = f(x) + g(x) + h(x)

p1 = plot(f, -5, 5)
p2 = plot(g, -5, 5)
p3 = plot(h, -5, 5)
p4 = plot(i, -5, 5)

s1 = L"y(t) = 3 cos((\pi t/5) - 2)";
s2 = L"y(t) = cos(\pi t/5)";
s3 = L"y(t) = cos((\pi t/5) - 3)";
s4 = L"y(t) = 3 cos((\pi t/5) - 2) + cos(\pi t/5) + cos((\pi t/5) - 3)";

plot(p1, p2, p3, p4, layout = (4, 1), xaxis = "x", yaxis = s1, label="", 
title=[s1 s2 s3 s4],
titleloc = :bottom, titlefont = font(8))
