using Javis, FFTW, FFTViews

function ground(args...)
    background("black")
    sethue("white")
end

function circ(; r = 10, vec = O, action = :stroke, color = "white")
    sethue(color)
    circle(O, r, action)
    my_arrow(O, vec)
    return vec
end

function my_arrow(start_pos, end_pos)
    start_pos ≈ end_pos && return end_pos
    arrow(
        start_pos,
        end_pos;
        linewidth = distance(start_pos, end_pos) / 100,
        arrowheadlength = 7,
    )
    return end_pos
end

function draw_line(
    p1 = O,
    p2 = O;
    color = "white",
    action = :stroke,
    edge = "solid",
    linewidth = 3,
)
    sethue(color)
    setdash(edge)
    setline(linewidth)
    line(p1, p2, action)
end

function draw_path!(path, pos, color)
    sethue(color)

    push!(path, pos)
    draw_line.(path[2:end], path[1:(end - 1)]; color = color)
end

function get_points(npoints, options)
    Drawing()
    shape = poly([Point(-200, 0), Point(250, 70), Point(165, -210)]; close=true)
    points = [Javis.get_polypoint_at(shape, i / (npoints-1)) for i in 0:(npoints-1)]
    return points
end

function poly_color(points, action; color=nothing)
    color !== nothing && sethue(color)
    poly(points, action)
end

c2p(c::Complex) = Point(real(c), imag(c))

remap_idx(i::Int) = (-1)^i * floor(Int, i / 2)
remap_inv(n::Int) = 2n * sign(n) - 1 * (n > 0)

function animate_fourier(options)
    npoints = options.npoints
    nplay_frames = options.nplay_frames
    nruns = options.nruns
    nframes = nplay_frames + options.nend_frames

    points = get_points(npoints, options)
    npoints = length(points)
    println("#points: $npoints")

    # optain the fft result and scale
    x = [p.x for p in points]
    y = [p.y for p in points]

    fs = fft(complex.(x, y)) |> FFTView
    # normalize the points as fft doesn't normalize
    fs ./= npoints
    npoints = length(fs)

    video = Video(options.width, options.height)
    Background(1:nframes, ground)
    Object((args...)->poly_color(points, :stroke; color="green"))

    circles = Object[]
    npoints = 5

    for i in 1:npoints
        ridx = remap_idx(i)

        push!(circles, Object((args...) -> circ(; r = abs(fs[ridx]), vec = c2p(fs[ridx]))))

        if i > 1
            # translate to the tip of the vector of the previous circle
            act!(circles[i], Action(1:1, anim_translate(circles[i - 1])))
        end
        ridx = remap_idx(i)
        act!(circles[i], Action(1:nplay_frames, anim_rotate(0.0, ridx * 2π * nruns)))
    end

    trace_points = Point[]
    Object(1:nframes, (args...) -> draw_path!(trace_points, pos(circles[end]), "red"))

    render(video, pathname = options.filename)
end

function main()
    gif_options = (
        npoints = 1000, # rough number of points for the shape => number of circles
        nplay_frames = 400, # number of frames for the animation of fourier
        nruns = 2, # how often it's drawn
        nend_frames = 0,  # number of frames in the end
        width = 800,
        height = 500,
        shape_scale = 0.8, # scale factor for the logo
        tsp_quality_factor = 40,
        filename = "images/fourier_tri_5.gif",
    )
    animate_fourier(gif_options)
end

main()
