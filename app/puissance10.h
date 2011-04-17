/*! \file puissance10.h
	\author Fabien Arcellier
*/

#ifndef PUISSANCE10_H
#define PUISSANCE10_H

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "mathematique.h"

#define PUISSANCE10_EXPOSANT_LIMIT 19

/*! \brief Cache de puissance pour la valeur 10

  Vous devez éviter de manipuler directement une instance de ce type la.
  Utilisez les fonctions ci-dessous.
*/
typedef struct cache_puissance_10
{
	char borne_superieure;
	long long *cache;
} CachePuissance10;

/*! \brief Initialise le cache en calculant les valeurs de 10^0 à 10^n
*/
void InitCachePuissance10(CachePuissance10 *cache, unsigned char borne_superieur);

/* \brief Retourne la puissance de 10 recherchée depuis le cache
*/
long long inline GetPuissance10(CachePuissance10 *cache, unsigned char exposant);

/* \brief Renvoie 1 si la puissance de 10 demandé est au dela de la capacite technique
	du long long
*/
int inline Puissance10_EstOverflow(CachePuissance10 *cache, unsigned char exposant);

/*\brief Destructeur du cache
*/
void DetruireCachePuissance10(CachePuissance10 *cache);

#endif
