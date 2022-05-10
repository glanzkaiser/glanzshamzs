# Linux

## Introduction

We are assuming that you are working in your home folder and you will need `sudo` rights to use apt.

These instructions will will lead you step by step through the process of setting up VTK in your home folder.

A good resource is here: [Building VTK](https://gitlab.kitware.com/vtk/vtk/-/blob/master/Documentation/dev/build.md).

The directory structure in your home folder will be:

``` text
Kitware
|-- Kitware
  |-- build
  |-- src
  |-- test

```

There will be a `VTK` folder in each of `build`, `src`, `test`. The advantage of this structure is a clear functional separation which also allows adding future sources and builds such as for **ParaView** and the **vtk-examples** in their own sub-folders.

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

You can:

``` bash
sudo apt-get install cmake cmake-gui
```

Or download and install CMake from [Get the Software](https://cmake.org/download/), it's a good idea to make sure `cmake-gui` is installed. Note that, if you are building `cmake-gui`, Qt needs to be installed.

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
pip install --upgrade Sphinx scipy numpy matplotlib pytz tzdata setuptools wheel
deactivate
```

At this stage you have a virtual environment for VTK, test it:

``` bash
source $HOME/venv/VTK/bin/activate
python -v
deactivate
```

## Create local source and build folders for VTK

The source for building VTK will be in `~/Kitware/src/VTK`, the build for VTK will be in `~/Kitware/build/VTK` and tests in `~/Kitware/tests/VTK`.

``` bash
cd ~
mkdir -p ~/Kitware/{src/VTK,build/VTK,tests/VTK}
```

## Build VTK

Download the [VTK Latest Release](https://vtk.org/download/), unpack it and move/copy the contents into `~/Kitware/src/VTK`.

Let's just do a minimal build, you can "build" on this later.
For more information see [Building VTK](https://gitlab.kitware.com/vtk/vtk/-/blob/master/Documentation/dev/build.md).

So for CMake we need the following settings:

* `BUILD_SHARED_LIBS`: `ON` - should be `ON` by default
* `VTK_ALL_NEW_OBJECT_FACTORY`: `ON`
* `VTK_ENABLE_WRAPPING`: `ON` - should be `ON` by default
* `VTK_WRAP_PYTHON`: `ON`

We will use `cmake-gui` to do the VTK configuration.

**Before even configuring VTK for a build using CMake, make sure your Python virtual environment is activated.**

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

Go to [CylinderExample](https://kitware.github.io/vtk-examples/site/Cxx/GeometricObjects/CylinderExample/) and download the tarball, extract it, and move it into `Kitware/test/VTK`

Create a file called `CylinderExample.py` in `Kitware/test/VTK`, mark it executable (if you want) and open it in a text editor. Go to the python version of [CylinderExample](https://kitware.github.io/vtk-examples/site/Python/GeometricObjects/CylinderExample/) and copy it into your `CylinderExample.py` and save it.

We need to pick up where the vtk build is and where the lib is:

``` bash
export VTK_DIR=$HOME/Kitware/build/VTK
source $VTK_DIR/unix_path.sh
alias vtkpython=$HOME/Kitware/build/VTK/bin/vtkpython
```

Now go to the Testing folder and build the test:

``` bash
cd ~/Kitware/test/VTK/CylinderExample/build
cmake-gui ..
```

Press `Configure`, specifying `Ninja` as the generator then press `Generate` and exit, then:

``` bash
ninja
./CylinderExample
```

For Python, you can use either `python`or `vtkpython`:

``` bash
cd ~/Kitware/test/VTK
python CylinderExample.py
vtkpython CylinderExample.py
```

If the CylinderExample is executable:

``` bash
./CylinderExample.py
```

## Finally

You **must** set the environment as follows:

``` bash
source $HOME/venv/VTK/bin/activate
export VTK_DIR=$HOME/Kitware/build/VTK
source $VTK_DIR/unix_path.sh
alias vtkpython=$HOME/Kitware/build/VTK/bin/vtkpython
```

This can be put into a bash script that you can source.

Here is an example:

``` bash
source $HOME/venv/VTK/bin/activate
export VTK_DIR=$HOME/Kitware/build/VTK
if [ -f $VTK_DIR/unix_path.sh ]
then
  source $VTK_DIR/unix_path.sh
else
  # Note: x86_64-linux-gnu and python3.9 depend on your implementation
  #       and may be different from the values here.
  export LD_LIBRARY_PATH=$VTK_DIR/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH
  export PYTHONPATH=$VTK_DIR/lib/python3.9/site-packages:$PYTHONPATH
fi
alias vtkpython=$HOME/Kitware/build/VTK/bin/vtkpython
```

Copy this into a file called `VTK.sh` and make it executable. Then you can just:

``` bash
source <path to>/VTK.sh
```

Thereby setting your VTK environment.
