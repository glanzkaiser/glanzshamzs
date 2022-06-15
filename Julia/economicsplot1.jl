using Plots
gr()
data = Plots.fakedata(50,2)
p = plot(data, w=3);
hspan!(p,[0,maximum(data)], color = :green, alpha = 0.2, labels = "good");
hspan!(p,[minimum(data),0], color = :red, alpha = 0.2, labels = "bad");
display(p) # or savefig(p, "filename.png")
