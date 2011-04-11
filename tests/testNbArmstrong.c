#include <assert.h>
#include <stdio.h>
#include "../app/CalculArmstrong.h"
#include "../app/puissanceDigit.h"

/* Liste des prototypes*/
void testCalculArmstrong();

int main(void)
{
	testCalculArmstrong();
	return 0;
}

void testCalculArmstrong()
{
	puts("L: Debut du test");
	int Combinaison[3] = {7,0,3};
	CachePuissanceDigit cachePuissanceDigitExposant3;
	InitCachePuissanceDigit(&cachePuissanceDigitExposant3, 0, 3);
	// Tests
	assert(CalculNombreArmstrong(Combinaison,3, &cachePuissanceDigitExposant3) == 370);
	assert(EstUnNombreArmstrong(Combinaison,CalculNombreArmstrong(Combinaison,3,&cachePuissanceDigitExposant3),
	3) == TRUE);
	puts("L: Fin du test");
	puts("");
}
