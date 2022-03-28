COMP_OP = -g -Wall -O2
fortran = gfortran
PRGR=a.out
COMP = gfortran
dir = LinuxObjs
LINKOPT = -lgfortran  -lpthread 
LAPACK = /scratch/lib/LAPACKETH/lapack.a
BLAS = /scratch/lib/GotoBLASETH/libgoto_core2p-r1.26.a

all: testdbqru timdbqru testzbqru timzbqru

TESTDOBJS=testdbqru.o \
 dbqru.o dbqru_appq.o dbqru_larf.o dbqru_larfb.o dbqru_larft.o dlaran.o dlarnd.o

TESTZOBJS=testzbqru.o \
 zbqru.o zbqru_larf.o zbqru_larft.o zbqru_larfb.o zbqru_appq.o zaxpyc.o

TIMDOBJS=timdbqru.o \
 dbqru.o dbqru_appq.o dbqru_larf.o dbqru_larfb.o dbqru_larft.o dlaran.o dlarnd.o

TIMZOBJS=timzbqru.o \
 zbqru.o zbqru_larf.o zbqru_larft.o zbqru_larfb.o zbqru_appq.o zaxpyc.o dlaran.o dlarnd.o

.SUFFIXES: .F

testdbqru : $(TESTDOBJS)
	$(COMP) $(COMP_OP) -o testdbqru.out $(TESTDOBJS) $(LINKOPT) $(LAPACK) $(BLAS)

testzbqru : $(TESTZOBJS)
	$(COMP) $(COMP_OP) -o testzbqru.out $(TESTZOBJS) $(LINKOPT) $(LAPACK) $(BLAS)

timdbqru : $(TIMDOBJS)
	$(COMP) $(COMP_OP) -o timdbqru.out $(TIMDOBJS) $(LINKOPT) $(LAPACK) $(BLAS)

timzbqru : $(TIMZOBJS)
	$(COMP) $(COMP_OP) -o timzbqru.out $(TIMZOBJS) $(LINKOPT) $(LAPACK) $(BLAS)


.F.o:
	$(COMP) $(COMP_OP) -c $<

.f.o:
	$(COMP) $(COMP_OP) -c $<
