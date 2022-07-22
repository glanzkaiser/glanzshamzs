# About
Simulations of a lot of science and engineering applications to real life problems.

## Tools
### 1. Julia-1.7.3
### 2. IJulia
### 3. Jupyter Notebook
### 4. Mozilla Firefox

To open Jupyter Notebook(you need a web browser installed first), then open your terminal and type
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
2. Graphs.jl is used for image processing tasks
3. OpenStreetMapX.jl package is used to load the data from the OpenStreetMap.org project and processes such graphs with Julia.


| OpenStreetMap' Pandemic Simulation: Machida, Japan | OpenStreetMap' Pandemic Simulation Plot: Cambridge, UK | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/JuliaSimulation1-1.png" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/JuliaSimulation1-2.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Simulations/OpenStreetMapMachida.ipynb">OpenStreetMapMachida</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Simulations/OpenStreetMapCambridge.ipynb">OpenStreetMapCambridge</a> | 

## 2. Oblique Slice for MRI

The orthoradial slice is straight up and down, while the oblique slice is slanted, similar to a forward slash on a computer. These slices help periodontists visualize the anatomical structures in the mouth and evaluate where the optimal placement of a dental implant would be.

In this 3-dimensional world, if we have a 3-d object, like a brain sample we can cut a slice at certain angle to obtain the oblique slice. To analyze the brain, or help in doing surgery or research about neurons.

### Packages used
1. FileIO is used to load the brain image (.tif file) 
2. Images is used to represent the directed graph structure object along with meta related to spatial information.
3. PlotlyJS is a Julia library for plotting with plotly.js .

| Oblique Slice | Oblique Slice from below | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/JuliaSimulation2-1.png" width="55%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/JuliaSimulation2-2.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/Simulations/obliqueslicemri.jl">obliqueslicemri.jl</a> | | 


# Sources

https://discourse.julialang.org/t/oblique-slices-in-makie/83879/6

https://pszufe.github.io/OpenStreetMapX_Tutorial/JuliaCon2020/
