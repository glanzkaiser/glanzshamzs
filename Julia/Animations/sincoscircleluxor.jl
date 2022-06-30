using Luxor

let
    w, h = 600, 400
    ntrig = 360
    sinarray = sind.(1:ntrig)
    cosarray = cosd.(1:ntrig)
    i = 1

    function frame(scene, i)
        w h begin
        background("gray"); sethue("white")

        # translate near bottom right corner
        origin(0.8w, 0.8h)
        setline(1); setopacity(1)
        cr = 0.15h
        circle(0, 0, cr, :stroke)
        circle_marker_pos = getworldposition(Point(cr*cosarray[i], cr*sinarray[i]))

        # translate to lower 20%, on the left
        origin(0, 0.8h)
        setline(1); setopacity(1)
        scale(1.0, cr)
        # draw a sin wave
        for j in 1:ntrig-1
            p1 = Point(j, sinarray[mod(j+i, ntrig)+1])
            p2 = Point((j+1), sinarray[mod(j+i+1, ntrig)+1])
            line(p1, p2, :stroke)
        end
        # record the last point of the sin wave
        sin_marker_pos = getworldposition(Point(ntrig,sinarray[mod(ntrig+i, ntrig)+1]))

        # translate to top left corner, then down 20%
        origin(0, 0.2h)
        scale(1.0, cr)
        setline(1); setopacity(1)
        # draw a sin wave
        for j in 1:ntrig-1
            p1 = Point(j, cosarray[mod(j+i, ntrig)+1])
            p2 = Point((j+1), cosarray[mod(j+i+1, ntrig)+1])
            line(p1, p2, :stroke)
        end
        # record the last point of the sin wave
        cos_marker_pos = getworldposition(Point(ntrig, cosarray[mod(ntrig+i, ntrig)+1]))

        # mark the last point of the sin and cos waves
        origin()
        setline(2); setopacity(1);
        circle(sin_marker_pos, 2, :stroke)
        circle(cos_marker_pos, 2, :stroke)
        circle(circle_marker_pos, 2, :stroke)
        # draw connecting lines between the wave and the circle
        setline(1); setopacity(0.5)
        line(sin_marker_pos, circle_marker_pos, :stroke)
        # line(cos_marker_pos, circle_marker_pos, :stroke)

        i %= ntrig
        i += 1
    end
    demo = Movie(600, 400, "sincos trig")
    animate(demo, [Scene(demo, frame, 1:360)], creategif=true, pathname="sincostrig.gif")
end
    
