#include "main.h"

/*

*/
int main(void)
{
	long debut = RANGE_DEBUT;
	long fin = RANGE_FIN;
	int combinaison[NOMBRE_DIGIT_MAXIMUM];
	int i = 0;
	

	int ordre_debut = (int) log10(debut);
        int ordre_fin = ((int) log10(fin)) + 1;
	int ordre_courant = ordre_debut;

	for(i = 0; i < NOMBRE_DIGIT_MAXIMUM; i++)
	{
		combinaison[i] = 0;
	}

	do
	{
		long nombreArmstrong = ObtenirNombreArmstrong(combinaison, 
			ordre_courant, 
			debut, 
			fin);

		if (nombreArmstrong != -1)
		{
			printf("%ld\n", nombreArmstrong);
		}

		ObtenirCombinaisonSuivante(combinaison, &ordre_courant);
	} while (ordre_courant < ordre_fin);

	return 0;
}

long ObtenirNombreArmstrong (int combinaison[], int ordre_courant, long debut, long fin)
{
	long valeurArmstrong = 0;
	int resultat = -1;// Aucun resultat
	int i = 0;
	for(i = 0; i < ordre_courant; i++)
	{
		valeurArmstrong = valeurArmstrong + 
			pow(combinaison[i], ordre_courant);
	}

	// int nombre_permutation = fact(ordre_courant);
	for(i = 0; i < nombre_permutation; i++)
	{
		long valeurCombinaison = ObtenirPermutation(
			combinaison, 
			ordre_courant,
			i);

		if (valeurCombinaison == valeurArmstrong)
		{
			resultat = valeurArmstrong;
			break;
		}
	}

	return resultat;
}

long ObtenirPermutation(int combinaison[], int ordre_courant, int i)
{
	
}
