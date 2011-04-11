#include <assert.h>
#include <stdlib.h>

typedef struct tache_combinaison_est_nombre_armstrong
{
  char *combinaison;
  char ordre_courant;
  CachePuissanceDigit *cache_puissance_digit;
  CachePuissance10 *cache_puissance_10;
  long resultat; /* -1 si n'est pas un nombre d'armstrong, sinon valeur */
} TacheCombinaisonEstNombreArmstrong;

/* \brief Instancie un objet TacheCombinaisonEstNombreArmstrong*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Init(char ordre_courant, CachePuissanceDigit *cache_puissance_digit, CachePuissance10 *cache_puissance_10);

/* \brief D�salloue la m�moire associ�e � une tache
*/
TacheCombinaisonEstNombreArmstrong * TacheCombinaisonEstNombreArmstrong_Detruire(
  TacheCombinaisonEstNombreArmstrong * tache);

/* \brief Cr�e le clone d'une structure de type TacheCombinaison

L'adresse de cachePuissanceDigit et cachePuissance10 est recopi�
combinaison est clon� dans un nouveau tableau
*/
void TacheCombinaisonEstNombreArmstrong_Clone(TacheCombinaisonEstNombreArmstrong * tache_clone, 
  TacheCombinaisonEstNombreArmstrong * tache_parent);

/* \brief Recopie le contenu du tableau combinaison dans la combinaison de TacheCombinaisonEstNombreArmstrong
*/
void TacheCombinaisonEstNombreArmstrong_SetCombinaison(TacheCombinaisonEstNombreArmstrong * tache,
  char *combinaison);