//
//  option.c
//  Maze
//
//  Created by Rémi on 25/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fichier de gestion des options                                  //
//=================================================================//


void options()
{
    int choix = 0;
    

    FctVideEcran();
    
    do
    {
        // Affichage de "OPTIONS" en ASCII //
        
        printf("                        _   _\n             ___  _ __ | |_(_) ___  _ __  ___\n            / _ \\| '_ \\| __| |/ _ \\| '_ \\/ __|\n           | (_) | |_) | |_| | (_) | | | \\__ \\\n            \\___/| .__/ \\__|_|\\___/|_| |_|___/\n                 |_|\n\n");
    
        printf("\tFaites votre choix :\n\n\n");
        printf("\t1 - High Score\n");
        printf("\t2 - Credits\n");
        printf("\t3 - Cheat Codes\n");
        printf("\t4 - Retour\n\n");
        printf("\t Veuillez entrez votre choix : ");
    
        scanf("%i",&choix);
    
    
        switch(choix)
        {
            case 1: menu_highscore(); break;
            case 2: credits(); break;
            case 3: cheat(); break;
            case 4: break;
            default:
                FctVideEcran();
                viderBuffer();
                printf("Erreur: votre choix doit être compris entre 1 et 4\n");
                char tempo = get_one_char();
                FctVideEcran();
                break;
        }
    
        FctVideEcran();
    }while(choix != 4);
}

//=================================================================//
// Fonctions de gestion des différents Cheats                      //
//=================================================================//

void chucknorris()
{
    
}

void bitchplease()
{
    
}

void godmode()
{
    
}

void veryeasy()
{
    
}

//=================================================================//
// Fonctions du menu des Cheats                                    //
//=================================================================//


void cheat()
{
    int choix = 0;
    
    FctVideEcran();
    
    printf("\n\n\tC'est pas bien de tricher !\n\n");
    printf("Appuyez sur une touche pour continuer...\n\n");
    viderBuffer();
    char tempo = get_one_char();
    FctVideEcran();
    
    do
    {
    
        // Affichage de "CHEAT" en ASCII //
        printf("                 ____ _                _\n                / ___| |__   ___  __ _| |_\n               | |   | '_ \\ / _ \\/ _` | __|\n               | |___| | | |  __/ (_| | |_\n                \\____|_| |_|\\___|\\__,_|\\__|\n\n");
    
        
        printf("\tFaites votre choix :\n\n\n");
        printf("\t1 - Chuck Norris\n");
        printf("\t2 - Bitch Please\n");
        printf("\t3 - God Mode\n");
        printf("\t4 - Very Easy !\n"); // En fait Very Very 2HARD4U !!!
        printf("\t5 - Retour\n\n");
        printf("\t Veuillez entrez votre choix : ");
        
        scanf("%i",&choix);
        
        switch(choix)
        {
            case 1: chucknorris(); break;
            case 2: bitchplease(); break;
            case 3: godmode(); break;
            case 4: veryeasy();break;
            case 5: break;
            default:
                FctVideEcran();
                viderBuffer();
                printf("Erreur: votre choix doit être compris entre 1 et 5\n");
                char tempo = get_one_char();
                FctVideEcran();
                break;
        }
        
        FctVideEcran();
    }while(choix != 5);
}


//=================================================================//
// Fonctions de gestion des Highscores                             //
//=================================================================//


void menu_highscore()
{
    int choix;
    
    FctVideEcran();
    
    do
    {
        printf("                _   _ ___ ____ _   _   ____   ____ ___  ____  _____\n               | | | |_ _/ ___| | | | / ___| / ___/ _ \\|  _ \\| ____|\n               | |_| || | |  _| |_| | \\___ \\| |  | | | | |_) |  _|\n               |  _  || | |_| |  _  |  ___) | |__| |_| |  _ <| |___\n               |_| |_|___\\____|_| |_| |____/ \\____\\___/|_| \\_\\_____|\n\n");
        
        printf("\tFaites votre choix :\n\n\n");
        printf("\t1 - Afficher les High Score\n");
        printf("\t2 - Reset\n");
        printf("\t3 - Retour\n\n");
        printf("\t Veuillez entrez votre choix : ");
        
        scanf("%i",&choix);
        
        switch(choix)
        {
            case 1: afficher_highscore(); break;
            case 2: reset(); break;
            case 3: break;
            default:
                FctVideEcran();
                viderBuffer();
                printf("Erreur: votre choix doit être compris entre 1 et 3\n");
                char tempo = get_one_char();
                FctVideEcran();
                break;
        }
        
        FctVideEcran();
    }while(choix != 3);
}



void afficher_highscore()
{
    int i = 1;
    char tempo;
    char chaine[TAILLE_MAX] = "";
    
    FILE* fichier = NULL;
	fichier = fopen("highscore.txt","r");
    
	if (fichier == NULL)
    {
        FctVideEcran();
        printf("\n\n\tImpossible d'ouvrir le fichier highscore.txt\n\n");
        printf("Appuyez sur une touche pour revenir aux options...");
        viderBuffer();
        tempo = get_one_char();
        FctVideEcran();
    }
    else
    {
        FctVideEcran();
        
        printf("                _   _ ___ ____ _   _   ____   ____ ___  ____  _____\n               | | | |_ _/ ___| | | | / ___| / ___/ _ \\|  _ \\| ____|\n               | |_| || | |  _| |_| | \\___ \\| |  | | | | |_) |  _|\n               |  _  || | |_| |  _  |  ___) | |__| |_| |  _ <| |___\n               |_| |_|___\\____|_| |_| |____/ \\____\\___/|_| \\_\\_____|\n\n");
        
        sleep(1);
        
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {
            printf("\t%i\t--\t%s",i, chaine);
            i++;
            
            sleep(1);
        }
        
        printf("\n\nAppuyez sur une touche pour revenir aux options...");
        viderBuffer();
        tempo = get_one_char();
        FctVideEcran();
    }
}

void  reset()
{
    int choix;
    char reponse;
    
    do
    {
        FctVideEcran();
        viderBuffer();
        
        printf("\n\tÊtes vous sûr de vouloir effacer tous les (misérables) scores effectués jusqu'à ce jour ? Y/N \n\n");
        reponse = get_one_char();
        FctVideEcran();
        if(reponse == 'y' || reponse == 'Y')
        {
            FILE *fichier;
            fichier = fopen("highscore.txt","w");
            fclose(fichier);
            printf("\n\tTous vos scores ont bien été effacés. \n\n");
        }
        else if(reponse == 'n' || reponse == 'N')
        {
            printf("\n\tLes scores n'ont pas été effacés. \n\n");
        }
        else
        {
            printf("\n\tVeuillez entrez un 'y' (yes) ou un 'n' (no)\n\n");
        }
        
        sleep(3);
    }while(reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N');

}

