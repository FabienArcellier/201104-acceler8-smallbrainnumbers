#include "fabriqueTacheCombinaisonEstNombreArmstrong.h"

/* \brief Instancie un nouvel objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
FabriqueTacheCombinaisonEstNombreArmstrong * InitialiserFabriqueTacheCombinaisonEstNombreArmstrong(
  long valeur_initiale, 
  long valeur_finale, 
  CachePuissanceDigit *cachePuissanceDigit, 
  CachePuissance10 *cachePuissance10)
{
  // Pré conditions
  assert(valeur_initiale < valeur_finale);
  assert(cachePuissanceDigit != NULL);
  assert(cachePuissance10 != NULL);
  
  // Traitement
  FabriqueTacheCombinaisonEstNombreArmstrong * fabrique;
  fabrique = (FabriqueTacheCombinaisonEstNombreArmstrong *) malloc(sizeof(FabriqueTacheCombinaisonEstNombreArmstrong));
  
  fabrique -> valeur_courante = valeur_initiale;
  fabrique -> valeur_initiale = valeur_initiale;
  fabrique -> valeur_finale = valeur_finale;
  fabrique -> ordre_courant = log10(valeur_initiale);
  fabrique -> ordre_initiale = log10(valeur_initiale);
  fabrique -> ordre_finale = log10(valeur_finale);
  
  fabrique -> cachePuissanceDigit = cachePuissanceDigit;
  fabrique -> cachePuissance10 = cachePuissance10;
  
  fabrique -> tacheModele = TacheCombinaisonEstNombreArmstrong_Init(valeur_initiale, cachePuissanceDigit, cachePuissance10);
}