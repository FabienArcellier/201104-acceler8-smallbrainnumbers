CC=gcc
CFLAG=-Wall -lm -O3 -fopenmp
#CFLAG=-Wall -lm -O3 -DNEBUG=0
LDFLAG=-Wall -lm -fopenmp

CPARALLEL= -pthread -ftree-parallelize-loops=40
PATH_BUILD=../build
PATH_APP=../app
PATH_TESTS=../tests


Production: clean init Smallbrain

Tests: clean init TestPuissance10 TestPuissanceDigit TestTacheCombinaisonEstNombreArmstrong TestCombinaison TestMathematique TestCalculArmstrong SpikeCompterPermutationUnique TestFabriqueTacheCombinaisonEstNombreArmstrong TestProcs

Smallbrain: timer.o mathematique.o puissance10.o puissanceDigit.o combinaison.o CalculArmstrong.o tacheCombinaisonEstNombreArmstrong.o fabriqueTacheCombinaisonEstNombreArmstrong.o ordonnanceur.o main.o hardware.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestCalculArmstrong: timer.o mathematique.o puissanceDigit.o combinaison.o puissance10.o CalculArmstrong.o testNbArmstrong.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestFabriqueTacheCombinaisonEstNombreArmstrong: timer.o combinaison.o mathematique.o puissance10.o puissanceDigit.o CalculArmstrong.o tacheCombinaisonEstNombreArmstrong.o fabriqueTacheCombinaisonEstNombreArmstrong.o testFabriqueTacheCombinaisonEstNombreArmstrong.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^
	
TestTacheCombinaisonEstNombreArmstrong: timer.o combinaison.o mathematique.o puissance10.o puissanceDigit.o CalculArmstrong.o tacheCombinaisonEstNombreArmstrong.o testTacheCombinaisonEstNombreArmstrong.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

SpikeCompterPermutationUnique: timer.o mathematique.o puissance10.o combinaison.o spikeCompterPermutationUnique.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestMathematique: timer.o mathematique.o testMathematique.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestCombinaison: timer.o mathematique.o puissance10.o combinaison.o testCombinaison.o 
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^ 

TestPuissance10: timer.o mathematique.o puissance10.o testPuissance10.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestPuissanceDigit: timer.o mathematique.o puissanceDigit.o testPuissanceDigit.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

TestProcs: timer.o hardware.o testProcesseurs.o
	$(CC) $(LDFLAG) -o $(PATH_BUILD)/$@ $^

main.o: $(PATH_APP)/main.c
	$(CC) $(CFLAG) -c $<
	
testFabriqueTacheCombinaisonEstNombreArmstrong.o: $(PATH_TESTS)/testFabriqueTacheCombinaisonEstNombreArmstrong.c
	$(CC) $(CFLAG) -c $<

fabriqueTacheCombinaisonEstNombreArmstrong.o: $(PATH_APP)/fabriqueTacheCombinaisonEstNombreArmstrong.c $(PATH_APP)/fabriqueTacheCombinaisonEstNombreArmstrong.h
	$(CC) $(CFLAG) -c $<

testTacheCombinaisonEstNombreArmstrong.o: $(PATH_TESTS)/testTacheCombinaisonEstNombreArmstrong.c
	$(CC) $(CFLAG) -c $<
	
tacheCombinaisonEstNombreArmstrong.o: $(PATH_APP)/tacheCombinaisonEstNombreArmstrong.c $(PATH_APP)/tacheCombinaisonEstNombreArmstrong.h
	$(CC) $(CFLAG) -c $<
	
testNbArmstrong.o:  $(PATH_TESTS)/testNbArmstrong.c
	$(CC) $(CFLAG) -c $<

ordonnanceur.o: $(PATH_APP)/ordonnanceur.c $(PATH_APP)/ordonnanceur.h
	$(CC) $(CFLAG) -c  $<

CalculArmstrong.o:$(PATH_APP)/CalculArmstrong.c $(PATH_APP)/CalculArmstrong.h
	$(CC) $(CFLAG) -c $<
	
testCombinaison.o: $(PATH_TESTS)/testCombinaison.c
	$(CC) $(CFLAG) -c $<
	
spikeCompterPermutationUnique.o: $(PATH_TESTS)/spikeCompterPermutationUnique.c
	$(CC) $(CFLAG) -c $<

combinaison.o: $(PATH_APP)/combinaison.c $(PATH_APP)/combinaison.h
	$(CC) $(CFLAG) -c $<
	
testPuissance10.o: $(PATH_TESTS)/testPuissance10.c
	$(CC) $(CFLAG) -c $<

puissance10.o: $(PATH_APP)/puissance10.c $(PATH_APP)/puissance10.h
	$(CC) $(CFLAG) -c $<
	
testPuissanceDigit.o: $(PATH_TESTS)/testPuissanceDigit.c
	$(CC) $(CFLAG) -c $<
	
puissanceDigit.o: $(PATH_APP)/puissanceDigit.c $(PATH_APP)/puissanceDigit.h
	$(CC) $(CFLAG) -c $<
	
testMathematique.o: $(PATH_TESTS)/testMathematique.c
	$(CC) $(CFLAG) -c $<

mathematique.o: $(PATH_APP)/mathematique.c $(PATH_APP)/mathematique.h
	$(CC) $(CFLAG) -c $<

timer.o: $(PATH_APP)/timer.c $(PATH_APP)/timer.h
	$(CC) $(CFLAG) -c $<
	
hardware.o: $(PATH_APP)/hardware.c $(PATH_APP)/hardware.h
	$(CC) $(CFLAG) -c $<

testProcesseurs.o: $(PATH_TESTS)/testProcesseurs.c
	$(CC) $(CFLAG) -c $<

clean:
	-rm *.o
	-rm -R ../build/*
	
init:
	-mkdir ../build
	-mkdir ../build/help
