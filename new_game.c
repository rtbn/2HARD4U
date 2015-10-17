//
//  new_game.c
//  Projet_info
//
//  Created by Rémi on 12/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fonction de création de pseudo                                  //
//=================================================================//

char *pseudo ()
{
    char *name;
    char pseudo[20];
    
    //affichage du titre en ascii
    
    aff_ng();
    
    printf("Saisir votre pseudo, 20 caractères maximum : ");
    scanf("%s", pseudo);
    
    //allocation dynamique pour le pseudo
    
	name = (char *)malloc(sizeof(pseudo));
	strcpy(name, pseudo);
	return name;
}

//=================================================================//
// Fonction qui gère la taille du labyrinthe                       //
//=================================================================//

/* 
*  Rien de bien compliqué içi, on affiche le menu de selection du niveau
*  Puis on enregistre la difficulté, qui sera la taille du labyrinthe, dans la variable
*  de la structure
*/

int difficult()
{

    int ichoix;
    int itaille;
    
    aff_ng();

    printf("Maintenant, choisis ton niveau:\n\n- 1 -  Facile\n- 2 -  Moyen");
    printf("\n- 3 -  Difficile\n- 4 -  Impossible\n- 5 -  Aléatoire \n\n");
    printf("Saisir votre choix : ");
    scanf("%i", &ichoix);
    switch(ichoix)
    {
        case 1: itaille = 5; break;
        case 2: itaille = 10; break;
        case 3: itaille = 15; break;
        case 4: itaille = 25; break;
        case 5: itaille=rand()%20+5; break;  //Chiffre choisit aléatoirement entre 5 et 25
        default:
        {
            printf("Erreur: votre choix doit être compris entre 1 et 5\n");
            printf("T'as voulu faire le malin, alors tu auras une surprise... \n");
            itaille = 50;  //petit piège, si l'utilisateur se trompe, taille 50 directement
        }
            
    }
    printf("\nLabyrinthe de taille %i. \n", itaille);
    sleep(2);
    return(itaille);
}

//=================================================================//
// Fonction qui alloue dynamiquement la matrice                    //
//=================================================================//

//allocation dynamique de la matrice en fonction de la taille retournée par la fonction précédente

char** allocation_laby (int itaille)
{
    char **gLaby;
    int i;
    
    gLaby = malloc(sizeof(*gLaby)*itaille);
    for (i = 0; i < itaille; i++)
    {
        gLaby[i] = malloc(sizeof(**gLaby)*itaille);
    }
    
    return gLaby;
}

//=================================================================//
// Fonction de gestion de nouvelle partie                          //
//=================================================================//

//Fonction qui retourne la structure de jeu qui premettra de jouer la partie par la suite

sLabyrinthe nouveau_jeu()
{
    char* cpseudo;
    char* ccreation;
    char **gLaby;
    int itaille;
    sLabyrinthe Resultat;

    
    FctVideEcran();
    
    //On lance la partie, en remplissant tout ce qui est demandé
    
    cpseudo = pseudo();
    viderBuffer();
    FctVideEcran();
    itaille = difficult();
    FctVideEcran();
    ccreation = datage();

    gLaby = allocation_laby(itaille);
    
    //Puis on insert tout dans la variable de type structure, pour pouvoir l'utiliser dans le moteur
   
    Resultat.gLaby = gLaby;
    Resultat.taille = itaille;
    Resultat.pseudo = cpseudo;
    Resultat.creation = ccreation;
    Resultat.nv_partie = 1;
    Resultat.temps = 0;
    
    initialisation_carte(&Resultat);
    creerLaby(&Resultat);
    aff_ng();
    
    viderBuffer();
    printf("Prêt ? \n");
    printf("Alors appuie sur une touche quand tu l'es vraiment...\n");
    char tempo = get_one_char();

    decompte(5);

    printf("\n\n\n");
    
    return Resultat;
}


