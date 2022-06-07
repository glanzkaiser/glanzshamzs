using Plots
pyplot()

function test(a)
    alpha = 1
    for i in 1:a
        alpha += 1
    end
    return alpha
end

a = 1:100
plot(test, 1, 100, xaxis=:log)

# plot(x -> exp(x) + exp(-x), -2, 2) 
