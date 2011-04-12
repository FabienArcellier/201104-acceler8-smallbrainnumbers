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
  fabrique -> ordre_initiale = fabrique -> ordre_courant;
  fabrique -> ordre_finale = log10(valeur_finale);
  
  fabrique -> cachePuissanceDigit = cachePuissanceDigit;
  fabrique -> cachePuissance10 = cachePuissance10;
  
  fabrique -> tacheModele = TacheCombinaisonEstNombreArmstrong_Init(valeur_initiale, cachePuissanceDigit, cachePuissance10);
  fabrique -> combinaison_initiale = (char *) malloc(sizeof(char) * fabrique -> ordre_courant);
  fabrique -> combinaison_courante = (char *) malloc(sizeof(char) * fabrique -> ordre_initiale);
  fabrique -> combinaison_finale = (char *) malloc(sizeof(char) * fabrique -> ordre_finale);
  
  //ConvertirNombreVersTableauDigit(fabrique -> combinaison_initiale, 0, fabrique -> ordre_initiale);
  //ConvertirNombreVersTableauDigit(fabrique -> combinaison_finale, valeur_initiale,  fabrique -> ordre_finale);
  //memcpy(fabrique -> combinaison_courante, fabrique -> combinaison_initiale, fabrique -> ordre_initiale);
  
  FabriqueTacheCombinaisonEstNombreArmstrong_ChoisirMeilleurFabricationMod(fabrique);
}

/* \brief Libere la mémoire d'un objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
void DetruireFabriqueTacheCombinaisonEstNombreArmstrong(
  FabriqueTacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong)
{
	free(fabrique -> combinaison_initiale);
	free(fabrique -> combinaison_courante);
	free(fabrique -> combinaison_finale);
	free(fabrique);
}

/* \brief En fonction des paramètres de la fabrique, détermine le meilleur mode de fabrication des taches

Un nom à 3 chiffres de valeur 345 a la meme valeur d'armstrong que 354, 435, 453, 534, 543. On peut donc en choisissant
les bonnes combinaisons diviser le nombre de calcul à faire par environ 3! (333 et 323 ont moins de combinaisons par exemple).

Si on commence les itérations à partir de 0, il y a une relation d'ordre entre les combinaisons uniques.
 - 5 > 4
 - 3 > 5
 
On peut généraliser, prenons un espace vectoriel X de dimension n X {x0, x1, ... xn}
x0, etant le digit de poids faible et xn celui de poids fort.

La relation devient :
 - x0 >= x1
 - x1 >= x2
 - ...
 - xn-1 >= xn

Ce mode qui consiste à calculer seulement les combinaisons uniques est combinaison_unique
L'autre mode, incrementation_direct teste toutes les combinaisons. 

On le choisira quand :
	- (valeur_courante - valeur_initiale) < Factoriel(ordre_initiale)
	- (valeur_finale - valeur_courante) < Factoriel(ordre_finale)

*/
void FabriqueTacheCombinaisonEstNombreArmstrong_ChoisirMeilleurFabricationMode(
	FabriqueTacheCombinaisonEstNombreArmstrong * tache)
{
	
}
