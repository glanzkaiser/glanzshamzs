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

An example for drawing Basic Turtle:
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
The file will be saved as .png at the current working directory.


| Basic Turtle | 9 Turtles | Hilbert Curve |
| ------------- | ------------- | ------------- |
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/turtle1.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/turtle2.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/turtle3.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/turtle1.jl">turtle1.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/turtle4.jl">turtle4.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/turtle-hilbertcurve.jl">turtle-hilbertcurve.jl</a> | 


| MyLeo | Sin Cos Circle | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/myleo.gif" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/sincos%20trig%20white.gif" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/myleo.jl">myleo.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/sincoscircleluxor.jl">sincoscircleluxor.jl</a> | 

# Javis
Javis.jl focuses on creating an easy to use interface written in Julia to create visualizations and animations. What Javis is, is a tool for exploration that gives great freedom and flexibility to a user. What it is not is a domain specific library for making a limited subset of visualizations or a true data analytics tool.


|  GreenBlue Hypotrochoids | Gravity |
| ------------- | ------------- |
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/greenblue.gif" width="73%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/gravities.gif" width="73%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/greenblue.jl">greenblue.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/gravities.jl">gravities.jl</a> | 

| VanilleCaldrazLasthrim | VanilleCaldraz | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/vcl_dance.gif" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/cosmic_dance2.gif" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/caldrazvanillelasthrim.jl">caldrazvanillelasthrim.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/cosmicdance.jl">cosmicdance.jl</a> | 

#### Vanille = Earth      
#### Caldraz = Venus      
#### Mischkra = Mercury
#### Lasthrim = Mars      
#### Lucrif = Moon
#### Zalsvik = Jupiter
#### Freya = Neptune     
#### Glanz = Uranus 
#### Zalsimourg = Pluto 

| Bezier Curve M | Bezier Curve C | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/bezier_d2-1.gif" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/bezier_c.gif" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/edit/main/Julia/Animations/beziercurve2-javis.jl">beziercurve2-javis.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/edit/main/Julia/Animations/beziercurve2-javis.jl">beziercurve2-javis.jl</a> | 

# Plots
| Trajectory | Trajectory | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/trajectory.gif" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/cosmic_dance2.gif" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/trajectory.jl">trajectory.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Animations/cosmicdance.jl">cosmicdance.jl</a> | 

# Sources
https://juliagraphics.github.io/Luxor.jl/stable/howto/turtle/

https://juliagraphics.github.io/Luxor.jl/stable/reference/api/

https://juliaanimators.github.io/Javis.jl/stable/

https://docs.juliahub.com/Luxor/HA9ps/2.15.0/howto/createdrawings/

https://juliagraphics.github.io/Luxor.jl/v0.11/basics.html

https://20akshay00.github.io/PhysicsJavisAnim/docs/SHM.jl.html

https://opensourc.es/blog/bezier-curve/
