using CSV, StatsPlots, DataFrames

df = CSV.read("/home/browni/LasthrimProjection/importedenergydata.csv", DataFrame)
#print(df)

@df df groupedbar(:Country, :Percentage, group=:Energy, ylabel="Percentage", title = "Asia’s reliance on imported energy", bar_width=0.7, legend=:outertopright)
