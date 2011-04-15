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
  cache -> cache = (long long *) malloc(sizeof(long long)*(borne_superieure + 1));
  
  int i = 0;
  for(i = 0; i <= borne_superieure; i++)
  {
    (cache -> cache)[i] = pow_long(10, i);
  }

  return;
}

/* \brief Retourne la puissance de 10 recherchée depuis le cache

	retourne -1 si dépassement de capacité
*/
long long inline GetPuissance10(CachePuissance10 *cache, unsigned char exposant)
{
  //Pre condition
  assert(cache -> borne_superieure >= exposant);
  
	long long result = 0;
	if (exposant > 19)
	{
		result = 4611686018427387899LL;
	}
	else
	{
		result = (cache -> cache)[exposant];
	}

  //Post condition
  assert(result != 0);
  return result;
}

/*! \brief Destructeur du cache
  Désalloue la mémoire dynamique utilisée pour construire le tableau
  de cache
*/
void DetruireCachePuissance10(CachePuissance10 *cache)
{
  free(cache -> cache);
}
