using Plots, Measures

x = [3, 5, 7, 9];
y = [10, 20, 30 , 40];
z = [-10, -20, -30, -40];

a = plot(1:10, color = :black, legend = false)

b = plot(x, y, color=:green, legend=false, margin=10mm)
scatter!(twinx(), x, z, color=:orange, legend=false, xlims=xlims(a))

plot(a, b, layout = (2, 1), link=:x, tickfontcolor=:black)
