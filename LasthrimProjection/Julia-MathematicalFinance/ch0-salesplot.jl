using Plots
pyplot()

sales = [1, 5, 2, 7];
plot(["winter", "spring", "summer", "autumn"], sales;
            labels=nothing, tickfontsize=10, xrot=90,
            yticks=(sales, 1000sales),
            ylim=extrema(sales) .+ (-1, 1),
            bottommargin=5Plots.mm)
