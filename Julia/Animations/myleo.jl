function frame(scene, framenumber)
    background("black")
    sethue("gold")
    fontface("BigMummy")
    fontsize(40)
    textpath("My Leo Goddess", boxtopcenter() + (0, 80) , halign=:center)
    tp1 = storepath()
    fontsize(130)
    textpath("Freya", O + (0, 80), halign=:center)
    tp2 = storepath()

    eased_n = scene.easingfunction(framenumber - scene.framerange.start,
        0, 1, scene.framerange.stop - scene.framerange.start)

    for tp in (tp1, tp2)
        drawpath(tp, eased_n, action = :stroke)
    end
end

amovie = Movie(600, 250, "a movie")
animate(amovie, Scene(amovie, frame, 1:150), creategif=true, pathname="/tmp/textanimation.gif")
