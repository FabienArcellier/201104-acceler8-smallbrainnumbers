/*! \file combinaison.c
    \author Fabien Arcellier
*/
#include "combinaison.h"

/* \brief Convertir un nombre en tableau de digit de longueur n

Convertit le nombre 371 en [1,7,3] si [longueur = 3]
Le nombre de poids fort est à la fin du tableau.

Le résultat est placé dans TableauDigit. La réservation de la mémoire est a
la charge de l'appellant.
*/
void ConvertirNombreVersTableauDigit(char * TableauDigit, long long nombre, int longueur)
{
  // Pré conditions
  
  // Traitement
  int i = 0;
  
  for(i = 0; nombre != 0; i++, nombre /= 10)
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

/* \brief Convertir un tableau de digit de longueur n en nombre

TODO : Parallélisable mais peu intéressant dans un premier temps
*/
long long ConvertirTableauDigitVersNombre(char * TableauDigit, int borne_superieure, CachePuissance10 *cache)
{
  // Traitement
  int i = 0;
  long long result = 0;
  for(i = 0; i < borne_superieure; i++)
  {
    result = result + TableauDigit[i] * GetPuissance10(cache, i);
  }
  
  // Post conditions
  assert(result >= 0);
  assert(result < pow(10,borne_superieure));
  
  return result;
}

/* \brief Compare 2 tableaux de digit de longueur n

Retourne 1 si TableauDigit1 > à TableauDigit2, 0 si TableauDigit1 = TableauDigit2, sinon -1
*/
int Compare2TableauxDigit(char * TableauDigit1, char * TableauDigit2, char borne_superieure)
{

  // Traitement
  int i = 0;
  int resultat_comparaison = 0;
  for(i = borne_superieure - 1; i >= 0; i--)
  {
    if(TableauDigit1[i] > TableauDigit2[i])
    {
      resultat_comparaison = 1;
      break;
    }
    if(TableauDigit1[i] < TableauDigit2[i])
    {
      resultat_comparaison = -1;
      break;
    }
  }
  
  // Post conditions
  assert(resultat_comparaison >= -1);
  assert(resultat_comparaison <= 1);
  
  return resultat_comparaison;
}

/* \brief Incremente le tableau de 1

Retourne 1 si c'est la fin du tableau
*/
int IncrementerTableauxDigit(char *TableauDigit, char borne_superieure)
{
  int i = 0;
  int fin_tableau = 0;
  for(i = 0; i < borne_superieure; i++)
  {
    TableauDigit[i]++;
    if (TableauDigit[i] != 10)
    {
      break;
    }
    
    if(i != borne_superieure - 1)
    {
    	TableauDigit[i] = 0;
    }
    else
    {
    	fin_tableau = 1;
    }
  }
  
  return fin_tableau;
}

/* \brief Incremente le tableau vers la prochaine combinaison unique

Définition d'une combinaison unique :
tab[0] >= tab[1], tab[1] >= tab[2], ..., tab[n-1] >= tab[n]

Retourne 1 si c'est la fin du tableau
*/
int IncrementerTableauxDigitCombinaisonUnique(char *TableauDigit, char borne_superieure)
{
  int i = 0;
  int profondeur = 0;
  int fin_tableau = 0;
  for(i = 0; i < borne_superieure; i++)
  {
    TableauDigit[i]++;
    if (TableauDigit[i] != 10)
    {
      break;
    }
    profondeur++;
  }
  
  for(i = 1;TableauDigit[borne_superieure - 1] < 10 && i <= profondeur; i++)
  {
  	TableauDigit[profondeur - i] = TableauDigit[profondeur];
  }
  
  if (TableauDigit[borne_superieure - 1] > 9)
 	{
 		fin_tableau = 1;
 	}
  
  return fin_tableau;
}
