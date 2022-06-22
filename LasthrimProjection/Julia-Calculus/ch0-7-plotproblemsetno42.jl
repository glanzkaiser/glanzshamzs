using Plots
pyplot()

function circleShape(h, k, r)
     θ = LinRange(0, 2*π, 500)
     h .+ r*sin.(θ), k .+ r*cos.(θ)
end

plot(circleShape(0, 0, 1), seriestype = [:shape,], lw = 0.5,
      c =:blue, linecolor = :black,
      legend = false, fillalpha = 0.2, aspect_ratio = 1, showaxis = false)

plot!([0.707106781,0],[0.707106781,0], linecolor=:green)
plot!([0.707106781,0],[-0.707106781,0], linecolor=:green)
plot!(Plots.partialcircle(-0.73,1//4*pi,100,0.21), color=:red, arrow=true)
plot!(Plots.partialcircle(-0.78,1//4*pi), color=:green, linewidth=2)
     
annotate!([(0.41,0.5, ("r", 17, :red)),
           (0.3,0, ("t", 17, :red))])
