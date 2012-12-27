#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"

#include "plateau.h"
#include "sdl_plus.h"

// Largeur de la fenÃªtre, en pixels
#define WINDOW_X 500
// Hauteur de la fenÃªtre, en pixels
#define WINDOW_Y 500
// Nombre de couleurs utilisÃ©es par la librairie
#define NB_COLOR 32

int main(int argc, char *argv[])
{
  /** SURFACES **/
	SDL_Surface *ecran = NULL; 
	SDL_Surface *icone=NULL;
	
	/** GESTION DE L'AFFICHAGE DE LA FENETRE **/
	
	// Initialisation de la librairie SDL
	SDL_Init(SDL_INIT_VIDEO);
	// Remplissage de la surface "Ã©cran"
	ecran = SDL_SetVideoMode(WINDOW_X, WINDOW_Y, NB_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Dames Chinoises -- SVMR", NULL);
	// Icone de la barre de titre
	icone = SDL_LoadBMP("icon.bmp");
	SDL_WM_SetIcon(icone, NULL);
	SDL_WM_SetCaption("Dames Chinoises -- SVMR", NULL);
	
	/** GESTION DES ERREURS SDL **/
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
	  
		fprintf(stderr, "Erreur d'initalisation de la SDL : %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
	if(ecran == NULL) 
	{
	  
		fprintf(stderr, "Impossible de charger le mode video :%s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	  
	 
	/** GESTION DE L'AFFICHAGE DU PLATEAU **/
		
	// Fond de la fenÃªtre
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 6, 112));
	
	// Trous
	Trou * trou = (Trou*)malloc(sizeof(Trou));
	init_Trou(ecran, trou);
	
	// Plateau
	Plateau * plateau = (Plateau*)malloc(sizeof(Plateau));
	
	// Pions
	init_Pion(plateau);
	init_Position(ecran, plateau) ;
	
	// Mise Ã  jour de l'affichage
	SDL_Flip(ecran); 

	pause();
	
	SDL_Quit();
    
	return EXIT_SUCCESS;
	
}
