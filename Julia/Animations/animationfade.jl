# Fetches the requried packages.
using Plots
using DifferentialEquations #Required to make the star.
Plots.default(dpi=200)
pyplot()

#Sets parameters
n = 200;                                     # Number of points in each cycle.
f = 0.85;                                    # Fraction of points displayed
pts_disp = f*n;                              # The number of points displayed at every time.
N = 7;                                       #The number of cycles displayed (reduces the number of times there is a "hack" in the snow fall).
t = range(0.,2*π,length=n);                  # The time vector.

#Prepares the tree
width = 2
tree_length = 8.5π
y = Array(range(0,tree_length,length=n))
x = width*sin.(y).*sqrt.(y)
Tree = (x,y[end:-1:1]);

#Prepares a ball
x = sin.(t[1:end-2])
y = cos.(t[1:end-2])
Ball = ([x...,x[1],x[2]],[y...,y[1],y[2]]);

#Prepares the root
r_length = tree_length/10;
y = Array(range(0,r_length,length=n))[end:-1:1]
x = zeros(n)
Root = (x,y.-tree_length/20);

#Prepares the star
star_size = 0.7
R = star_size*5.;     # Hypotrochoid parameter.
r = star_size*3.;     # Hypotrochoid parameter.
d = star_size*3.;     # Hypotrochoid parameter.
function star(du,u,p,t)
 du[1] = (p[1]-p[2])*cos(t)+p[3]*cos(t*(p[1]-p[2])/p[2])
 du[2] = (p[1]-p[2])*sin(t)-p[3]*sin(t*(p[1]-p[2])/p[2])
end;
u0 = [R-r+d,0.]
tspan = (0., 6*π)
p = [R,r,d]
prob = ODEProblem(star,u0,tspan,p)
sol_star = solve(prob,dtmax=0.2,saveat=range(0.,6*π,length=(n-2)));
x = first.(sol_star.u).-R
y = last.(sol_star.u).+tree_length.+r
Star = ([x...,x[1],x[2]],[y...,y[1],y[2]]);

#Stacks up the designated number of cycles
for object in [Tree, Ball, Root, Star]
    cpy = deepcopy(object)
    for i = 2:N 
        append!(object[1],cpy[1])
        append!(object[2],cpy[2])
    end
end

#Define the plotting area
x0 = -25; x1 = -x0;
y0 = -5; y1 = 40;
sx = 400;
sy = sx*(y1-y0)/(x1-x0);


#Let it snow
n_snow = 50
x_snow = x1 .* 2 .* (0.5 .- rand(n_snow))
y_snow = (y1 - y0) .* rand(n_snow) .+ y0
function move_y_snow(y_snow, movements, ylims) 
    y_snow .-= movements
    for i in eachindex(y_snow)
        if y_snow[i] < ylims[1]
            y_snow[i] = ylims[2]
        end
    end
end
function move_x_snow(x_snow, additions, xlims) 
    x_snow .+= additions
    for i in eachindex(y_snow)
        if x_snow[i] > xlims[2]
            x_snow[i] -= xlims[2] - xlims[1]
        elseif y_snow[i] < xlims[1]
            x_snow[i] += xlims[2] - xlims[1]
        end
    end
end;

#Makes the animation
anim = @animate for t_end1 in 1:n*N
    t_end1 = t_end1%n
    (t_end1==0)&&(t_end1=1)
    t_start1 = Int(max(1,t_end1-pts_disp)) 
    t_start2 = Int(t_end1+n-pts_disp)
    t_end2 = Int(min(t_start2+pts_disp-t_end1+t_start1,n))
    plot(xlims=(x0, x1), ylims=(y0, y1),size=(sx,sy), legend=false)
    plot!(xaxis=false,yaxis=false, grid=false, legend=false,linewidth=5)
    
    
    y_rate = 0.5
    x_rate = 0.5
    move_y_snow(y_snow, y_rate .* rand(n_snow), (y0, y1))
    move_x_snow(x_snow, x_rate .* (0.5 .- rand(n_snow)), (x0, x1))
    scatter!(x_snow, y_snow, ms=8, markershape=:star6, color=:white)
    
    lw_tree = 7
    plot!(Tree[1][t_start1:t_end1],Tree[2][t_start1:t_end1],color=:green, linewidth=lw_tree) 
    plot!(Tree[1][t_start2:t_end2],Tree[2][t_start2:t_end2],color=:green,linewidth=lw_tree)
    plot!(Star[1][t_start1:t_end1],Star[2][t_start1:t_end1],color=:yellow,linewidth=lw_tree)
    plot!(Star[1][t_start2:t_end2],Star[2][t_start2:t_end2],color=:yellow,linewidth=lw_tree)
    
    lw_ball = 9
    plot!(Ball[1][t_start1:t_end1].-8,Ball[2][t_start1:t_end1].+2.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start2:t_end2].-8,Ball[2][t_start2:t_end2].+2.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start1:t_end1].+8,Ball[2][t_start1:t_end1].+5.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start2:t_end2].+8,Ball[2][t_start2:t_end2].+5.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start1:t_end1].-6.5,Ball[2][t_start1:t_end1].+9,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start2:t_end2].-6.5,Ball[2][t_start2:t_end2].+9,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start1:t_end1].+5,Ball[2][t_start1:t_end1].+12,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start2:t_end2].+5,Ball[2][t_start2:t_end2].+12,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start1:t_end1].-3.75,Ball[2][t_start1:t_end1].+15.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start2:t_end2].-3.75,Ball[2][t_start2:t_end2].+15.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start1:t_end1].+3.25,Ball[2][t_start1:t_end1].+18.5,color=:red,linewidth=lw_ball)
    plot!(Ball[1][t_start2:t_end2].+3.25,Ball[2][t_start2:t_end2].+18.5,color=:red,linewidth=lw_ball)
    
    lw_root = 20
    plot!(Root[1][t_start1:t_end1],Root[2][t_start1:t_end1],color=:brown,linewidth=lw_root)
    plot!(Root[1][t_start2:t_end2],Root[2][t_start2:t_end2],color=:brown,linewidth=lw_root)
    
    plot!(bg_color=:black)
end;

#Displays/saves the animation
gif(anim,"christmas_tree.gif",fps = 40)
