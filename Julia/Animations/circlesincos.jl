using Javis, Animation

begin	
	function ground(args...)
	    background("black")
	    sethue("white")
	end
	
	function draw_line(p1 = O, p2 = O, color = "black", action = :stroke, edge = "solid")
	    sethue(color)
	    setdash(edge)
		setline(2)
	    line(p1, p2, action)
	end
	
	function circ(p = O, color = [1.0, 1.0, 1.0], alph = 1.0, action = :fill, radius = 25, edge = "solid")
	    setcolor(color..., 0.6)
		setdash(edge)
	    circle(p, radius, action = :stroke)
		
		setcolor(color..., alph)
	    circle(p, radius, action)
		
		return p
	end
	
	function path(p = O, color = [1.0, 1.0, 1.0], alph = 1.0, radius = 25, edge = "dashed")
	    setcolor(color..., 0.6)
		setdash(edge)
		setline(3)
	    circle(p, radius, action = :stroke)
	end	
	
	nframes = 140
	myvideo = Video(500, 500)
	Background(1:nframes, ground)
	
	r = 25
	R = 100
	θ = range(0, stop = 2π, length = 140)
	x = cos.(θ) .- 1
	y = sin.(θ)
	
	xballpath = Point.(R*x, 0)
	yballpath = Point.(0, R*y)
	bpath = Point.(R*x, R*y)
		
	xanim = Animation(
				range(0, stop = 1, length = 140),
				xballpath,
				linear())
	
	yanim = Animation(
				range(0, stop = 1, length = 140),
				yballpath,
				linear())
	
	banim = Animation(
				range(0, stop = 1, length = 140),
				bpath,
				linear())
	
	
	ball = Object(
		1:nframes, 
		(args...) -> circ(O, [1.0, 0.0, 1.0], 0.6, :fill, r), 
		Point(100, 0))
	
	ball_path = Object(
				1:nframes, 
				(args...) -> path(O, [1.0, 0.0, 1.0], 1.0, 100, "dashed"),
				O)
	
	yball = Object(
				1:nframes, 
				(args...) -> circ(O, [1.0, 0.0, 0.0], 0.6, :fill, r), 
				Point(200, 0))
	
	y_proj_ax = Object(
				1:nframes, 
				(args...) -> draw_line(Point(200, 100 + r), Point(200, -100-r), "red", :stroke, "dashed"), 
				O)
	
	xball = Object(
				1:nframes, 
				(args...) -> circ(O, [0.0, 0.0, 1.0], 0.6, :fill, r), 
				Point(100, 200))
	
	x_proj_ax = Object(
					1:nframes, 
					(args...) -> draw_line(Point(100 + r, 200), Point(-100 - r, 200), "blue", :stroke, "dashed"), 
					O)
	
	act!(ball, Action(1:nframes, banim, translate()))

	act!(xball, Action(1:nframes, xanim, translate()))

	act!(yball, Action(1:nframes, yanim, translate()))

	
	# connector lines (projections)
	Object(1:nframes, (args...) -> draw_line(pos(ball) .+ Point(0, r), pos(xball) .- Point(0, r), "blue", :stroke, "solid"), O)
	Object(1:nframes, (args...) -> draw_line(pos(ball) .+ Point(r, 0), pos(yball) .- Point(r, 0), "red", :stroke, "solid"), O)
	
	render(
    myvideo;
    pathname="SHM.gif")
	
end
