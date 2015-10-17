//
//  moteur.c
//  Maze
//
//  Created by Rémi on 25/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Sous menu du jeu                                                //
//=================================================================//

/*
*   Toujours la même logique qui sera présentée
*   Les fonctions FctVideEcran() et getonechar() ne sont que des fonctions d'esthétiques
*   Elles ont pour but de rendre le jeu plus agréable visuelement et plus confortable pour l'utilisateur
*/
void help(sLabyrinthe sLaby, sHeros sHeros)
{
    int ichoix;
    char tempo;     /* Pour permettre d'attendre l'appuie d'une touche par l'utilisateur */
    FctVideEcran();
    
    do // Affichage du menu et saisie du choix
    {
        printf(" _   _      _       \n");
        printf("| | | | ___| |_ __  \n");
        printf("| |_| |/ _ \\ | '_ \\ \n");
        printf("|  _  |  __/ | |_) |\n");
        printf("|_| |_|\\___|_| .__/ \n");
        printf("             |_|    \n");
        printf("- 1 - Les touches\n");
        printf("- 2 - J'ai la clé ?\n");
        printf("- 3 - Trouver le chemin de la clé\n");
        printf("- 4 - Trouver le chemin de la porte\n");
        printf("- 5 - Effacer le chemin\n");
        printf("- 6 - Retour\n");
        printf("\n\n");
        printf("Votre choix : ");
        scanf("%i",&ichoix);
        
        printf("\n\n\n");
        
        
        /* Traitement du choix de l'utilisateur */
        switch(ichoix)
        {
            case 1:
                FctVideEcran();
                printf("Utilisez Z Q S D pour bouger...\n");
                viderBuffer();
                tempo = get_one_char();
                FctVideEcran();
                break;
                
            case 2:
                FctVideEcran();
                
                if(trouver_cle(sLaby) != 0)
                {
                    printf("Vous n'avez pas la clé ...\n");
                }
                else
                {
                    printf("Vous avez la clé !\n");
                }
                
                viderBuffer();
                tempo = get_one_char();
                FctVideEcran();
                break;
                
                //Pour les cas 3 & 4 on efface avant le chemin (si il y en a un) pour que cela soit plus lisible
                
            case 3:
                FctVideEcran();
                effacer_chemin(sLaby);
                trouver_chemin_cle(sLaby, sHeros);
                viderBuffer();
                tempo = get_one_char();
                FctVideEcran();
                break;
                
            case 4:
                FctVideEcran();
                effacer_chemin(sLaby);
                trouver_chemin_porte(sLaby, sHeros);
                viderBuffer();
                tempo = get_one_char();
                FctVideEcran();
                break;
                
            case 5:
                FctVideEcran();
                effacer_chemin(sLaby);
                printf("DONE\n");
                viderBuffer();
                tempo = get_one_char();
                FctVideEcran();
                break;
                
            case 6: break;
                
            default:
                FctVideEcran();
                viderBuffer();
                printf("Erreur: votre choix doit être compris entre 1 et 6\n");
                tempo = get_one_char();
                FctVideEcran();
                break;
        }
    }while(ichoix!=6);
}

//Fonction de sous menu faisant appelle à d'autre fonction. Traitement classique

