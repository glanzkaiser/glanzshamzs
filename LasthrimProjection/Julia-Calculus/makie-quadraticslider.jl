# Open terminal / xterm
# mkdir project1
# cd project1
# julia --project="."
# julia> add GLMakie
# julia> include("makie-quadraticslider.jl")

using GLMakie, GeometryBasics

function quadraticsliders(x=-5:0.01:5)
  fig = Figure()

  ax = Axis(fig[1, 1], xlabel="X", ylabel="Y")

  sl_a = Slider(fig[2, 1], range = -3:0.01:3, startvalue = 0.)
  sl_b = Slider(fig[1, 2], range = -3:0.01:3, horizontal = false, startvalue = 0.)

  points = lift(sl_a.value, sl_b.value) do a, b
      Point2f.(x, a.*x.^2 .+ b.*x)
  end

  l = lines!(points, color = :blue)

  onany((a,b)->axislegend(ax, [l], ["$(a)x² + $(b)x"]), sl_a.value, sl_b.value)

  limits!(ax, minimum(x), maximum(x), -10, 10)

  fig
end

quadraticsliders()
