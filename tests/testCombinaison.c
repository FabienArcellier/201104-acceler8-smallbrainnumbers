#include <assert.h>
#include "combinatoire.h"

/* Liste des prototypes*/
void TestConvertirNombreVersTableauDigit();
void TestConvertirTableauDigitVersNombre();
void TestCompare2TableauxDigit();
void TestIncrementerTableauxDigit();
void TestIncrementerTableauxDigitCombinaisonUnique();

void main()
{
  TestConvertirNombreVersTableauDigit();
  TestConvertirTableauDigitVersNombre();
  TestCompare2TableauxDigit();
  TestIncrementerTableauxDigit();
  TestIncrementerTableauxDigitCombinaisonUnique();
}

void TestConvertirNombreVersTableauDigit()
{
  puts("L: Debut du test TestConvertirNombreVersTableauDigit");
  long long test_time;
  test_time= time_start();
  long nombre1 = 371;
  char tableauDigit1[5];
  
  ConvertirNombreVersTableauDigit(tableauDigit1, nombre1, 5);
  
  assert(tableauDigit[0] == 1);
  assert(tableauDigit[1] == 7);
  assert(tableauDigit[2] == 3);
  assert(tableauDigit[3] == 0);
  assert(tableauDigit[4] == 0);
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestConvertirNombreVersTableauDigit");
  puts("")
}

void TestConvertirTableauDigitVersNombre()
{
  puts("L: Debut du test TestConvertirTableauDigitVersNombre");
  long long test_time;
  test_time= time_start();
  
  char tableauDigit1[5] = {1,7,3,0,0};
  long long resultat = 0;
  resultat = ConvertirTableauDigitVersNombre(tableauDigit1, 5);
  assert(resultat == 371);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestConvertirTableauDigitVersNombre");
  puts("")
}

void TestCompare2TableauxDigit()
{
  puts("L: Debut du test TestCompare2TableauxDigit");
  long long test_time;
  test_time= time_start();
  
  char tableauDigit1[5] = {1,7,3,0,0};
  char tableauDigit2[5] = {2,7,3,0,0};
  
  assert(Compare2TableauxDigit(tableauDigit1, tableauDigit2) == -1);
  assert(Compare2TableauxDigit(tableauDigit2, tableauDigit1) == 1);
  assert(Compare2TableauxDigit(tableauDigit1, tableauDigit1) == 0);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestCompare2TableauxDigit");
  puts("")
}

void TestIncrementerTableauxDigit()
{
  puts("L: Debut du test TestIncrementerTableauxDigit");
  long long test_time;
  test_time= time_start();
  
  char tableauDigit1[5] = {0,0,0,0,0};
  char tableauDigit2[5] = {9,1,0,0,0};
  
  IncrementerTableauxDigit(tableauDigit1, 5);
  assert(tableauDigit1[0] == 1 &&
    tableauDigit1[1] == 0);
  
  IncrementerTableauxDigit(tableauDigit2, 5);
  assert(tableauDigit1[0] == 0 &&
    tableauDigit1[1] == 2 &&
    tableauDigit1[2] == 0);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestIncrementerTableauxDigit");
  puts("")
}

void TestIncrementerTableauxDigitCombinaisonUnique()
{
  puts("L: Debut du test TestIncrementerTableauxDigit");
  long long test_time;
  test_time= time_start();
  
  char tableauDigit1[5] = {9,0,0,0,0};
  char tableauDigit2[5] = {9,9,8,0,0};
  
  IncrementerTableauxDigitCombinaisonUnique(tableauDigit1, 5);
  assert(tableauDigit1[0] == 1 &&
    tableauDigit1[1] == 1 &&
    tableauDigit1[2] == 0);
  
  IncrementerTableauxDigitCombinaisonUnique(tableauDigit2, 5);
  assert(tableauDigit1[0] == 9 &&
    tableauDigit1[1] == 9 &&
    tableauDigit1[2] == 9 &&
    tableauDigit1[3] == 0);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestIncrementerTableauxDigit");
  puts("")
}
