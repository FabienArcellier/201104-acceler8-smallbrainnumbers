Main: clean init puissance10.o puissanceDigit.o main.o timer.o CalculArmstrong.o
	cc -Wall -o ../build/AfficherNombresArmstrong puissanceDigit.o puissance10.o main.o CalculArmstrong.o timer.o
	
Tests: clean init TestPuissance10 TestPuissanceDigit TestTacheCombinaisonEstNombreArmstrong TestCalculArmstrong
	
TestTacheCombinaisonEstNombreArmstrong: tacheCombinaisonEstNombreArmstrong.o testTacheCombinaisonEstNombreArmstrong.o
	cc -Wall -lm -o ../build/TestTacheCombinaisonEstNombreArmstrong tacheCombinaisonEstNombreArmstrong.o testTacheCombinaisonEstNombreArmstrong.o

TestPuissance10: puissance10.o testPuissance10.o
	cc -Wall -lm -o ../build/TestPuissance10 puissance10.o testPuissance10.o

TestPuissanceDigit: puissanceDigit.o testPuissanceDigit.o
	cc -Wall -lm -o ../build/TestPuissanceDigit puissanceDigit.o testPuissanceDigit.o

TestCalculArmstrong: CalculArmstrong.o testNbArmstrong.o timer.o puissanceDigit.o
	cc -Wall -lm -o ../build/TestCalculArmstrong CalculArmstrong.o testNbArmstrong.o timer.o puissanceDigit.o

main.o: ./main.c
	cc -Wall -O2 -c ../app/main.c
	
testTacheCombinaisonEstNombreArmstrong.o: ../tests/testTacheCombinaisonEstNombreArmstrong.c
	cc -Wall -O2 -c ../tests/testTacheCombinaisonEstNombreArmstrong.c
	
tacheCombinaisonEstNombreArmstrong.o: ../app/tacheCombinaisonEstNombreArmstrong.c ../app/tacheCombinaisonEstNombreArmstrong.h
	cc -Wall -O2 -c ../app/tacheCombinaisonEstNombreArmstrong.c
	
testPuissance10.o: ../tests/testPuissance10.c
	cc -Wall -c ../tests/testPuissance10.c

testNbArmstrong.o:  ../tests/testNbArmstrong.c
	cc -Wall -c ../tests/testNbArmstrong.c

CalculArmstrong.o:../app/CalculArmstrong.c ../app/CalculArmstrong.h
	cc -Wall -O2 -c ../app/CalculArmstrong.c -lm

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