int sous_menu(sLabyrinthe sLaby, sHeros sHeros, int temps)
{
    FctVideEcran();
    
    int ichoix, sortie = 0;
    char reponse;

    do
    {
        printf(" ______        ___   _ ____  \n");
        printf("|  _ \\ \\      / / \\ | |  _ \\ \n");
        printf("| |_) \\ \\ /\\ / /|  \\| | | | |\n");
        printf("|  __/ \\ V  V / | |\\  | |_| |\n");
        printf("|_|     \\_/\\_/  |_| \\_|____/ \n\n\n");
        printf("- 1 - Sauvegarder\n");
        printf("- 2 - Aide\n");
        printf("- 3 - Options\n");
        printf("- 4 - Revenir au jeu\n");
        printf("- 5 - Quitter la partie\n");
        printf("\n\n");
        printf("Votre choix : ");
        scanf("%i",&ichoix);
        
        printf("\n\n\n");
        
        switch(ichoix)
        {
            case 1:
                viderBuffer();
                FctVideEcran();
                save_laby(sLaby, temps);
                
                do
                {
                    printf("Voulez vous continuez ? Y/N \n\n");
                    reponse = get_one_char();
                    
                    if(reponse == 'y' || reponse == 'Y')
                    {
                        printf("CHAMPION !\n\n");
                        ichoix = 5;
                    }
                    else if(reponse == 'n' || reponse == 'N')
                    {
                        printf("Tapette...\n\n");
                        sleep(2);
                        sortie = 2;
                        ichoix = 5;
                    }
                } while (reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N');
                
                break;
                
            case 2:
                viderBuffer();
                FctVideEcran();
                help(sLaby, sHeros);
                FctVideEcran();
                break;
                
            case 3:
                viderBuffer();
                FctVideEcran();
                options();
                break;
                
            case 4:
                ichoix = 5;
                break;
                
            case 5 :
                viderBuffer();
                FctVideEcran();
                save_laby(sLaby, temps);
                
                do
                {
                    printf("Voulez vraiment partir ? Y/N \n");
                    reponse = get_one_char();
                    
                    if(reponse == 'y' || reponse == 'Y')
                    {
                        sortie = 2;
                    }
                    else if(reponse == 'N' || reponse == 'n')
                    {
                        printf("Good Guy !\n");
                        sleep(2);
                        ichoix = 5;
                    }
                } while (reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N');
                
                break;
                
            default: printf("Erreur: votre choix doit être compris entre 1 et 5\n");
        }
    }while(ichoix!=5);
    
    FctVideEcran();
    return sortie;
}

//Comme son nom l'indique, cette fonction met la partie pause

void game_pause()
{
    char car;
    
    FctVideEcran();
    
    printf(" ____   _   _   _ ____  _____ \n");
    printf("|  _ \\ / \\ | | | / ___|| ____|\n");
    printf("| |_) / _ \\| | | \\___ \\|  _|  \n");
    printf("|  __/ ___ \\ |_| |___) | |___ \n");
    printf("|_| /_/   \\_\\___/|____/|_____|\n");
    
    printf("\n\n\n");
    
    printf("Pour repartir, appuie sur une touche\n");
    
    car = get_one_char();
    FctVideEcran();
}


//=================================================================//
// Fonction de début de partie                                     //
//=================================================================//

void tout_placer(sLabyrinthe* Laby)
{
    //Placement de tout les éléments en fonction de la taille du labyrinthe de façon à ce que la clé soit toujours en bas à gauche
    //et la porte en haut à droite
    Laby->gLaby[0][0] += PRESENT;
    Laby->gLaby[0][Laby->taille-1] += PORTE;
    Laby->gLaby[Laby->taille-1][0] += CLE;
}

/* Cette fonction sert à trouver le Héros dans le labyrinthe afin de faciliter le traitement de celui ci */
sHeros trouver_heros(sLabyrinthe sLaby)
{
    int i,j;
    sHeros Heros;
    
    for(i=0;i<sLaby.taille; i++)
    {
        for(j=0;j<sLaby.taille;j++)
        {
            if(sLaby.gLaby[i][j] & PRESENT)
            {
                Heros.x = i;
                Heros.y = j;
            }
                
        }
    }
    return Heros;
}

/* Cette fonction sert à trouver la clé dans le labyrinthe afin de faciliter le traitement de fin de partie */
int trouver_cle(sLabyrinthe sLaby)
{
    int i,j;
    int trouver = 0;
    
    for(i=0;i<sLaby.taille; i++)
    {
        for(j=0;j<sLaby.taille;j++)
        {
            if(sLaby.gLaby[i][j] & CLE)
                trouver = 1;
        }
    }
    
    return trouver;
}

//=================================================================//
// Fonction de gestion du moteur                                   //
//=================================================================//

/*La porte n'est accessible que de la droite ou pas le bas
*La clé n'est accessible que de la gauche ou du haut
*Le traitement de ces objets n'est donc fait que 2 fois par cas
*
*Les fonctions de vidage d'écran ne sont appelées que pour "faire propre"
*Quant à la fonction de vidage de Buffer, elle sert à eviter que le message ne disparaisse aussi tôt qu'il apparait
*La variable tempo sert uniquement à teporiser le jeu, elle est senblable à Kbhit()
*/

int bouger(sLabyrinthe* sLaby, sHeros* sHeros, short Dir)
{
    *sHeros = trouver_heros(*sLaby);
    int sortie = 0;
    
    switch(Dir)
    {
        case DROIT:
            //Pour chaque case, on regarde si il n'y a pas de murs dans la direction souhaitée
            if(!(sLaby->gLaby[sHeros->x][sHeros->y] & DROIT))
            {
                if(sLaby->gLaby[sHeros->x][sHeros->y+1] & PORTE) //on vérifie si le joueur à la clé avant de faire le traitement de fin de partie
                {
                    if(trouver_cle(*sLaby) == 0)
                    {
                        FctVideEcran();
                        printf("Félicitation, tu as gagné...\n");
                        printf("TRICHEUR\n");
                        char tempo = get_one_char();
                        sortie = 1;
                    }
                    else
                    {
                        FctVideEcran();
                        printf("Manque la clé non ?\n");
                        printf("Petit Malin... Allez, file !\n");
                        char tempo = get_one_char();
                        sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                        sLaby->gLaby[sHeros->x][sHeros->y+1] += PRESENT;
                    }
                }
                else if(sLaby->gLaby[sHeros->x][sHeros->y+1] & ACCS)
                {
                    sLaby->gLaby[sHeros->x][sHeros->y+1] -= ACCS;
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x][sHeros->y+1] += PRESENT;
                }
                else
                {
                sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                sLaby->gLaby[sHeros->x][sHeros->y+1] += PRESENT;
                }
            }
            break;
            
        case GAUCHE:
            if(!(sLaby->gLaby[sHeros->x][sHeros->y] & GAUCHE))
            {
                if(sLaby->gLaby[sHeros->x][sHeros->y-1] & CLE)
                {
                    FctVideEcran();
                    printf("Bravo, vous avez la clé\n");
                    printf("Reste plus qu'à trouver le chemin de la porte... MOUAHAHAHAHA\n");
                    char tempo = get_one_char();
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x][sHeros->y-1] -= CLE;
                    sLaby->gLaby[sHeros->x][sHeros->y-1] += PRESENT;
                }
                else if(sLaby->gLaby[sHeros->x][sHeros->y-1] & ACCS)
                {
                    sLaby->gLaby[sHeros->x][sHeros->y-1] -= ACCS;
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x][sHeros->y-1] += PRESENT;
                }
                else
                {
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x][sHeros->y-1] += PRESENT;
                }
            } 
            break;
            
        case BAS:
            if(!(sLaby->gLaby[sHeros->x][sHeros->y] & BAS))
            {
                if(sLaby->gLaby[sHeros->x+1][sHeros->y] & CLE)
                {
                    FctVideEcran();
                    printf("Bravo, vous avez la clé\n");
                    printf("Reste plus qu'à trouver le chemin de la porte... MOUAHAHAHAHA\n");
                    char tempo = get_one_char();
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x+1][sHeros->y] -= CLE;
                    sLaby->gLaby[sHeros->x+1][sHeros->y] += PRESENT;
                }
                else if(sLaby->gLaby[sHeros->x+1][sHeros->y] & ACCS)
                {
                    sLaby->gLaby[sHeros->x+1][sHeros->y] -= ACCS;
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x+1][sHeros->y] += PRESENT;
                }
                else
                {
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x+1][sHeros->y] += PRESENT;
                }
            }
            break;
        
        case HAUT:
            if(!(sLaby->gLaby[sHeros->x][sHeros->y] & HAUT))
            {
                if(sLaby->gLaby[sHeros->x-1][sHeros->y] & PORTE)
                {
                    if(trouver_cle(*sLaby) == 0)
                    {
                        FctVideEcran();
                        printf("Félicitation, tu as gagné...\n");
                        printf("TRICHEUR\n");
                        char tempo = get_one_char();
                        sortie = 1;
                    }
                    else
                    {
                        FctVideEcran();
                        printf("Manque la clé non ?\n");
                        printf("Petit Malin... Allez, file !\n");
                        char tempo = get_one_char();
                        sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                        sLaby->gLaby[sHeros->x-1][sHeros->y] += PRESENT;
                    }
                    
                }
                else if(sLaby->gLaby[sHeros->x-1][sHeros->y] & ACCS)
                {
                    sLaby->gLaby[sHeros->x-1][sHeros->y] -= ACCS;
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x-1][sHeros->y] += PRESENT;
                }
                else
                {
                    sLaby->gLaby[sHeros->x][sHeros->y] -= PRESENT;
                    sLaby->gLaby[sHeros->x-1][sHeros->y] += PRESENT;
                }
            }
            break;
    }
    
    //affichage à chaque mouvement
    Affichage(*sLaby);
    return sortie;
}
//=================================================================//
// Fonction des chemins                                            //
//=================================================================//

