/*!
*/

#ifndef PUISSANCE_DIGIT_H
#define PUISSANCE_DIGIT_H

#include <assert.h>
#include <math.h>
#include <stdlib.h>

/*! \brief Cache de puissance pour les chiffres entre 1 et 9

  Vous devez éviter de manipuler directement une instance de ce type la.
  Utilisez les fonctions ci-dessous.
*/
typedef struct cache_puissance_digit
{
  char borne_inferieure;
  char borne_superieure;
  long *cache;
} CachePuissanceDigit;

/*! \brief Initialise un cache pour les puissances des chiffres de 1 à 9
*/
void InitCachePuissanceDigit(CachePuissanceDigit *cache, unsigned char borne_inferieure,
  unsigned char borne_superieure);

/*! \brief Renvoie la puissance tirée du cache d'un chiffre entre 0 et 9
*/
long inline GetPuissanceDigit(CachePuissanceDigit *cache, unsigned char digit, unsigned char exposant);

/*!  \brief Detruit l'objet cache
*/
void DetruireCachePuissanceDigit(CachePuissanceDigit *cache);

#endif
