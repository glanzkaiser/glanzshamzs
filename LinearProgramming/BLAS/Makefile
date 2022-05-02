.POSIX:

FC      = gfortran11
FFLAGS  = -std=f2018
LDFLAGS =
LDLIBS  = -lblas
TARGET  = example

.PHONY: all clean

all:
	$(FC) $(FFLAGS) $(LDFLAGS) -o $(TARGET) example.f90 $(LDLIBS)

clean:
	rm $(TARGET)