/////////////////////////////////// Effacer le chemin  ///////////////////////////////////

void effacer_chemin(sLabyrinthe sLaby)
{
    int i, j;
    
    for(i=0; i<sLaby.taille; i++)
    {
        for(j=0; j<sLaby.taille; j++)
        {
            if(sLaby.gLaby[i][j] & ACCS)
                sLaby.gLaby[i][j] -= ACCS;
        }
    }
    
}

/////////////////////////////////// Trouver le Chemin de la clé ///////////////////////////////////

/*
*   Le traitement sera le même pour la fonction trouver_chemin_porte
*   Tout d'abord, on recopie initialise une seconde matrice qu'avec des 0
*   On cherche ensuite la place du héros, que l'on marque avec un 1
*   Ensuite, pour chaque case accessible, on regarde si la clé est présente, sinon, on marque les cases comem accessibles
*   Puis on réitere le traitement jusqu'à trouver la clé
*   Pour chaque case accessible, on avance incrémente l'indice de 1
*/

void trouver_chemin_cle(sLabyrinthe sLaby, sHeros sHeros)
{
    int i, j, k, l, m, pion, marque;
    int travel = 0;
    sChemin Chemin;
    int matrice[sLaby.taille][sLaby.taille];
    
    for(i=0; i<sLaby.taille; i++)
    {
        for(j=0; j<sLaby.taille; j++)
        {
            matrice[i][j] = 0;
        }
    }

    sHeros = trouver_heros(sLaby);
    Chemin.x = sHeros.x;
    Chemin.y = sHeros.y;
    
    matrice[Chemin.x][Chemin.y] = 1;
    
    pion = 1;

    while(travel != 1)
    {
        for(k=0;k<sLaby.taille; k++)
        {
            for(l=0;l<sLaby.taille; l++)
            {
                if(matrice[k][l] == pion)
                {
                    if(!(sLaby.gLaby[k][l] & BAS))
                    {
                        if(sLaby.gLaby[k+1][l] & CLE)
                        {
                            matrice[k+1][l] = pion + 1;
                            travel = 1;
                        }
                        else if(matrice[k+1][l] == 0)
                        {
                            matrice[k+1][l] = pion + 1;
                        }
                        
                    }
                    
                    if(!(sLaby.gLaby[k][l] & GAUCHE))
                    {
                        if(sLaby.gLaby[k][l-1] & CLE)
                        {
                            travel = 1;
                            matrice[k][l-1] = pion + 1;
                        }
                        else if(matrice[k][l-1] == 0)
                        {
                            matrice[k][l-1] = pion + 1;
                        }
                    }
                    
                    if(!(sLaby.gLaby[k][l] & HAUT))
                    {
                        if(matrice[k-1][l] == 0)
                        {
                            matrice[k-1][l] = pion + 1;
                        }
                    }
                    
                    if(!(sLaby.gLaby[k][l] & DROIT))
                    {
                        if(matrice[k][l+1] == 0)
                        {
                            matrice[k][l+1] = pion + 1;
                        }
                    }
                }
            }
        }

      pion++;
    }

    /*
    *   Dans cette partie, on se place à la position de la porte
    *   Puis, on trace le chemin dans le labyrinthe du joueur en suivant les valeurs décroissante
    *   jusqu'arriver à la position du héros
    */
    
    for(i=0;i<sLaby.taille; i++)
    {
        for(j=0;j<sLaby.taille;j++)
        {
            if(sLaby.gLaby[i][j] & CLE)
            {
                while(pion > 1)
                {
                    if(matrice[i-1][j] == pion - 1)
                    {
                        sLaby.gLaby[i-1][j] += ACCS;
                        pion--;
                        i--;
                    }
                    
                    if(matrice[i+1][j] == pion - 1)
                    {
                        sLaby.gLaby[i+1][j] += ACCS;
                        pion--;
                        i++;
                    }
                    
                    if(matrice[i][j-1] == pion - 1)
                    {
                        sLaby.gLaby[i][j-1] += ACCS;
                        pion--;
                        j--;
                    }
                    
                    if(matrice[i][j+1] == pion - 1)
                    {
                        sLaby.gLaby[i][j+1] += ACCS;
                        pion--;
                        j++;
                    }
                }
            }
        }
    }
 
 
    printf("C'est fait, tricheur...\n");
    
}

