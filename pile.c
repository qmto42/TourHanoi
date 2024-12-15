#include "pile.h"

Pile pileVide(void)
{
    return NULL;
}

Pile ajouterEnTete(Pile p, int x)
{
    Maillon *m = (Maillon*)malloc(sizeof(Maillon));
    if (m == NULL)
    {
        printf("Erreur d'allocation de memoire dans une pile\n");
        exit(1);
    }
    m->v = x;
    m->suiv = p;
    return m;
}


Pile supprimerEnTete(Pile p)
{
    Maillon *aux;

    if(p==NULL)
    {
        printf("opération interdit\n");
        exit (1);
    }

    aux = p->suiv;
    free(p);
    return aux;
}

Bool vide(Pile p) // vide ou pas ?
{
    if (p==NULL)
        return true;
    else
        return false;
}

int longueur(Pile p)
{
    if (p==NULL) return 0;
    return 1 + longueur(p->suiv);
}

int tete(Pile p)
{
    if (vide(p))
    {
        printf("opération interdite\n");
        exit (1);
    }
    return p->v;
}

Bool existe(Pile p, int x)
{
    if (p==NULL)
        return false;
    
    if (x < p->v)
        return false;

    if (x == p->v)
        return true;
    
    return existe(p->suiv,x);
}

void afficherPile(Pile p)
{
    if (vide(p))
        printf("pile vide");

    while (p!=NULL)
    {
        printf("%d ",p->v);
        p=p->suiv;
    }
    
}

Pile dupliquerPile(Pile p)
{
    if (p == NULL) return NULL;

    Pile copie = pileVide();
    Pile temp = pileVide();
    Pile parcours = p;

    while (!vide(parcours))
    {
        temp = ajouterEnTete(temp, tete(parcours));
        parcours = parcours->suiv;
    }

    while (!vide(temp))
    {
        copie = ajouterEnTete(copie, tete(temp));
        temp = supprimerEnTete(temp);
    }

    return copie;
}
