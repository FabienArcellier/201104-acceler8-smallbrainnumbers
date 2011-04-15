#include <assert.h>
#include <stdio.h>
#include "../app/mathematique.h"
#include "../app/tacheCombinaisonEstNombreArmstrong.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testCombinaisonEstNombreArmstrong_Clone();

int main(void)
{
  testCombinaisonEstNombreArmstrong_Clone();
  return 0;
}

void testCombinaisonEstNombreArmstrong_Clone()
{
  puts("Debut testCombinaisonEstNombreArmstrong_Clone");
  
  char combinaison[3] = {1, 2, 3};
  char combinaison2[3] = {1, 2, 4};
  TacheCombinaisonEstNombreArmstrong *tache1, *tache2;
  
  CachePuissance10 cachePuissance10;
	InitCachePuissance10(&cachePuissance10, 5);
	
	CachePuissanceDigit cachePuissanceDigit;
	InitCachePuissanceDigit(&cachePuissanceDigit, 1, 5);
  
  long long test_time_init;
  test_time_init = time_start();
  
  tache1 = TacheCombinaisonEstNombreArmstrong_Init(3, &cachePuissanceDigit, &cachePuissance10);
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache1, combinaison);
  
  
  
  printf("T: Init : %lld\n", time_end(test_time_init));
  
  long long test_time_clone;
  test_time_clone= time_start();
  
  tache2 = TacheCombinaisonEstNombreArmstrong_Clone(tache1);
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache2, combinaison2);
  
  printf("T: Clone : %lld\n", time_end(test_time_clone));
  
  assert((tache1 -> combinaison)[1] == 2);
  assert((tache1 -> combinaison)[2] == 3);
  assert((tache1 -> combinaison)[1] == 2);
  assert((tache2 -> combinaison)[2] == 4);
  
  
  TacheCombinaisonEstNombreArmstrong_Detruire(tache1);
  TacheCombinaisonEstNombreArmstrong_Detruire(tache2);
  
  puts("Fin testCombinaisonEstNombreArmstrong_Clone");
  puts("");
}
