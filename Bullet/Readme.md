# About
Bullet Physics is a professional open source collision detection, rigid body and soft body dynamics library. Bullet Physics target real-time and interactive  use in games, visual effects in movies and robotics.

# Install Bullet 3
To download it first type:
```
wget https://github.com/bulletphysics/bullet3/archive/refs/tags/3.24.tar.gz
tar -xvf 3.24.tar.gz
```
Make sure cmake is installed then enter the directory then type:
```
./build_cmake_pybullet_double.sh
```
(You can also build Bullet using premake)

After finish then cd to build_cmake, then type:
```
ccmake .
		
```
#### Set the CMAKE_INSTALL_PREFIX=/opt/hamzstlib

Then type:
```
make
make install
```  

# Install PyBullet
Install PyBullet using:
```
pip3 install pybullet --user --upgrade
```

## Try myexamples.zip

Unzip the folder then type:
```
pip install trimesh[easy]
python example_01.py
```
