using Javis
function ground(args...)
    background("black")
    sethue("white")
end

function my_circle(args...)
    circle(O, 100, :fill)
    sethue("black")
    # setline(2)
    # line(O, Point(line_length, 0), :stroke)
    line(O, Point(100, 0), :stroke)
end

video = Video(800, 400)
Background(1:100, ground)
ball = Object(my_circle, Point(-500, 0))
translating = Action(anim_translate(Point(1000, 0)))
rotating = Action(anim_rotate(0.0, 2*2π))
#changing_len = Action(change(:line_length, 0 => 100))
#act!(ball, [translating, rotating, changing_len])
act!(ball, [translating, rotating])

render(video; pathname="rolling_ball_2.gif")
