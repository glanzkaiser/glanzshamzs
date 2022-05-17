# Official User Guide
https://cfd.direct/openfoam/user-guide/v9-introduction/

# About OpenFOAM
OpenFOAM is a framework for developing application executables that use packaged functionality contained within a collection of over 100 C++ libraries. OpenFOAM is shipped with approximately 200 pre-built applications that fall into two categories: solvers, that are each designed to solve a specific problem in fluid (or continuum) mechanics; and utilities, that are designed to perform tasks that involve data manipulation. 

# Geometry in OpenFOAM
Salome is a good option for creating complex geometry otherwise use what already provided for simple example in $FOAM_TUTORIAL then

   blockMesh
   snappyHexMesh
  
are more than enough
 
# How to Simulate OpenFOAM with Paraview
When the calculation terminated (e.g. after pisoFoam, simpleFoam, etc) type 

  touch results.foam
  
or

  paraFoam -builtin
  
# Hamzst' Opinion on OpenFOAM
A nice open source software on CFD, we can solve a lot of real world problems by modifying the current solvers or combining the existing solvers, by permutation methods. 


Freya has uploaded OpenFOAM tutorials on her Youtube channel, you may see it, it contains the step to simulate OpenFOAM with Paraview 5.10.0 instead of 5.6.3

https://www.youtube.com/watch?v=78rN0WNYC3M&list=PLjKBQAK4kvphNYh4ufnKatizAvdCxRPmt

The Operating System in use: GFreya OS (From Linux From Scratch to BLFS and then Glanz keeps adding packages with focus on Science and Engineering)
