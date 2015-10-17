//
//  save_load.c
//  Projet_info
//
//  Created by Remi on 12/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fonction de sauvegarde du labyrinthe en fonction du pseudo      //
//=================================================================//

void save_laby(sLabyrinthe Laby, int temps)
{
    int i,j;
    char save[30] = "save/";
    FILE* fichier = NULL;
    char reponse = 0;
    

    /* On concate le pseudo à "/save" pour se placer correctement dans le repertoire */
  
    do
    {
        
        printf("Voulez vous sauvgarder ? Y/N \n");
        reponse = get_one_char();
    
        if(reponse == 'y' || reponse == 'Y')
        {
            printf("Enregistrement en cours...\n");
            strcat(save, Laby.pseudo);
            strcat(save, ".lvl");

            fichier = fopen(save, "w");
   
            //on écrit la taille du laby, et le temps au début du fichier
            fprintf(fichier, "%i\n", Laby.taille);
            fprintf(fichier, "%i\n", temps);
    
            //puis on retranscrit la matrice binaire dnas le fichier
            for(i=0; i<Laby.taille; i++)
            {
                for(j=0; j<Laby.taille; j++)
                {
                    fprintf(fichier, "%i ", Laby.gLaby[i][j]);
                }
                fprintf(fichier, "\n");
            }
        
            //on termine par la date
            fprintf(fichier, "Créé le %s\n", Laby.creation);
        
            FctVideEcran();
        
            printf("Fini \n");
            //puis on rappelle le pseudo de jeu
            printf("Votre pseudo de jeu est : %s.\n", Laby.pseudo);
                
            fclose(fichier);
        }
        else if(reponse == 'n' || reponse == 'N')
            printf("Dommage...\n\n");
        
    }while(reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N');
} 

//=================================================================//
// Fonction de chargement de niveau en fonction du pseudo          //
//=================================================================//

sLabyrinthe load_laby()
{
    FILE* fichier = NULL;
    char spseudo[20] = "";
    char slevel[25] = "save/";
    char chaine[TAILLE_MAX] = "";
    char reponse;
    int taille, i, j, valeur, temps;
    char** gLaby;
    sLabyrinthe Reponse;
    
    printf("Saisir votre pseudo : ");
    scanf("%s", spseudo);
    printf("\n\n");
    
    //On concate le pseudo à "save/" puis à ".lvl" pour avoir un chemin du type "save/pseudo.lvl" et ainsi être au bon endroit
    
    strcat(slevel, spseudo);
    strcat(slevel, ".lvl");
    
    fichier = fopen(slevel, "r");
    
    
    if (fichier != NULL)
    {
        //on récupere la taille, et le temps
        fscanf(fichier, "%i", &taille);
        gLaby = allocation_laby(taille);
        fscanf(fichier, "%i", &temps);
        
        //puis on met tout dans la structure de type sLabyrinthe
        Reponse.taille = taille;
        Reponse.gLaby = gLaby;
        Reponse.temps = temps;
        Reponse.pseudo = strdup(spseudo);
        Reponse.nv_partie = 0;
        
        //on récupère le labyrinthe
        for (i=0;i<taille;i++)
        {
            for (j=0;j<taille;j++)
            {
                fscanf(fichier, "%i", &valeur);
                Reponse.gLaby[i][j] = valeur;
            }
        }
        
        Affichage(Reponse);
        
        printf("Labyrinthe de taille %i !\n", taille);
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {
            printf("%s", chaine);
        }
        
        fclose(fichier);
        
        viderBuffer();
        
        do
        {
            printf("Voulez vous reprendre cette partie ? Y/N \n");
            reponse = get_one_char();
            
            if(reponse == 'y' || reponse == 'Y')
            {
                printf("Ok\n");
                return Reponse;
            }
            else if(reponse == 'N' || reponse =='n')
            {
                printf("Tapette...\nAppuyer sur une touche pour continuer\n");
                char tempo = get_one_char();
                liberer(Reponse);
                FctVideEcran();
            }
            
        } while (reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N');
        
        
        
    }
    else
    {
        printf("Pseudo inconnu, désolé\n\n");
    }
}
