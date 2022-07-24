# About
Compilation of Julia code for Elementary Linear Algebra learning for Undergraduate degree.

We are using Jupyter Notebook for creating the code to help us with matrix computations.

## To download and setup

Open terminal (use Linux OS or any kind of OS with Python 3 installed)
```
pip3 install jupyterlab
python3 -m pip install webio_jupyter_extension

```

Now you must have Julia installed, open Julia REPL:

```
julia

julia> ]

pkg> add IJulia

julia> using IJulia
julia> notebook()
```

After that your browser will be opened and you can load the .ipynb file here and test it out.

For those having 500 internal server error / kernel error type this at terminal:

```
pip3 install --upgrade nbconvert
```

Adjust your path as user at `~/.bashrc`, this is my path at CAELinux:

```
export JULIA_DIR="/home/browni/julia-1.7.3"
export CUDA_DIR="/usr/local/cuda-11.7"
export PATH="$PATH:$JULIA_DIR/bin:$CUDA_DIR/bin:/home/browni/.local/bin"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$CUDA_DIR/lib64"

```

#### based on Lasthrim Projection book 

## Lasthrim' Galleries for Julia-ElementaryLinearAlgebra
| Chapter 1: Systems of Linear Equations and Matrices | Gaussian Elimination | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/LPdiscretemath-1-tautology.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/LPdiscretemath-1-tautology.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/LasthrimProjection/Julia-ElementaryLinearAlgebra/ElementaryLinearAlgebra.ipynb">ElementaryLinearAlgebra.ipynb</a> |  | 

# Source

Rorres, Chris, Anton, Howard. Elementary Linear Algebra with Supplemental Applications 10th Edition
