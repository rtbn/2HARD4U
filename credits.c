//
//  Crédits
//  Projet info
//
//  Created by Rémi on 03/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fichier de gestion des crédits                                  //
//=================================================================//


void credits()
{

	FILE* fichier = NULL;
	char chaine[TAILLE_MAX] = "";

	fichier = fopen("credits.txt","r");

	if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier credits.txt");
    }
    else
    {
        FctVideEcran();
	
        sleep(1);

        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {
            printf("	  ____              _ _ _\n	 / ___|_ __ ___  __| (_) |_ ___ \n	| |   | '__/ _ \\/ _` | | __/ __|\n	| |___| | |  __/ (_| | | |_\\__ \\\n	 \\____|_|  \\___|\\__,_|_|\\__|___/\n");
            
            sleep(1);

            fgets(chaine, TAILLE_MAX, fichier);
            printf("\n\t%s\n", chaine);
            
            sleep(1);
            
            fgets(chaine, TAILLE_MAX, fichier);
            printf("\n\t%s", chaine);
            
            sleep(1);
            
            fgets(chaine, TAILLE_MAX, fichier);
            printf("\n\t%s", chaine);
            
            sleep(1.5);
            
            FctVideEcran();
        }
    }
	fclose(fichier);
}

