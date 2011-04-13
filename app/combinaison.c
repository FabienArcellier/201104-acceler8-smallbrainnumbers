#include "combinatoire.h"

/* \brief Convertir un nombre en tableau de digit de longueur n

Convertit le nombre 371 en [1,7,3] si [longueur = 3]
Le nombre de poids fort est à la fin du tableau.

Le résultat est placé dans TableauDigit. La réservation de la mémoire est a
la charge de l'appellant.
*/
void ConvertirNombreVersTableauDigit(char * TableauDigit, long nombre, char longueur)
{
  // Pré conditions
  assert(pow(10,longueur) > nombre);
  
  // Traitement
  int i = 0;
  
  for(i = 0; nombre != 0 ; i++; nombre / 10;)
  {
    TableauDigit[i] = nombre % 10;
  }
  for(;i < longueur; i++)
  {
    TableauDigit[i] = 0;
  }
  
  // Post conditions
  assert(i == longueur);
  
  return;
}