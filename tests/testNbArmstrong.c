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
	long long test_time;
	test_time = time_start();
	puts("L: Debut du test");
	int Combinaison[9] = {1,4,6,5,1,1,2,0,8};
	CachePuissanceDigit cachePuissanceDigitExposant9;
	InitCachePuissanceDigit(&cachePuissanceDigitExposant9, 0, 9);
	// Tests
	assert(CalculNombreArmstrong(Combinaison,9, &cachePuissanceDigitExposant9) == 146511208);
	assert(EstUnNombreArmstrong(Combinaison,CalculNombreArmstrong(Combinaison,9,&cachePuissanceDigitExposant9),
	9) == TRUE);
	printf("%lld ms\n",time_end(test_time));
	puts("L: Fin du test");
	puts("");
}
