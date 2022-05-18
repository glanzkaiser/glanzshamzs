# About
The Irrlicht Engine is an open source realtime 3D engine written in C++. It is cross-platform, using D3D, OpenGL and its own software renderers. OpenGL-ES2 and WebGL renderers are also in development. It is a stable library which has been worked on for nearly 2 decades. 

Irrlicht is used by hobbyists and professional companies alike. You can find enhancements for it all over the web, like alternative terrain renderers, portal renderers, exporters, world layers, tutorials, editors, language bindings and so on. And best of all: It's completely free. 

# Edit Makefile
You can edit the Makefile to adjust with your target file, the default target is experimental.cpp

# Notes on using Makefile instead of Gcc
Based on a forum that I read:

You shouldn't use GCC raw, you're making your life much harder. You should use cmake or another build tool for any serious project. Using GCC or a makefile is only good for when you have small projects without many dependencies

You don't need to compile in all of the object files for irrlicht (these are already included in libirrlicht.a), so you only need to link against the library that has already been compiled.

#### -IPATH 

directive tells the compiler to look in PATH for include files

#### -LPATH 

directive tells the compiler to look in PATH for library files

#### -I$(IRRLICHT_PATH)/include 

tells the compiler to look in that path for the include files
When <irrlicht.h> is included in the cpp file it will look in this path for it (the other includes from this will be found as well)
