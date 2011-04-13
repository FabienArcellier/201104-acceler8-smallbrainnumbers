#include "../app/mathematique.h"

/* Liste des prototypes */
void TestFactoriel();

void main()
{
  TestFactoriel();
}

void TestFactoriel()
{
  puts("L: Debut du test TestFactorielle");
  long long test_time;
  test_time= time_start();

  assert(factorielle(0) == 1);
  assert(factorielle(1) == 1);
  assert(factorielle(2) == 2);
  assert(factorielle(9) == 362880);
  
  printf("T: %lld\n", time_end(test_time));
  puts("L: Fin du test TestFactorielle");
  puts("")
}

