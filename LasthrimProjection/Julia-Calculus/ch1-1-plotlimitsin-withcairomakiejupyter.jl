# Need to use Browser and Jupyter Notebook
# start terminal then type julia
# julia> using IJulia
# julia> notebook()

using CairoMakie

x = LinRange(-0.3, 0.01, 500)
y = sin.(1 ./x)

x1 = LinRange(-0.01, 0.3, 500)
y1 = sin.(1 ./x1)

x2 = LinRange(-2, 2, 500)
y2 = sin.(1 ./x2)

fig = Figure()
lines(fig[1, 1], x, y, color = :red)
lines(fig[1, 2], x1, y1, color = :blue)
lines(fig[2, 1:2], x2, y2, color = :green)

fig
