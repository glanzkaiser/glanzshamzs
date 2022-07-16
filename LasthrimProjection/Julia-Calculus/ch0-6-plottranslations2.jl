using Plots, LaTeXStrings
pyplot()

f(x) = sqrt(x)
g(x) = sqrt(x-3)
h(x) = sqrt(x)+2
i(x) = sqrt(x-3)+2

p1 = plot(f, -8, 8)
p2 = plot(g, -8, 8)
p3 = plot(h, -8, 8)
p4 = plot(i, -8, 8)

s1 = L"y = \sqrt{x}";
s2 = L"y = \sqrt{x-3}";
s3 = L"y = \sqrt{x}+2";
s4 = L"y = \sqrt{x-3}+2";

plot(p1, p2, p3, p4, layout = (2, 2), xaxis = "x", yaxis = "y", label=[s1 s2 s3 s4], 
title=["Original function" "Translated 3 units to the right" "Translated upward by 2 units" "Translated 3 units to the right then 2 units upward"],
titleloc = :bottom, titlefont = font(8))
