using Plots, LaTeXStrings
pyplot()

# write pi or π is the same

f(x) = 2*sin.(pi*x/5)
g(x) = sin.(pi*x/5) + cos.(pi*x/5)

p1 = plot(f, -5, 5)
p2 = plot(g, -5, 5)

s1 = L"y(t) = 2 sin(\pi t/5)";
s2 = L"y(t) = sin(\pi t/5) + cos(\pi t/5)";

plot(p1, p2, layout = (2, 1), xaxis = "x", yaxis = s1, label=[s1 s2], 
title=["Sum of two sine" "Sum of sine and cosine"],
titleloc = :bottom, titlefont = font(8))
