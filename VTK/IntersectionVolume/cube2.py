from vedo import Cube, show
c1 = Cube()
c2 = Cube().pos(0.6,0.4,0.3).rotateX(30).rotateY(40)
c1.triangulate().subdivide(4, method=1).wireframe().alpha(0.1)
c2.triangulate().subdivide(4, method=1).wireframe().alpha(0.1)
cc = c1.boolean("intersect", c2).c("red5")
show(c1, c2, cc, f"Volume = {cc.volume()}", axes=1)
