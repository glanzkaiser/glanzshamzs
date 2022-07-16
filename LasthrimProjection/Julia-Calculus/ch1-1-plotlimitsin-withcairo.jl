using CairoMakie

x = LinRange(-1, 1, 700)
y = sin.(1 ./x)

x1 = LinRange(-1, 0.02, 700)
y1 = sin.(1 ./x)

x2 = LinRange(-30, 30, 700)
y2 = sin.(1 ./x)

fig = Figure()
lines(fig[1, 1], x, y, color = :red)
lines(fig[1, 2], x1, y1, color = :blue)
lines(fig[2, 1:2], x2, y2, color = :green)

fig
