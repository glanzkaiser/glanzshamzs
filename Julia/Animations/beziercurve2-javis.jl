using Plots, LaTeXStrings 
pyplot()

function compute_bernstein(i,n; steps=100)
    return [binomial(n,i)*t^i*(1-t)^(n-i) for t in LinRange(0,1,steps)]
end

function compute_bernstein_poly(px,py; steps=100)
    n = length(px)-1
    bernsteins = [compute_bernstein(i,n) for i=0:n]
    x_vals = [sum(px[k]*bernsteins[k][t] for k=1:n+1) for t=1:steps]
    y_vals = [sum(py[k]*bernsteins[k][t] for k=1:n+1) for t=1:steps]
    return x_vals, y_vals
end

function plot_with_bernstein(px,py; steps=100, subplot=1)
    x_vals, y_vals = compute_bernstein_poly(px,py; steps=steps)
    plot!(x_vals, y_vals, color=:blue, label="",subplot=subplot)
end

function animate_bezier(px,py;steps=100)
    n = length(px)-1
    # saving all in between de Casteljau points
    bs = [zeros(2,r) for r=n+1:-1:0]
    # base case Bézier points
    bs[1][1,:] = px 
    bs[1][2,:] = py
    points = zeros(steps,2)
    colors = [:green,:orange,:red,:yellow]
    c = 1
    anim = @animate for t in LinRange(0,1,steps)
        plot(;size=(700,500), axisratio=:equal, legend=false)
        plot!(px, py, linetype=:scatter)
        for i=1:n
            for j=0:n-i   
                # linear interpolation between twp ponts                   
                new_b = (1-t)*bs[i][:,j+1]+t*bs[i][:,j+2]
                bs[i+1][:,j+1] = new_b
                # drawing the line for linear interpolation as well as the specific point for t
                plot!(bs[i][1,j+1:j+2],bs[i][2,j+1:j+2], legend=false, color=colors[i])
                plot!([new_b[1]],[new_b[2]], linetype=:scatter, legend=false, color=colors[i])
                if i == n
                    points[c,:] = [new_b[1],new_b[2]]
                    # draw the curve until point t = LinRange(0,1,steps)[c]
                    plot!(points[1:c,1],points[1:c,2], color=:black)
                    c += 1
                end
            end
        end
    end
    gif(anim, "bezier_d2-1.gif", fps=30)
end
# M
px = [0, 3, 6, 9, 12]
py = [2, 17, 7, 17, 2]

# C
#=
px = [9, 3, 2, 4, 9]
py = [17, 12, 9, 6, 2]
=#
animate_bezier(px, py)
