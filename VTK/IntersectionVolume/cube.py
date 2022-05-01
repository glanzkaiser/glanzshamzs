from vedo import Cube, show
c1 = Cube().triangulate().wireframe()
c2 = Cube().pos(0.5,0.4,0.3).rotateX(20).triangulate().wireframe()
cc = c1.boolean("intersect", c2)
print(cc.volume())
show(c1,c2,cc, axes=1)
