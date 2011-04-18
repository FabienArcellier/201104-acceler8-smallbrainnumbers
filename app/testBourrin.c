#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#define LONGUEUR_DATA 10

void IncrementData (int data[]);
int RecherchePremierNonNul(int data[]);
long long CalculArmstrong(int data[], int n);

int main(void)
{
	long time_start = time(NULL);
	long time_end = 0;
	int data[LONGUEUR_DATA];
	int i = 0;
	for (i = 0; i < LONGUEUR_DATA; i++)
	{
		data[i]=0;
	}

	long long end = 5000000000LLU;
	long long k = 1;
	for (k = 1; k < end; k++)
	{
		IncrementData(data);
		int n = RecherchePremierNonNul(data);
		long long  Armstrong = CalculArmstrong(data, n);
		// printf("debug Armstrong %d - k %d\n", Armstrong, k);
		if (Armstrong == k)
		{
			printf("%lld\n", Armstrong);
		}
	}
	time_end = time(NULL);
	printf("Temps (s) : %ld\n", time_end - time_start);

	return 0;
}

void IncrementData (int data[])
{
	int i = 0;
	data[LONGUEUR_DATA - 1]++;
	// printf("Debug Tableau ");
	for (i = LONGUEUR_DATA - 1; i >= 0; i--)
	{
		// printf("%d",data[i]);
		if (data[i] == 10)
		{
			data[i] = 0;
			data[i - 1]++;
		}
	}
	// printf("\n");

	return;
}

int RecherchePremierNonNul(int data[])
{
	int i = 0;
	for(i = 0; i < LONGUEUR_DATA; i++)
	{
		if (data[i] != 0)
		{
			break;
		}
	}
	// printf("debug : %d\n", i);
	return LONGUEUR_DATA - i;
}

long long  CalculArmstrong(int data[], int n)
{
	int i = 0;
	long long result = 0;
	for (i = 0; i < n; i++)
	{
		result = result + pow(data[LONGUEUR_DATA -1 -i], n);
	}
	// printf("debug Armstrong :  %d\n", result);

	return result;
}
