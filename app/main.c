#include "main.h"

/*

*/
int main(int argc, char * argv[])
{
	// Decouper les arguments en utilisant les espaces
		// Si le nombre d'argument est != 2, afficher_aide
		// Si l'un des arguments contient un caractere non numerique, afficher_aide_format_nombre_incorrecte
	// Si le premier argument est superieur au deuxieme argument, afficher_aide_nombre_incoherent 
	// Calculer le log10(borne_inferieure) + 1 -> ordre_initiale
	// Calculer le log10(borne_superieure) + 1 -> ordre_finale
	
	// Initialiser de le cache des puissances_digit
}

void afficher_aide()
{
	puts("./Smallbrain borne_inferieure borne_superieure");
	puts("");
	puts("borne_inferieure : Nombre entier ou l'on commence la recherche [1;9223372036854779999LL]");
	puts("borne_superieure : Nombre entier ou l'on termine la recherche [1;9223372036854779999LL]");
	puts("");
	puts("Remarque : borne_inferieure doit etre inferieur ou egal a borne_superieure");
	puts("Remarque : les nombres s'écrivent avec leur forme pleine 567, 456.");
	puts("	N'utilisez pas de notation scientifique 1.5E23);
}

void afficher_aide_format_nombre_incorrecte()
{
	puts("le format de nombre que vous avez utilise n'est pas correcte");
	puts("");
	afficher_aide();
}

void afficher_aide_nombre_incoherent(long long borne_inferieure, long long borne_superieure)
{
	printf("%lld n'est pas inferieur a %lld\n\n", borne_inferieure, borne_superieure);
	afficher_aide();
}
