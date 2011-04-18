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
  do
  {
	  TacheCombinaisonEstNombreArmstrong *tache = NULL;
	  reste_des_taches = FabriqueTacheCombinaisonEstNombreArmstrong_ObtenirTacheSuivante(ordonnanceur -> fabrique, &tache);
	  if (reste_des_taches == 1)
	  {
		  TacheCombinaisonEstNombreArmstrong_Executer(tache);
		  TacheCombinaisonEstNombreArmstrong_Detruire(tache);
	  }
  } while (reste_des_taches == 1);
	
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