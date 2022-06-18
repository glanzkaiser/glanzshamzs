using Luxor

@draw begin
  t = Turtle()
  Message(t, "commencer")
end

# Draw a horizontal line to the left (method 1)
@draw begin
  t = Turtle()
  Message(t, "commencer")
  Forward(t, -200)
  Message(t, "finir")
end

# Draw a horizontal line to the left (method 2)
@draw begin
  t = Turtle()
  Message(t, "commencer")
  Turn(t, 180)
  Forward(t, 200)
  Message(t, "finir")
end

# Draw a vertical line down 
@draw begin
  t = Turtle()
  Message(t, "commencer")
  Turn(t, 90)
  Forward(t, 200)
  Message(t, "finir")
end

# Draw a vertical line up
@draw begin
  t = Turtle()
  Message(t, "commencer")
  Turn(t, -90)
  Forward(t, 200)
  Message(t, "finir")
end

# Draw a square without fill (clockwise)
@draw begin
  t = Turtle()
  for i in 1:4
    Forward(t, 200)
    Turn(t, 90)
    Message(t, "$i")
  end
end

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
