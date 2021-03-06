using Plots
pyplot()

begin
    default(titlefont = (20, "times"), legendfontsize = 18, guidefont = (18, :darkgreen), tickfont = (12, :orange), guide = "x", framestyle = :zerolines, yminorgrid = true)
    plot([sin, cos], -2π, 2π, label = ["sin(θ)" "cos(θ)"], title = "Trigonometric Functions", xlabel = "θ", linewidth = 2, legend = :outertopleft)
end
