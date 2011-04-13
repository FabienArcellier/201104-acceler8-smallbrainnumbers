#include <assert.h>
#include "combinatoire.h"

/* Liste des prototypes*/
void TestConvertirNombreVersTableauDigit()

void main()
{
  TestConvertirNombreVersTableauDigit();
}

void TestConvertirNombreVersTableauDigit()
{
  long nombre1 = 371;
  char tableauDigit1[5];
  
  ConvertirNombreVersTableauDigit(tableauDigit1, nombre1, 5);
  
  assert(tableauDigit[0] == 1);
  assert(tableauDigit[1] == 7);
  assert(tableauDigit[2] == 3);
  assert(tableauDigit[3] == 0);
  assert(tableauDigit[4] == 0);
}

