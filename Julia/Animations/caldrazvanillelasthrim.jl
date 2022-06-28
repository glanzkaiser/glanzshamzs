using Javis

function ground(args...)
    background("black")
    sethue("white")
end

frames = 1000

myvideo = Video(730, 730)
Background(1:frames, ground)

# Distance from the sun (in miles): Earth = 93 000 000, Venus = 67 000 000, Mars = 142 000 000
# Diameter: Earth = 12742 km, Venus = 12102 km, Mars = 6792 km
vanille = Object(1:frames, JCircle(O, 12.7, color = "pink", action = :fill), Point(200, 0))
caldraz = Object(1:frames, JCircle(O, 12.1, color = "orange", action = :fill), Point(144, 0))
lasthrim = Object(1:frames, JCircle(O, 6.7, color = "red", action = :fill), Point(305, 0))

vanille_orbit = Object(@JShape begin
    sethue(color)
    setdash(edge)
    circle(O, 200, action)
end color = "white" action = :stroke edge = "solid")

caldraz_orbit = Object(@JShape begin
    sethue(color)
    setdash(edge)
    circle(O, 144, action)
end color = "white" action = :stroke edge = "solid")

lasthrim_orbit = Object(@JShape begin
    sethue(color)
    setdash(edge)
    circle(O, 305, action)
end color = "white" action = :stroke edge = "solid")

# We need the planets to revolve according to their time periods.
# Mars completes its one revolution in 687 days
# Earth completes its one revolution in 365 days and Venus does that in 224.7 days.
# Hence, we need to multiply (224.7/365) so that the time period matches properly i.e.,
# When earth completes its full revolution, Venus has done (224.7/365) th of its revolution.
act!(vanille, Action(anim_rotate_around(12.5 * 2π * (224.7 / 365), O)))
act!(caldraz, Action(anim_rotate_around(12.5 * 2π , O)))
act!(lasthrim, Action(anim_rotate_around(12.5 * 2π * (224.7 / 687), O)))

connection1 = [] # To store the connectors
Object(@JShape begin
    sethue(color)
    push!(connection1, [p1, p2])
    map(x -> line(x[1], x[2], :stroke), connection1)
end connection1 = connection1 p1 = pos(vanille) p2 = pos(caldraz) color = "#ceeab7")

connection2 = [] # To store the connectors
Object(@JShape begin
    sethue(color)
    push!(connection2, [p2, p3])
    map(x -> line(x[1], x[2], :stroke), connection2)
end connection2 = connection2 p2 = pos(caldraz) p3 = pos(lasthrim) color = "#f9e8b3")

render(myvideo; pathname = "vcl_dance.gif")
