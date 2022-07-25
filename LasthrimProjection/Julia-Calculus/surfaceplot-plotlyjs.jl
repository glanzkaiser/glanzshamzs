using LaTeXStrings, Plots
plotlyjs()

x = collect(-5:0.5:5)
y = collect(-5:0.5:5)

z(x, y) = x^2 - 3*y + 2

l = L"x^2 - 3y + 2"

plot(x, y, z, st = :surface, camera = (10, 10),
           extra_plot_kwargs = KW(
               :include_mathjax => "cdn",
               :yaxis => KW(:automargin => true),
               :xaxis => KW(:domain => "auto")
               ),
       )
title!(l)
savefig("test.html")
