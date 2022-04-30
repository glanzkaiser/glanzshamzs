using Plots
pyplot()

histogram(randn(1000), bins = :scott, weights = repeat(1:5, outer = 200))
