/*! \file tacheCombinaisonEstNombreArmstrong.h
	\brief Fichier qui contient les méthodes rattachés à une tache associée au problème
	
	TacheCombinaisonEstNombreArmstrong rassemble les informations pour effectuer un 
	traitement indépendant dans un fil d'exécution séparé.
	
	Un objet TacheCombinaisonEstNombreArmstrong contient :
	- une combinaison de chiffre à tester (C'est une donnée qui lui est propre)
	- l'ordre courant qui correspond au nombre de chiffre de la combinaison
	- un lien vers le cache des puissances de 10
	- un lien vers le cache des puissances de chiffres entre 1 et 9
	- un espace pour stocker le résultat obtenu, -1 si ce n'est pas un nombre d'armstrong, sinon
		la valeur de celui-ci
		
	Vous pouvez accéder aux attributs suivants en lecture seule :
	- tache -> combinaison
	- tache -> ordre_courant
	- tache -> cache_puissance_digit
	- tache -> cache_puissance_10
	
	Vous pouvez accéder aux attributs suivant en lecture / ecriture :
	- tache -> resultat
*/

#include <assert.h>
#include <stdlib.h>
#include "../app/puissanceDigit.h"
#include "../app/puissance10.h"

typedef struct tache_combinaison_est_nombre_armstrong
{
  char *combinaison;
  char ordre_courant;
  CachePuissanceDigit *cache_puissance_digit;
  CachePuissance10 *cache_puissance_10;
  long resultat; /* -1 si n'est pas un nombre d'armstrong, sinon valeur */
} TacheCombinaisonEstNombreArmstrong;

/* \brief \brief Instancie un objet TacheCombinaisonEstNombreArmstrong
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Init(char ordre_courant, CachePuissanceDigit *cache_puissance_digit, CachePuissance10 *cache_puissance_10);

/* \brief \brief Désalloue la mémoire associée à une instance de TacheCombinaisonEstNombreArmstrong
*/
void TacheCombinaisonEstNombreArmstrong_Detruire(
  TacheCombinaisonEstNombreArmstrong * tache);

/* \brief Retourne le clone d'une structure de type TacheCombinaisonEstNombreArmstrong

L'adresse de cachePuissanceDigit et cachePuissance10 est recopié
combinaison est cloné dans un nouveau tableau
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Clone( 
  TacheCombinaisonEstNombreArmstrong * tache_parent);

/* \brief Recopie le contenu du tableau combinaison dans la combinaison de TacheCombinaisonEstNombreArmstrong
*/
void TacheCombinaisonEstNombreArmstrong_SetCombinaison(TacheCombinaisonEstNombreArmstrong * tache,
  char *combinaison);
