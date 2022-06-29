function test!(du,u,p,t)
    yield = 10
    decay = 5
    du[1] = yield*p(t) - decay*u[1]
end

u0 = [0]
tspan = (0,10)
p = 3

prob = ODEProblem(test!,u0,tspan,p)
sol = solve(prob);

ts_time = (0:11)
ts_val = [1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0]

ts = LinearInterpolation(ts_time, ts_val)

prob = ODEProblem(test!,u0,tspan,ts)
sol = solve(prob);

