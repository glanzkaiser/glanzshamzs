using LinearAlgebra
using LazyGrids
using CoordinateTransformations, Rotations, StaticArrays, Interpolations

meshgrid(y,x) = (ndgrid(x,y)[[2,1]]...,)

"""
   obliqueslice(v, point, normal; method=Linear(), fillvalue::Real=0)

Extract an oblique slice from a 3-D volume `v`, by using the `point` on the output slice and
`normal` to the output slice.

# Arguments
- `point::Vector`: vector containing X, Y, Z coordinates of the point in which output slice
passes through.
- `normal:Vector`: a normal vector to the output slice.
- `method`: `Constant()` for nearest neighbor interpolation, `Linear()` for linear
interpolation.
- `fillvalue::Real=0`: Numeric scalar value used to fill pixels in the output slice that are
outside the limits of the volume.

# Output Arguments
- `slice`: interpolated values on the oblique plane.
- `xdata, ydata, zdata`: the X, Y and Z coordinates of the extracted slice in volume `v`.
"""
function obliqueslice(v, point, normal; method=Linear(), fillvalue::Real=0)

   point = Float64.(point)
   sz = size(v)
   xhalf, yhalf, zhalf = ntuple(i -> round(sz[i] / 2 + 1e-12), Val(3))

   # Initial normal vector along z axis
   ẑ = [0., 0., 1.]

   # Unit normal vector
   n̂ = normalize(normal)
   n̂ = normalize(normal)

   # Compute axis of rotation
   if ẑ == n̂
      W = n̂
   else
      W = ẑ × n̂
      normalize!(W)
   end

   # Compute angle of rotation in radians
   angle = acos(ẑ ⋅ n̂)

   # Quaternion rotation matrix
   t_quat = quat_matrix(W, -angle)

   # X, Y and Z coordinates of a plane with origin as the center
   (xp, yp), zp = let
      planeSize = 3*maximum(sz)
      xrange = round(-planeSize/2):round(planeSize/2)
      yrange = round(-planeSize/2):round(planeSize/2)
      meshgrid(yrange, xrange), zeros(length(yrange), length(xrange))
   end

   # Rotate coordinates of a plane
   xr, yr, zr = similar(xp), similar(yp), similar(zp)
   for i in eachindex(xp)
      coords = SVector(xp[i], yp[i], 0.0) 
      xr[i], yr[i], zr[i] = t_quat * coords
   end

   # Shift user input point, relative to input volume having origin as center
   point[1] -= yhalf
   point[2] -= xhalf
   point[3] -= zhalf

   # Find the shortest distance between the plane that passes through input point and origin
   D = n̂[1]*point[1] + n̂[2]*point[2] + n̂[3]*point[3]

   # Translate a plane that passes from origin to input point
   xq = @. xr + D*n̂[1] + yhalf
   yq = @. yr + D*n̂[2] + xhalf
   zq = @. zr + D*n̂[3] + zhalf

   # Obtain slice at desired coordinates using interpolation
   nodes = (axes(v,2), axes(v,1), axes(v,3))
   vpermute = permutedims(v, (2,1,3))
   itp = interpolate(nodes, vpermute, Gridded(method))
   etp = extrapolate(itp, fillvalue)

   # Make bounding box around the data in oblique slice
   slicelimit = @. (xq>=1) & (xq<=sz[2]) & (yq>=1) & (yq<=sz[1]) & (zq>=1) & (zq<=sz[3])

   slicerange = find_bounding_box(slicelimit)
   XData = xq[slicerange[1], slicerange[2]]
   YData = yq[slicerange[1], slicerange[2]]
   ZData = zq[slicerange[1], slicerange[2]]

   croppedslice = etp.(XData, YData, ZData)

   croppedslice, XData, YData, ZData
end

"Return Quaternion matrix for a rotation by a given angle `θ` about a fixed axis `w`."
function quat_matrix(w, θ)
   a_x, a_y, a_z = w

   c = cos(θ)
   s = sin(θ)

   t1 = c + a_x^2*(1-c)
   t2 = a_x*a_y*(1-c) - a_z*s
   t3 = a_x*a_z*(1-c) + a_y*s
   t4 = a_y*a_x*(1-c) + a_z*s
   t5 = c + a_y^2*(1-c)
   t6 = a_y*a_z*(1-c)-a_x*s
   t7 = a_z*a_x*(1-c)-a_y*s
   t8 = a_z*a_y*(1-c)+a_x*s
   t9 = c+a_z^2*(1-c)

   r = RotMatrix{3}(t1, t2, t3, t4, t5, t6, t7, t8, t9)
   q = QuatRotation(r)
end

"Find the position of the smallest box containing the 2D `region`."
function find_bounding_box(region)
   edges = Vector{CartesianIndex}(undef, 4)

   for j in axes(region,2), i in axes(region,1)
      if region[i,j]
         edges[1] = CartesianIndex(i, j)
         break
      end
   end

   for i in axes(region,1), j in axes(region,2)
      if region[i,j]
         edges[2] = CartesianIndex(i, j)
         break
      end
   end

   for j in reverse(axes(region,2)), i in reverse(axes(region,1))
      if region[i,j]
         edges[3] = CartesianIndex(i, j)
         break
      end
   end

   for i in reverse(axes(region,1)), j in reverse(axes(region,2))
      if region[i,j]
         edges[4] = CartesianIndex(i, j)
         break
      end
   end

   imin, imax = extrema(x -> x[1], edges)
   jmin, jmax = extrema(x -> x[2], edges)

   imin:imax, jmin:jmax
end

# Write this below at the Julia REPL
using PyPlot
point = [4,4,6]
normal = [1,1,1]
v = [i + (j-1)*10 + (k-1)*20  for i in 1:10, j in 1:20, k in 1:20]
slice, XData, YData, ZData = obliqueslice(v, point, normal)

imshow(slice, cmap="gray")

# To create an oblique slice from any kind of functions in 3 dimension, e.g. f(x,y) = x^2 + y^2 
#=
point = [4.0,4.0,6.0]
normal = [1,1,1]
v = [x^2 + y^2 + z^2  for x in 0:1.0:10, y in 0:1.0:10, z in 0:1.0:10]
slice, XData, YData, ZData = obliqueslice(v, point, normal)
=#
