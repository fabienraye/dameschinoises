#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"
#include "SDL/SDL.h"

// Fonction initialisant la position des pions sur le plateau
void init_Position (SDL_Surface *ecran, Plateau *plateau) 
{
	
	int x; 									// Position x (horizontale) du pion
	int y; 									// Position y (verticale) du pion
	int couleur; 								// Couleur du pion
	
	int i;									// Compteur de boucle
	
	i=0;
	
	FILE *fichier_plateau;						// Fichier contenant les positions (x,y) des pions et leur couleur
	
	// Ouverture du fichier contenant les positions des pions
	if(fichier_plateau = fopen("plateau.txt", "r")) 
	{
	
		// Lecture du fichier contenant les positions des pions
		while(fscanf(fichier_plateau,"%d %d %d", &couleur, &x, &y) != EOF) 
		{
		
			// Affectation des positions des pions sur le plateau
			plateau->tab[i]->position_pion.x = x-100;
			plateau->tab[i]->position_pion.y = y-100;
			
			// Affectation de la couleur des pions
			switch(couleur) 
			{
				
				case 1 : 
					
					plateau->tab[i]->surface= IMG_Load("Image/red.png");
					SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
					i++;
				
				break;
				
				case 2 :
					
					plateau->tab[i]->surface = IMG_Load("Image/blue.png");
					SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
					i++;
				
				break;
				
				case 3 :
					
					plateau->tab[i]->surface= IMG_Load("Image/yellow.png");
					SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
					i++;
				
				break;
				
				case 4 :
					
					plateau->tab[i]->surface = IMG_Load("Image/grey.png");
					SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
					i++;
				
				break;
				
				case 5 :
					
					plateau->tab[i]->surface = IMG_Load("Image/green.png");
					SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
					i++;
				
				break;
				
				case 6 :
					
					plateau->tab[i]->surface= IMG_Load("Image/purple.png");
					SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
					i++;
				
				break;
				
				default :
				break;
				
			}
			
		}
		
		// Fermeture du fichier contenant les positions des pions
		fclose(fichier_plateau);
		
		// Mise à jour de l'affichage
		SDL_Flip(ecran); 
		
	}
	
	else 
	{
		
		fprintf(stderr, "Erreur d'initialisation du plateau : %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
}

// Fonction initialisant les trous
void init_Trou (SDL_Surface *ecran, Trou *trou) 
{
	int x, y, couleur, i=0;
	FILE * f;
	int k;
	for(k=0; k <121; k++) {
	trou->tab[k] = (Pion *)malloc(sizeof(Pion));
	}
	if(f = fopen("plateau.txt", "r")) {
		while(fscanf(f,"%d %d %d", &couleur, &x, &y) != EOF) {
			trou->tab[i]->position_pion.x = x-100;
			trou->tab[i]->position_pion.y = y-100;
			trou->tab[i]->surface= IMG_Load("Image/hole.png");
			SDL_BlitSurface(trou->tab[i]->surface, NULL, ecran, &(trou->tab[i]->position_pion));
			i++;
		}
		fclose(f);
		SDL_Flip(ecran); 
		
	}
	else {
		fprintf(stderr, "Erreur d'initialisation du plateau : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	
}


/**

Fonction d'allocations des pions

**/
void init_Pion(Plateau * plateau) {
	int k;
	for(k=0; k <60; k++) {
	plateau->tab[k] = (Pion *)malloc(sizeof(Pion));
	}
}


/**

Fonction de libération des pions

**/
void free_plateau(Plateau * plateau) {
	int i;
	for(i=0; i <60; i++) {
		SDL_FreeSurface(plateau->tab[i]->surface);
	}
}
	
	
	
	
