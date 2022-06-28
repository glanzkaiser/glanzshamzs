using Plots 
pyplot()

@gif for i in 1:50
    plot(sin, 0, i * 2pi / 10)
end
