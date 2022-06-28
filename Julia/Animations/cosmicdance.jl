using Javis

function ground(args...)
    background("black")
    sethue("white")
end

frames = 1000

myvideo = Video(500, 500)
Background(1:frames, ground)

earth = Object(1:frames, JCircle(O, 10, color = "blue", action = :fill), Point(200, 0))
venus = Object(1:frames, JCircle(O, 7, color = "red", action = :fill), Point(144, 0))

earth_orbit = Object(@JShape begin
    sethue(color)
    setdash(edge)
    circle(O, 200, action)
end color = "white" action = :stroke edge = "solid")

venus_orbit = Object(@JShape begin
    sethue(color)
    setdash(edge)
    circle(O, 144, action)
end color = "white" action = :stroke edge = "solid")

# We need the planets to revolve according to their time periods.
# Earth completes its one revolution in 365 days and Venus does that in 224.7 days.
# Hence, we need to multiply (224.7/365) so that the time period matches properly i.e.,
# When earth completes its full revolution, Venus has done (224.7/365) th of its revolution.
act!(earth, Action(anim_rotate_around(12.5 * 2π * (224.7 / 365), O)))
act!(venus, Action(anim_rotate_around(12.5 * 2π, O)))

connection = [] # To store the connectors
Object(@JShape begin
    sethue(color)
    push!(connection, [p1, p2])
    map(x -> line(x[1], x[2], :stroke), connection)
end connection = connection p1 = pos(earth) p2 = pos(venus) color = "#accd8a")

render(myvideo; pathname = "cosmic_dance.gif")
