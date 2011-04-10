/*! \file puissance10.c
	\author Fabien Arcellier
*/

#include "puissance10.h"

/* \brief Initialise le cache en calculant les valeurs de 10^0 à 10^n
  
  Remplit un tableau permettant de garder en cache les valeurs pour
  les puissances de 10. On économise ainsi de nombreux cycles processeurs

*/
void InitCachePuissance10(CachePuissance10 *cache, unsigned char borne_superieure)
{
  cache -> borne_superieure = borne_superieure;
  cache -> cache = (long *) malloc(sizeof(int)*borne_superieure);
  
  int i = 0;
  for(i = 0; i <= borne_superieure; i++)
  {
    (cache -> cache)[i] = pow(10, i);
  }

  return;
}

/* \brief Retourne la puissance de 10 recherchée depuis le cache
*/
long inline GetPuissance10(CachePuissance10 *cache, unsigned char exposant)
{
  //Pre condition
  assert(cache -> borne_superieure >= exposant);

  //Post condition
  assert((cache -> cache)[exposant] > 0);
  return (cache -> cache)[exposant];
}

/*! \brief Destructeur du cache
  Désalloue la mémoire dynamique utilisée pour construire le tableau
  de cache
*/
void DetruireCachePuissance10(CachePuissance10 *cache)
{
  free(cache -> cache);
}
