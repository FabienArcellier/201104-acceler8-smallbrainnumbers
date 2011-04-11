#include <assert.h>
#include <stdio.h>
#include "../app/tacheCombinaisonEstNombreArmstrong.h"

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
  TacheCombinaisonEstNombreArmstrong *tache, *tache2; 
  
  tache = TacheCombinaisonEstNombreArmstrong_Init(3, NULL, NULL);
  TacheCombinaisonEstNombreArmstrong_Clone(tache2, tache1);
  
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache2, combinaison2);
  
  assert((tache1 -> combinaison)[2] == 3);
  assert((tache2 -> combinaison)[2] == 4);
  
  TacheCombinaisonEstNombreArmstrong_Detruire(tache);
  TacheCombinaisonEstNombreArmstrong_Detruire(tache2);
  puts("Fin testCombinaisonEstNombreArmstrong_Clone");
  puts();
}