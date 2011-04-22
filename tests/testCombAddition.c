#include <assert.h>
#include <stdio.h>
#include "../app/combinaison.h"
#include "../app/ordonnanceur.h"
#include "../app/timer.h"

/* Liste des prototypes*/
void testCombinaison();

int main(void)
{
	testCombinaison();
	return 0;
}

void testCombinaison()
{
  puts("L: Debut du test testCombinaison");
  long long test_time;
  test_time = time_start();
	
	// Tests
	char test[4]={9,0,9,9};
	char test2[4]={0,6,9,9};
	char *test3;
	test3=(char*) malloc(sizeof(char)*4);
	test3=addition_tableaux(test,test2,4);
	int i;	
	for(i=0;i<4;i++)
		printf("%d",test3[i]);
	affichage_Armstrong(test3,4);

	printf("\nT: %lld\n", time_end(test_time));
  puts("L: Fin du test testCombinaison");
  puts("");
  
}
