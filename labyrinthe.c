//
//  labyrinthe.c
//  Algo de mise en place du Labyrinthe
//
//  Created by Rémi on 03/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Création du labyrinthe avec initialisation à CLOS               //
//=================================================================//


void initialisation_carte(sLabyrinthe* laby)
{
    int i,j;
    
    for(i=0;i<laby->taille;i++)
    {
        for(j=0; j<laby->taille; j++)
        {
            laby->gLaby[i][j]=CLOS;
        }
    }
}

// renvoie 1 si au moins une case voisine accessible
int tester(int x, int y, char** gLaby, int taille)
{
    int i, j;
    
    for (i=-1; i<2; i++)
        for (j=-1; j<2; j++)
        {
            if (i*j==0 && i!=j) // tester uniquement les 4 directions (N, E, S, O)
            {
                if (x+i<0 || x+i>=taille || y+j<0 || y+j>=taille)
                    continue;
                if (gLaby[x+i][y+j] == CLOS)
                    return 1;
            }
        }
    return 0;
}

//=================================================================//
// Fonction créée le labyrinthe                                    //
//=================================================================//

void creerLaby(sLabyrinthe* Laby)
{
    //Pile de taille maximum du nombre de case total du labyrinthe
    sPILE gPile[Laby->taille*Laby->taille]; 
    int gNiveauPile = 0;
    int i, j;
    int di, dj;
    int alea;
    int dir;
    
    alea = rand();
    i = alea%Laby->taille; // première case au hasard
    alea = rand();
    j = alea%Laby->taille;
    
    // empiler la première case
    gPile[gNiveauPile].x = i;
    gPile[gNiveauPile].y = j;
    gNiveauPile++;
    
    while (gNiveauPile > 0)
    {
        // tester les 4 cases d'à côté
        if (tester(i, j, Laby->gLaby, Laby->taille) == 0)
        {
            // aucune case autour de [i,j] n'est à CLOS
            // on dépile
            gNiveauPile--;
            if (gNiveauPile > 0)
            {
                i = gPile[gNiveauPile].x;
                j = gPile[gNiveauPile].y;
            }
            continue;
        }
        
        for (;;) // tant qu'on n'a pas trouvé une case OK 
        {
            dir = rand()%4;
            switch(dir)
            {
                case 0:
                    dj=1; di=0;
                    dir = DROIT;
                    break;
                case 1:
                    dj=0; di=1;
                    dir = BAS;
                    break;
                case 2:
                    dj=-1; di=0;
                    dir = GAUCHE;
                    break;
                case 3:
                    dj=0; di=-1;
                    dir = HAUT;
                    break;
            }
            
            if (i+di<0 || i+di>=Laby->taille || j+dj<0 || j+dj>=Laby->taille || Laby->gLaby[i+di][j+dj] != CLOS)
                continue; // hors limites, ou case déjà traitée
            
            // que des murs, on peut ouvrir.
           // printf("i=%d, j=%d, dir=%s\n", i, j, di==1 ? "Droit":dj==1 ? "Bas":di==-1 ? "Gauche": "Haut");
            // ouvrir le mur dans la case courante
            Laby->gLaby[i][j] &= ~dir; // on enlève le bit correspondant au mur
            
            // ouvrir le mur dans la case destination
            if (dir==HAUT)
                Laby->gLaby[i+di][j+dj] &= ~BAS;
            if (dir==BAS)
                Laby->gLaby[i+di][j+dj] &= ~HAUT;
            if (dir==GAUCHE)
                Laby->gLaby[i+di][j+dj] &= ~DROIT;
            if (dir==DROIT)
                Laby->gLaby[i+di][j+dj] &= ~GAUCHE;
            
            // empiler la nouvelle case
            i = i+di;
            j = j+dj;
            gPile[gNiveauPile].x = i;
            gPile[gNiveauPile].y = j;
            gNiveauPile++;
            break;
        }
    }
}

//=================================================================//
// Fonction qui affiche la matrice propement                       //
//=================================================================//


void Affichage(sLabyrinthe Laby)
{
    int i, j;
    char chaine1[Laby.taille*4+1]; // ligne pour les cases (ex: "| | | |")
    char chaine2[Laby.taille*4+1]; // ligne pour les murs horizontaux entre les cases (ex: "+--+--+ +--+")
    
    FctVideEcran();
    
    //Fermeture de la ligne du haut
    for (i=0; i<Laby.taille; i++)
    {
        printf("+---");
    }
    printf("+\n");
    
    
    for(i=0; i<Laby.taille; i++)
    {
        chaine1[0] = chaine2[0] = 0; // RAZ chaine /!\ sécurité
        for(j=0; j<Laby.taille; j++)
        {
            // le mur droit est traité par la case à droite
            // le mur haut par la case du dessous
            if (Laby.gLaby[i][j] & GAUCHE)
            {
                //traitement des différents cas qui l'est possible de rencontré
                if(Laby.gLaby[i][j] & PRESENT)
                    strcat(chaine1, "| X ");
                else if(Laby.gLaby[i][j] & CLE)
                    strcat(chaine1, "|CLE");
                else if(Laby.gLaby[i][j] & PORTE)
                    strcat(chaine1, "|[ ]");
                else if(Laby.gLaby[i][j] & ACCS)
                    strcat(chaine1, "| . ");
                else
                    strcat(chaine1, "|   ");
            }
            else
            {
                if(Laby.gLaby[i][j] & PRESENT)
                    strcat(chaine1, "  X ");
                else if(Laby.gLaby[i][j] & PORTE)
                    strcat(chaine1, " [ ]");
                else if(Laby.gLaby[i][j] & ACCS)
                    strcat(chaine1, "  . ");
                else
                    strcat(chaine1, "    ");
            }
        
            if (Laby.gLaby[i][j] & BAS)
                strcat(chaine2, "+---");
            else
                strcat(chaine2, "+   ");
        }
        // affichage d'une ligne de case, de son mur droit, de la ligne de murs, et de son + final
        printf("%s|\n%s+\n", chaine1, chaine2);
    }
}

//=================================================================//
// Fonction qui affiche les valeurs en bit de la matrice (debug)   //
//=================================================================//

void Affichage_b(sLabyrinthe sLaby)
{
    int i,j;
    
    for(i=0;i<sLaby.taille;i++)
    {
        for(j=0; j<sLaby.taille; j++)
        {
            printf("%i ", sLaby.gLaby[i][j]);
        }
        printf("\n");
    }
}