/////////////////////////////////// Trouver le Chemin de la porte ///////////////////////////////////

void trouver_chemin_porte(sLabyrinthe sLaby, sHeros sHeros)
{
    int i, j, k, l, m, pion;
    int travel = 0;
    sChemin Chemin;
    int matrice[sLaby.taille][sLaby.taille];
    
    for(i=0; i<sLaby.taille; i++)
    {
        for(j=0; j<sLaby.taille; j++)
        {
            matrice[i][j] = 0;
        }
    }
    
    sHeros = trouver_heros(sLaby);
    Chemin.x = sHeros.x;
    Chemin.y = sHeros.y;
    
    matrice[Chemin.x][Chemin.y] = 1;
    
    pion = 1;
    
    while(travel != 1)
    {
        for(k=0;k<sLaby.taille; k++)
        {
            for(l=0;l<sLaby.taille; l++)
            {
                if(matrice[k][l] == pion)
                {
                    if(!(sLaby.gLaby[k][l] & HAUT))
                    {
                        if(sLaby.gLaby[k-1][l] & PORTE)
                        {
                            matrice[k-1][l] = pion + 1;
                            travel = 1;
                        }
                        else if(matrice[k-1][l] == 0)
                        {
                            matrice[k-1][l] = pion + 1;
                        }
                        
                    }
                    
                    if(!(sLaby.gLaby[k][l] & DROIT))
                    {
                        if(sLaby.gLaby[k][l+1] & PORTE)
                        {
                            travel = 1;
                            matrice[k][l+1] = pion + 1;
                        }
                        else if(matrice[k][l+1] == 0)
                        {
                            matrice[k][l+1] = pion + 1;
                        }
                    }
                    
                    if(!(sLaby.gLaby[k][l] & BAS))
                    {
                        if(matrice[k+1][l] == 0)
                        {
                            matrice[k+1][l] = pion + 1;
                        }
                    }
                    
                    if(!(sLaby.gLaby[k][l] & GAUCHE))
                    {
                        if(matrice[k][l-1] == 0)
                        {
                            matrice[k][l-1] = pion + 1;
                        }
                    }
                }
            }
        }
        
        pion++;
    }
    
    for(i=0;i<sLaby.taille; i++)
    {
        for(j=0;j<sLaby.taille;j++)
        {
            if(sLaby.gLaby[i][j] & PORTE)
            {
                while(pion > 1)
                {
                    if(matrice[i-1][j] == pion - 1)
                    {
                        sLaby.gLaby[i-1][j] += ACCS;
                        pion--;
                        i--;
                    }
                    
                    if(matrice[i+1][j] == pion - 1)
                    {
                        sLaby.gLaby[i+1][j] += ACCS;
                        pion--;
                        i++;
                    }
                    
                    if(matrice[i][j-1] == pion - 1)
                    {
                        sLaby.gLaby[i][j-1] += ACCS;
                        pion--;
                        j--;
                    }
                    
                    if(matrice[i][j+1] == pion - 1)
                    {
                        sLaby.gLaby[i][j+1] += ACCS;
                        pion--;
                        j++;
                    }
                }
            }
        }
    }
    
    
    printf("C'est fait, tricheur...\n");
    
}

