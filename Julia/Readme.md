# About
Julia is a high-level, high-performance, dynamic programming language. While it is a general-purpose language and can be used to write any application, many of its features are well suited for numerical analysis and computational science.

Julia is garbage-collected, uses eager evaluation, and includes efficient libraries for floating-point calculations, linear algebra, random number generation, and regular expression matching. Many libraries are available, including some (e.g., for fast Fourier transforms) that were previously bundled with Julia and are now separate.

# Notable Uses
Julia has attracted some high-profile users, from investment manager BlackRock, which uses it for time-series analytics, to the British insurer Aviva, which uses it for risk calculations. Since 2015, the Federal Reserve Bank of New York has used Julia to make models of the United States economy (including estimating COVID-19 shocks in 2021), noting that the language made model estimation "about 10 times faster" than its previous MATLAB implementation. 

Julia was selected by the Climate Modeling Alliance as the sole implementation language for their next generation global climate model. This multi-million dollar project aims to build an earth-scale climate model providing insight into the effects and challenges of climate change.

Julia is used by NASA, e.g. for modeling spacecraft separation dynamics (15,000 times faster than before with Simulink/MATLAB and the Brazilian INPE for space mission planning and satellite simulation. Another effort is working on an embedded project to control a satellite in space using Julia for attitude control.

# Achievement
Julia joins C, C++, and Fortran as high-level languages in which petaFLOPS computations have been achieved. 

# Run the Example
For the test.c
'test -fPIC -I\$JULIA\_DIR/include/julia -L\$JULIA\_DIR/lib -Wl,-rpath,\$JULIA\_DIR/lib test.c -ljulia'
