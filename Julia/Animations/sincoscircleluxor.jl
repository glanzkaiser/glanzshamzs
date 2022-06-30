using Luxor

let
    w, h = 800, 600
    ntrig = 360
    sinarray = sind.(1:ntrig)
    cosarray = cosd.(1:ntrig)
    i = 1
 
    function frame(scene, i)
        
        background("green"); sethue("white")

        # translate near bottom right corner
        origin(0.8w, 0.5h)
        setline(1); setopacity(1)
        cr = 0.15h
        circle(0, 0, cr, :stroke)
        circle_marker_pos = getworldposition(Point(cr*-cosarray[i], cr*sinarray[i]))
	

	for k = i + 180
		setfont("Georgia Bold", 73)
		sethue("orange")
		text(string("cos $k"),
		Point(O.x-83, O.y-108),
		halign=:center)

		setfont("Georgia Bold", 73)
		sethue("red")
		text(string("sin $k"),
		Point(O.x-83, O.y+108),
		halign=:center)    
	end
	
		
        # translate to lower 20%, on the left
        origin(0, 0.8h)
        setline(1); setopacity(1)
		sethue("red")
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
		sethue("orange")
        # draw a cos wave
        for j in 1:ntrig-1
            p1 = Point(j, cosarray[mod(j+i, ntrig)+1])
            p2 = Point((j+1), cosarray[mod(j+i+1, ntrig)+1])
            line(p1, p2, :stroke)
        end
        # record the last point of the cos wave
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
        line(cos_marker_pos, circle_marker_pos, :stroke)

        i %= ntrig
        i += 1

    end
    demo = Movie(800, 600, "sincos trig")
    animate(demo, [Scene(demo, frame, 1:360)], creategif=true)
end
