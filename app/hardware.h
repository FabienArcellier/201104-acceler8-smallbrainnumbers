/*! \file hardware.h
	\author Maxime RIVIERE
*/

#include <stdio.h>
#include <omp.h>

/*! \brief Calcule le nombre de processeur alloués au programme et le renvoi
*/
int ObtenirNombreProcesseurs();

int ObtenirNombreThreads();