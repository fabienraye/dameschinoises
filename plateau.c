#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"

// Fonction initialisant la position des trous sur le pions (init_Trou)
void init_position_trous (SDL_Surface *ecran, Plateau *plateau) 
{
	
	int x;					// Position x (horizontale) du trou
	int y; 					// Position y (verticale) du trou
	
	int k;					// Compteur de boucle
	int i;					// Compteur de boucle
	
	i=0;
	
	FILE *fichier_plateau;
	
	/* GESTION DE LA MEMOIRE */
	
	for (k=0; k <121; k++) 
	{
		
		plateau->tab[k] = (Pion*) malloc(sizeof(Pion));
		
	}
	
	/* AFFICHAGE DES TROUS DU PLATEAU */
	
	// Ouverture du fichier contenant les positions des trous
	if ((fichier_plateau = fopen("trous.txt", "r"))) 
	{
		
		// Lecture du fichier contenant les positions des trous
		while(fscanf(fichier_plateau,"%d %d", &x, &y) != EOF) 
		{
			
			// Affectation de la positions du trou sur le plateau
			plateau->tab[i]->position_pion.x = x;
			plateau->tab[i]->position_pion.y = y;
			
			// Affichage du trou sur le plateau
			plateau->tab[i]->surface=IMG_Load("Image/hole.png");
			SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
			
			i++;
			
		}
		
		// Fermeture du fichier contenant les positions des trous
		fclose(fichier_plateau);
		
		// Mise à jour de l'affichage
		SDL_Flip(ecran); 
		
	}
	
	/* GESTION DES ERREURS SDL */
	
	else 
	{
		
		fprintf(stderr, "Erreur dans la fonction d'initialisation de la position des trous (init_position_trous) : %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
}

// Fonction initialisant la position des pions sur le pions (init_Position)
void init_position_pions (SDL_Surface *ecran, Pions *pions) 
{
	
	int x; 									// Position x (horizontale) du pion
	int y; 									// Position y (verticale) du pion
	int couleur; 								// Couleur du pion
	int id;									// Identifiant unique du pion
	
	int i;									// Compteur de boucle
	
	i=0;
	
	FILE *fichier_plateau;						// Fichier contenant l'identifiant, la couleur et la position (x,y) de chaque pion
	FILE *log;									// Fichier log
	
	log=fopen("log_position_pions.txt", "w");
	
	/* AFFICHAGE DES PIONS DU PLATEAU */
	
	// Ouverture du fichier contenant les positions des pions
	if((fichier_plateau = fopen("pions.txt", "r"))) 
	{
	
		// Lecture du fichier contenant les positions des pions
		while(fscanf(fichier_plateau,"%d %d %d %d", &id, &couleur, &x, &y) != EOF) 
		{
		
			// Affectation des positions des pions sur le plateau
			pions->tab[i]->id = id;
			pions->tab[i]->couleur = couleur;
			pions->tab[i]->position_pion.x = x;
			pions->tab[i]->position_pion.y = y;
			
			fprintf(log, "%d %d %d %d  \n", i, couleur, pions->tab[i]->position_pion.x, pions->tab[i]->position_pion.y);
			
			// Affectation de la couleur des pions
			switch(couleur) 
			{
				
				// Couleur 1 : ROUGE
				case 1 : 
					
					pions->tab[i]->surface=IMG_Load("Image/red.png");
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
					
					pions->tab[i]->surface = IMG_Load("Image/purple.png");
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
	
	/* GESTION DES ERREURS SDL */
	
	else 
	{
		
		fprintf(log, "Erreur dans la fonction d'initialisation de la position des pions (init_position_pions) %s \n", SDL_GetError());
		exit(EXIT_FAILURE);
		
	}
	
	fclose(log);
	
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

// Fonction permettant d'effectuer un mouvement
void mouvement(int depart, int arrivee, Plateau *plateau)
{
	
	
	
}

// Fonction d'affichage d'un mouvement de pion
void afficher_mouvement(int depart, int arrivee, SDL_Surface *ecran, Pions *pions)
{
	
	int couleur;						// Couleur du pion à déplacer
	
	couleur = pions->tab[depart]->couleur;
	
	switch(couleur) 
	{
		
		// Couleur 1 : ROUGE
		case 1 : 
			
			pions->tab[depart]->surface = IMG_Load("Image/hole.png");
			pions->tab[arrivee]->surface = IMG_Load("Image/red.png");
		
			SDL_BlitSurface(pions->tab[depart]->surface, NULL, ecran, &(pions->tab[depart]->position_pion));
			SDL_BlitSurface(pions->tab[arrivee]->surface, NULL, ecran, &(pions->tab[arrivee]->position_pion));
		
		break;
		
		// Couleur 2 : BLEU
		case 2 :
			
			pions->tab[depart]->surface = IMG_Load("Image/hole.png");
			pions->tab[arrivee]->surface = IMG_Load("Image/blue.png");
		
			SDL_BlitSurface(pions->tab[depart]->surface, NULL, ecran, &(pions->tab[depart]->position_pion));
			SDL_BlitSurface(pions->tab[arrivee]->surface, NULL, ecran, &(pions->tab[arrivee]->position_pion));
		
		break;
		
		// Couleur 3 : JAUNE
		case 3 :
			
			pions->tab[depart]->surface = IMG_Load("Image/hole.png");
			pions->tab[arrivee]->surface = IMG_Load("Image/yellow.png");
		
			SDL_BlitSurface(pions->tab[depart]->surface, NULL, ecran, &(pions->tab[depart]->position_pion));
			SDL_BlitSurface(pions->tab[arrivee]->surface, NULL, ecran, &(pions->tab[arrivee]->position_pion));
		
		break;
		
		// Couleur 4 : GRIS
		case 4 :
			
			pions->tab[depart]->surface = IMG_Load("Image/hole.png");
			pions->tab[arrivee]->surface = IMG_Load("Image/grey.png");
		
			SDL_BlitSurface(pions->tab[depart]->surface, NULL, ecran, &(pions->tab[depart]->position_pion));
			SDL_BlitSurface(pions->tab[arrivee]->surface, NULL, ecran, &(pions->tab[arrivee]->position_pion));
		
		break;
		
		// Couleur 5 : VERT
		case 5 :
			
			pions->tab[depart]->surface = IMG_Load("Image/hole.png");
			pions->tab[arrivee]->surface = IMG_Load("Image/green.png");
		
			SDL_BlitSurface(pions->tab[depart]->surface, NULL, ecran, &(pions->tab[depart]->position_pion));
			SDL_BlitSurface(pions->tab[arrivee]->surface, NULL, ecran, &(pions->tab[arrivee]->position_pion));
		
		break;
		
		// Couleur 6 : VIOLET
		case 6 :
			
			pions->tab[depart]->surface = IMG_Load("Image/hole.png");
			pions->tab[arrivee]->surface = IMG_Load("Image/purple.png");
		
			SDL_BlitSurface(pions->tab[depart]->surface, NULL, ecran, &(pions->tab[depart]->position_pion));
			SDL_BlitSurface(pions->tab[arrivee]->surface, NULL, ecran, &(pions->tab[arrivee]->position_pion));
		
		break;
		
		default :
			
		break;
		
	}
	
}

// Fonction permettant d'identifier un pion à partir des coordonnées d'un clic de souris
int identifier_pion(int x_souris, int y_souris)
{
	
	int id;						// Identifiant du pion
	int couleur;					// Couleur du pion
	int x;						// Coordonnée x du pion
	int y;						// Coordonnée y du pion
	
	int xmin;						// 						
	int xmax;						// 
	int ymin;						// 
	int ymax;						// 
	
	int largeur_image;				// Largeur de l'image utilisée pour chaque pion
	int hauteur_image;				// Hauteur de l'image utilsée pour chaque pion
	
	int id_possible[60];				// Tableau contenant les identifiants de pions potentiellement cliqués aux coordonnées de la souris
	int id_clique;					// Identifiant du pion qui a été cliqué
	
	FILE *pions;					// Fichier contenant l'identifiant, la couleur et la position (x,y) de chaque pion
	
	FILE *x_range;					// Fichier contenant l'espace occupé en largeur par chaque pion
	FILE *y_range;					// Fichier contenant l'espace occupé en hauteur par chaque pion
	
	FILE *log;						// Fichier log
	
	SDL_Surface *image_pion; 
	
	log=fopen("log_identifier_pions.txt", "a");
	
	pions=fopen("pions.txt", "r");
	x_range=fopen("x_range.txt", "w");
	y_range=fopen("y_range.txt", "w");
	
	image_pion = IMG_Load("Image/hole.png");
	
	largeur_image=image_pion->w;
	hauteur_image=image_pion->h;
	
	fprintf(log, "x=%d \t y=%d \n", x_souris, y_souris);
	
	while(fscanf(pions,"%d %d %d %d", &id, &couleur, &x, &y) != EOF) 
	{
		
		fprintf(x_range, "%d %d %d \n", id, x, x+largeur_image);
		fprintf(y_range, "%d %d %d \n", id, y, y+hauteur_image);
		
	}
	
	while(fscanf(y_range,"%d %d %d", &id, &ymin, &ymax) != EOF) 
	{
		
		if (y_souris >= ymin && y_souris <= ymax)
		{
			
			id_possible[id]=id;
			
		}
		
	}
	
	while(fscanf(x_range,"%d %d %d", &id, &xmin, &xmax) != EOF) 
	{
		
		if (x_souris >= xmin && x_souris <= xmax)
		{
			
			if (id_possible[id] != NULL)
			{
				
				id_clique=id;
				fprintf(log, "ID cliqué : %d", id);
				
			}
			
		}
		
	}
	
	fclose(y_range);
	fclose(x_range);
	fclose(pions);
	fclose(log);
	
	return 0;
	
}
