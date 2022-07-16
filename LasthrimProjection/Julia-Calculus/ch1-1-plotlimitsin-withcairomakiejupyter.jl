# Need to use Browser and Jupyter Notebook
# start terminal then type julia
# julia> using IJulia
# julia> notebook()

using CairoMakie

x = LinRange(-0.1, 0.1, 700)
y = sin.(1 ./x)

x1 = LinRange(-0.1, 0.2, 700)
y1 = sin.(1 ./x)

x2 = LinRange(-3, 3, 700)
y2 = sin.(1 ./x)

fig = Figure()
lines(fig[1, 1], x, y, color = :red)
lines(fig[1, 2], x1, y1, color = :blue)
lines(fig[2, 1:2], x2, y2, color = :green)

fig
