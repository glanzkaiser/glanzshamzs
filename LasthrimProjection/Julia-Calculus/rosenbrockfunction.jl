using Gnuplot

x  = [-2:0.05:2;]
y = [-1:0.05:3;]
z = (1 .-x').^2 .+ 100 .*(y.-x'.^2).^2

minZ = minimum(z[:]);  
maxZ = maximum(z[:]);

c =  minZ .+ (maxZ-minZ).*log.(1 .+z .- minZ) ./ log(1+maxZ-minZ)

@gsp "set xyplane at 0" palette(:jet1) cbr=extrema(c) :-
@gsp :- x y z c "w pm3d notit"

@gsp :- xlab="x" ylab="y" "set zlabel 'f(x,y)' rot parallel" :-
@gsp :- xr=[-2.01,NaN] yr=[-1.01, NaN]
@gsp :- "set view 50, 240"
@gsp :- "set grid vertical"
@gsp :- "set grid ztics"

save(output="rosenbrock.png", term="pngcairo size 800,600")