//=================================================================//
// Fonction d'ajout du score	                                   //
//=================================================================//


void ajout_highscore(int score,char* pseudo)
{
	int score_cour, place = 0, i=0;
    long pos;
	char c,pseudo_cour[TAILLE_MAX],insertion_txt[TAILLE_MAX];

    FILE* fichier = NULL;
    
    fichier = fopen("highscore.txt","r+");

    if (fichier == NULL)
    {
        printf("\n\n\tImpossible d'ouvrir le fichier highscore.txt");
        FctVideEcran();
    }
    else
    {
////////////// On cherche où placer le nouveau score //////////////////
        
            do
            {
                pos = ftell(fichier);
                place++;
                fscanf(fichier,"%i",&score_cour);
                fscanf(fichier,"%s",pseudo_cour);
            }while(score < score_cour && !feof(fichier));
        
            if(!feof(fichier))
            {
////////////// On copie la fin du fichier pour la remettre à la suite de l'insertion ////////

                if(pos == 0)
                {
                    fseek(fichier,pos,SEEK_SET);
                }else
                {
                    fseek(fichier,pos+1,SEEK_SET);
                }
                
                
                do
                {
                    c = fgetc(fichier);
                    insertion_txt[i] = c;
                    i++;
                }while(c != EOF);

/////////////// On se repositionne au bon endroit, on écrit le score et le pseudo, puis on réécrit la fin du fichier ////
                
                if(pos == 0)
                {
                    fseek(fichier,pos,SEEK_SET);
                }else
                {
                    fseek(fichier,pos+1,SEEK_SET);
                }

                fprintf(fichier,"%i\t",score);
                fprintf(fichier,"%s\n",pseudo);
        
                i = 0;
        
                while(insertion_txt[i] != EOF)
                {
                    fputc(insertion_txt[i],fichier);
                    i++;
                }
            }else
            {
                
//////////////// Si le score est le moins bon, on rajoute en fin de fichier ////////////////
                
                if(pos != 0)
                {
                    fseek(fichier,1,SEEK_CUR);
                }
                fprintf(fichier,"%i\t",score);
                fprintf(fichier,"%s\n",pseudo);
            }
        
        if(place == 1)
        {
            printf("\nVous obtenez la 1ère place !!!\n\n");
        }
        else if(place == 2)
        {
            printf("\nVous obtenez la 2nd place !!\n\n");
        }
        else
        {
            printf("\nVous obtenez la %ième place !\n\n",place);
        }
        fclose(fichier);
    }
}

