Main: clean init timer.o puissance10.o puissanceDigit.o combinaison.o CalculArmstrong.o tacheCombinaisonEstNombreArmstrong.o fabriqueTacheCombinaisonEstNombreArmstrong.o  main.o 
	cc -Wall -o ../build/AfficherNombresArmstrong timer.o puissance10.o puissanceDigit.o combinaison.o CalculArmstrong.o tacheCombinaisonEstNombreArmstrong.o fabriqueTacheCombinaisonEstNombreArmstrong.o  main.o
	
Tests: clean init TestPuissance10 TestPuissanceDigit TestTacheCombinaisonEstNombreArmstrong TestCombinaison TestMathematique TestCalculArmstrong

TestCalculArmstrong: CalculArmstrong.o testNbArmstrong.o timer.o puissanceDigit.o  mathematique.o combinaison.o puissance10.o
	cc -Wall -lm -o ../build/TestCalculArmstrong CalculArmstrong.o testNbArmstrong.o timer.o puissanceDigit.o  mathematique.o combinaison.o puissance10.o
	
TestTacheCombinaisonEstNombreArmstrong: timer.o tacheCombinaisonEstNombreArmstrong.o testTacheCombinaisonEstNombreArmstrong.o
	cc -Wall -lm -o ../build/TestTacheCombinaisonEstNombreArmstrong timer.o tacheCombinaisonEstNombreArmstrong.o testTacheCombinaisonEstNombreArmstrong.o
	
TestMathematique: timer.o mathematique.o testMathematique.o
	cc -Wall -lm -o ../build/TestMathematique timer.o mathematique.o testMathematique.o

TestCombinaison: timer.o puissance10.o combinaison.o testCombinaison.o 
	cc -Wall -lm -o ../build/TestCombinaison timer.o puissance10.o combinaison.o testCombinaison.o 

TestPuissance10: timer.o puissance10.o testPuissance10.o
	cc -Wall -lm -o ../build/TestPuissance10 timer.o puissance10.o testPuissance10.o

TestPuissanceDigit: timer.o puissanceDigit.o testPuissanceDigit.o mathematique.o
	cc -Wall -lm -o ../build/TestPuissanceDigit timer.o puissanceDigit.o testPuissanceDigit.o mathematique.o
	
main.o: ./main.c
	cc -Wall -O2 -c ../app/main.c

fabriqueTacheCombinaisonEstNombreArmstrong.o: ../app/fabriqueTacheCombinaisonEstNombreArmstrong.c ../app/fabriqueTacheCombinaisonEstNombreArmstrong.h
	cc -Wall -O2 -c ../app/fabriqueTacheCombinaisonEstNombreArmstrong.c

testTacheCombinaisonEstNombreArmstrong.o: ../tests/testTacheCombinaisonEstNombreArmstrong.c
	cc -Wall -O2 -c ../tests/testTacheCombinaisonEstNombreArmstrong.c
	
tacheCombinaisonEstNombreArmstrong.o: ../app/tacheCombinaisonEstNombreArmstrong.c ../app/tacheCombinaisonEstNombreArmstrong.h
	cc -Wall -O2 -c ../app/tacheCombinaisonEstNombreArmstrong.c
	
testNbArmstrong.o:  ../tests/testNbArmstrong.c
	cc -Wall -c ../tests/testNbArmstrong.c

CalculArmstrong.o:../app/CalculArmstrong.c ../app/CalculArmstrong.h
	cc -Wall -O2 -c ../app/CalculArmstrong.c -lm
	
testMathematique.o: ../tests/testMathematique.c
	cc -Wall -c ../tests/testMathematique.c

mathematique.o: ../app/mathematique.c ../app/mathematique.h
	cc -Wall -O2 -c ../app/mathematique.c -lm
	
testCombinaison.o: ../tests/testCombinaison.c
	cc -Wall -c ../tests/testCombinaison.c

combinaison.o: ../app/combinaison.c ../app/combinaison.h
	cc -Wall -O2 -c ../app/combinaison.c -lm
	
testPuissance10.o: ../tests/testPuissance10.c
	cc -Wall -c ../tests/testPuissance10.c

puissance10.o: ../app/puissance10.c ../app/puissance10.h
	cc -Wall -O2 -c ../app/puissance10.c -lm
	
testPuissanceDigit.o: ../tests/testPuissanceDigit.c
	cc -Wall -O2 -c ../tests/testPuissanceDigit.c
	
puissanceDigit.o: ../app/puissanceDigit.c ../app/puissanceDigit.h
	cc -Wall -O2 -c ../app/puissanceDigit.c -lm

timer.o: ../app/timer.c ../app/timer.h
	cc -Wall -O2 -c ../app/timer.c -lm
	
clean:
	-rm *.o
	-rm -R ../build/*
	
init:
	-mkdir ../build
	-mkdir ../build/help
