//
//  Boite à outil
//  Projet info
//
//  Created by Rémi on 03/11/12.
//  Copyright (c) 2012 Rémi. All rights reserved.
//

#include "bibli.h"

//=================================================================//
// Fonction qui place le curseur dnas la console                   //
//=================================================================//

void gotoxy(int x, int y)
{
    printf("\033[%u;%uH", y, x);         // séquences d'échappement ANSI
}


//=================================================================//
// Fonction qui vide l'Ècran                                       //
//=================================================================//

void FctVideEcran()
{
    system("clear");
}

//=================================================================//
// Fonction créé un repertoire                                     //     
//=================================================================//

void FctCreerRep()
{
    system("mkdir save");
}

//=================================================================//
// Fonction créé un fichier                                     //
//=================================================================//

void FctCreerFile()
{
    system(">highscore.txt");
}

//=================================================================//
// Fonction de coloration du texte                                 //
//=================================================================//

void ColorAllShell(int C_texte, int C_fond)
{
    printf ("\033[%d;%dm\n", C_texte, C_fond + 10);     // séquences d'échappement ANSI
    system("clear");
}

void WriteInColor(char texte[], int C_texte, int C_fond, int init) {
    if (init)
        printf ("\033[%d;%dm%s\033[0m\n", C_texte, C_fond + 10, texte);
    else
        printf ("\033[%d;%dm%s\n", C_texte, C_fond + 10, texte);
}

//=================================================================//
// Fonction de vidage du buffer                                    //
//=================================================================//

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

//=================================================================//
// Fonction de décompte                                            //
//=================================================================//

void decompte(int temps)
{
    int i;
    
    for(i=temps; i>=0; i--)
    {
        printf("%i...", i);
        fflush(stdout);
        sleep(1);
    }
}

//=================================================================//
// Fonction d'affichage de la date                                 //
//=================================================================//

char* datage()
{
    char *ccreation;
    char cformat[128];
    time_t temps;
    struct tm date;
    
    // On récupère la date et l'heure actuelles.
    time(&temps);
    date=*localtime(&temps);
    
    // Format personnalisé 
    strftime(cformat, 128, "%d/%m/%Y à %X\n", &date);
	ccreation = (char *)malloc(sizeof(cformat));
    
	strcpy(ccreation, cformat);
	return ccreation;
}

//=================================================================//
// Modélisation de la fonction getch()                             //
//=================================================================//

char get_one_char()
{
    char car;
    struct termios termModeRaw, termOriginal;
    tcgetattr(STDIN_FILENO, &termOriginal); 
    termModeRaw = termOriginal;
    cfmakeraw(&termModeRaw);
    tcsetattr(STDIN_FILENO, TCSANOW, &termModeRaw); 
    car = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &termOriginal); 
    return car;
}

//=================================================================//
// Fonction de libération de la mémoire                            //
//=================================================================//

void liberer(sLabyrinthe sLaby)
{
    int i;
    
    for(i=0;i<sLaby.taille;i++)
     free(sLaby.gLaby[i]);
     
     free(sLaby.gLaby);
     free(sLaby.pseudo);
     free(sLaby.creation);
    
}

//=================================================================//
// ASCII ART ( à refaire )                                         //
//=================================================================//

void aff_ng()
{
    printf(" _   _ _______        __   ____    _    __  __ _____\n");
    printf("| \\ | | ____\\ \\      / /  / ___|  / \\  |  \\/  | ____|\n");
    printf("|  \\| |  _|  \\ \\ /\\ / /  | |  _  / _ \\ | |\\/| |  _|\n");
    printf("| |\\  | |___  \\ V  V /   | |_| |/ ___ \\| |  | | |___\n");
    printf("|_| \\_|_____|  \\_/\\_/    \\ ____/_/   \\_\\_|  |_|_____|\n");
    printf("\n\n");
}

