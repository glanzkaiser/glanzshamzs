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
plot!(Plots.partialcircle(1.55,-1//36*pi,50,0.6), color=:red, arrow=true)
     
annotate!([(1.07,-0.15, ("r = 2 foot", 10, :red)),
           (0.37,2.10, ("t=0 / t=10", 10, :red)),
           (2.21,-0.17, ("(2,0)", 10, :red)),
           (2.05,0.15, ("t=2.5", 10, :red))])

scatter!([2],[0], color = "red", label="", markersize = 5)
