#include <assert.h>
#include <stdlib.h>
#include "tacheCombinaisonEstNombreArmstrong.h"

typedef struct fabrique_tache_combinaison_est_nombre_armstrong
{
  tacheCombinaisonEstNombreArmstrong *tacheModele;
  long valeur_courante;
  long valeur_initiale;
  long valeur_finale;
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

typedef enum fabrique_tache_combinaison_est_nombre_armstrong_mode 
{
	combinaison_unique, //Ce mode ne fonctionne que si l'on part de 0 pour l'incrementation
	incrementation_direct
} FabriqueTacheCombinaisonEstNombreArmstrong_Mode;

/* \brief Instancie un nouvel objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
FabriqueTacheCombinaisonEstNombreArmstrong * InitialiserFabriqueTacheCombinaisonEstNombreArmstrong(
  long valeur_initiale, 
  long valeur_finale, 
  CachePuissanceDigit *cachePuissanceDigit, 
  CachePuissance10 *cachePuissance10);

/* \brief Remplit tache_vide avec la tache suivante 
  
  \param tache_vide : réserver seulement l'adresse, l'espace mémoire sera réservé en interne
  Si il reste des taches, retourne 1, sinon retourne 0
*/
int FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(TacheCombinaisonEstNombreArmstrong *tache_vide);

/* \brief Libere la mémoire d'un objet FabriqueTacheCombinaisonEstNombreArmstrong
*/
void DetruireFabriqueTacheCombinaisonEstNombreArmstrong(
  FabriqueTacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong);
  
/* \brief En fonction des paramètres de la fabrique, détermine le meilleur mode de fabrication des taches
*/
void FabriqueTacheCombinaisonEstNombreArmstrong_ChoisirMeilleurFabricationMode(
	FabriqueTacheCombinaisonEstNombreArmstrong * tache);

