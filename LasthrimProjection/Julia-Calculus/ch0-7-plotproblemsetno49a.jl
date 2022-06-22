using Plots
pyplot()

function circleShape(h, k, r)
     θ = LinRange(0, 2*π, 500)
     h .+ r*sin.(θ), k .+ r*cos.(θ)
end

plot(circleShape(0, 0, 1), seriestype = [:shape,], lw = 0.5,
      c =:blue, linecolor = :black,
      legend = false, fillalpha = 0.2, aspect_ratio = 1, showaxis = false)

plot!([0], seriestype="vline", color=:green, label="")
plot!([0], seriestype="hline", color=:green, label="")
plot!([1.9021,0],[0.618,0], linecolor=:green, linestyle=:dash)
plot!([-1.1756,0],[-1.618,0], linecolor=:green, linestyle=:dash)
plot!(Plots.partialcircle(0,-8//4*pi,50,0.42), color=:red, arrow=true)
     
annotate!([(1.07,-0.15, ("r = 2 foot", 12, :red)),
           (0.37,2.10, ("t=0 / t=10", 12, :red)),
           (-1.27,-1.8, ("t=6", 12, :red)),
           (2.15,0.65, ("t=2", 12, :red))])

scatter!([-1.1756],[-1.618], color = "red", label="", markersize = 5)
scatter!([1.9021],[0.618], color = "red", label="", markersize = 5)
scatter!([0],[2], color = "red", label="", markersize = 5)
