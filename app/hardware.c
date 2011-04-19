/*! \file hardware.c
	\author Maxime RIVIERE
*/

#include "hardware.h"

/*! \brief Calcule le nombre de processeur alloués au programme et le renvoi
*/
int ObtenirNombreProcesseurs()
{
  return(omp_get_num_procs());
}