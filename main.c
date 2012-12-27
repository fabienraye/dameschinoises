#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"
#include "sdl_plus.h"
#include "SDL/SDL.h"

#define WINDOW_X 500
#define WINDOW_Y 500
#define NB_COLOR 32

int main(int argc, char *argv[])
{
	
	/* INITIALISATION DE LA LIBRAIRIE SDL */
	
	// Création de la surface "écran"
	SDL_Surface *ecran = NULL, *icone=NULL;
	SDL_Init(SDL_INIT_VIDEO);
	
	/* GESTION DES ERREURS SDL */
	
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		
		fprintf(stderr, "Erreur d'initalisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
	if(ecran == NULL) 
	{
		
		fprintf(stderr, "Impossible de charger le mode video :%s\n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
	/* GESTION DE LA FENETRE */
	
	// Paramétrage de la surface "écran
	ecran = SDL_SetVideoMode(WINDOW_X, WINDOW_Y, NB_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	// Définition de l'icone de la fenêtre
	icone = SDL_LoadBMP("icon.bmp");
	SDL_WM_SetIcon(icone, NULL);
	
	// Définition du titre de la fenêtre
	SDL_WM_SetCaption("Dames Chinoises -- SVMR", NULL);
	
	// Gestion de l'affichage fond de la fenêtre
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 6, 112));
	
	// Gestion de l'affichage des trous du plateau
	Trou *trou = (Trou*) malloc(sizeof(Trou));
	init_Trou(ecran, trou);
	
	// Gestion de l'affichage des pions sur le plateau
	Plateau *plateau = (Plateau*)malloc(sizeof(Plateau));
	init_Pion(plateau);
	init_Position(ecran, plateau) ;
	
	// Mise à jour de l'affichage
	SDL_Flip(ecran); 

	pause();

	// Fermeture de la librairie SDL
	SDL_Quit();
    
	return EXIT_SUCCESS;
	
}
