using Plots, LaTeXStrings
pyplot()
import Base: isequal, ==


abstract type GeoObject end
abstract type GeoShape <: GeoObject end

struct Point <: GeoObject
    x::Number
    y::Number
end
(==)(p1::Point, p2::Point) = p1.x==p2.x && p1.y==p2.y

struct Triangle <: GeoShape
    A::Point
    B::Point
    C::Point
end
Triangle(ax, ay, bx, by, cx, cy) = Triangle(Point(ax, ay), Point(bx, by), Point(cx, cy))
(==)(t1::Triangle, t2::Triangle) = vertices(t1) == vertices(t2)

function vertices(tri::Triangle) 
    [tri.A, tri.B, tri.C]
end

struct Edge <: GeoShape
    src::Point
    dst::Point
end

function edges(tri::Triangle)
    elist = Edge[]
    pts = vertices(tri)
    for i in 1:length(pts)-1
        push!(elist, Edge(pts[i], pts[i+1]))
    end
    push!(elist, Edge(pts[length(pts)], pts[1]))
    elist
end

struct Circle
    center::Point
    radius::Number
end
(==)(c1::Circle, c2::Circle) = c1.center == c2.center && c1.radius == c2.radius

ccenter(c::Circle) = c.center

A = Point(2,2); B = Point(6, 2); C = Point(6,5);
tri = Triangle(A, B, C)

function shape(ptlist::Vector{Point})
    xlist = [pt.x for pt in ptlist]
    ylist = [pt.y for pt in ptlist]
    shape = Shape(xlist, ylist)
end;
shape(tri::Triangle) = shape(vertices(tri));

trishape=shape(tri)
    
s1 = L"\theta";
s2 = L"sin \theta = \frac{opp}{hyp}";
s3 = L"cos \theta = \frac{adj}{hyp}";
s4 = L"tan \theta = \frac{opp}{adj}";

plot(trishape, leg=false, fill=(0, :green), aspect_ratio=:equal, fillalpha= 0.2)
scatter!(trishape.x, trishape.y, color=:red, series_annotations = text.(["A", "B", "C"], :bottom))
annotate!([(2.5, 2.5, (s1, 8, :green)), 
    (4.5, 1, ("adj", :right, 8, "courier")), 
    (6.5, 3.5, ("opp", :right, 8, "courier")), 
    (4.5, 4.5, ("hyp", :right, 8, "courier"))])
    
