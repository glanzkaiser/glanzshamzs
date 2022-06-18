# Turtle Graphics
In computer graphics, turtle graphics are vector graphics using a relative cursor (the "turtle") upon a Cartesian plane (x and y axis). Turtle graphics is a key feature of the Logo programming language.

The turtle has three attributes: 
1. A location
2. An orientation (or direction)
3. A pen. The pen, too, has attributes: color, width, and on/off state (also called down and up). 

The turtle moves with commands that are relative to its own position, such as "move forward 10 spaces" and "turn left 90 degrees". The pen carried by the turtle can also be controlled, by enabling it, setting its color, or setting its width. A student could understand (and predict and reason about) the turtle's motion by imagining what they would do if they were the turtle. Seymour Papert called this "body syntonic" reasoning. 

The idea of turtle graphics, for example is useful in a Lindenmayer system for generating fractals. 

## Extension to three dimensions
The ideas behind turtle graphics can be extended to include three-dimensional space. This is achieved by using one of several different coordinate models. If the turtle operates in cylindrical coordinates, then it has a location and a heading within its plane, and its plane may be rotated around the vertical axis. This often manifests itself as the turtle having two different heading angles, one within the plane and the other determining the plane's angle. Usually changing the plane's angle does not move the turtle. 

## Turtle graphics in Luxor.jl
Some simple "turtle graphics" functions are included. Functions to control the turtle begin with a capital letter: Forward, Turn, Circle, Orientation, Rectangle, Pendown, Penup, Pencolor, Penwidth, and Reposition, and so on, and angles are specified in degrees.

#### Counterclockwise -> -(degree)
#### Clockwise -> +(degree)


```
using Luxor, Colors
Drawing(600, 400)
origin()
background("midnightblue")

🐢 = Turtle() # you can type the turtle emoji with \:turtle:
Pencolor(🐢, "cyan")
Penwidth(🐢, 1.5)
global n = 5
for i in 1:400
    Forward(🐢, n)
    Turn(🐢, 89.5)
    HueShift(🐢)
    n += 0.75
end
fontsize(20)
Message(🐢, "finished")
finish()
```
