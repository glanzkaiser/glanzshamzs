using Plots
 
#data to plot
globaltemperatures = [14.4, 14.5, 14.8, 15.2, 15.5, 15.8];
numindustries = [17, 400, 5000, 15000, 20000, 45000];
 
#use PyPlot
Plots.pyplot()
 
#plot
plot(numindustries, globaltemperatures, label="line")
#add points
scatter!(numindustries, globaltemperatures, label="points")
 
#adding labels to plot
xlabel!("Number of Industries")
ylabel!("Global Temperature (°C)")

#save plot
png("/opt/hamzstlib/glanzshamzs/glanzshamzs/Julia")
