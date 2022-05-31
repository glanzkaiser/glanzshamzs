# About
The Tokamak Game Physics SDK is an open-source physics engine. Tokamak features a unique iterative method for solving constraints. This is claimed to allow developers to make trade-offs between accuracy and speed and provides more predictable processor and memory usage. Tokamak's constraint solver does not involve solving large matrices, thereby avoiding memory bandwidth limitations on some game consoles. 

The SDK supports a variety of joint types and joint limits and a realistic friction model. Tokamak is optimized for stacking large numbers of objects - a frequently requested feature by game developers. Tokamak provides collision detection for primitives (box, sphere, capsule), combinations of primitives, and arbitrary static triangle meshes. Lightweight 'rigid particles' provide particle effects in games at minimal cost.

Tokamak also supports "Breakage Constructing models" which will break when a collision occurs. Fragments of the original model will automatically be spawned by Tokamak's built-in breakage functionality. 
