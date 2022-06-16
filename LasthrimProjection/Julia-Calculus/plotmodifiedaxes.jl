using Plots
pyplot()

f(x)=sin(18*x)

plot(
    f, 0, 6,
    legend=false, 
    framestyle=:origin,
    yticks=(-3:3, ["$i" for i in 0:6])
)
