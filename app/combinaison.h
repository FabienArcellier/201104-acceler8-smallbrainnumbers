/* \file combinatoire.h
  \author Fabien Arcellier
*/

#ifndef COMBINAISON_H
#define COMBINAISON_H

#include <math.h>

/* \brief Convertir un nombre en tableau de digit de longueur n

Convertit le nombre 371 en [1,7,3] si [longueur = 3]
Le nombre de poids fort est � la fin du tableau.

Le r�sultat est plac� dans TableauDigit. La r�servation de la m�moire est a
la charge de l'appellant.
*/
void ConvertirNombreVersTableauDigit(char * TableauDigit, long nombre, char longueur);

/* \brief Convertir un tableau de digit de longueur n en nombre
*/
long ConvertirTableauDigitVersNombre(char * TableauDigit, char borne_superieure);

/* \brief Compare 2 tableaux de digit de longueur n

Retourne 1 si TableauDigit1 > � TableauDigit2, 0 si TableauDigit1 = TableauDigit2, sinon -1
*/
int Compare2TableauxDigit(char * TableauDigit1, char * TableauDigit2, char borne_superieure);

/* \brief Incremente le tableau de 1
*/
void IncrementerTableauxDigit(char *TableauDigit, char borne_superieure);

/* \brief Incremente le tableau vers la prochaine combinaison unique

D�finition d'une combinaison unique :
tab[0] >= tab[1], tab[1] >= tab[2], ..., tab[n-1] >= tab[n]
*/
int IncrementerTableauxDigitCombinaisonUnique(char *TableauDigit, char borne_superieure);

#endif