/*! \file NombreCombinaison.c
    \author Maxime RIVIERE
*/

#include "NombreCombinaison.h"


/*! \brief Fonctions de calcul du nombre de combinaison pour une taille donnée

  Vous devez éviter de manipuler directement une instance de ce type la.
  Utilisez les fonctions ci-dessous.
*/

/*! \brief Calcule du nombre de combinaison à calculer pour un nombre de digit donné (objectif => choix entre itératif et en combinaison unique pour ordre de valeur min et ordre valeur max)
*/

int nombreCombinaisonsDunNombreDigit(int size)
{
	int i,ordre=0,tableau =2, resultat =0;
	int Tab_Calcul1[11], Tab_Calcul2[11];
	Tab_Calcul1[0]=0;
	Tab_Calcul2[0]=0;
	if(size==0)
	{
		return 0;
	}
	for(i=1;i<=10;i++)
	{
		Tab_Calcul1[i]=1;
	}
	ordre+=1;
	while(ordre<=size)
	{
		for(i=1;i<=10;i++)
		{
			Tab_Calcul2[i]=Tab_Calcul1[i]+Tab_Calcul2[i-1];
		}
		ordre+=1;
		if(ordre<=size)
		{
			for(i=1;i<=10;i++)
			{
				Tab_Calcul1[i]=Tab_Calcul2[i]+Tab_Calcul1[i-1];
			}
			ordre+=1;
		}
		else tableau=1;
	}
	if (tableau == 1)
	{
		for(i=1;i<=10;i++)
		{
			resultat = resultat +Tab_Calcul1[i];
		}
	}
	else
	{
		for(i=1;i<=10;i++)
		{
			resultat = resultat +Tab_Calcul2[i];
		}
	}
	return resultat;
}	
