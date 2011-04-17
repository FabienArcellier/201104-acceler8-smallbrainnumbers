#include "fabriqueTacheCombinaisonEstNombreArmstrong.h"

/* \brief Instancie un nouvel objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
FabriqueTacheCombinaisonEstNombreArmstrong * InitialiserFabriqueTacheCombinaisonEstNombreArmstrong(
  char * combinaison_initiale, 
  char * combinaison_finale, 
  int ordre_initiale,
  int ordre_finale,
  CachePuissanceDigit *cachePuissanceDigit, 
  CachePuissance10 *cachePuissance10)
{
  // Pré conditions
  assert(cachePuissanceDigit != NULL);
  assert(cachePuissance10 != NULL);
  
  // Traitement
  FabriqueTacheCombinaisonEstNombreArmstrong *fabrique;
  fabrique = (FabriqueTacheCombinaisonEstNombreArmstrong *) malloc(sizeof(FabriqueTacheCombinaisonEstNombreArmstrong));
  
	fabrique -> valeur_initiale = ConvertirTableauDigitVersNombre(combinaison_initiale, ordre_initiale, cachePuissance10);
	fabrique -> valeur_finale = ConvertirTableauDigitVersNombre(combinaison_finale, ordre_finale, cachePuissance10);
  fabrique -> ordre_initiale = ordre_initiale;
  fabrique -> ordre_courant = ordre_initiale;
  fabrique -> ordre_finale = ordre_finale;
  
  fabrique -> cachePuissanceDigit = cachePuissanceDigit;
  fabrique -> cachePuissance10 = cachePuissance10;
  
  fabrique -> tacheModele = TacheCombinaisonEstNombreArmstrong_Init(ordre_initiale, 
																																		fabrique -> valeur_initiale,
																																		fabrique -> valeur_finale, 
																																		cachePuissanceDigit, 
																																		cachePuissance10);
	
  fabrique -> combinaison_initiale = (char *) malloc(sizeof(char) * fabrique -> ordre_initiale);
  fabrique -> combinaison_courante = (char *) malloc(sizeof(char) * fabrique -> ordre_finale);
  fabrique -> combinaison_finale = (char *) malloc(sizeof(char) * fabrique -> ordre_finale);
	
  memcpy(fabrique -> combinaison_initiale, combinaison_initiale, sizeof(char) * fabrique -> ordre_initiale);
	memcpy(fabrique -> combinaison_courante, fabrique -> combinaison_initiale, sizeof(char) * fabrique -> ordre_initiale);
	memcpy(fabrique -> combinaison_finale, combinaison_finale, sizeof(char) * fabrique -> ordre_finale);
  
  FabriqueTacheCombinaisonEstNombreArmstrong_ChoisirMeilleurFabricationMode(fabrique);
  
  return fabrique;
}

/* \brief Libere la mémoire d'un objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
void DetruireFabriqueTacheCombinaisonEstNombreArmstrong(
  FabriqueTacheCombinaisonEstNombreArmstrong * fabrique)
{
	free(fabrique -> combinaison_initiale);
	free(fabrique -> combinaison_courante);
	free(fabrique -> combinaison_finale);
	free(fabrique);
}

/* \brief Remplit tache_vide avec la tache suivante 
  
  \param tache_vide : réserver seulement l'adresse, l'espace mémoire sera réservé en interne
  Si il reste des taches, retourne 1, sinon retourne 0
*/
int FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(FabriqueTacheCombinaisonEstNombreArmstrong *fabrique, TacheCombinaisonEstNombreArmstrong **tache_vide)
{
	int reste_des_taches = 0;
	
	// Vérifier la valeur finale
	if (fabrique -> ordre_courant != fabrique -> ordre_finale ||
		Compare2TableauxDigit(fabrique -> combinaison_courante, fabrique -> combinaison_finale, fabrique -> ordre_courant) < 1)
	{
		// Cloner le template
		reste_des_taches = 1;
		*tache_vide = TacheCombinaisonEstNombreArmstrong_Clone(fabrique -> tacheModele);
		TacheCombinaisonEstNombreArmstrong_SetCombinaison(*tache_vide, fabrique -> combinaison_courante);
		
		// Calculer la combinaison suivante
		// Changer d'ordre si renvoie 1
		if(IncrementerTableauxDigitCombinaisonUnique(fabrique -> combinaison_courante, fabrique -> ordre_courant) == 1)
		{
			fabrique -> ordre_courant++;
			fabrique -> tacheModele -> ordre_courant = fabrique -> ordre_courant;
			ConvertirNombreVersTableauDigit(fabrique -> combinaison_courante, 2, fabrique -> ordre_courant);
		}
	}
	
	return reste_des_taches;
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
	FabriqueTacheCombinaisonEstNombreArmstrong * fabrique)
{
	fabrique -> mode = combinaison_unique;
}
