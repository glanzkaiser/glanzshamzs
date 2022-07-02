using Plots
pyplot()

z = exp.(range(0, 2π, 65)im)
plot(z; title="Circle", legend=:bottomright, labels="z", 
      marker=:o, aspectratio=:equal, size=(400, 400))
scatter!(z; xlabel="Re", ylabel="Im", labels=nothing)
savefig("plot1.png")
