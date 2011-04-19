#include <assert.h>
#include <stdio.h>
#include "../app/CalculArmstrong.h"
#include "../app/puissanceDigit.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testCalculArmstrong();
void testCalculArmstrong23();
void testCalculArmstrong4150();

int main(void)
{
	testCalculArmstrong();
	testCalculArmstrong23();
  testCalculArmstrong4150();
	return 0;
}

void testCalculArmstrong()
{
	char Combinaison[19] = {3,2,8,9,5,8,2,9,8,4,4,4,3,1,8,7,0,3,2};
	CachePuissanceDigit *cachePuissanceDigitExposant19;
	cachePuissanceDigitExposant19 = InitCachePuissanceDigit(0, 19);
	
	// Tests
	long long test_time;
	test_time = time_start();
	
	puts("L: Debut du test");
	assert(CalculNombreArmstrong(Combinaison,19, cachePuissanceDigitExposant19) == 3289582984443187032LLU);
	assert(EstUnNombreArmstrong(Combinaison,CalculNombreArmstrong(Combinaison,19,cachePuissanceDigitExposant19),19) == TRUE);
	printf("%lld us\n",time_end(test_time));
	puts("L: Fin du test");
	puts("");
}

void testCalculArmstrong23()
{
	char Combinaison[2] = {3,2};
	CachePuissanceDigit *cachePuissanceDigitExposant19;
	cachePuissanceDigitExposant19 = InitCachePuissanceDigit(0, 19);
	
	// Tests
	long long test_time;
	test_time = time_start();
	
	puts("L: Debut du test testCalculArmstrong23");
	
	assert(CalculNombreArmstrong(Combinaison,2, cachePuissanceDigitExposant19) == 13);
	assert(EstUnNombreArmstrong(Combinaison,CalculNombreArmstrong(Combinaison,2,cachePuissanceDigitExposant19),
	2) == FALSE);
	
	printf("%lld us\n",time_end(test_time));
	puts("L: Fin du test testCalculArmstrong23");
	puts("");
}

void testCalculArmstrong4150()
{
	char Combinaison[5] = {0,5,1,4,0};
	CachePuissanceDigit *cachePuissanceDigitExposant19;
	cachePuissanceDigitExposant19 = InitCachePuissanceDigit(0, 19);
	
	// Tests
	long long test_time;
	test_time = time_start();
	
	puts("L: Debut du test testCalculArmstrong4150");
	
	assert(CalculNombreArmstrong(Combinaison,5, cachePuissanceDigitExposant19) == 4150);
	assert(EstUnNombreArmstrong(Combinaison,CalculNombreArmstrong(Combinaison,5,cachePuissanceDigitExposant19),
	5) == FALSE);
	
	printf("%lld us\n",time_end(test_time));
	puts("L: Fin du test testCalculArmstrong4150");
	puts("");
}
