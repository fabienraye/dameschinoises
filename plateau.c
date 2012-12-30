#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"
#include "SDL/SDL.h"

// Fonction initialisant la position des pions sur le pions (init_Position)
void init_position_pions (SDL_Surface *ecran, Pions *pions) 
{
	
	int x; 									// Position x (horizontale) du pion
	int y; 									// Position y (verticale) du pion
	int couleur; 								// Couleur du pion
	
	int i;									// Compteur de boucle
	
	i=0;
	
	FILE *fichier_plateau;						// Fichier contenant les positions (x,y) des pions et leur couleur
	
	// Ouverture du fichier contenant les positions des pions
	if((fichier_plateau = fopen("plateau.txt", "r"))) 
	{
	
		// Lecture du fichier contenant les positions des pions
		while(fscanf(fichier_plateau,"%d %d %d", &couleur, &x, &y) != EOF) 
		{
		
			// Affectation des positions des pions sur le pions
			pions->tab[i]->position_pion.x = x-100;
			pions->tab[i]->position_pion.y = y-100;
			
			// Affectation de la couleur des pions
			switch(couleur) 
			{
				
				// Couleur 1 : ROUGE
				case 1 : 
					
					pions->tab[i]->surface= IMG_Load("Image/red.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 2 : BLEU
				case 2 :
					
					pions->tab[i]->surface = IMG_Load("Image/blue.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 3 : JAUNE
				case 3 :
					
					pions->tab[i]->surface= IMG_Load("Image/yellow.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 4 : GRIS
				case 4 :
					
					pions->tab[i]->surface = IMG_Load("Image/grey.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 5 : VERT
				case 5 :
					
					pions->tab[i]->surface = IMG_Load("Image/green.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 6 : VIOLET
				case 6 :
					
					pions->tab[i]->surface= IMG_Load("Image/purple.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
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
	
	// Gestion des erreurs
	else 
	{
		
		fprintf(stderr, "Erreur d'initialisation du pions : %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
}

// Fonction initialisant la position des trous sur le pions (init_Trou)
void init_position_trous (SDL_Surface *ecran, Plateau *plateau) 
{
	
	int x;					// Position x (horizontale) du trou
	int y; 					// Position y (verticale) du trou
	int couleur;
	
	int k;					// Compteur de boucle
	int i;					// Compteur de boucle
	
	i=0;
	
	FILE *fichier_plateau;

	for (k=0; k <121; k++) 
	{
		
		plateau->tab[k] = (Pion*) malloc(sizeof(Pion));
		
	}
	
	// Ouverture du fichier contenant les positions des trous
	if ((fichier_plateau = fopen("plateau.txt", "r"))) 
	{
		
		// Lecture du fichier contenant les positions des trous
		while(fscanf(fichier_plateau,"%d %d %d", &couleur, &x, &y) != EOF) 
		{
			
			plateau->tab[i]->position_pion.x = x-100;
			plateau->tab[i]->position_pion.y = y-100;
			plateau->tab[i]->surface= IMG_Load("Image/hole.png");
			SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
			i++;
			
		}
		
		// Fermeture du fichier contenant les positions des trous
		fclose(fichier_plateau);
		
		// Mise à jour de l'affichage
		SDL_Flip(ecran); 
		
	}
	
	// Gestion des erreurs
	else 
	{
		
		fprintf(stderr, "Erreur d'initialisation du pion : %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
}


// Fonction d'allocation mémoire de la position des pions (init_Pion)
void allocation_memoire_position_pions (Pions *pions) 
{
	
	int i;
	
	for(i=0; i<60; i++) 
	{
		
		pions->tab[i] = (Pion*) malloc(sizeof(Pion));
		
	}
	
}


// Fonction de libération de la mémoire allouée à la position des pions (free_Plateau)
void liberation_memoire_position_pions (Pions *pions) 
{
	
	int i;
	
	for(i=0; i <60; i++) 
	{
		
		SDL_FreeSurface(pions->tab[i]->surface);
		
	}
	
}
	
	
