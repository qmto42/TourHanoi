#include "stdlib.h"
#include "stdio.h"

typedef enum{
    true = 1,
    false = 0
} Bool;

typedef struct maillon{
    int v;
    struct maillon *suiv;
} Maillon, *Pile;

Pile pileVide(void);
Pile ajouterEnTete(Pile p, int x);
Pile supprimerEnTete(Pile p);
Bool vide(Pile p);
int longueur(Pile p);
int tete(Pile p);
Bool existe(Pile p, int x);
void afficherPile(Pile p);
Pile dupliquerPile(Pile p) ;