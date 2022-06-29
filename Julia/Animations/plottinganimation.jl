using Plots
plotly()

f = x->x*x
g = x->f(x)+.2*randn()
p = plot(-1:.1:0, f, ylim=(-1,2), c=:blue)
scatter!(-1:.1:0, g, c=:red)

anim = Animation()
for i=1:10
    x = i/10
    push!(p, 1, x, f(x))
    push!(p, 2, x, g(x))
    frame(anim)
end

gif(anim, "test.gif", fps=8)
