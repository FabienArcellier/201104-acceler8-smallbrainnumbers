#include "ordonnanceur.h"

/*! \brief Initialise une instance de l'ordonnanceur
 */
Ordonnanceur inline * Ordonnanceur_Init(int nombre_processeurs, FabriqueTacheCombinaisonEstNombreArmstrong *fabrique)
{
  Ordonnanceur *ordonnanceur = (Ordonnanceur *)malloc(sizeof(Ordonnanceur));
  ordonnanceur -> nombre_processeurs = nombre_processeurs;
  ordonnanceur -> fabrique = fabrique;
  return ordonnanceur;
}

/*! \brief Demande a l'ordonnanceur de commencer le dispatch des taches
 */
void Ordonnanceur_Start(Ordonnanceur *ordonnanceur)
{
  int reste_des_taches = 1;
  int ordre_finale = ordonnanceur -> fabrique -> ordre_finale;
  long long i = 0;
  long long nb_combinaison_max;
  int nombre_proc = ObtenirNombreProcesseurs();
  nb_combinaison_max = nombreCombinaisonsDunNombreDigit(ordre_finale);
  
  // Réservation de l'espace mémoire pour les permutations et construction de la combinaison initiale
  char * permutations = (char *) malloc(sizeof(char) * ordre_finale * nb_combinaison_max);
  char * combinaison = (char *) malloc(sizeof(char) * ordre_finale);
  for (i = 0; i <= ordre_finale; i++)
  {
    combinaison[i] = 0;
  }
  combinaison[0] = 1;

	printf("D: nb_combinaison_max : %lld\n", nb_combinaison_max);
  for (i = 0; i < nb_combinaison_max - 2; i++)
  {
    int retour = IncrementerTableauxDigitCombinaisonUnique(combinaison, ordre_finale);
		if (retour == 1)
		{
			printf("D: i : %lld\n", i);
			printf("D: nb_combinaison_max : %lld\n", nb_combinaison_max);
			break;
		}
		
    memcpy(&(permutations[i * ordre_finale]), combinaison, sizeof(char) * ordre_finale);
  }
  
  // Execution du traitement parallèle pour trouver les nombres d'armstrong
	#pragma omp parallel for num_threads(nombre_proc*2)
  for (i = 0; i < nb_combinaison_max; i++)
  {
		char *combinaison_for = (char *) malloc(sizeof(char) * ordre_finale);
		memcpy(combinaison_for, &(permutations[i * ordre_finale]), sizeof(char) * ordre_finale);
		
    int j = 0;
    int ordre_min = GetOrdreMinimumCombinaison(combinaison_for, ordre_finale);
		// printf("D: ordre_finale : %d\n", ordre_finale);
    for (j = ordre_min; j <= ordre_finale; j++)
    {
			// printf("D: ordre : %d\n", j);
      long long valeurArmstrong = CalculNombreArmstrong(combinaison_for, j,  ordonnanceur -> fabrique -> cachePuissanceDigit);
			
      if (j != 0 &&
				(Puissance10_EstOverflow(ordonnanceur -> fabrique -> cachePuissance10, j) == 1 
					|| valeurArmstrong <= GetPuissance10(ordonnanceur -> fabrique -> cachePuissance10, j)) &&
				valeurArmstrong >= GetPuissance10(ordonnanceur -> fabrique -> cachePuissance10, j - 1) &&
				valeurArmstrong <= ordonnanceur -> fabrique -> valeur_finale &&
        valeurArmstrong >= ordonnanceur -> fabrique -> valeur_initiale &&
        EstUnNombreArmstrong(combinaison_for, valeurArmstrong, j, ordonnanceur -> fabrique -> cachePuissance10))
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
