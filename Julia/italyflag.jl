using Plots
pyplot()
theme(:dark)

x = LinRange(0,π,2021);  y =  2*cos.(x)
ymin, ymax = extrema(y)
c = [-1.; 1.]  # BAD < -1 ;  -1 < OK < 1;   GOOD > 1
cs = @. (c - ymin)/(ymax - ymin)   # map input data ranges to color scale 0-1 range:
my_cgrad2 = cgrad([:red,:white,:green], cs, categorical=true)

scatter([-1 -1 -1],[0 0 0], mc=[:red :white :green],label=["BAD < -1" "-1 < OK < 1" "GOOD > 1"],marker=:rect, ratio=1)
plot!(x,y, fill=true,fill_z=y,fc=my_cgrad2, colorbar=false,clims=(ymin,ymax),lc=:black,
     xlabel="x", ylabel="y", widen=false,label=false, xlims=extrema(x),ylims=(-2.1,2.1))
plot!(xticks=([0, pi/3, 2pi/3, pi], ["0","π/3","2π/3", "π"]), dpi=300)