//=================================================================//
// Moteur du jeu                                                   //
//=================================================================//

void lets_play(sLabyrinthe sLaby)
{
    char reponse;
    unsigned char car;
    int temps_sauve, choix,score, diff, sortie = 0;
    sHeros sHeros;
    sTemps Duree;
    time_t time1,time2, time3; //structure pourle temps

    //ici on verifie si il s'agit d'une nouvelle partie ou non, si c'est le cas, on met le chrono à 0
    if(sLaby.nv_partie == 1)
    {
        tout_placer(&sLaby);
        sLaby.temps = 0;
    }
    
    //sinon, on recupere le temps dans la structure
    temps_sauve = sLaby.temps;
    
    printf("Let's GO !\n");
    
    time (&time1);
    Affichage(sLaby);
    
    do {

        Affichage(sLaby);
        printf("\nZ Q S D uniquement pour jouer\nEchap pour le menu, 'H' pour l'aide et 'P' pour mettre en pause\n");
        car = get_one_char();
        
        //cette boucle est censé proteger de tout les caractères non traité
        //malheureusement, elle ne fonctionne pas pour les caractères étendus
        if (car == 'z' || car == 'q' || car ==  's' || car == 'd' || car == 'h' || car == 'p' || car == 27)
        {
        
            //traitement classique des touches pour faire bouger le bonhomme
            switch(car)
            {
                case 'z':
                    sortie = bouger(&sLaby, &sHeros, HAUT);
                    break;
                case 'q':
                    sortie = bouger(&sLaby, &sHeros, GAUCHE);
                    break;
                case 's':
                    sortie = bouger(&sLaby, &sHeros, BAS);
                    break;
                case 'd':
                    sortie = bouger(&sLaby, &sHeros, DROIT);
                    break;
                case 'h':
                    help(sLaby, sHeros);
                    break;
                case 'p':
                    game_pause();
                    break;
                case 27 :
                    time (&time2);
                    diff = difftime (time2,time1);
                    sortie = sous_menu(sLaby, sHeros, diff);
                    break;
                default: printf("Touche inconnue \n"); break;
            }
        }
        else
        {
            printf("Caractère incorrect\n");
        }
        
    } while (sortie != 1 && sortie != 2);
    
    //Traitement du temps en fonction de la condition de sortie
    if(sortie == 2)
    {
        FctVideEcran();
        printf("__   _____  _   _   _____ _    ___ _  \n");
        printf("\\ \\ / / _ \\| | | | |  ___/ \\  |_ _| |    \n");
        printf(" \\ V / | | | | | | | |_ / _ \\  | || |    \n");
        printf("  | || |_| | |_| | |  _/ ___ \\ | || |___ \n");
        printf("  |_| \\___/ \\___/  |_|/_/   \\_\\___|_____|\n\n");
        printf("It's obviously really 2HARD4U, noob..\n");
        
        //Traitement du temps afin de l'afficher en hh/mm/ss
        time (&time3);
        diff = difftime (time3,time1) + temps_sauve;
        if(diff < 60 && diff > 0)
        {
            Duree.seconde = diff;
            printf("Tu as mis %is avant de craquer.\n", Duree.seconde);
        }
        else if(diff > 60 && diff <3600)
        {
            Duree.seconde = diff % 60;
            Duree.minute = (diff / 60) % 60;
            printf("Tu as mis %imn%is avant de craquer ! \n", Duree.minute, Duree.seconde);
        }
        else if(diff > 3600)
        {
            Duree.seconde = diff % 60;
            Duree.minute = (diff / 60) % 60;
            Duree.heure = (diff / 3600);
            printf("Tu as mis %iH%imn%is avant de craquer... \n", Duree.heure, Duree.minute, Duree.seconde);
        }
    }
    else if(sortie == 1)
    {
        FctVideEcran();
        printf(" ____  _   _  ____ ____ _____ ____ ____  \n");
        printf("/ ___|| | | |/ ___/ ___| ____/ ___/ ___| \n");
        printf("\\___ \\| | | | |  | |   |  _| \\___ \\___ \\ \n");
        printf(" ___) | |_| | |__| |___| |___ ___) |__) |\n");
        printf("|____/ \\___/ \\____\\____|_____|____/____/ \n\n");
        
        FctVideEcran();
        time (&time3);
        diff = difftime (time3,time1) + temps_sauve;
        
        //Traitement du temps afin de l'afficher en hh/mm/ss
        if(diff < 60 && diff > 0)
        {
            Duree.seconde = diff;
            printf("Tu as mis %is pour finir la grille.\n", Duree.seconde);
        }
        else if(diff > 60 && diff <3600)
        {
            Duree.seconde = diff % 60;
            Duree.minute = (diff / 60) % 60;
            printf("Tu as mis %imn%is pour finir la grille ! \n", Duree.minute, Duree.seconde);
        }
        else if(diff > 3600)
        {
            Duree.seconde = diff % 60;
            Duree.minute = (diff / 60) % 60;
            Duree.heure = (diff / 3600);
            printf("Tu as mis %iH%imn%is pour finir la grille ... \n", Duree.heure, Duree.minute, Duree.seconde);
        }
        
        score = (sLaby.taille*100)-diff;
        if(score < 0)
            score = 0;
        
        printf("Soit un score de ... %i !\n\n",score);
        printf("Veux tu sauver ton score et faire partie de la légende ? Y/N \n");
        reponse = get_one_char();
        
        //enregistrement du highscore si oui
        
        if(reponse == 'y' || reponse == 'Y')
        {
            ajout_highscore(score,sLaby.pseudo);
            printf("On remet ça ?!\n\n");
        }
        else
        {
            printf("Dommage...\n\n");
        }
    }
    
    
    car = get_one_char();
    
    FctVideEcran();
}

