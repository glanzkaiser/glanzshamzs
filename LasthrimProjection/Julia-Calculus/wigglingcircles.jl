using Plots

function circle(x, y, r=1; n=30)
    θ = 0:360÷n:360
    Plots.Shape(r*sind.(θ) .+ x, r*cosd.(θ) .+ y)
end

function move_circles!(circles; Δ=0.01)
    for c in circles
        dx = Δ*(2rand() - 1)
        dy = Δ*(2rand() - 1)
        c.x .+= dx
        c.y .+= dy
    end
    nothing
end

nframes = 100
ncircles = 1000

circles = circle.([i*rand(ncircles) for i in (1, 1, 0.01)]...)

plot_kwargs = (aspect_ratio=:equal, fontfamily="Helvetica", legend=false, line=nothing,
    color=:black, grid=false, xlim=(0,1), ylim=(0,1))

anim = @animate for _ in 1:nframes
    move_circles!(circles)
    plot(circles; plot_kwargs...)
end
gif(anim, "anim.gif")
