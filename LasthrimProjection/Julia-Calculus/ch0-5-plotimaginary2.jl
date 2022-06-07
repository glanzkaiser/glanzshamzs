using PyPlot
nums = ComplexF64.([1,2,4],[2,2,-1])
polar.(Base.vect.(0.0,angle.(nums)),Base.vect.(0.0,abs.(nums)),marker="o")
