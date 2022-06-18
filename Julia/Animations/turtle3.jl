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
