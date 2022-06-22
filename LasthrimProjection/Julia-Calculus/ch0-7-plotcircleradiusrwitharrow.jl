using Plots, LaTeXStrings
pyplot()

function circleShape(h, k, r)
     θ = LinRange(0, 2*π, 500)
     h .+ r*sin.(θ), k .+ r*cos.(θ)
end

plot(circleShape(0, 0, 1), seriestype = [:shape,], lw = 0.5,
      c =:blue, linecolor = :black,
      legend = false, fillalpha = 0.2, aspect_ratio = 1, showaxis = false)

t = L"$\theta$"

plot!([0], seriestype="vline", color=:green, label="")
plot!([0], seriestype="hline", color=:green, label="")
plot!([-0.707106781,0],[-0.707106781,0], linecolor=:green)
plot!(Plots.partialcircle(0,1//4*pi,10,0.1), color=:red, arrow=true)
plot!(Plots.partialcircle(0,1//4*pi), color=:red, linewidth=2)
     
annotate!([(0.17,005, (t, 10, :red)),
           (-0.88,0.81, ("(x,y)", 10, :red)),
           (-0.51,0.37, ("r", 10, :red))])

scatter!([0.707106781], [0.707106781], color = "red", label="", markersize = 5)
