
using Plots, LaTeXStrings
pyplot(fmt=:svg)

f(x) = 5*sin.(5*x + 30)
g(x) = 3*sin.(5*x + 60)
h(x) = 10*sin.(5*x + 135)
i(x) = 5*sin.(5*x + 30) + 3*sin.(5*x + 60) + 10*sin.(5*x + 135)

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

a, b = -2π, 2π

plot(f, a, b; xtick=pitick(a, b, 4; mode=:latex), label=L"y = 5 \sin{\omega t + 30}", size=(720, 250), tickfontsize=10, legend=:outertop)
plot!(g, a, b; xtick=pitick(a, b, 4; mode=:latex), label=L"y = 3 \sin{\omega t + 60}", size=(720, 250), tickfontsize=10, legend=:outertop)
plot!(h, a, b; xtick=pitick(a, b, 4; mode=:latex), label=L"y = 10 \sin{\omega t + 225}", size=(720, 250), tickfontsize=10, legend=:outertop)
#plot(i, a, b; xtick=pitick(a, b, 4; mode=:latex), label=L"y = 5 \sin{(\omega t + 30)} + 3 \sin{(\omega t + 60)} + 10 \sin{(\omega t + 135)}", size=(720, 250), tickfontsize=10, legend=:outertop)
