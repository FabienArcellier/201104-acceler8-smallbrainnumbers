#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "tacheCombinaisonEstNombreArmstrong.h"

typedef enum fabrique_tache_combinaison_est_nombre_armstrong_mode 
{
	combinaison_unique, //Ce mode ne fonctionne que si l'on part de 0 pour l'incrementation
	incrementation_directe
} FabriqueTacheCombinaisonEstNombreArmstrong_Mode;

typedef struct fabrique_tache_combinaison_est_nombre_armstrong
{
	long long valeur_initiale;
	long long valeur_finale;
  TacheCombinaisonEstNombreArmstrong *tacheModele;
  char *combinaison_courante;
  char *combinaison_initiale;
  char *combinaison_finale;
  char ordre_courant;
  char ordre_initiale;
  char ordre_finale;
  CachePuissanceDigit *cachePuissanceDigit;
  CachePuissance10 *cachePuissance10;
  FabriqueTacheCombinaisonEstNombreArmstrong_Mode mode;
} FabriqueTacheCombinaisonEstNombreArmstrong;

/* \brief Instancie un nouvel objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
FabriqueTacheCombinaisonEstNombreArmstrong * InitialiserFabriqueTacheCombinaisonEstNombreArmstrong(
  char * combinaison_initiale, 
  char * combinaison_finale, 
  int ordre_initiale,
  int ordre_finale,
  CachePuissanceDigit *cachePuissanceDigit, 
  CachePuissance10 *cachePuissance10);

/* \brief Remplit tache_vide avec la tache suivante 
  
  \param tache_vide : réserver seulement l'adresse, l'espace mémoire sera réservé en interne
  Si il reste des taches, retourne 1, sinon retourne 0
*/
int FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(FabriqueTacheCombinaisonEstNombreArmstrong *fabrique, TacheCombinaisonEstNombreArmstrong **tache_vide);

/* \brief Libere la mémoire d'un objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
void DetruireFabriqueTacheCombinaisonEstNombreArmstrong(
  FabriqueTacheCombinaisonEstNombreArmstrong * fabrique);
  
/* \brief En fonction des paramètres de la fabrique, détermine le meilleur mode de fabrication des taches
*/
void FabriqueTacheCombinaisonEstNombreArmstrong_ChoisirMeilleurFabricationMode(
	FabriqueTacheCombinaisonEstNombreArmstrong *tache);

