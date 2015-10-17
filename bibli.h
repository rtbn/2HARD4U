//===========================================================================//
// bibli.h : bibliothèque du programme                                       //
//===========================================================================//

#ifndef _main       //Pour eviter les inclusions infinies
#define _main       //

//=================================================================//
// Include                                                         //
//=================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
//#include <curses.h>                   //A remettre si l'on decide de ne pas jouer le son
//#include <ncurses.h>                  //Ou si l'on compile ailleur que sous Mac
#include <termios.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "Fmod/fmod.h"                  //A enlever si
#include "Fmod/fmod_errors.h"           //l'on decide de ne
#include "Fmod/wincompat.h"             //plus jouer de son

//==================================================================//
// macros utilisé dans tout le programme                            //
//==================================================================//

#define TAILLE_MAX 1000

#define couleur(param) printf("\033[%sm",param)

#define HAUT 1
#define DROIT 2
#define BAS 4
#define GAUCHE 8
#define PRESENT 16
#define CLE 32
#define PORTE 64
#define ACCS 128
#define CLOS HAUT+DROIT+BAS+GAUCHE

//==================================================================//
// structure de définition d'un point en 2D                         //
//==================================================================//

typedef struct _sPILE_
{
    int x;
    int y;
} sPILE;

//==================================================================//
// structure de gestion du labyrinthe                               //
//==================================================================//

typedef struct _sLabyrinthe_
{
    char **gLaby;
    char* pseudo;
    char* creation;
    int taille;
    int nv_partie;
    int temps;
} sLabyrinthe;

typedef struct _sHeros_
{
    int x;
    int y;
} sHeros;

typedef struct _sChemin_
{
    int x;
    int y;
} sChemin;

typedef struct _sTemps_
{
    int heure;
    int minute;
    int seconde;
} sTemps;

//===================================================================//
// Fonctions                                                         //
//===================================================================//
// A chaque partie correspond un fichier


///////////////////////////////Fonctions du Main//////////////


void FctCreerRep();
void FctCreerFile();
void launch();
void FtcVideEcran();
void viderBuffer();
void menu();

///////////////////////////////Menu///////////////////////////

void liberer(sLabyrinthe sLaby);
void FctVideEcran();
sLabyrinthe nouveau_jeu();
sLabyrinthe load_laby();
char get_one_char();
void lets_play();
void options();
void credits();

///////////////////////////////New_game//////////////////////

void aff_ng();
void FctVideEcran();
char* datage();
void initialisation_carte(sLabyrinthe* sLaby);
void creerLaby(sLabyrinthe* sLaby);
void decompte(int temps);
void Affichage(sLabyrinthe);
char get_one_char();
void viderBuffer();
void save_laby();

///////////////////////////////Save/load////////////////////

char get_one_char();
char** allocation_laby(int taille);
void Affichage(sLabyrinthe);
void liberer(sLabyrinthe);
void viderBuffer();

///////////////////////////////Moteur/////////////////////

void ajout_highscore(int score, char* pseudo);
int trouver_cle(sLabyrinthe sLaby);
void effacer_chemin(sLabyrinthe sLaby);
void trouver_chemin_cle(sLabyrinthe sLaby, sHeros sHeros);
void trouver_chemin_porte(sLabyrinthe sLaby, sHeros sHeros);
void help(sLabyrinthe sLaby, sHeros sHeros);
int sous_menu(sLabyrinthe sLaby, sHeros sHeros, int temps);
void game_pause();
void tout_placer(sLabyrinthe* sLaby);
sHeros trouver_geros(sLabyrinthe sLaby);
int trouver_cle(sLabyrinthe sLaby);
int bouger(sLabyrinthe* sLaby, sHeros*, short Dir);
void lets_play(sLabyrinthe sLaby);
void viderBuffer();
void FctVideEcran();
char get_one_char();
void save_laby();
void options ();

///////////////////////////////Crédits/////////////////////

void credits();
void FctVideEcran();

///////////////////////////////Options////////////////////

void afficher_highscore();
void bitchplease();
void cheat();
void chucknorris();
void FctVideEcran();
void godmode();
void menu_highscore();
void reset();
void veryeasy();

#endif
