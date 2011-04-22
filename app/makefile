LD_LIBRARY_PATH=/opt/mpfr/lib:/opt/gmp/lib:/opt/mpc/lib

GCC_VERSION=4.5.1
PREFIX=/opt/gcc/${GCC_VERSION}/bin
CC=${PREFIX}/gcc
CFLAG=-Wall -lm -O3 -DNDEBUG=1 -fopenmp
LDFLAG=-Wall -lm -fopenmp
PATH_BUILD=./
PATH_APP=./app


Main: clean init Smallbrain

Smallbrain: timer.o mathematique.o puissance10.o puissanceDigit.o combinaison.o CalculArmstrong.o ordonnanceur.o main.o hardware.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^
	
main.o: $(PATH_APP)/main.c
	$(CC) $(CFLAG) -c $<

ordonnanceur.o: $(PATH_APP)/ordonnanceur.c $(PATH_APP)/ordonnanceur.h
	$(CC) $(CFLAG) -c  $<

CalculArmstrong.o:$(PATH_APP)/CalculArmstrong.c $(PATH_APP)/CalculArmstrong.h
	$(CC) $(CFLAG) -c $<
	
combinaison.o: $(PATH_APP)/combinaison.c $(PATH_APP)/combinaison.h
	$(CC) $(CFLAG) -c $<
	
puissance10.o: $(PATH_APP)/puissance10.c $(PATH_APP)/puissance10.h
	$(CC) $(CFLAG) -c $<
	
puissanceDigit.o: $(PATH_APP)/puissanceDigit.c $(PATH_APP)/puissanceDigit.h
	$(CC) $(CFLAG) -c $<
	
mathematique.o: $(PATH_APP)/mathematique.c $(PATH_APP)/mathematique.h
	$(CC) $(CFLAG) -c $<

timer.o: $(PATH_APP)/timer.c $(PATH_APP)/timer.h
	$(CC) $(CFLAG) -c $<

hardware.o: $(PATH_APP)/hardware.c $(PATH_APP)/hardware.h
	$(CC) $(CFLAG) -c $<
	
clean:
	-rm *.o
	-rm -R ./build/*
	-cp Exec.sh ./build/
	
init:
	-mkdir ./build
	-mkdir ./build/help