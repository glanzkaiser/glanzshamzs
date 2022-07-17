# About
Simulation of a lot of science and engineering application to real life problems.

## Tools
### 1. Julia-1.7.3
### 2. IJulia
### 3. Jupyter Notebook
### 4. Mozilla Firefox

To open Jupyter Notebook(you need a web browser installed first), then open you terminal and type
```
julia

julia> using IJulia
julia> notebook()
```

# Gallery

## 1. OpenStreetMapX

A package for spatial analysis, simulation and visualization of Open Street Map data. This simulation provides a backbone for multi-agent modelling and simulation of cities. The library provides a bridging functionality between real world spatial data available in the OpenStreetMap project and Graphs.jl. 

First we create complex graphs in transportation networks for vehicles moving under certain time, afterwards we simulate agents and moving it inside the area selected and after certain time we can predict how many people will be infected in that area.

### Packages used
1. folium package is used for graphs visualization and providing an interactive vizualization of results.
2. Graphs.jl is used to represent the directed graph structure object along with meta related to spatial information.
3. OpenStreetMapX.jl package is used to load the data from the OpenStreetMap.org project and processes such graphs with Julia.


| OpenStreetMap' Pandemic Simulation: Machida, Japan | OpenStreetMap' Pandemic Simulation Plot: Cambridge, UK | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/JuliaSimulation1-1.png" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/JuliaSimulation1-2.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Simulations/OpenStreetMapCambridge.ipynb">OpenStreetMapCambridge.ipynb</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Simulations/OpenStreetMapMachida.ipynb">OpenStreetMapMachida.ipynb</a> | 

# Sources

https://pszufe.github.io/OpenStreetMapX_Tutorial/JuliaCon2020/
