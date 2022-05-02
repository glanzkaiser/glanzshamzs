.POSIX:

FC      = gfortran
FFLAGS  = -o
SRC = example.f90
PROGRAM = dot product
LDLIBS  = -lblas
OBJECTS = $(SRCS:.f90=.o)
TARGET = example

.PHONY: all clean

all: 
	$(FC) $(FFLAGS) $(TARGET) $(SRC) $(LDLIBS)

clean:
	rm $(TARGET)

#run make to build the executable.
