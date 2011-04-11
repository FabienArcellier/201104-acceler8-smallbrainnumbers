#include "tacheCombinaisonEstNombreArmstrong.h"

/* \brief Instancie un objet TacheCombinaisonEstNombreArmstrong
*/
TacheCombinaisonEstNombreArmstrong * inline TacheCombinaisonEstNombreArmstrong_Init(
  char ordre_courant, CachePuissanceDigit *cache_puissance_digit, CachePuissance10 *cache_puissance_10)
{
  TacheCombinaisonEstNombreArmstrong *tache = (TacheCombinaisonEstNombreArmstrong *) malloc(sizeof(TacheCombinaisonEstNombreArmstrong)
  tache.combinaison = (char *) malloc(sizeof(char) * ordre_courant);
  tache.ordre_courant = ordre_courant;
  tache.cache_puissance_digit = cache_puissance_digit;
  tache.cache_puissance_10 = cache_puissance_10;
  tache.resultat = 0;
  return tache;
}

/* \brief Désalloue la mémoire associée à une tache
*/
TacheCombinaisonEstNombreArmstrong * inline TacheCombinaisonEstNombreArmstrong_Detruire(
  TacheCombinaisonEstNombreArmstrong * tache)
{
  free(tache -> combinaison)
  free(tache);
}

/* \brief Recopie le contenu du tableau combinaison dans la combinaison de TacheCombinaisonEstNombreArmstrong
*/
void inline TacheCombinaisonEstNombreArmstrong_SetCombinaison(TacheCombinaisonEstNombreArmstrong * tache,
  char *combinaison)
{
  int i = 0;
  for(i = 0; i < tache -> ordre_courant; i++)
  {
    (tache -> combinaison)[i] = combinaison[i];
  }
  
  return;
}

/* \brief Crée le clone d'une structure de type TacheCombinaison

L'adresse de cachePuissanceDigit et cachePuissance10 est recopié
combinaison est cloné dans un nouveau tableau
*/
void TacheCombinaisonEstNombreArmstrong_Clone(TacheCombinaisonEstNombreArmstrong * tache_clone, 
  TacheCombinaisonEstNombreArmstrong * tache_parent)
{
  *tache_clone = *tache_parent;
  tache_clone.combinaison = (char *) malloc(sizeof(char) * ordre_courant);
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache_clone, tache_parent -> combinaison);
}