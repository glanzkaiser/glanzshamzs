using Luxor, Colors
Drawing(1200, 1400)

g = GridRect(O + (200, -200), 80, 20, 85)
text("#sides", nextgridpoint(g), halign=:right)
text("area", nextgridpoint(g), halign=:right)

for i in 20:-1:3
    sethue(i/20, 0.5, 1 - i/20)
    ngonside(O, 50, i, 0, :fill)
    sethue("grey40")
    ngonside(O, 50, i, 0, :stroke)
    p = ngonside(O, 50, i, 0, vertices=true)
    text(string(i), nextgridpoint(g), halign=:right)
    text(string(round(polyarea(p), 3)), nextgridpoint(g), halign=:right)
end

finish()
preview()
