# use HTTP if needs to download
using FileIO, Images
using PlotlyJS
#url = "https://s3.amazonaws.com/assets.datacamp.com/blog_assets/attention-mri.tif"
#download(url, "attention-mri.tif")
img = load("/home/browni/LasthrimProjection/JupyterLab/attention-mri.tif");
vol = permutedims(channelview(img),  (1, 3, 2));
bone =  [[0.0, "rgb(255, 255, 255)"], #matplotlib colormap; I couldn't find the Colorschemes.bone
         [0.1, "rgb(220, 233, 233)"],
         [0.2, "rgb(185, 210, 210)"],
         [0.3, "rgb(156, 184, 188)"],
         [0.4, "rgb(133, 153, 165)"],
         [0.5, "rgb(112, 123, 143)"],
         [0.6, "rgb(89, 92, 121)"],
         [0.7, "rgb(66, 66, 92)"],
         [0.8, "rgb(44, 44, 62)"],
         [0.9, "rgb(21, 21, 30)"],
         [1.0, "rgb(0, 0, 0)"]];
function oblique_slice(vol::Array{T,3};  a=0, α=0,  axis="x", colorscale=bone) where T
    r, c, h = size(vol)
    xl = 0:1:c-1
    yl = 0:1:r-1
    x = ones(r, c) .* xl'
    y = yl .* ones(r,c)
    α = deg2rad(α)
    if axis == "x"
        z  = a/cos(α) .+ y*tan(α)
    elseif axis == "y" 
         z = a/cos(α) .-x*tan(α)  
    else
        error("rotate only about xaxis and yaxis")
    end
    sc = similar(z) #surfacecolor
    for idx in CartesianIndices(z) 
        s = floor(Int, z[idx])
        if 0 <= z[idx] <= h-1
            t = z[idx]-s 
            # the color at the slice point, P(x[i,j], y[i,j], z[i, j)), is the
            # interpolated color of the two nearest  voxels on the same vertical
            sc[idx] = (1-t)*vol[idx, s+1] + t*vol[idx, s+2]  
        else
            sc[idx] = NaN
        end   
    end 
    #hmax=maximum(z[(x->!isnan(x)).(sc)])
    return Plot(surface(x=x, y=y, z=z, surfacecolor=sc, 
                        colorscale=colorscale, #reversescale=true,
                        showscale=false), 
                Layout(width=500, height=500, font_size=11, 
                       scene_zaxis_range=(0, h) #or (0, hmax)
            ))
end 

fig1 = oblique_slice(vol, a=35, α=-10, axis="x")

# Try different slice
# fig2 = oblique_slice(vol, a=48, α=12, axis="y")
