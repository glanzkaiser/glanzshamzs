using Plots, LaTeXStrings
pyplot()

f₀ = 50;
t = range(0,stop=1/f₀,length=1000)
θ = 2*pi*f₀*t
y = sin.(θ)

isintegralmultipleof(f, x) = f != 0 && x / f ≈ round(x / f)

function pifrac(x)
    if isintegralmultipleof(pi/2, x)
        n = Int(round(2 * x / π))
        return iseven(n) ? "$(n ÷ 2) \\pi" : "$(n) \\pi / 2"
    end
    return string(x)
end

pirange = [0:π/2:3*π;]

plot(θ, y, xticks = (pirange, pifrac.(pirange)))
