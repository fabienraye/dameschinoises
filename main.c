#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"
#include "sdl_plus.h"

#define WINDOW_X 500
#define WINDOW_Y 500
#define NB_COLOR 32

int main(int argc, char *argv[])
{
	
	FILE *log;
	
	log=fopen("log.txt", "w");
	
	fprintf(log, "***** Initialisation de la librairie SDL \n");
	
	/* INITIALISATION DE LA LIBRAIRIE SDL */
	
	// Création des surfaces
	SDL_Surface *ecran = NULL;
	SDL_Surface *icone=NULL;
	
	// Démarrage du module vidéo de la librairie SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	/* GESTION DE LA FENETRE */
	
	fprintf(log, "***** Affichage de l'icone de la fenêtre \n");
	
	// Affichage de l'icone de la fenêtre
	icone = SDL_LoadBMP("icone.bmp");
	SDL_WM_SetIcon(icone, NULL);
	
	// Paramétrage de la surface "écran
	ecran = SDL_SetVideoMode(WINDOW_X, WINDOW_Y, NB_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	// Définition du titre de la fenêtre
	SDL_WM_SetCaption("Dames Chinoises", NULL);
	
	fprintf(log, "***** Affichage du background \n");
	
	// Affichage fond de la fenêtre
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	
	/* GESTION DES ERREURS SDL */
	
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		
		fprintf(log, "Erreur d'initalisation de la SDL : %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
	if(ecran == NULL) 
	{
		
		fprintf(log, "Impossible de charger le mode video :%s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
	/* AFFICHAGE DU PLATEAU DE JEU */
	
	fprintf(log, "***** Affichage des trous du plateau (appel à la fonction init_position_trous) \n");
	
	// Affichage des trous du plateau
	Plateau *plateau = (Plateau*) malloc(sizeof(Plateau));
	init_position_trous (ecran, plateau);
	
	fprintf(log, "***** Affichage des pions sur le plateau (appel à la fonction init_position_pions) \n");
	
	// Affichage des pions sur le plateau
	Pions *pions = (Pions*) malloc(sizeof(Pions));
	allocation_memoire_position_pions(pions);
	init_position_pions(ecran, pions);
	
	fprintf(log, "***** Mise à jour de l'affichage \n");
	
	mouvement(0, 59, ecran, pions);
	mouvement(10, 58, ecran, pions);
	
	// Mise à jour de l'affichage
	SDL_Flip(ecran); 

	// Attente d'un évènement SDL
	pause();
	
	fprintf(log, "***** Fermeture de la librairie SDL \n");
	
	// Fermeture de la librairie SDL
	SDL_Quit();
	
	fclose(log);
    
	return EXIT_SUCCESS;
	
}
