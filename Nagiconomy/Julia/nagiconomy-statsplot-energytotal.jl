using CSV, DataFrames, StatsPlots, Measures, Plots
gr()

df = CSV.read("/home/browni/LasthrimProjection/csv/Public_net_electricity_generation_in_Germany.csv", DataFrame)

df[:,15] .= coalesce.(df[:,15], 0)
df.Month = join.(split.(rpad.(string.(df.Month),6,"0"),'.'),'-')

plot(legendfontsize=6, widen=false, legend=:outerright, size=(1200,600), dpi=600, margins=10mm)
groupedbar!(df.Month, Matrix(df[:,2:end]), bar_position=:stack, lw=0.2, label=permutedims(names(df)[2:end]))

# Adjusting the font size, layout, colors
# xlabel and ylabel can be put below for uniform labeling
plot!(xrotation=90, tickfontsize=6, xlabel="Month-Year", title = "Electricity Generation in Germany", legendfontsize=4, legend=:outerright,
	ylabel="Energy (GWh)", right_margin = 8Plots.mm, guidefontsize=7)

