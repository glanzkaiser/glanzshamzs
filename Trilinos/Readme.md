# About
A core requirement of many engineering and scientific applications is the need to solve linear and non-linear systems of equations, eigensystems and other related problems. Thus it is no surprise that any part of the application that solves these problems is called a “solver.” The exact definition of what specifically constitutes a solver depends on many factors. However, a good working definition of a solver is the following: any piece of software that finds unknown values for some set of discrete governing equations in an application.

Another characteristic of solvers is that we can often implement them in such a way that they are “general-purpose”, so that the details of how the discrete problem was formed are not specifically needed for the solver to work (although information about problem characteristics can often be vital to robust solutions.) Advanced solution techniques increasingly require more than “just a matrix” since a the matrix alone discards so much information about the origin of the problem and how it might best be solved. 

As a result solvers need compatible tools in differentiation, discretization and data partitioning. These tools are also essential for robust solutions in scalable computing environments.

Many applications are standardizing on the Trilinos APIs. As a result, these applications have access to all Trilinos solver components without any unnecessary interface modifications.

# Robust Implementation of Advanced Parallel Algorithms
Numerical methods are effective at solving a variety of problems on parallel computers. At the same time, there are many problems that cannot be solved by numerical methods, and there are good serial algorithms which have undesirable properties for parallel computing. An over-riding emphasis of the Trilinos Project is to develop robust algorithms for scientific and engineering applications on parallel computers, and make these algorithms accessible to application developers in the most effective way. All other Trilinos objectives are in some way derived from this primary goal.

Presently Trilinos are focused on the following algorithmic areas:
1. Automatic differentiation
2. Data partitioning for load balance and robustness 
3. Multi-level preconditioners
4. Block iterative methods (linear and eigen solvers)
5. Incomplete factorizations
6. Solution of linear systems with successive and simultaneous right-hand-sides
7. Nonlinear methods including continuation
8. Large-scale optimization, e.g., SAND
9. Time integration methods

# Product Areas

1. Data Services (Trilinos solvers, partitioners and discretization tools are built upon a collection of data containers and functions that support effecient parallel execution. These packages support MPI, threading and vectorization and execution on distributed memory machines, multicore CPUs, and GPUS. Packages include Kokkos, Tpetra and Epetra.)
2. Linear Solvers (Trilinos provides a wide-variety of solution methods for linear and eigen systems. The Linear & Eigen Solvers Capability Area provides iterative and direct solvers, preconditioners, high-level interfaces, and eigen-solvers. Wide-variety of preconditioners such as incomplete factorizations, domain decomposition preconditioners, and multigrid methods are supported.)
3. Nonlinear Solvers (The Trilinos Embedded Nonlinear Analysis Tools Capability Area collects the top level algorithms (outermost loops) in a computational simulation or design study. These include: the solution of nonlinear equations, time integration, bifurcation tracking, parameter continuation, optimization, and uncertainty quantification. A common theme of our algorithm R&D efforts is the philosophy of Analysis beyond Simulation, which aims to automate many computational tasks that are often performed by application code users by trial-and-error or repeated simulation. The tasks that can be automated include performing parameter studies, sensitivity analysis, calibration, optimization, time step size control, and locating instabilities. Also included in this capability area is the automatic differentiation technology that can be used in an application code to provide the derivatives critical to the analysis algorithms. The packages represented in this area include Piro, NOX, LOCA, Rythmos, MOOCHO, Aristos, Sacado, Stokhos, and TriKota. )
4. Discretizations (The objective of the Discretizations product is to provide modular, interoperable and extensible tools for the discretization of integral and differential equations. Adopting state-of-the-art numerics and HPC programming models, the discretization tools target both research and production applications. The Discretizations product includes tools for mesh-based discretizations such as finite element analysis as well as meshless discretization such as generalized moving least squares.)
5. Framework (The Framework and Tools Capability Area provides resources for both users and developers. Like User Experience, this capability area is different from most of the other capability areas in that the resources provided extend beyond packages and focus on tools that aid in building, maintaining and documenting Trilinos.)
6. Product Manager (The Trilinos Project Manager serves as a single point of contact for Trilinos stakeholders. They provide an important role that crosscuts the product areas and facilitates a more coordinated effort to user support for our customers. )

# How to Build
The build directory (trilinosbuild) and the source directory (the one you git clone -> Trilinos) need to be made parallel, unlike other package where we create the build inside the source directory, this one needs to be made parallel. Parallel means if you see a directory you can see the folder of the source and build directory together side by side.

    git clone https://github.com/trilinos/Trilinos.git
    mkdir -v trilinosbuild
    cd trilinosbuild
    cmake \
    -D CMAKE_INSTALL_PREFIX=/opt/hamzstlib/trilinos \
    -D Trilinos_ENABLE_Teuchos=ON \
    -D Trilinos_ENABLE_Tpetra=ON \
    -D Trilinos_ENABLE_Tpetra=ON \
    -D BUILD_SHARED_LIBS:BOOL=ON \
    -D TPL_ENABLE_MPI:BOOL=ON \
    -D MPI_BASE_DIR="/opt/hamzstlib" \
    -D MPI_EXEC:FILEPATH="/opt/hamzstlib/bin/mpiexec" \
    -D MPI_Fortran_COMPILER:FILEPATH="/opt/hamzstlib/bin/mpif90" \
    -D MPI_CXX_COMPILER:FILEPATH="/opt/hamzstlib/bin/mpicxx" \
    -D MPI_C_COMPILER:FILEPATH="/opt/hamzstlib/bin/mpicc" \
    -D CMAKE_CXX_FLAGS:STRING="-ansi -pedantic -Wall" \
    -D BLAS_LIBRARY_DIRS:FILEPATH="/opt/hamzstlib/lib" \
    -D BLAS_LIBRARY_NAMES:STRING="blas" \
    -D LAPACK_LIBRARY_DIRS:FILEPATH="/opt/hamzstlib/lib" \
    -D LAPACK_LIBRARY_NAMES:STRING="lapack" \
    -D TPL_ENABLE_MKL:BOOL=OFF \
    -D Trilinos_ENABLE_OpenMP:BOOL=ON \
    -D TPL_ENABLE_Pthread:BOOL=ON \
    -D TPL_ENABLE_Boost:BOOL=ON \
    -D Boost_LIBRARY_DIRS:FILEPATH="/usr/lib" \
    -D Boost_INCLUDE_DIRS:FILEPATH="/usr/include" \
    ../Trilinos &&
    make -j4
    
