using Plots, LaTeXStrings
pyplot()

function circleShape(h, k, r)
     θ = LinRange(0, 2*π, 500)
     h .+ r*sin.(θ), k .+ r*cos.(θ)
end

plot(circleShape(0, 0, 1), seriestype = [:shape,], lw = 0.5,
      c =:blue, linecolor = :black,
      legend = false, fillalpha = 0.2, aspect_ratio = 1, showaxis = false)

t = L"45^0"
f(x) = x

plot!([0], seriestype="vline", color=:green, label="")
plot!([0], seriestype="hline", color=:green, label="")
plot!([0.707106781,0.707106781],[0.707106781,0], linecolor=:green, linestyle=:dash)
plot!(f, linecolor=:green, linestyle=:dash)
plot!(Plots.partialcircle(0,1//4*pi,100,0.1), color=:red, arrow=true)
plot!(Plots.partialcircle(0,1//4*pi), color=:red, linewidth=2)
     
annotate!([(1.1,0, ("x", 10, :red)), 
           (0.17,005, (t, 8, :red)),
           (0.15,1.03, ("y", 10, :red)), 
           (0.17,-0.1, ("O (0,0)", 10, :red)),
           (0.71,-0.1, ("B", 10, :red)),
           (-0.88,-1, ("y=x", 10, :red)),
           (0.42,0.073, ("x", 10, :red)),
           (0.66,0.33, ("x", 10, :red)),
           (0.37,0.46, ("1", 10, :red)),
           (1.08,-0.08, ("(1,0)", 10, :red)),
           (-0.1,1.03, ("(0,1)", 10, :red)),
           (0.73,0.87, ("P", 10, :red))])

scatter!([1], [0], color = "red", label="", markersize = 5)
scatter!([0.707106781], [0.707106781], color = "red", label="", markersize = 5)
