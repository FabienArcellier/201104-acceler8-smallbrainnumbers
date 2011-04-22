/*! \file CalculArmstrong.c
	\author Maxime RIVIERE
*/

#include "CalculArmstrong.h"

/*! \brief Calcule le nombre d'Armstrong d'une combinaison à l'aide du cache des puissance
*/
char *CalculNombreArmstrong(char *Combinaison, int size,CachePuissanceDigit *cache)
{
	int i;
	char* ResCalcul;
	char* ResultatArmstrong = (char*) malloc (sizeof(char*)*size);
	for(i=0;i<size;i++)
	{
		ResultatArmstrong[i] = 0;
	}
	for(i=0;i<size;i++)
	{
		//printf("D: Combinaison[i] = %d\n", Combinaison[i]);
		GetPuissanceDigit(cache,&ResCalcul,Combinaison[i],size);
		ResultatArmstrong = addition_tableaux(ResCalcul,ResultatArmstrong,size);
				
	}
	return ResultatArmstrong;
}

/*! \brief Vérifie si le nombre trouvé est un nombre d'Armstrong ou non. Mise en tableau du Nombre à tester puis recherche de l'intersection entre les deux.
*/
bool EstUnNombreArmstrong(char *Combinaison,char *Combinaison_Armstrong, int size, CachePuissance10 *cache_puissance_10)
{
	bool test = FALSE;
	bool Armstrong = TRUE;
	int i = 0;
	int j = 0;
	char *Test_variable=(char *) malloc (sizeof(char)*size);
	if(Combinaison_Armstrong[size-1]!=0)
	{
		for(i=0;i < size && (Armstrong == TRUE );i++)
		{
			for(j=0;(j < size) && (test == FALSE);j++)
			{
				if((Combinaison[i] == Combinaison_Armstrong[j]) &&
				(used_comparedigit(Test_variable, j,size) == FALSE))
				{
					test = TRUE;
					add_comparedigit(Test_variable, j);
					break;
				}
			}
		
			if (test == FALSE)
			{
				Armstrong = FALSE;
			}
		
			test = FALSE;
		}
	}
	
	else
		Armstrong=FALSE;
	
	
	return Armstrong;
}

/*! \brief Initialisation du tableau de comparaison des digit déjà utilisé.
*/
void init_comparedigit(char *Test_variable,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		Test_variable[i] = -1;
	}
}

/*! \brief Vérification que le digit égal dans Combinatoire et Combinaison n'ai pas déja été utilisé pour un autre digit
*/
bool used_comparedigit(char *Test_variable, int j, int size)
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
void add_comparedigit(char *Test_Variable, int j)
{
	int i=0;
	while(Test_Variable[i] != -1)
	{
		i++;
	}
	
	Test_Variable[i] = j;
}
