# About
The src folder contains the C++ (.cpp) files for demo in project Chrono.

Project Chrono is a physics-based simulation infrastructure based on a platform-independent, open-source design.

# Edit Makefile
You can edit the Makefile to adjust with your target file, the default target is experimental.cpp

# Notes on using Makefile instead of Gcc
Based on a forum that I read:

You shouldn't use GCC raw, you're making your life much harder. 
You should use cmake or another build tool for any serious project. Using GCC or a makefile is only good for when you have small projects without many dependencies.

You don't need to compile in all of the object files for irrlicht (these are already included in libirrlicht.a), 
so you only need to link against the library that has already been compiled.

#### -IPATH 

directive tells the compiler to look in PATH for include files

#### -LPATH 

directive tells the compiler to look in PATH for library files

#### -I$(IRRLICHT_PATH)/include 

tells the compiler to look in that path for the include files
When <irrlicht.h> is included in the cpp file it will look in this path for it (the other includes from this will be found as well)
