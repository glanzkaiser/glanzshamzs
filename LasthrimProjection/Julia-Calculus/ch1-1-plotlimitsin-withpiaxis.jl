
using Plots, LaTeXStrings
pyplot()

function pitick(start, stop, denom; mode=:text)
    a = Int(cld(start, π/denom))
    b = Int(fld(stop, π/denom))
    tick = range(a*π/denom, b*π/denom; step=π/denom)
    ticklabel = piticklabel.((a:b) .// denom, Val(mode))
    tick, ticklabel
end

function piticklabel(x::Rational, ::Val{:text})
    iszero(x) && return "0"
    S = x < 0 ? "-" : ""
    n, d = abs(numerator(x)), denominator(x)
    N = n == 1 ? "" : repr(n)
    d == 1 && return S * N * "π"
    S * N * "π/" * repr(d)
end

function piticklabel(x::Rational, ::Val{:latex})
    iszero(x) && return L"0"
    S = x < 0 ? "-" : ""
    n, d = abs(numerator(x)), denominator(x)
    N = n == 1 ? "" : repr(n)
    d == 1 && return L"%$S%$N\pi"
    L"%$S\frac{%$N\pi}{%$d}"
end

println("x \t sin 1/πx")

for N in 1:10:550
    g = sin.(1 / (pi*N))
    println("$N \t $g ")
end

f(x) = sin.(1/x)
a, b = -π/2, π/2
plot(f, a, b; xtick=pitick(a, b, 4), label=L"y = \sin \frac{1}{x}", legend=:outertop, size=(720, 250))
#plot(f, a, b; xtick=pitick(a, b, 4; mode=:latex), label="y = sin(x)", legend=:outertop, size=(720, 250), tickfontsize=10)
