#include "puissanceDigit.h"

/*! \brief Initialise un cache pour les puissances des chiffres de 1 à 9

  Il est possible de personnaliser le cache construit grace à 2 paramètres :
    - [borne_inferieure] : Puissance la plus petite que le programme a besoin pour un chiffre
    - [borne_superieure] : Puissance la plus grande que le programme a besoin pour un chiffre

  Le cache est un tableau de type long de 2 dimensions :
    - 10 colonnes
    - [borne_superieure + 1] lignes

  Le contenu des lignes dont l'indice est < à [borne_inferieure] sont initialisés à 0
*/
CachePuissanceDigit * InitCachePuissanceDigit(unsigned char borne_inferieure,
  unsigned char borne_superieure)
{
  // Pré conditions
  assert(borne_inferieure <= borne_superieure);
  
  // Traitement
  CachePuissanceDigit * cache = (CachePuissanceDigit *) malloc(sizeof(CachePuissanceDigit));
  cache -> borne_inferieure = borne_inferieure;
  cache -> borne_superieure = borne_superieure;
  cache -> cache = (char *) malloc(sizeof(char) * borne_superieure * 10 * (borne_superieure + 1));

  int i = 0;
  for(i = 0; i < borne_inferieure; i++)
  {
	int j = 0;
    for(j = 0; j < 10;j++)
    {
		int k = 0;
		for(k = 0; k < borne_superieure; k++)
		{
			(cache -> cache)[i * 10 * borne_superieure + j * borne_superieure + k] = 1;
		}
    }
  }

  for(i = borne_inferieure; i <= borne_superieure; i++)
  {
	int j = 0;
    for(j = 0; j < 10;j++)
    {
		ConvertirNombreVersTableauDigit(&((cache -> cache)[i * 10 * borne_superieure + j * borne_superieure]), pow_long(j, i), borne_superieure);
    }
  }

  return cache;
}

/*! \brief Clone un cache pour les puissances des chiffres de 1 à 9
*/
CachePuissanceDigit * CloneCachePuissanceDigit(CachePuissanceDigit *cache)
{
  CachePuissanceDigit * cache_clone = (CachePuissanceDigit *) malloc(sizeof(CachePuissanceDigit));
  cache_clone -> borne_inferieure = cache -> borne_inferieure;
  cache_clone -> borne_superieure = cache -> borne_superieure;
  cache_clone -> cache = (char *) malloc(sizeof(char) * cache -> borne_superieure * 10 * (cache -> borne_superieure + 1));
  memcpy(cache_clone -> cache, cache -> cache, sizeof(char) * cache -> borne_superieure * 10 *(cache -> borne_superieure + 1));
  
  return cache_clone;
}

/*! \brief Renvoie la puissance tirée du cache d'un chiffre entre 0 et 9
*/
void GetPuissanceDigit(CachePuissanceDigit *cache, char **combinaison, unsigned char digit, unsigned char exposant)
{
  // Pré conditions
  assert(exposant >= cache -> borne_inferieure);
  assert(exposant <= cache -> borne_superieure);
  assert(digit <= 9);

  // Post conditions
  // assert((cache -> cache)[exposant * 10 * cache -> borne_superieure + digit * cache -> borne_superieure] > 0 || digit == 0);

  // Traitement
  *combinaison = (cache -> cache + exposant * 10 * cache -> borne_superieure + digit * cache -> borne_superieure);
	
	return;
}

/*!  \brief Detruit l'objet cache
*/
void DetruireCachePuissanceDigit(CachePuissanceDigit *cache)
{
  free(cache -> cache);
  free(cache);
}
