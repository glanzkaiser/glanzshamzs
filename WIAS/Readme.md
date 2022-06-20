# Background Story
Why we put WIAS here ?
On June 20th 2022, I saw this VTK question:
#### I have a .stl mesh file that is hollow inside. Can I change this to a solid mesh file in vtk? 

Then someone answered it:

#### VTK does not have general 3D meshing capabilities. vtkDelaunay3D can fill the volume but it will output the convex hull of your input. You may look at CGAL ( or a python wrapper of CGAL), Gmsh (or a python wrapper of Gmsh) or TetGen 1 (or PyVista Wrapper of TetGen) for more general mesh generation capabilities. All three can output to VTK formats.

I already browsed Gmsh, and Freya said that CGAL is only a pain better focus on BLAS and LAPACK instead of CGAL. Then why not try TetGen?
When I see the organization that created TetGen (WIAS), is more or less like SANL that created Trilinos.. Meaning. Tons of Mathematics packages, in Stochastics and Numerics area. 

# About
The Weierstrass Institute conducts project oriented research in applied mathematics with the aim of solving complex problems in technology, science and the economy. The institute deals with the whole scientific solution process, starting with mathematical modeling, followed by the theoretical analysis of models, and ending with the numerical simulation of the solution. In this context, the WIAS maintains long term, wide-ranging contacts with those who apply mathematics in industry and other areas of research and for whom it is a reliable partner.

The institute's core strengths are applied analysis and stochastics, developing and implementing numerical algorithms, and producing scientific software, as well as the consistent mathematical modeling of scientific and technological phenomena, and suitably combining all these strengths. Due to this wide range of strengths, WIAS is able to work on complex problems over long periods of time and through different phases, as well as tackle new problems and deliver fast solutions.

Application areas are oriented towards social requirements like the utilization of energy, development of medicine, research on material characteristics, or the quality analysis of technological innovations, which are reflected through our main areas of application: 
1. Conversion, Storage and Distribution of Energy
2. Flow and Transport 
3. Materials Modeling
4. Nano- and Optoelectronics
5. Optimization and Control in Technology and Economy
6. Quantitative Biomedicine

It is becoming more and more important to extract structure from very large disordered data sets or to give reliable statements about a process, even when the input data is subject to uncertainty. To solve these kinds of problems, WIAS combines methods from statistics, partial (stochastic) differential equations and numerics.

# Research
The Weierstrass Institute dedicates itself to fundamental mathematical research in analysis, stochastics and numerical methods, as well as the development of algorithms and scientific software, and the software's long-term maintenance. During the problem-solving process, mathematical models of physical and technological systems are designed that properly capture observed phenomena, thereby providing access to highly developed mathematical analysis. At WIAS the phases of the solving process are repeated and coordinated until an optimal solution is found.

## 1. TetGen
TetGen is a software for tetrahedral mesh generation. Its goal is to generate good quality tetrahedral meshes suitable for numerical methods and scientific computing. It can be used as either a standalone program or a library component integrated in other software.

TetGen generates the Delaunay tetrahedralization, Voronoi diagram, and convex hull for three-dimensional point sets, generates the constrained Delaunay tetrahedralizations and quality tetrahedral meshes for three-dimensional domains with piecewise linear boundary.

### TetGen Manual:

https://wias-berlin.de/software/tetgen/1.5/doc/manual/manual.pdf


## 2. TetView
TetView is a small graphic program for viewing tetrahedral meshes and piecewise linear complexes. It is created sepcifically for viewing and analyzing the input and output files of TetGen. However, it has the general features for viewing geometry objects and triangular and tetrahedral meshes.

### Install TetView
After you download TetView either from this directory or the website, unzip it then type:
```
chmod +x tetview-xxx
```
Unzip and extract the example files (examples.tar.gz) of TetView. Save these files into the same directory where you have the executable version of TetView, then type:
```
./tetview
```
TetView starts the lua script environment, you can run lua scripts or special commands available in TetView. To exit type 'Ctrl+D'

### TetView Tutorial:

https://wias-berlin.de/software/tetgen/tetview.tutorial.html

https://wias-berlin.de/software/tetgen/tetview.html

# Sources
https://wias-berlin.de/about/mission.jsp?lang=1

https://wias-berlin.de/research/rgs/index.jsp?lang=1

https://wias-berlin.de/software/tetgen/features.html

https://wias-berlin.de/software/tetgen/tetview.tutorial.html
