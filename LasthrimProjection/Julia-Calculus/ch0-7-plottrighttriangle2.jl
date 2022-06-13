using Plots
pyplot()

function RightTriangle(x0, y0, θ, L1, L2)
    s, c = sincosd(θ)
    x1, y1 = L1 .* (c,s) 
    return Shape(x0 .+ [0, x1, x1 - L2*s], y0 .+ [0, y1, y1 + L2*c])
end

RT = RightTriangle(0, 0, 30, 1, 2)
plot(RT, lc=:black, lw=0.5, leg=false, ratio=1, c=:green, fa=0.2)
scatter!(RT, c=:red, ms=2.5)
