# About
Bullet Physics is a professional open source collision detection, rigid body and soft body dynamics library. Bullet Physics target real-time and interactive  use in games, visual effects in movies and robotics.

#### This folder contain all the Bullet-3.24 examples that can be tested and modified then build with CMakeLists.txt.

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

If you want to configure Bullet installation more, you can directly build and install it with:

```
mkdir build
cd build
ccmake ..
make -j4
make install
```

# Install PyBullet
Install PyBullet using:
```
pip3 install pybullet --user --upgrade
```

## Example at PyBullet

```
cd /$physics/bullet/examplesfull/pybullet/examples
python3 addPlanarReflection.py
```

![ducks](https://github.com/glanzkaiser/glanzshamzs/blob/main/Robotics/images/ducks.png)

## Try my_example.zip

Unzip the folder:
```
unzip my_example.zip -d /sources/Hamzstlab/
```

Then type:
```
pip install trimesh[easy]
python example_01.py
```

# Sources:

https://github.com/bulletphysics/bullet3/tree/master/docs
