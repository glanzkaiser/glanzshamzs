using Plots
pyplot()

f(x)=x-3

plot(
    f, 0, 5,
    legend=false, 
    framestyle=:origin,
    yticks=(-3:3, ["$i" for i in 0:6])
)
