#include "ordonnanceur.h"

/*! \brief Initialise une instance de l'ordonnanceur
*/
Ordonnanceur *Ordonnanceur_Init(char * combinaison_borne_inferieure, 
																				char * combinaison_borne_superieure,
																				int nombre_chiffre_borne_inferieure,
																				int nombre_chiffre_borne_superieure,
																				CachePuissance10 *cachePuissance10,
																				CachePuissanceDigit *cachePuissanceDigit
																			)
{
	Ordonnanceur *ordonnanceur = (Ordonnanceur *) malloc(sizeof(Ordonnanceur));
	
	ordonnanceur -> nombre_processeurs = ObtenirNombreProcesseurs();
	ordonnanceur -> borne_inferieure = ConvertirTableauDigitVersNombre(combinaison_borne_inferieure, nombre_chiffre_borne_inferieure, cachePuissance10);
	ordonnanceur -> borne_superieure = ConvertirTableauDigitVersNombre(combinaison_borne_superieure, nombre_chiffre_borne_superieure, cachePuissance10);
	ordonnanceur -> nombre_chiffre_borne_inferieure = nombre_chiffre_borne_inferieure;
	ordonnanceur -> nombre_chiffre_borne_superieure = nombre_chiffre_borne_superieure;
	ordonnanceur -> cachePuissanceDigit = cachePuissanceDigit;
	ordonnanceur -> cachePuissance10 = cachePuissance10;
}

/*! \brief Demande a l'ordonnanceur de commencer le dispatch des taches
*/
void Ordonnanceur_Start(Ordonnanceur *ordonnanceur)
{
	assert(ordonnanceur -> borne_inferieure <= ordonnanceur -> borne_superieure);
	assert(ordonnanceur -> nombre_chiffre_borne_inferieure <= ordonnanceur -> nombre_chiffre_borne_superieure);
	
	int nombre_chiffre_borne_superieure = ordonnanceur -> nombre_chiffre_borne_superieure;
	long long borne_inferieure = ordonnanceur -> borne_inferieure;
	long long borne_superieure = ordonnanceur -> borne_superieure;
	CachePuissance10 * cachePuissance10 = ordonnanceur -> cachePuissance10;
	CachePuissanceDigit * cachePuissanceDigit = ordonnanceur -> cachePuissanceDigit;
	
	long long i = 0, nb_combinaison_max = 0;
	nb_combinaison_max = nombreCombinaisonsDunNombreDigit(nombre_chiffre_borne_superieure);
	
	// Réservation de l'espace mémoire pour les permutations et construction de la combinaison initiale
	char * permutations = (char *) malloc(sizeof(char) * nombre_chiffre_borne_superieure * nb_combinaison_max);
	char * combinaison = (char *) malloc(sizeof(char) * nombre_chiffre_borne_superieure);
	for (i = 0; i <= nombre_chiffre_borne_superieure; i++)
	{
		combinaison[i] = 0;
	}

	printf("D: nb_combinaison_max : %lld\n", nb_combinaison_max);
	for (i = 0; i < nb_combinaison_max - 2; i++)
	{
		IncrementerTableauxDigitCombinaisonUnique(combinaison, nombre_chiffre_borne_superieure);
		/*if (retour == 1)
		{
			printf("D: i : %lld\n", i);
			printf("D: nb_combinaison_max : %lld\n", nb_combinaison_max);
			break;
		}*/
		
		memcpy(&(permutations[i * nombre_chiffre_borne_superieure]), combinaison, sizeof(char) * nombre_chiffre_borne_superieure);
	}
	
	// Execution du traitement parallèle pour trouver les nombres d'armstrong
	char *combinaison_for;
	int j = 0, nombre_chiffre_minimum;
	long long valeurArmstrong = 0, combinaison_valeur_min = 0;
	#pragma omp parallel for num_threads(80) private(combinaison_for, nombre_chiffre_borne_superieure, j, nombre_chiffre_minimum, valeurArmstrong,\
	combinaison_valeur_min, cachePuissance10, cachePuissanceDigit, borne_superieure, borne_inferieure)
	for (i = 0; i < nb_combinaison_max; i++)
	{
		combinaison_for = (char *) malloc(sizeof(char) * nombre_chiffre_borne_superieure);
		memcpy(combinaison_for, &(permutations[i * nombre_chiffre_borne_superieure]), sizeof(char) * nombre_chiffre_borne_superieure);
		
// 		printf("D: combinaison_for : %lld \n", ConvertirTableauDigitVersNombre(combinaison_for, nombre_chiffre_borne_superieure, cachePuissance10));
// 		printf("D: borne_inferieure : %d\n", borne_inferieure);
// 		printf("D: borne_superieure : %d\n", borne_superieure);
// 		puts("");
		
		nombre_chiffre_minimum = GetOrdreMinimumCombinaison(combinaison_for, nombre_chiffre_borne_superieure);
		// printf("D: ordre_finale : %d\n", ordre_finale);
		for (j = nombre_chiffre_minimum; j <= nombre_chiffre_borne_superieure; j++)
		{
			valeurArmstrong = CalculNombreArmstrong(combinaison_for, j, cachePuissanceDigit);
// 			printf("D: ordre : %d\n", j);
// 			printf("D: valeurArmstrong : %lld\n", valeurArmstrong);
// 			printf("D : condition overflow : %d\n", Puissance10_EstOverflow(cachePuissance10, j) == 1);
			
			long long combinaison_valeur_min = ConvertirTableauDigitVersNombre(combinaison_for, nombre_chiffre_borne_superieure, cachePuissance10);
			
			if (j != 0 &&
				(Puissance10_EstOverflow(cachePuissance10, j) == 1 || valeurArmstrong < GetPuissance10(cachePuissance10, j)) &&
				valeurArmstrong >= GetPuissance10(cachePuissance10, j - 1) &&
				valeurArmstrong <= borne_superieure &&
				valeurArmstrong >= borne_inferieure &&
				EstUnNombreArmstrong(combinaison_for, valeurArmstrong, j, cachePuissance10))
			{
				printf("NA: %lld\n", valeurArmstrong);
			}
		}
		
		free(combinaison_for);
	}
}

/*! \brief Permet a un code exterieur de se mettre en attente de la fin de l'ordonnanceur
*/
void inline Ordonnanceur_AttendreFin(Ordonnanceur *ordonnanceur)
{
}

/*! \brief Detruit une instance de l'ordonnanceur
*/
void inline Ordonnanceur_Detruire(Ordonnanceur *ordonnanceur)
{
	free(ordonnanceur);
}
