/*! \file tacheCombinaisonEstNombreArmstrong.c
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

#include "tacheCombinaisonEstNombreArmstrong.h"

/* \brief Instancie un objet TacheCombinaisonEstNombreArmstrong
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Init(
  char ordre_courant, 
	long long borne_inferieure, 
	long long borne_superieure, 
	CachePuissanceDigit *cache_puissance_digit, 
	CachePuissance10 *cache_puissance_10)
{
  TacheCombinaisonEstNombreArmstrong *tache;
  tache = (TacheCombinaisonEstNombreArmstrong *) malloc(sizeof(TacheCombinaisonEstNombreArmstrong));
  tache -> combinaison = (char *) malloc(sizeof(char) * ordre_courant);
  tache -> ordre_courant = ordre_courant;
	tache -> borne_inferieure = borne_inferieure;
	tache -> borne_superieure = borne_superieure;
  tache -> cache_puissance_digit = cache_puissance_digit;
  tache -> cache_puissance_10 = cache_puissance_10;
  tache -> resultat = -1;
  return tache;
}

/* \brief Désalloue la mémoire associée à une instance de TacheCombinaisonEstNombreArmstrong
*/
void TacheCombinaisonEstNombreArmstrong_Detruire(
  TacheCombinaisonEstNombreArmstrong * tache)
{
  free(tache -> combinaison);
  free(tache);
}

/* \brief Retourne le clone d'une structure de type TacheCombinaisonEstNombreArmstrong

Les adresses de cachePuissanceDigit et cachePuissance10 sont recopiés
combinaison est cloné dans un nouveau tableau
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Clone( 
  TacheCombinaisonEstNombreArmstrong * tache_parent)
{
  TacheCombinaisonEstNombreArmstrong *tache_clone;
  tache_clone = (TacheCombinaisonEstNombreArmstrong *) malloc(sizeof(TacheCombinaisonEstNombreArmstrong));
  *tache_clone = *tache_parent;

  tache_clone -> combinaison = (char *) malloc(sizeof(char) * (tache_clone -> ordre_courant));
  TacheCombinaisonEstNombreArmstrong_SetCombinaison(tache_clone, tache_parent -> combinaison);
  
  return tache_clone;
}

/* \brief Recopie le contenu du tableau [combinaison] dans la combinaison de TacheCombinaisonEstNombreArmstrong
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

/* \brief Tache : Calcule le nombre d'armstrong d'une combinaison, vérifie si le résultat est valide
*/
void TacheCombinaisonEstNombreArmstrong_Executer(TacheCombinaisonEstNombreArmstrong * tache)
{
	// Pré conditions
	assert(tache -> combinaison != NULL);
	assert(tache -> cache_puissance_digit != NULL);
	assert(tache -> cache_puissance_10 != NULL);
	
	// Traitement
	long long nombre_armstrong = 0;
	// Calculer le nombre d'armstrong de la combinaison
	nombre_armstrong = CalculNombreArmstrong(tache -> combinaison, tache -> ordre_courant, tache -> cache_puissance_digit);

	// Valider si le calcul renvoie un nombre d'armstrong
	// Enregistrer le résultat dans resultat
	//inutile car calculé dans CalculArmstrong.c/*if (nombre_armstrong >= GetPuissance10(tache -> cache_puissance_10, tache -> ordre_courant - 1) &&*//
		if(nombre_armstrong >= tache -> borne_inferieure &&
		nombre_armstrong <= tache -> borne_superieure &&
		(nombre_armstrong < GetPuissance10(tache -> cache_puissance_10, tache -> ordre_courant) || Puissance10_EstOverflow(tache -> cache_puissance_10, tache -> ordre_courant + 1) == 1) &&
		EstUnNombreArmstrong(tache -> combinaison, nombre_armstrong, tache -> ordre_courant,tache -> cache_puissance_10) == 1)
	{
		tache -> resultat = nombre_armstrong;
		printf("NA: %lld\n", nombre_armstrong);
	}
	else
	{
		tache -> resultat = -1;
	}
	
	return;
}
