
//
//  Created by Rémi on 16/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fonction gère le menu du jeu                                    //
//=================================================================//


void launch()
{
    int i, compte=0;

    for(i=0;i<5;i++)
    {
        FctVideEcran();
        compte = 0;

        while(compte<i)
        {
            printf("\n");
            compte++;
        }
    printf("\tRénice inc. present :\n");
    sleep(1);
    }

    sleep(1);
    
    FctVideEcran();
    printf("\n\n\n\n");
    printf("\tAn Original Game Production\n");
    sleep(3);
    FctVideEcran();
    printf("\n\n\n\n");
    printf("\tCopyright © All Right Reserved - Since 2012\n");
    sleep(3);
    
    for(i=0;i<5;i++)
    {
        FctVideEcran();
        compte = 0;
        
        while(compte<i)
        {
            printf("\n");
            compte++;
        }
        printf("\n\t #######  ##     ##    ###    ########  ########  ##        ##     ##\n\t##     ## ##     ##   ## ##   ##     ## ##     ## ##    ##  ##     ##\n\t       ## ##     ##  ##   ##  ##     ## ##     ## ##    ##  ##     ##\n\t #######  ######### ##     ## ########  ##     ## ##    ##  ##     ##\n\t##        ##     ## ######### ##   ##   ##     ## ######### ##     ##\n\t##        ##     ## ##     ## ##    ##  ##     ##       ##  ##     ##\n\t######### ##     ## ##     ## ##     ## ########        ##   #######\n");
        sleep(1);
    }
    
    sleep(3);
}

void menu(void)
{    
    int ichoix;
    int compteur = 0;
    char reponse = 0;
    sLabyrinthe sLaby;
    

    do // Affichage du menu et saisie du choix
    {
        FctVideEcran();
        
        printf("\t\t     ___  ___   _____   __   _   _   _\n");
        printf("\t\t    /   |/   | | ____| |  \\ | | | | | |\n");
        printf("\t\t   / /|   /| | | |__   |   \\| | | | | |\n");
        printf("\t\t  / / |__/ | | |  __|  | |\\   | | | | |\n");
        printf("\t\t / /       | | | |___  | | \\  | | |_| |\n");
        printf("\t\t/_/        |_| |_____| |_|  \\_| \\____/\n\n\n\n\n");
        printf("- 1 - Nouveau jeu\n");
        printf("- 2 - Charger\n");
        printf("- 3 - Options\n");
        printf("- 4 - Quitter\n");
        printf("\n\n");
        printf("Votre choix : ");
        scanf("%i",&ichoix);
        
        printf("\n\n\n");
        
        /* Traitement du choix de l'utilisateur */
        switch(ichoix)
        {
            case 1:
                FctVideEcran();
                sLaby = nouveau_jeu();
                lets_play(sLaby);
                compteur++;
                break;
                
            case 2:
                if(sLaby.taille > 0 )
                {
                    liberer(sLaby);
                }
                
                FctVideEcran();
                sLaby = load_laby();
                
                if(sLaby.taille > 0 )
                {
                    lets_play(sLaby);
                    compteur++;
                }
                
                break;
                
            case 3: options();
                break;
            case 4:
                if(compteur > 0)
                    liberer(sLaby);
                break;
            default:
                FctVideEcran();
                viderBuffer();
                printf("Erreur: votre choix doit être compris entre 1 et 4\n");
                char tempo = get_one_char();
                FctVideEcran();
                break;
        }
    }while(ichoix!=4);
    
    
    printf("Au revoir !\n");
    sleep(2);
    
}

