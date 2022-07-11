f(x) = sin.(x)/(x)

println("x \t sin(x)/x ")

for N in -1:0.1:10
    g = sin.(N) / N
    println("$N \t $g ")
end
