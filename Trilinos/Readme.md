# About

The Trilinos Project is an effort to facilitate the design, development, integration and ongoing support of mathematical software libraries within an object-oriented framework for the solution of large-scale, complex multi-physics engineering and scientific problems. Trilinos addresses two fundamental issues of developing software for these problems: (i) Providing a streamlined process and set of tools for development of new algorithmic implementations and (ii) promoting interoperability of independently developed software.

Trilinos uses a two-level software structure designed around collections of packages. A Trilinos package is an integral unit usually developed by a small team of experts in a particular algorithms area such as algebraic preconditioners, nonlinear solvers, etc. Packages exist underneath the Trilinos top level, which provides a common look-and-feel, including configuration, documentation, licensing, and bug-tracking.

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

![Trilinos](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/Trilinos/images/Summary-of-Trilinos-packages.png)
![Trilinos](https://raw.githubusercontent.com/glanzkaiser/glanzshamzs/main/Trilinos/images/TrilinosPackage1.png)

# How to Build
The build directory (trilinosbuild) and the source directory (the one you git clone -> Trilinos) need to be made parallel, unlike other package where we create the build inside the source directory, this one needs to be made parallel. Parallel means if you see a directory you can see the folder of the source and build directory together side by side.

Below is the scripts for configuring, building and installing Trilinos with Tpetra and all linear solvers on GFreya OS. It has been tested and worked.

    git clone https://github.com/trilinos/Trilinos.git
    mkdir -v trilinosbuild
    cd trilinosbuild
    cmake \
    -D CMAKE_INSTALL_PREFIX=/opt/hamzstlib/trilinos \
    -D Trilinos_ENABLE_Teuchos=ON \
    -D Trilinos_ENABLE_Tpetra=ON \
    -D Trilinos_ENABLE_Anasazi=ON \
    -D Trilinos_ENABLE_Amesos2=ON \
    -D Trilinos_ENABLE_Belos=ON \
    -D Trilinos_ENABLE_Ifpack2=ON \
    -D Trilinos_ENABLE_MueLu=ON \
    -D Trilinos_ENABLE_Stratimikos=ON \
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
    make install
 
You may adjust the options above and choose packages suitable for your needs and system, look at the list of packages here:
https://github.com/trilinos/Trilinos/blob/master/PackagesList.cmake

The installation directory will be in /opt/hamzstlib/trilinos and it will contain
    
    /bin  /include  /lib
    
## Adjust the Environment Variables
1. Add /opt/hamzstlib/trilinos/bin to PATH
2. Add /opt/hamzstlib/trilinos/lib to LD_LIBRARY_PATH
3. Add /opt/hamzstlib/trilinos/include to CPLUS_INCLUDE_PATH

# Epetra
1. The Epetra Comm virtual class is an interface that encapsulates the general information and services needed for the other Epetra classes to run on serial or parallel computer. An Epe- tra Comm object is required for building all Epetra Map objects, which in turn are required for all other Epetra classes.
2. Epetra Comm has two basic concrete implementations: Epetra SerialComm (for serial executions) and Epetra MpiComm (for MPI distributed memory executions)

# Linear Solvers
Trilinos provides a wide-variety of solution methods for linear and eigen systems.

You should first decide whether you want to use the Epetra or Tpetra sparse linear algebra library. This decision will determine which solvers and preconditioners you can use, as not all solvers are compatible with both.

Epetra uses integer ordinal types and double scalar types. 

Tpetra is templated on the ordinal type, scalar type, and node type. Tpetra allows creation of problems with any number of DOFs, problems other than of type double, optimized computations on a variety of many-core architectures (including GPUs) through Kokkos, and mixing of MPI and threading.

#### Almost all linear solvers packages compatible with Epetra

## Linear solver interfaces

1. Stratimikos contains a unified set of wrappers to linear solver and preconditioner capabilities in Trilinos. Stratimikos essentially consists of the single class DefaultLinearSolverBuilder. This class takes as input a (nested) parameter list that contains options for the desired solvers and preconditioners.

## Iterative linear and eigen-solvers
1. AztecOO includes a number of Krylov iterative methods such as conjugate gradient (CG), generalized minimum residual (GMRES) and stabilized biconjugate gradient (BiCGSTAB) to solve systems of equations. AztecOO may use a variety of internally implemented preconditioners, such as SOR, polynomial, domain decomposition, and incomplete factorization preconditioning, as well as preconditioners provided by other Trilinos packages. AztecOO also fully contains the C-language Aztec linear solver package, so any application that is using Aztec can use the AztecOO library in place of Aztec. Note that only bug fixes are being applied to AztecOO. 
2. Belos provides next-generation iterative linear solvers and a powerful linear solver developer framework.
3. Anasazi is an extensible and interoperable framework for large-scale eigenvalue algorithms. The motivation for this framework is to provide a generic interface to a collection of algorithms for solving large-scale eigenvalue problems. Anasazi is interoperable because both the matrix and vectors (defining the eigenspace) are considered to be opaque objects—only knowledge of the matrix and vectors via elementary operations is necessary. An implementation of Anasazi is accomplished via the use of interfaces. Current interfaces available include Epetra and so any libraries that understand Epetra matrices and vectors (such as AztecOO) may also be used in conjunction with Anasazi. 
4. KOMPLEX is an add-on module to AZTEC that allows users to solve complex-valued linear systems. KOMPLEX solves a complex-valued linear system Ax=b by solving an equivalent real-valued system of twice the dimension. 

## Direct linear solvers
1. Amesos is a set of C++ interfaces to serial and parallel sparse direct solvers. Amesos contains two nice sparse solvers: KLU and Paraklete. KLU is serial, while Paraklete (distributed with Trilinos 7.0 or higher) is a parallel solver. Amesos also offers an interface to LAPACK, and several other well-know solvers available on the web.
2. Amesos2 can be considered a templated version of Amesos that supports a wider variety of scalar and index types. Amesos2 provides two internal serial direct solvers, KLU2 (as of release 11.12) and Basker (as of release 11.14). Users of prior releases will need a third-party direct solver, such as SuperLU.
3. Pliris is an object-oriented interface to a LU solver for dense matrices on parallel platforms. These matrices are double precision real matrices distributed on a parallel machine.

## Preconditioners
1. ShyLU is designed as a set of domain-decomposition solvers that us distributed memory and node-level solvers and kernels that support the distributed memory solvers. The approaches in ShyLU are algebraic and so can be used as a black-box solvers.
2. Teko is a package for development and implementation of block preconditioners. This includes support for manipulation and setup of block operators. Furthermore tools exist to support decomposition of a fully coupled operator. Additionally, facilities that allow the construction of approximate inverse operators using the full complement of available preconditioners and solvers are available in Teko. Finally, a small number of generic block preconditioners has been implemented in Teko, including block Jacobi, and block Gauss-Seidel. For the Navier-Stokes equation, Teko has implementations of SIMPLE, PCD and LSC.
3. Ifpack provides a suite of object-oriented algebraic preconditioners. Ifpack constructors expect an Epetra_RowMatrix object for construction. Ifpack objects interact well with other Trilinos classes. In particular,Ifpack can be used as a preconditioner for AztecOO and smoother in ML.
4. Ifpack2 can be considered a templated version of Ifpack. It provides SOR type relaxation methods, incomplete factorizations, and additive Schwarz methods.
5. ML contains a variety of parallel multigrid schemes for preconditioning or solving large sparse linear systems of equations arising primarily from elliptic PDE discretizations. 
6. MueLu provides a framework for parallel multigrid preconditioning methods for large sparse linear systems. MueLu provides algebraic multigrid methods for symmetric and nonsymmetric systems based on smoothed aggregation. It is designed to be extensible and can in principle support other algebraic multigrid (e.g., Ruge-Stueben) and geometric multigrid methods. MueLu does not provide any smoothers itself, but instead relies on other Trilinos packages for these capabilities. MueLu is templated on the ordinal and scalar types, and it can also exploit the hybrid communication benefits of Tpetra and Kokkos.

# Nonlinear Solvers (Trilinos’ Embedded Nonlinear Analysis Tools)
The Trilinos Embedded Nonlinear Analysis Tools Capability Area collects the top level algorithms (outermost loops) in a computational simulation or design study. These include: the solution of nonlinear equations, time integration, bifurcation tracking, parameter continuation, optimization, and uncertainty quantification. 

1. The Nonlinear Solver NOX solves a set of nonlinear algebraic equations $f(x)=0$ for $x$ The methods included Newton-based algorithms such as inexact Newton, matrix-free Newton-Krylov, line-search methods, trust-region methods, tensor methods, and homotopy methods. Most of these methods ask the user to supply a Jacobian matrix $J = \frac{df}{dx} $ and include the computational step of approximating $J = \frac{df}{dx} $.

2. The Time Integration algorithms in Tempus solve ODEs of the forms $f(\dot{x}, x, t)=0$ and $\dot{x}=f(x, t)$. The algorithms include explicit and implicit methods with adaptive step size control, including Forward/Backward Euler, Trapezoidal, Explicit Runge-Kutta, Diagonally Implicit Runge-Kutta, Implicit/Explicit Runge-Kutta, Leapfrog, Newmark-Beta, HHT-Alpha, BDF2, operator-splitting, and subcycling. For systems with parameter dependence, $f(\dot{x}, x, t, p)=0$, a sensitivity analysis capability is now available to solve for $\frac{dx}{dp}$.

3. The Time Integration algorithms in Rythmos solve ODEs and DAEs of the form $f(\dot{x}, x, t)=0$. The algorithms include explicit and implicit methods with adaptive step size control and integration order control, including BDF and Runge-Kutta methods. Given an initial conditions $x(t=0)$ , the methods find a series of solutions $x(t_i)$ at time points $t=t_i$. For systems with parameter dependence, $f(\dot{x}, x, t, p)=0$, a sensitivity analysis capability is now available to solve for $\frac{dx}{dp} $ simultaneously. A checkpointing interface for adjoint integrations is under development.

4. A set of Bifurcation Tracking algorithms have been implemented in LOCA. These algorithms augment the steady-state system of equations with extra distinguishing conditions that find a parameter value where there is an exchange of stability ($F(X) = \left[ \begin{array}{c}f(x,p)\ h(x,p) \end{array} \right] =0$). This augmented system is then solved by the nonlinear solver package. Specifically, turning point (folds), pitchfork bifurcations, and Hopf bifurcations can be located and tracked. Similarly, this formulation can be used for Constraint Enforcement, where the extra equations $h(x,p)$ can be supplied by the user, and the same number of parameters can be freed to be part of the solution.

5. PDE-Constrained Optimization algorithms have been implemented in MOOCHO and Aristos packages to take advantage of the efficiencies accessible by embedded algorithms. These have the form: $\mbox{minimize } g(x,p) \mbox{ subject to } f(x,p)=0$ The algorithms use Quasi-Newton approaches to simultaneously minimize the objective function and satisfy the constraint equations. The algorithms can make use if adjoint information if available to most efficiently solve systems with large design spaces. Both reduced-space (MOOCHO) and full-space (Aristos) algorithms have been developed.

6. Automatic Differentiation tools for C++ codes have been developed in SACADO to automatically extract analytic derivative information from codes. This capability is implemented with expression templates that essentially inline code that performs the chain rule. The application code must template a key part of their code (such as the single element fill portion in a finite element code) on the type.

7. Embedded UQ methods are under active development. This includes the Stokhos tools to automate the propagation of random variables through codes, such as stochastic finite element formulations, leveraging the same templated interfaces as the automatic differentiation capability. Other pieces include the subsequent nonlinear solution, transient propoagation, and linear solution of the full stochastic system.


# Other Info
Much of Trilinos was developed under funding from the Advanced Scientific Computing Initiative (ASCI). A major focus of ASCI is Software Quality Engineering(SQE), which is the set of practices for ensuring that high-quality, relevant software is produced, and that software processes are well defined, documented and followed. 

# Packages Documentation
1. Amesos (https://docs.trilinos.org/latest-release/packages/amesos/doc/html/)
2. Amesos2 (https://docs.trilinos.org/latest-release/packages/amesos2/doc/html/)
3. Anasazi (https://docs.trilinos.org/latest-release/packages/anasazi/doc/html/)
4. Epetra (https://docs.trilinos.org/dev/packages/epetra/doc/html/index.html)
5. Kokkos (https://docs.trilinos.org/latest-release/packages/kokkos/doc/html/index.html)
6. Komplex (https://docs.trilinos.org/dev/packages/komplex/doc/html/index.html)
7. Tpetra (https://docs.trilinos.org/dev/packages/tpetra/doc/html/index.html)

# Sources
https://trilinos.github.io/pdfs/Trilinos10.10Tutorial.pdf

https://trilinos.github.io/getting_started.html

https://github.com/trilinos/Trilinos_tutorial/wiki/TrilinosHandsOnTutorial

https://trilinos.github.io/packages.html

https://docs.trilinos.org/latest-release/packages/

https://docs.trilinos.org/files/TrilinosBuildReference.html
