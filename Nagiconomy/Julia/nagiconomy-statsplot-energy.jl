using CSV, DataFrames, StatsPlots, Measures, Plots
gr()

df1 = CSV.read("/home/browni/LasthrimProjection/csv/energy-charts_Public_net_electricity_generation_in_Germany_in_January_Excel.csv", DataFrame)
df2 = CSV.read("/home/browni/LasthrimProjection/csv/energy-charts_Public_net_electricity_generation_in_Germany_in_February_Excel.csv", DataFrame)
df3 = CSV.read("/home/browni/LasthrimProjection/csv/energy-charts_Public_net_electricity_generation_in_Germany_in_March_Excel.csv", DataFrame)
df4 = CSV.read("/home/browni/LasthrimProjection/csv/energy-charts_Public_net_electricity_generation_in_Germany_in_April_Excel.csv", DataFrame)

df1.Month = join.(split.(rpad.(string.(df1.Month),4,"0"),'.'), '-')
df2.Month = join.(split.(rpad.(string.(df2.Month),4,"0"),'.'), '-')
df3.Month = join.(split.(rpad.(string.(df3.Month),4,"0"),'.'), '-')
df4.Month = join.(split.(rpad.(string.(df4.Month),4,"0"),'.'), '-')

a1 = groupedbar(df1.Month, Matrix(df1[:,2:end]), title="January", xlabel="Year", ylabel="Energy(GWh)", 
	titlefontsize=14, bar_position=:stack, bar_width=0.6, label="")
a2 = groupedbar(df2.Month, Matrix(df2[:,2:end]), title="February", xlabel="Year", ylabel="Energy(GWh)", 
	titlefontsize=14, bar_position=:stack, bar_width=0.6, label="")
a3 = groupedbar(df3.Month, Matrix(df3[:,2:end]), title="March", xlabel="Year", ylabel="Energy(GWh)", 
	titlefontsize=14, bar_position=:stack, bar_width=0.6, label="")
a4 = groupedbar(df4.Month, Matrix(df4[:,2:end]), title = "Electricity Generation in Germany",
	showaxis=false, xticks=false, yticks=false, 
	titlefontsize=7, bar_position=:stack, bar_width=0, bottom_margin = 0mm, 
	label=permutedims(names(df4)[2:end]))

#plot(title = "Electricity Generation in Germany", xticks=false,yticks=false)

plot(a1, a2, a3, a4, layout = @layout([grid(2,2)]))

# Adjusting the font size, layout, colors
# xlabel and ylabel can be put below for uniform labeling
plot!(tickfontsize=4, framestyle = :box, guidefontsize=4,
	legendfontsize=4, legend=:outertop)
