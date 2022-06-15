using Plots, LaTeXStrings
pyplot()

function circleShape(h, k, r)
     θ = LinRange(0, 2*π, 500)
     h .+ r*sin.(θ), k .+ r*cos.(θ)
end

plot(circleShape(0, 0, 1), seriestype = [:shape,], lw = 0.5,
      c =:blue, linecolor = :black,
      legend = false, fillalpha = 0.2, aspect_ratio = 1, showaxis = false)

p1 = L"P_3 (x,y)"
p2 = L"P_4 (y,x)"
f(x) = x

plot!([0], seriestype="vline", color=:green, label="")
plot!([0], seriestype="hline", color=:green, label="")
plot!(f, linecolor=:green, linestyle=:dash)

annotate!([(1.1,0, ("x", 10, :red)), 
           (0.15,1.03, ("y", 10, :red)), 
           (0.1,-0.1, ("(0,0)", 10, :red)),
           (-0.88,-1, ("y=x", 10, :red)),
           (1.08,0.51, (p1, 10, :red)),
           (0.73,0.87, (p2, 10, :red))])

scatter!([0.50], [0.866025404], color = "red", label="", markersize = 5)
scatter!([0.866025404], [0.50], color = "red", label="", markersize = 5)
