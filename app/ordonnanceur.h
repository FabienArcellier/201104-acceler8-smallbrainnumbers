#include <assert.h>
#include "fabriqueTacheCombinaisonEstNombreArmstrong.h"
#include <omp.h>

typedef struct ordonnanceur
{
   int nombre_processeurs;
   FabriqueTacheCombinaisonEstNombreArmstrong *fabrique;
} Ordonnanceur;

/*! \brief Initialise une instance de l'ordonnanceur
 */
Ordonnanceur inline * Ordonnanceur_Init(int nombre_processeurs, FabriqueTacheCombinaisonEstNombreArmstrong *fabrique);

/*! \brief Demande a l'ordonnanceur de commencer le dispatch des taches
 */
void Ordonnanceur_Start(Ordonnanceur *ordonnanceur);

/*! \brief Permet a un code exterieur de se mettre en attente de la fin de l'ordonnanceur
 */
void inline Ordonnanceur_AttendreFin(Ordonnanceur *ordonnanceur);

/*! \brief Detruit une instance de l'ordonnanceur
 */
void inline Ordonnanceur_Detruire(Ordonnanceur *ordonnanceur);
