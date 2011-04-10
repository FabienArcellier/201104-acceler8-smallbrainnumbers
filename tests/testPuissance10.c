#include <assert.h>
#include <stdio.h>
#include "../app/puissance10.h"

/* Liste des prototypes*/
void testPuissance10Exposant5();

int main(void)
{
	testPuissance10Exposant5();
	return 0;
}

void testPuissance10Exposant5()
{
	puts("L: Debut du test testPuissance10Exposant5");
	CachePuissance10 cachePuissance10Exposant5;
	InitCachePuissance10(&cachePuissance10Exposant5, 5);
	
	// Tests
	assert(GetPuissance10(&cachePuissance10Exposant5,0) == 1);
	assert(GetPuissance10(&cachePuissance10Exposant5,1) == 10);
	assert(GetPuissance10(&cachePuissance10Exposant5,5) == 100000);
	
	DetruireCachePuissance10(&cachePuissance10Exposant5);
	
	puts("L: Fin du test testPuissance10Exposant5");
	puts("");
}
