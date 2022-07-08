using Plots, LaTeXStrings, ValidatedNumerics
pyplot()

f(x) = √(4 - x^2)

#plot(f, 0, 2, aspect_ratio=:equal, fill=(0, :green), alpha=0.2, label="")


function make_intervals(N=10)
    xs = range(0, stop=2, length=N+1)
    return [xs[i]..xs[i+1] for i in 1:length(xs)-1]
end

intervals = make_intervals()

# Plot Riemann Sums
intervals = make_intervals(33)

t = L"\sqrt{4 - x^2}"
p = plot(aspect_ratio=:equal)
for X in intervals
    Y = f(X)

    plot!(IntervalBox(X, Interval(0, Y.lo)), c=:blue, label="", alpha=0.1)
    plot!(IntervalBox(X, Interval(Y.lo, Y.hi)), c=:red, label="", alpha=0.1)
end

plot!(f, 0, 2, label=t)


#=
# Sum up the areas of each partition of the rectangle to approximate the area of one quadrant of a circle 
N = 20
intervals = make_intervals(N)

width = 2/N
width * sum(√(4 - X^2) for X in intervals)

# The area approximation for each partition from 50 to 1000
# Increasing the number of sub-intervals makes better approximation

setdisplay(:standard, sigfigs=5)

println("N \t area interval \t \t diameter")
for N in 50:50:1000
    intervals = make_intervals(N)
    area = (2/N) * sum(√(4 - X^2) for X in intervals)

    println("$N \t $area \t $(diam(area))")
end

=#
