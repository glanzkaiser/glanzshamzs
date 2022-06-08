using Plots 
pyplot()

COL = append!([colorant"blue",colorant"lime"],range(colorant"yellow",colorant"red",length=20))
  
Plots.plot(x,y,z,st=:surface,color=cgrad(COL,scale=:exp),#cgrad(:jet,c),
xlabel = "x",ylabel="y",zlabel="f(x,y)",zguidefontrotation=45,camera=(-30,30))
