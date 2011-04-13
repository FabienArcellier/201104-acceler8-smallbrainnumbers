#include <assert.h>
#include <stdio.h>
#include "../app/puissanceDigit.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testPuissanceDigitExposant5();

int main(void)
{
	testPuissanceDigitExposant5();
	return 0;
}

void testPuissanceDigitExposant5()
{	
	puts("L: Debut du test testPuissanceDigitExposant5");
	long long test_time;
  test_time= time_start();
  
	CachePuissanceDigit cachePuissanceDigitExposant5;
	InitCachePuissanceDigit(&cachePuissanceDigitExposant5, 3, 5);
	
	// Tests
	// printf("D: GetPuissanceDigit(&cachePuissanceDigitExposant5, 4, 3) = %ld\n",
	//	GetPuissanceDigit(&cachePuissanceDigitExposant5, 4, 3));
	assert(GetPuissanceDigit(&cachePuissanceDigitExposant5, 4, 3) == 64);
	assert(GetPuissanceDigit(&cachePuissanceDigitExposant5, 0, 3) == 0);
	assert(GetPuissanceDigit(&cachePuissanceDigitExposant5, 0, 5) == 0);
	assert(GetPuissanceDigit(&cachePuissanceDigitExposant5, 4, 5) == 1024);
	
	DetruireCachePuissanceDigit(&cachePuissanceDigitExposant5);
	
	printf("T: %lld\n", time_end(test_time));
	puts("L: Fin du test testPuissanceDigitExposant5");
	puts("");
}
