# Linux

We are assuming that you are working in your home folder and you will need sudo rights to use apt.

This instructions will will lead you step by step through the process of setting up VTK in your home folder.

A good resource is here: [Building VTK](https://gitlab.kitware.com/vtk/vtk/-/blob/master/Documentation/dev/build.md).

``` bash
cd ~
```

## Preliminary Steps

### Update your installation

``` bash
sudo apt-get update
sudo apt-get upgrade
```

Make sure we have the tools needed to build VTK:

``` bash
sudo apt-get install  build-essential  libncurses5-dev libxext-dev mesa-common-dev mesa-utils freeglut3-dev python3-dev python3-venv git-core gitk git-gui ninja-build
```

Download and install CMake from [Get the Software](https://cmake.org/download/), it's a good idea to make sure `cmake-gui` is installed, for this you need Qt.

Or you can use:

``` bash
sudo apt-get install cmake cmake-gui
```

### Setup Python

We will use a virtual environment for VTK, let's call it `VTK`.

If you are already in a virtual environment `deactivate` to make sure the correct version of python is being used.

Create the virtual environment:

``` bash
deactivate
python3 -m venv $HOME/venv/VTK
```

Activate and install the necessary components for VTK:

``` bash
source $HOME/venv/VTK/bin/activate
python -m pip install --upgrade pip
pip install wheel
pip install Sphinx scipy numpy matplotlib pytz tzdata setuptools
deactivate
```

In future, if you want to upgrade packages:

``` bash
source $HOME/venv/VTK/bin/activate
python -m pip install --upgrade pip
pip install  --upgrade Sphinx scipy numpy matplotlib pytz tzdata setuptools
deactivate
```

At this stage you have a virtual environment for VTK, test it:

``` bash
source $HOME/venv/VTK/bin/activate
python -v
deactivate
```

## Create local source and build folders for VTK

The source for building VTK will be in `~/Kitware/src/VTK` and the build for VTK will be in `~/Kitware/build/VTK`.

``` bash
cd ~
mkdir -p ~/Kitware/{src/VTK,build/VTK}
```

## Download the VTK Source

Download the [VTK Latest Release](https://vtk.org/download/), unpack it and move/copy the contents into `~/Kitware/src/VTK`.

## Build VTK

Let's just do a minimal build, you can "build" on this later.
For more information see [Building VTK](https://gitlab.kitware.com/vtk/vtk/-/blob/master/Documentation/dev/build.md).

So for CMake we need the following settings:

* `BUILD_SHARED_LIBS`: `ON` - should be `ON` by default
* `VTK_ALL_NEW_OBJECT_FACTORY`: `ON`
* `VTK_ENABLE_WRAPPING`: `ON` - should be `ON` by default
* `VTK_WRAP_PYTHON`: `ON`

When you configure VTK make sure your Python virtual envirionment is activated. We will use cmake-gui to do the VTK configuration.

``` bash
cd ~/Kitware/build/VTK
source $HOME/venv/VTK/bin/activate
cmake-gui ~/Kitware/src/VTK
```

Press `Configure`, specifying `Ninja` as the generator and then set the above settings to `ON`. Use `Search` to find the settings.

Once you have set everything, press `Generate`.

Exit and run `ninja`:

``` bash
ninja
```

## Testing

Create a folder:

``` bash
mkdir ~/Kitware/Testing
```

Go to [CylinderExample](https://kitware.github.io/vtk-examples/site/Cxx/GeometricObjects/CylinderExample/) and download the tarball, extract it, and move it into `Kitware/Testing`

Create a file called `CylinderExample.py` in `Kitware/Testing` mark it executable (if you want) and open it in a text editor. Go to the python version of [CylinderExample](https://kitware.github.io/vtk-examples/site/Python/GeometricObjects/CylinderExample/) and copy it into your `CylinderExample.py` and save it.

We need to pick up where the vtk build is and where the lib is:

``` bash
export VTK_DIR=$HOME/Kitware/build/VTK
source $VTK_DIR/unix_path.sh
```

Now go to the Testing folder and build the test:

``` bash
cd ~/Kitware/Testing/CylinderExample/build
cmake-gui ..
```

Press `Configure`, specifying `Ninja` as the generator then press `Generate` and exit, then:

``` bash
ninja
./CylinderExample
```

For Python, you can use either `python`or `vtkpython`:

``` bash
cd ~/Kitware/Testing/
python CylinderExample.py
~/Kitware/build/VTK/bin/vtkpython CylinderExample.py
```

If the CylinderExample is executable:

``` bash
./CylinderExample.py
```
