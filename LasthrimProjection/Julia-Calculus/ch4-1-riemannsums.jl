using Plots, LaTeXStrings, ValidatedNumerics
gr()

f(x) = √(4 - x^2)

#plot(f, 0, 2, aspect_ratio=:equal, fill=(0, :green), alpha=0.2, label="")


function make_intervals(N=10)
    xs = range(0, stop=2, length=N+1)
    return [xs[i]..xs[i+1] for i in 1:length(xs)-1]
end

intervals = make_intervals()

# Plot Riemann Sums
intervals = make_intervals(30)

t = L"\sqrt{4 - x^2}"
p = plot(aspect_ratio=:equal)
for X in intervals
    Y = f(X)

    plot!(IntervalBox(X, Interval(0, Y.lo)), c=:blue, label="", alpha=0.1)
    plot!(IntervalBox(X, Interval(Y.lo, Y.hi)), c=:red, label="", alpha=0.1)
end

plot!(f, 0, 2, label=t)
