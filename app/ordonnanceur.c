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
  long long i;
  int nb_combinaison_max;
  int nombre_proc = ObtenirNombreProcesseurs();
  nb_combinaison_max = nombreCombinaisonsDunRange(ordonnanceur->fabrique->ordre_initiale, ordonnanceur->fabrique->ordre_finale);  
  #pragma omp parallel for num_threads(nombre_proc*4)
  for(i=0;i<nb_combinaison_max;i++)
  {
    //printf("D: Nombre de Thread : %d\n",omp_get_num_threads());
	  TacheCombinaisonEstNombreArmstrong *tache = NULL;
	  #pragma omp critical
	  {
	  reste_des_taches = FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(ordonnanceur -> fabrique, &tache);
	  }
	  if (reste_des_taches == 1)
	  {
		  TacheCombinaisonEstNombreArmstrong_Executer(tache);
		  TacheCombinaisonEstNombreArmstrong_Detruire(tache);
	  }
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
