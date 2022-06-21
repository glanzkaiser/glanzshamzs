using Plots, LaTeXStrings
pyplot()

t = L"$/theta$""
t1 = L"$/theta_1$""
t2 = L"$/theta_2$""
f(x) = x-1
g(x) = 3.33*x-5
l1 = L"$l_1$"
l2 = L"$l_2$"

plot!([0], seriestype="vline", color=:black, legend=false)
plot!([0], seriestype="hline", color=:black)
plot!(f, linecolor=:green)
plot!(g, linecolor=:green)
plot!(Plots.partialcircle(0,1//14*pi,50,1.33), color=:red, arrow=true)
plot!(Plots.partialcircle(0,1//10*pi,100,1.75), color=:red, arrow=true)
     
annotate!([(1.81,0.9, (t, 8, :red)), 
           (2.05,1.07, (l1, 8, :red)),
           (2.05,1.66, (l2, 8, :red)),
           (1.37,0.173, (t1, 8, :red)),
           (1.75,0.25, (t2, 8, :red))])
