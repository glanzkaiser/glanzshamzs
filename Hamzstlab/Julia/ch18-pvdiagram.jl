using Plots

T0 = 492
V0 = 275
Tmax = 25
Vmax = 75

V(t) = V0-Vmax*cos(t)
P(t) = (T0 + Tmax*sin(t))/V(t)
plot(V, P, 0:0.1:2pi, label="p-V diagram", legend=:outertop)
