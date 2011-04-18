/*! \file tacheCombinaisonEstNombreArmstrong.h
	\brief Fichier qui contient les m�thodes rattach�s � une tache associ�e au probl�me
	
	TacheCombinaisonEstNombreArmstrong rassemble les informations pour effectuer un 
	traitement ind�pendant dans un fil d'ex�cution s�par�.
	
	Un objet TacheCombinaisonEstNombreArmstrong contient :
	- une combinaison de chiffre � tester (C'est une donn�e qui lui est propre)
	- l'ordre courant qui correspond au nombre de chiffre de la combinaison
	- un lien vers le cache des puissances de 10
	- un lien vers le cache des puissances de chiffres entre 1 et 9
	- un espace pour stocker le r�sultat obtenu, -1 si ce n'est pas un nombre d'armstrong, sinon
		la valeur de celui-ci
		
	Vous pouvez acc�der aux attributs suivants en lecture seule :
	- tache -> combinaison
	- tache -> ordre_courant
	- tache -> cache_puissance_digit
	- tache -> cache_puissance_10
	
	Vous pouvez acc�der aux attributs suivant en lecture / ecriture :
	- tache -> resultat
*/

#ifndef TACHE_COMBINAISON_EST_NOMBRE_ARMSTRONG_H
#define TACHE_COMBINAISON_EST_NOMBRE_ARMSTRONG_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../app/puissanceDigit.h"
#include "../app/puissance10.h"
#include "../app/CalculArmstrong.h"

typedef struct tache_combinaison_est_nombre_armstrong
{
  char *combinaison;
  char ordre_courant;
	long long borne_inferieure;
	long long borne_superieure;
  CachePuissanceDigit *cache_puissance_digit;
  CachePuissance10 *cache_puissance_10;
  long long resultat; /* -1 si n'est pas un nombre d'armstrong, sinon valeur */
} TacheCombinaisonEstNombreArmstrong;

/* \brief \brief Instancie un objet TacheCombinaisonEstNombreArmstrong
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Init(char ordre_courant, 
																																						 long long borne_inferieure,
																																						 long long borne_superieure,
																																						 CachePuissanceDigit *cache_puissance_digit, 
																																						 CachePuissance10 *cache_puissance_10);

/* \brief \brief D�salloue la m�moire associ�e � une instance de TacheCombinaisonEstNombreArmstrong
*/
void TacheCombinaisonEstNombreArmstrong_Detruire(
  TacheCombinaisonEstNombreArmstrong * tache);

/* \brief Retourne le clone d'une structure de type TacheCombinaisonEstNombreArmstrong

L'adresse de cachePuissanceDigit et cachePuissance10 est recopi�
combinaison est clon� dans un nouveau tableau
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Clone( 
  TacheCombinaisonEstNombreArmstrong * tache_parent);

/* \brief Recopie le contenu du tableau combinaison dans la combinaison de TacheCombinaisonEstNombreArmstrong
*/
void TacheCombinaisonEstNombreArmstrong_SetCombinaison(TacheCombinaisonEstNombreArmstrong * tache,
  char *combinaison);

/* \brief Tache : Calcule le nombre d'armstrong d'une combinaison, v�rifie si le r�sultat est valide
*/
void TacheCombinaisonEstNombreArmstrong_Executer(TacheCombinaisonEstNombreArmstrong * tache);

#endif