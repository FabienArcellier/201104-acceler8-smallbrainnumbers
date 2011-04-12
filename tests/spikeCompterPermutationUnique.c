#include <assert.h>
#include <stdio.h>

#define VALEUR_FIN 1000000
#define ORDRE 20

int main()
{
	long long i = 0;
	long long compteur_armstrong_a_calculer = 0;
	char combinaison[ORDRE];
	
	for(i = 0; i < VALEUR_FIN; i++)
	{
		long long nombre = i;
		int j = 0;
		for(j=0;nombre!=0;nombre=nombre/10,j++)
		{
		  combinaison[j] = nombre % 10;
		}
		for(;j < ORDRE; j++)
		{
			combinaison[j] = 0;
		}
		
		for(j = 0; j < ORDRE - 1; j++)
		{
			if (combinaison[j] < combinaison[j+1] && combinaison[j+1] != 0)
			{
				break;
			}
			if (j == ORDRE - 2)
			{
				compteur_armstrong_a_calculer++;
			}
			
		}
		// printf("D: nombre %lld\n", i);
	}
	
	printf("Nombre de nombre a calculer : %lld\n", compteur_armstrong_a_calculer);
	
	return 0;
}
