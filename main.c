//
//  main.c
//  Laby
//
//  Created by Rémi on 03/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fonction main                                                   //
//=================================================================//

int main(void)
{
    
    FMOD_SYSTEM *system;
    FMOD_SOUND *tir;
    
    FMOD_RESULT resultat;
    
    /* Création et initialisation d'un objet système */
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
    
    /* Chargement du son et vérification du chargement */
    resultat = FMOD_System_CreateSound(system, "Media/pan.wav", FMOD_CREATESAMPLE, 0, &tir);
    if (resultat != FMOD_OK)
    {
        fprintf(stderr, "Impossible de lire pan.wav\n");
    }
    
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0, NULL);
    
    
    // Ouverture du répertoire et création si il n'existe pas
    // Cela permet de ranger les parties sauvées dans un fichier pour limiter la propagations des fichiers

    couleur("40;37");
    
    DIR *save;
    save = opendir("save");
    
    if (save == NULL)
    {
        FctCreerRep();
    }
    
    //Vérification de la présence du fichier
    
    FILE* fichier = NULL;
    fichier = fopen("highscore.txt","r+");
    
    if(fichier == NULL)
    {
        FctCreerFile();
    }else
    {
        fclose(fichier);
    }
    
    
    srand((unsigned int)time(NULL));  //Initialisation du générateur de chiffre aléatoire
    
    launch();
    menu();
    
    couleur("0");
    FctVideEcran();
    
    FMOD_System_Close(system);
    FMOD_System_Release(system);
    
}
