using Plots
pyplot()

xp = [[i, (i+1 - 5*eps())] for i in -12:11]
p = plot(ylim=(-12,12))
for x in xp
    plot!(x, floor.(x), c=:black, label=false)
    scatter!(x, floor.(x), ms=3, msc=:black, mc=[:black, :white], label=false)
end
p
