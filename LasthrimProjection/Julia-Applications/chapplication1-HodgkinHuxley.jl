using Plots
gr()
 
# Hyperparameters
tmin = 0.0
tmax = 1000.0
dt = 0.01
T = tmin:dt:tmax
 
# Parameters
gK = 35.0
gNa = 40.0
gL = 0.3
Cm = 1.0
EK = -77.0
ENa = 55.0
El = -65.0
 
# Potassium ion-channel rate functions
alpha_n(Vm) = (0.02 * (Vm - 25.0)) / (1.0 - exp((-1.0 * (Vm - 25.0)) / 9.0))
beta_n(Vm) = (-0.002 * (Vm - 25.0)) / (1.0 - exp((Vm - 25.0) / 9.0))
 
# Sodium ion-channel rate functions
alpha_m(Vm) = (0.182*(Vm + 35.0)) / (1.0 - exp((-1.0 * (Vm + 35.0)) / 9.0))
beta_m(Vm) = (-0.124 * (Vm + 35.0)) / (1.0 - exp((Vm + 35.0) / 9.0))
 
alpha_h(Vm) = 0.25 * exp((-1.0 * (Vm + 90.0)) / 12.0)
beta_h(Vm) = (0.25 * exp((Vm + 62.0) / 6.0)) / exp((Vm + 90.0) / 12.0)
 
# n, m & h steady-states
n_inf(Vm=0.0) = alpha_n(Vm) / (alpha_n(Vm) + beta_n(Vm))
m_inf(Vm=0.0) = alpha_m(Vm) / (alpha_m(Vm) + beta_m(Vm))
h_inf(Vm=0.0) = alpha_h(Vm) / (alpha_h(Vm) + beta_h(Vm))
 
# Conductances
GK(gK, n) = gK * (n ^ 4.0)
GNa(gNa, m) = gNa * (m ^ 3.0) * h
GL(gL) = gL
 
# Differential equations
function dv(Vm, GK, GNa, GL, Cm, EK, ENa, El, I, dt);
    ((I  - (GK * (v - EK)) - (GNa * (v - ENa)) - (GL * (v - El))) / Cm) * dt
end
dn(n, Vm, dt) = ((alpha_n(Vm) * (1.0 - n)) - (beta_n(Vm) * n)) * dt
dm(m, Vm, dt) = ((alpha_m(Vm) * (1.0 - m)) - (beta_m(Vm) * m)) * dt
dh(h, Vm, dt) = ((alpha_h(Vm) * (1.0 - h)) - (beta_h(Vm) * h)) * dt
I = T * 0.002
 
# Initial conditions and setup
v = -65
m = m_inf(v)
n = n_inf(v)
h = h_inf(v)
 
v_result = Array{Float64}(undef, length(T))
m_result = Array{Float64}(undef, length(T))
n_result = Array{Float64}(undef, length(T))
h_result = Array{Float64}(undef, length(T))
 
v_result[1] = v
m_result[1] = m
n_result[1] = n
h_result[1] = h
 
 
for t = 1:length(T)-1
    GKt = GK(gK, n)
    GNat = GNa(gNa, m)
    GLt = GL(gL)
 
    dvt = dv(v, GKt, GNat, GLt, Cm, EK, ENa, El, I[t], dt)
    dmt = dm(m, v, dt)
    dnt = dn(n, v, dt)
    dht = dh(h, v, dt)
 
    global v = v + dvt
    global m = m + dmt
    global n = n + dnt
    global h = h + dht
 
    v_result[t+1] = v
    m_result[t+1] = m
    n_result[t+1] = n
    h_result[t+1] = h
end
 
p1 = plot(T, v_result, xlabel="time (ms)", ylabel="voltage (mV)", legend=false, dpi=300)
