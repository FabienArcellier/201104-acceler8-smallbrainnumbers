#include <assert.h>
#include <stdlib.h>

typedef struct fabrique_tache_combinaison_est_nombre_armstrong
{
  tacheCombinaisonEstNombreArmstrong *tacheModele;
  char *combinaison_courante;
  char *combinaison_initiale;
  char *combinaison_finale;
  char ordre_courant;
  char ordre_initiale;
  char ordre_finale;
  CachePuissanceDigit *cachePuissanceDigit;
  CachePuissance10 *cachePuissance10;
} FabriqueTacheCombinaisonEstNombreArmstrong;

int ObtenirTacheSuivante(TacheCombinaisonEstNombreArmstrong *tache_vide);