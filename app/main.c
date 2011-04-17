#include "main.h"

/*! \brief Point d'entrée du programme
 * 
 * Codes d'erreur :
 * - 1 : Le nombre d'arguments est incorrect
 * - 2 : le format des nombres en entrée est incorrect
 * - 4 : La borne inferieure est superieure a la borne superieure
*/
int main(int argc, char *argv[])
{
	long long time_zero = time_start();
	
	int i = 0;
	
	if (argc != 3)
	{
		afficher_aide_longueur_argument_incorrect();
		return 3;
	}
	
	int borne_longueur[2];
	borne_longueur[0] = strlen(argv[1]);
	borne_longueur[1] = strlen(argv[2]);
	
	// Formater les bornes pour qu'elles aient le format d'une combinaison (inverser le contenu du tableau)
	for (i = 1; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < (borne_longueur[i - 1]) / 2 + (borne_longueur[i - 1]) % 2; j++)
		{
			//printf("D : argv[%d][%d], %d\n", i, j, argv[i][j]);
			
			char stockage_tmp = argv[i][j] - '0';
			argv[i][j] = argv[i][borne_longueur[i - 1] - j - 1] - '0';
			argv[i][borne_longueur[i - 1] - j - 1] = stockage_tmp;
			
			//printf("D : argv[%d][%d], %d\n", i, j, argv[i][j]);
			//printf("D : argv[%d][%d], %d\n", i, borne_longueur[i - 1] - j - 1, argv[i][borne_longueur[i - 1] - j - 1]);
		}
	}
	
	char borne_inferieure[20], borne_superieure[20];
	for(i = 0; i < 20; i++)
	{
		borne_inferieure[i] = 0;
		borne_superieure[i] = 0;
	}
	
	int borne_inferieure_longueur = borne_longueur[0], borne_superieure_longueur = borne_longueur[1];
	
	memcpy(borne_inferieure, argv[1], borne_inferieure_longueur);
	memcpy(borne_superieure, argv[2], borne_superieure_longueur);
	
	printf("T: Recuperation des arguments : %lld\n", time_end(time_zero));
	
	// Initialiser le cache des puissances de 10
	CachePuissance10 cachePuissance10;
	InitCachePuissance10(&cachePuissance10, borne_superieure_longueur);
	
	// Initialiser de le cache des puissances_digit
	CachePuissanceDigit cachePuissanceDigit;
	InitCachePuissanceDigit(&cachePuissanceDigit, borne_inferieure_longueur, borne_superieure_longueur);
	
		// Si le premier argument est superieur au deuxieme argument, afficher_aide_nombre_incoherent
	if (borne_inferieure_longueur > borne_superieure_longueur || Compare2TableauxDigit(borne_inferieure, borne_superieure, borne_superieure_longueur) == 1)
	{
		afficher_aide_nombre_incoherent(
			ConvertirTableauDigitVersNombre(borne_inferieure, borne_inferieure_longueur, &cachePuissance10), 
			ConvertirTableauDigitVersNombre(borne_superieure, borne_superieure_longueur, &cachePuissance10));
		return 4;
	}
	
	printf("T: Initialisation des caches : %lld\n", time_end(time_zero));
	
	//printf("D: Borne inferieure : %lld\n", ConvertirTableauDigitVersNombre(borne_inferieure, borne_inferieure_longueur, &cachePuissance10));
	//printf("D: Borne superieure : %lld\n", ConvertirTableauDigitVersNombre(borne_superieure, borne_superieure_longueur, &cachePuissance10));
	
	FabriqueTacheCombinaisonEstNombreArmstrong *fabrique;
	fabrique = InitialiserFabriqueTacheCombinaisonEstNombreArmstrong(
		borne_inferieure, 
		borne_superieure, 
		borne_inferieure_longueur, 
		borne_superieure_longueur,
		&cachePuissanceDigit, 
		&cachePuissance10);
	
	int reste_des_taches = 1;
	
	do
	{
		TacheCombinaisonEstNombreArmstrong *tache = NULL;
		reste_des_taches = FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(fabrique, &tache);
		if (reste_des_taches == 1)
		{
			TacheCombinaisonEstNombreArmstrong_Executer(tache);
			TacheCombinaisonEstNombreArmstrong_Detruire(tache);
		}
	} while(reste_des_taches == 1);
	
	printf("T: Temps total : %lld\n", time_end(time_zero));
	
	return 0;
}

/*! \brief Affiche l'aide de la ligne de commande dans le terminal
 */
void afficher_aide()
{
	puts("");
	puts("Usage : ./Smallbrain borne_inferieure borne_superieure");
	puts("");
	puts("Smallbrain est un programme pour calculer les smallbrains,");
	puts("aussi appellé nombres d'armstrong ou nombres narcissiques.");
	puts("Un smallbrain est nombre de la valeur est égale à la somme des chiffres");
	puts("de celui ci chacun eleve a la puissance correspondant au nombre de chiffres");
	puts("");
	puts("e.g : 371 est un smallbrain car 3^3 + 7^3 + 1^3 = 371");
	puts("");
	puts("Arguments:");
	puts("	borne_inferieure : Nombre entier ou l'on commence la recherche ");
	puts("		compris entre [1;9223372036854779999]");
	puts("	borne_superieure : Nombre entier ou l'on termine la recherche");
	puts("		compris entre [1;9223372036854779999]");
	puts("");
	puts("Remarques");
	puts("	- borne_inferieure doit etre inferieur ou egal a borne_superieure");
	puts("	- les nombres s'écrivent avec leur forme pleine 567, 456.");
	puts("	- N'utilisez pas de notation scientifique 1.5E23");
	puts("");
	puts("");
}

/*! \brief Affiche une information supplémentaire dans le cas ou le format d'un des nombres est invalide
 */
void afficher_aide_format_nombre_incorrecte()
{
	puts("");
	puts("ERREUR :");
	puts("- le format de nombre que vous avez utilise n'est pas correcte");
	afficher_aide();
}

/*! \brief Affiche une information supplémentaire dans le cas ou le format d'un des nombres est invalide
 */
void afficher_aide_nombre_incoherent(long long borne_inferieure, long long borne_superieure)
{
	puts("");
	puts("ERREUR :");
	printf("	la borne inferieure (%lld) est superieure a la borne superieure (%lld)\n\n", borne_inferieure, borne_superieure);
	afficher_aide();
}

/*! \brief Informe l'utilisateur que sa ligne d'argument est trop longue
 */
void afficher_aide_longueur_argument_incorrect()
{
	puts("");
	puts("ERREUR :");
	puts("	Vous devez avoir 3 arguments");
	puts("");
	afficher_aide();
}
