#include "Hanoi.h"

void global(void)
{
    int menu=0;
    while (menu != 2)
    {
        afficherMenu();
        scanf("%d", &menu);
        printf("\n");

        if (menu == 1)
        {
            partie();
            menu = 0;
        }
    }
}

void afficherMenu(void)
{
    printf("\n//----------| Tour de Hanoi |----------//\n");
    printf("\t1) Jouer une partie\n");
    printf("\t2) Quitter\n");
    printf("\tChoix :");
}

void partie(void)
{
    int i;
    int taillet2;
    int taillet3;

    // création des tour
    Pile t1=pileVide();
    Pile t2=pileVide();
    Pile t3=pileVide();

    // remplir la tour 1
    for (i=6 ; i>0 ; i--)
        t1 = ajouterEnTete(t1, i);  

    taillet2 = longueur(t2);
    taillet3 = longueur(t3);

    while (taillet2 != 6 && taillet3 != 6)
    {   
        affichageTour(t1,t2,t3);

        // Selectionné une tour sur laquelle on va récupéré le disque
        int ts; // Tour sélectionné par le joueur
        Bool tsVide = true; // tour sélectionné Vide ? par défaut vrai pour le while

        while (tsVide == true) // Tant que le joueur n'aura pas selectionné un tour qui n'est pas vide
        {
            printf("\nSelectionné une Tour :");
            
            scanf("%d",&ts); //Sélection entre tour 1, 2 ou 3

            switch (ts) // Suivant la tour sélectionné par le joueur
            {
            case 1 :
                tsVide = vide(t1); // tsVide sera vrai si la pile est vide / faux si elle a au moins une valeur
                break;
            case 2 :
                tsVide = vide(t2);
                break;
            case 3 :
                tsVide = vide(t3);
                break;
            default:
                tsVide = true;
                printf("Veuillez choisir entre la tour 1, 2 ou 3");
                break;
            }
            
            if ((ts == 1 || ts == 2 || ts == 3 ) && tsVide == true) // Si le joueur a selectionné une tour qui est vide
                printf("La tour sélectionné est vide");
        }

        // Apres avoir selectionné une tour valide
        // On récupère le disque en tête de la tour selectionné

        int disqueS; // pour enregestrer la valeur du disque en tête de la tour selectionné

        switch (ts) // suivant la tour sélectionné
            {
            case 1 :
                disqueS = tete(t1); // disqueS = valeur du disque en tête de la tour
                t1 = supprimerEnTete(t1); // On supprime le disque en tête de la tour
                break;
            case 2 :
                disqueS = tete(t2);
                t2 = supprimerEnTete(t2);
                break;
            case 3 :
                disqueS = tete(t3);
                t3 = supprimerEnTete(t3);
                break;
            default:
                printf("Veuillez choisir entre la tour 1, 2 ou 3");
                break;
            }

        int tc; // Tour ciblé par le joueur pour recevoir le disque
    Bool tcv = false; // Validité de la tour ciblé, par défaut invalide
    int tct; // tête de la tour ciblé

    while (tcv == false) // vérifie si la tour ciblé est valide pour recevoir le disque
    {   
        printf("Tour ciblé :");
        scanf("%d",&tc);                // cible une tour dans laquelle on veut poser le disque qu'on vient de récupéré
        printf("\n");

        switch (tc)
        {
        case 1:
            if (vide(t1) == false)      // on vérifie si la tour que l'on cible est vide
                tct = tete(t1);         // si elle est pas vide, on récupère la valeur du disque en tête de la tour ciblée
            else tct = 7;               // si elle est vide, on lui attribu 7 (pour etre sûr de pouvoir poser le disque qu'on avait récupéré)
            break;
        case 2:
            if (vide(t2) == false)
                tct = tete(t2);
            else tct = 7;
            break;
        case 3:
            if (vide(t3) == false)
                tct = tete(t3);
            else tct = 7;
            break;
        default:
            printf("Veuillez choisir entre la tour 1, 2 ou 3");
            break;
        }

        if (disqueS > tct) // on vérifie si le disque que l'on a récupéré est plus lourd que celui de la tour sur laquelle on veut l'empiller
            printf("La disque de la tour sélectionné est plus grand que le disque de la tour ciblé\n");
        else 
            tcv = true; // validation de la condition de sortie du while
    }

    if (tc == 1)
        t1 = ajouterEnTete(t1,disqueS);
    else if (tc == 2)
        t2 = ajouterEnTete(t2,disqueS);
    else if (tc == 3)
        t3 = ajouterEnTete(t3,disqueS);

        taillet2 = longueur(t2);
        taillet3 = longueur(t3);

    } 
    affichageTour(t1,t2,t3);
    printf("\nBravo vous avez réussi\n");
}

void affichageTour(Pile t1, Pile t2, Pile t3) // 100% fonctionnel
{
    int i, taille, sommet;

    Pile tt1 = dupliquerPile(t1);
    Pile tt2 = dupliquerPile(t2);
    Pile tt3 = dupliquerPile(t3);

    for (i = 6; i > 0; i--)
    {
        taille = longueur(tt1);
        if (taille == i)
        {
            sommet = tete(tt1);
            affichageBaton(sommet);
            tt1 = supprimerEnTete(tt1);
        }
        else printf("      |      ");

        printf(" ");

        taille = longueur(tt2);
        if (taille == i)
        {
            sommet = tete(tt2);
            affichageBaton(sommet);
            tt2 = supprimerEnTete(tt2);
        }
        else printf("      |      ");

        printf(" ");

        taille = longueur(tt3);
        if (taille == i)
        {
            sommet = tete(tt3);
            affichageBaton(sommet);
            tt3 = supprimerEnTete(tt3);
        }
        else printf("      |      ");

        printf("\n");
    }

    // Libérer la mémoire allouée
    while (!vide(tt1)) tt1 = supprimerEnTete(tt1);
    while (!vide(tt2)) tt2 = supprimerEnTete(tt2);
    while (!vide(tt3)) tt3 = supprimerEnTete(tt3);
}

void affichageBaton(int x) // 100% fonctionnel
{
    int i;

    for (i=6 ; i>0 ; i--)
    {
        if (x>=i)
            printf("-");
        else printf(" ");
    }

    printf("|");

    for (i=0 ; i<6 ; i++)
    {
        if (x>i)
            printf("-");
        else printf(" ");
    }
}
    

