using Luxor
Drawing(1400, 900)
origin()
background("antiquewhite")

function square(t)
  for i in 1:4
    Forward(t, 200)
    Turn(t, 90)
  end
end


@draw begin
  background("antiquewhite")
  t = Turtle()
  n = 10
  Penwidth(t, 0.5)
  Pencolor(t, "darkblue")
  for i in 1:n
    square(t)
    Turn(t, 360/n)
  end
  Message(t, "Freya")
end
finish()
