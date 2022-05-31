# About
The Tokamak Game Physics SDK is an open-source physics engine. Tokamak features a unique iterative method for solving constraints. This is claimed to allow developers to make trade-offs between accuracy and speed and provides more predictable processor and memory usage. Tokamak's constraint solver does not involve solving large matrices, thereby avoiding memory bandwidth limitations on some game consoles. 

The SDK supports a variety of joint types and joint limits and a realistic friction model. Tokamak is optimized for stacking large numbers of objects - a frequently requested feature by game developers. Tokamak provides collision detection for primitives (box, sphere, capsule), combinations of primitives, and arbitrary static triangle meshes. Lightweight 'rigid particles' provide particle effects in games at minimal cost.

Tokamak also supports "Breakage Constructing models" which will break when a collision occurs. Fragments of the original model will automatically be spawned by Tokamak's built-in breakage functionality. 

As 3d games advance in complexity, it is commonly becoming a requirement to model realistic interaction between objects in the game world as they move, touch and collide with one another. The mathematical calculation required to perform these tasks is significant however and it is not a task that many game developers would wish to undertake themselves.

For example, think of the simple act of dropping a cube above a flat surface. The cube does not simply fall on to the surface and then stop moving, it bounces on the surface, perhaps at an odd angle that sends it spinning unpredictably back into the air. This is the type of movement that a physics engine attempts to model.

# Understanding the physics engine
The Tokamak engine has quite a number of variables and parameters that can affect the way in which it works.

Tokamak hinges around a class called neSimulator. This class is used to access all of the items of the physics engine and is also responsible for updating the positions of all the objects as the simulation runs.

There are two main types of object used in the simulation: rigid bodies and animated bodies. Rigid bodies are those for which the movement is completely controlled by the simulator; animated bodies are those for which the simulator will never change the position, these bodies are only ever repositioned by the application itself. For our sample, the floor will be an animated body and the cubes we drop towards it will be rigid bodies.

Because of the complexity of the calculations involved and the fact that the timing will not be identical every time the application runs, the simulation is never the same twice. 

# Sources
https://en.wikipedia.org/wiki/Tokamak_(software)

https://adamdawes.com/programming/tokamak/00_Intro.html
