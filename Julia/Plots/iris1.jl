using Plots; theme(:ggplot2)
using RDatasets

iris = dataset("datasets", "iris");

X = iris.PetalLength
Y = iris.SepalLength
sizes = iris.SepalWidth
labels = iris.Species

# Scatter plot with some custom settings
scatter(X,
    Y,
    xlim = (0, 7.5),
    ylim = (3.5, 8.5),
    group = labels,
    legend = :topleft,
    title = "The Iris Dataset",
    xlabel = "Petal Length",
    ylabel = "Sepal Length",
    color = [:darkviolet :green3 :red3],
    markersize = sizes,
    markershape = [:hex :star7 :cross],
    alpha = 0.60,
    dpi = 1000
)
