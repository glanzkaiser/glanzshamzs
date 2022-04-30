using Plots
pyplot()

plot(rand(10, 4), layout = 4, xguide = "x guide", yguide = "y guide", xguidefonthalign = [:left :right :right :left], yguidefontvalign = [:top :bottom :bottom :top], xguideposition = :top, yguideposition = [:right :left :right :left], ymirror = [false true true false], xmirror = [false false true true], legend = false, seriestype = [:bar :scatter :path :stepmid])
