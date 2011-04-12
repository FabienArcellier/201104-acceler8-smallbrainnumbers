/*! \file CalculArmstrong.c
	\author Maxime RIVIERE
*/

#include "CalculArmstrong.h"



/*! \brief Calcule le nombre d'Armstrong d'une combinaison à l'aide du cache des puissance
*/
long long CalculNombreArmstrong(int *Combinaison, int size,CachePuissanceDigit *cache)
{
  int i;
  long long ResCalcul = 0;
  for(i=0;i<size;i++)
  {
    ResCalcul += GetPuissanceDigit(cache,Combinaison[i],size);
  }
  return ResCalcul;
 }

/*! \brief Vérifie si le nombre trouvé est un nombre d'Armstrong ou non. Mise en tableau du Nombre à tester puis recherche de l'intersection entre les deux.
*/
bool EstUnNombreArmstrong(int *Combinaison,long long NbTeste, int size)
{
  long *Combinatoire;
  bool test = FALSE;
  bool Armstrong = TRUE;
  Combinatoire = (long *)malloc (sizeof(long)*size);
  int *Test_variable;
  Test_variable = (int *)malloc (sizeof(int)*size);
  init_comparedigit(Test_variable,size);
  int i = 0;
  int j;
  for(i=0;NbTeste!=0;NbTeste/=10,i++)
  {
    Combinatoire[i] = NbTeste % 10;
  }
  for(i=0;i<size;i++){
    for(j=0;(j<size)&&(test==FALSE);j++)
    {
      if((Combinatoire[i] == Combinaison[j]) && (used_comparedigit(Test_variable,j,size) == FALSE))
      {
	test = TRUE;
	add_comparedigit(Test_variable,j);
      }
    }
    if (test == FALSE)
    {
      Armstrong = FALSE;
      break;
    }
    test= FALSE;
  }
  return Armstrong;
}

/*! \brief Initialisation du tableau de comparaison des digit déjà utilisé.
*/
void init_comparedigit(int *Test_variable,int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    Test_variable[i] = -1;
  }
}

/*! \brief Vérification que le digit égal dans Combinatoire et Combinaison n'ai pas déja été utilisé pour un autre digit
*/
bool used_comparedigit(int *Test_variable,int j,int size)
{
  int i;
  bool test = FALSE;
  for(i=0;i<size;i++)
  {
    if(Test_variable[i] == j)
    {
      test = TRUE;
      break;
    }
  }
  return test;
}

/*! \brief Ajout de la variable égale dans Combinatoire et Combinaison dans le tableau de test des variables.
*/
void add_comparedigit(int *Test_Variable,int j)
{
   int i=0;
   while(Test_Variable[i]!=-1)
   {
    i++;
   }
   Test_Variable[i] = j;
}
