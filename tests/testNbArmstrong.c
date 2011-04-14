#include <assert.h>
#include <stdio.h>
#include "../app/CalculArmstrong.h"
#include "../app/puissanceDigit.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testCalculArmstrong();

int main(void)
{
	testCalculArmstrong();
	return 0;
}

void testCalculArmstrong()
{
	
	int Combinaison[19] = {3,2,8,9,5,8,2,9,8,4,4,4,3,1,8,7,0,3,2};
	CachePuissanceDigit cachePuissanceDigitExposant19;
	InitCachePuissanceDigit(&cachePuissanceDigitExposant19, 0, 19);
	// Tests
	long long test_time;
	test_time = time_start();
	puts("L: Debut du test");
	assert(CalculNombreArmstrong(Combinaison,19, &cachePuissanceDigitExposant19) == 3289582984443187032LLU);
	assert(EstUnNombreArmstrong(Combinaison,CalculNombreArmstrong(Combinaison,19,&cachePuissanceDigitExposant19),
	19) == TRUE);
	printf("%lld ms\n",time_end(test_time));
	puts("L: Fin du test");
	puts("");
}
