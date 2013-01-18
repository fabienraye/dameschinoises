#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"

// Fonction initialisant la position des trous sur le plateau (init_Trou)
void init_position_trous (SDL_Surface *ecran, Plateau *plateau) 
{
	
	int id;						// Identifiant du trou
	int x;						// Position x (horizontale) du trou
	int y; 						// Position y (verticale) du trou
	
	int largeur_image;				// Largeur de l'image utilisée pour chaque pion
	int hauteur_image;				// Hauteur de l'image utilsée pour chaque pion
	
	int i;						// Compteur de boucle
	int k;						// Compteur de boucle
	
	i=0;
	
	SDL_Surface *image_pion; 
	
	/* GESTION DES FICHIERS */
	
	FILE *log;					// Fichier log
	FILE *fichier_trous;				// Fichier contenant la position des trous sur le plateau
	FILE *x_range_trous;				// Fichier contenant l'espace occupé en largeur par chaque trou
	FILE *y_range_trous;				// Fichier contenant l'espace occupé en largeur par chaque trou
	
	log=fopen("log_init_position_trous.txt", "w");
	x_range_trous=fopen("x_range_trous.txt", "w+");
	y_range_trous=fopen("y_range_trous.txt", "w+");
	
	image_pion = IMG_Load("Image/hole.png");
	
	largeur_image=image_pion->w;
	hauteur_image=image_pion->h;
	
	if (x_range_trous != NULL && y_range_trous != NULL)
	{
		
		/* GESTION DE LA MEMOIRE */
		
		for (k=0; k <121; k++) 
		{
			
			plateau->tab[k] = (Pion*) malloc(sizeof(Pion));
			
		}
		
		/* AFFICHAGE DES TROUS DU PLATEAU */
		
		// Ouverture du fichier contenant les positions des trous
		if ((fichier_trous = fopen("trous.txt", "r"))) 
		{
			
			// Lecture du fichier contenant les positions des trous
			while(fscanf(fichier_trous,"%d %d %d", &id, &x, &y) != EOF) 
			{
				
				// Affectation de la positions du trou sur le plateau
				plateau->tab[i]->id=id;
				plateau->tab[i]->position_pion.x = x;
				plateau->tab[i]->position_pion.y = y;
				
				// Création des fichiers de taille des surfaces
				fprintf(x_range_trous, "%d %d %d \n", id, x, x+largeur_image);
				fprintf(y_range_trous, "%d %d %d \n", id, y, y+hauteur_image);
				
				// Affichage du trou sur le plateau
				plateau->tab[i]->surface=IMG_Load("Image/hole.png");
				SDL_BlitSurface(plateau->tab[i]->surface, NULL, ecran, &(plateau->tab[i]->position_pion));
				
				i++;
				
			}
			
			// Fermeture du fichier contenant les positions des trous
			fclose(fichier_trous);
			
			// Mise à jour de l'affichage
			SDL_Flip(ecran); 
			
		}
		
		/* GESTION DES ERREURS SDL */
		
		else 
		{
			
			fprintf(log, "Erreur dans la fonction d'initialisation de la position des trous (init_position_trous) : %s \n", SDL_GetError());
			exit(EXIT_FAILURE);
			
		}
		
		// Fermeture des fichiers
		fclose(x_range_trous);
		fclose(y_range_trous);
		
	}
	
	else
	{
		
		fprintf(log, "Erreur lors de l'ouverture des fichiers x_range_trous.txt et y_range_trous.txt");
		
	}
	
}

// Fonction initialisant la position des pions sur le plateau (init_Position)
void init_position_pions (SDL_Surface *ecran, Pions *pions) 
{
	
	int x; 									// Position x (horizontale) du pion
	int y; 									// Position y (verticale) du pion
	int couleur; 								// Couleur du pion
	int id;									// Identifiant unique du pion
	
	int i;									// Compteur de boucle
	
	i=0;
	
	/* GESTION DES FICHIERS */
	
	FILE *fichier_pions;							// Fichier contenant l'identifiant, la couleur et la position (x,y) de chaque pion
	FILE *log;								// Fichier log
	
	log=fopen("log_position_pions.txt", "w");
	fichier_pions=fopen("pions.txt", "r");
	
	/* AFFICHAGE DES PIONS DU PLATEAU */
	
	// Ouverture du fichier contenant les positions des pions
	if(fichier_pions != NULL) 
	{
	
		// Lecture du fichier contenant les positions des pions
		while(fscanf(fichier_pions,"%d %d %d %d", &id, &couleur, &x, &y) != EOF) 
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
				
				// Couleur 1 : JAUNE
				case 1 : 
					
					pions->tab[i]->surface=IMG_Load("Image/yellow.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 2 : VIOLET
				case 2 :
					
					pions->tab[i]->surface = IMG_Load("Image/purple.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 3 : NOIR
				case 3 :
					
					pions->tab[i]->surface= IMG_Load("Image/black.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 4 : VERT
				case 4 :
					
					pions->tab[i]->surface = IMG_Load("Image/green.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 5 : BLEU
				case 5 :
					
					pions->tab[i]->surface = IMG_Load("Image/blue.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				// Couleur 6 : ROUGE
				case 6 :
					
					pions->tab[i]->surface = IMG_Load("Image/red.png");
					SDL_BlitSurface(pions->tab[i]->surface, NULL, ecran, &(pions->tab[i]->position_pion));
					i++;
				
				break;
				
				default :
					
				break;
				
			}
			
		}
		
		// Fermeture du fichier contenant les positions des pions
		fclose(fichier_pions);
		
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

// Fonction permettant d'identifier un pion à partir des coordonnées d'un clic de souris
int identifier_pion(int x_souris, int y_souris)
{
	
	/* VARIABLES */
	
	int id;							// Identifiant du pion
	int couleur;						// Couleur du pion
	int x;							// Coordonnée x du pion
	int y;							// Coordonnée y du pion
	
	int xmin;							// Borne x minimale pour être dans la surface
	int xmax;							// Borne x maximale pour être dans la surface
	int ymin;							// Borne y minimale pour être dans la surface
	int ymax;							// Borne y maximale pour être dans la surface
	
	int largeur_image;					// Largeur de l'image utilisée pour chaque pion
	int hauteur_image;					// Hauteur de l'image utilsée pour chaque pion
	
	int id_possible[121];				// Tableau contenant les identifiants des pions/trous potentiellement cliqués aux coordonnées de la souris
	int id_pion_clique;					// Identifiant du pion qui a été cliqué
	
	int i;							// Compteur
	int k;							// Compteur
	
	id_pion_clique=-1;
	
	i=0;
	k=0;
	
	/* GESTION DES FICHIERS */
	
	FILE *fichier_pions;					// Fichier contenant l'identifiant, la couleur et la position (x,y) de chaque pion
	
	FILE *x_range_pions;				// Fichier contenant l'espace occupé en largeur par chaque pion
	FILE *y_range_pions;				// Fichier contenant l'espace occupé en hauteur par chaque pion
	
	FILE *log;							// Fichier log
	
	SDL_Surface *image_pion; 
	
	log=fopen("log_identifier_pion.txt", "a");
	
	fichier_pions=fopen("pions.txt", "r");
	x_range_pions=fopen("x_range_pions.txt", "w+");
	y_range_pions=fopen("y_range_pions.txt", "w+");
	
	/* IDENTIFICATION DU PION */
	
	image_pion = IMG_Load("Image/hole.png");
	
	largeur_image=image_pion->w;
	hauteur_image=image_pion->h;
	
	// fprintf(log, "Coordonnées du clic de souris : x=%d \t y=%d \n", x_souris, y_souris);
	
	if (fichier_pions != NULL && x_range_pions != NULL && y_range_pions != NULL)
	{
		
		while(fscanf(fichier_pions,"%d %d %d %d", &id, &couleur, &x, &y) != EOF)
		{
			
			fprintf(x_range_pions, "%d %d %d \n", id, x, x+largeur_image);
			fprintf(y_range_pions, "%d %d %d \n", id, y, y+hauteur_image);
			
		}
		
		fclose(fichier_pions);
		
		// Retour au début des fichiers
		rewind(x_range_pions);
		rewind(y_range_pions);
		
		while(fscanf(y_range_pions,"%d %d %d", &id, &ymin, &ymax) != EOF) 
		{
			
			if (y_souris >= ymin && y_souris <= ymax)
			{
				
				id_possible[i]=id;
				i++;
				
				// fprintf(log, "ID pion possible en y : %d \n", id);
				
			}
			
		}
			
		while(fscanf(x_range_pions,"%d %d %d", &id, &xmin, &xmax) != EOF) 
		{
			
			for (k=0; k<=i; k++)
			{
				
				if (id == id_possible[k])
				{
					
					// fprintf(log, "ID pion possible en x : %d \n", id);
					
					if (x_souris >= xmin && x_souris <= xmax)
					{
						
						id_pion_clique=id;
						fprintf(log, "ID pion cliqué : %d \n", id_pion_clique);
						fprintf(log, "************** \n");

					}
					
				}
				
			}
			
		}
		
	}
	
	// Fermeture des fichiers
	fclose(y_range_pions);
	fclose(x_range_pions);
	fclose(log);
	
	return id_pion_clique;
	
}

// Fonction permettant d'identifier un trou à partir des coordonnées d'un clic de souris
int identifier_trou(int x_souris, int y_souris)
{
	
	/* VARIABLES */
	
	int id;						// Identifiant du trou
	
	int xmin;					// Borne x minimale pour être dans la surface
	int xmax;					// Borne x maximale pour être dans la surface
	int ymin;					// Borne y minimale pour être dans la surface
	int ymax;					// Borne y maximale pour être dans la surface
	
	int id_possible[121];				// Tableau contenant les identifiants des pions/trous potentiellement cliqués aux coordonnées de la souris
	int id_trou_clique;				// Identifiant du trou qui a été cliqué
	
	int i;						// Compteur
	int k;						// Compteur
	
	/* GESTION DES FICHIERS */
	
	FILE *x_range_trous;				// Fichier contenant l'espace occupé en largeur par chaque trou
	FILE *y_range_trous;				// Fichier contenant l'espace occupé en hauteur par chaque trou
	
	FILE *log;					// Fichier log
	
	id_trou_clique=-1;
	
	i=0;
	k=0;
	
	log=fopen("log_identifier_trou.txt", "a");
	
	x_range_trous=fopen("x_range_trous.txt", "r");
	y_range_trous=fopen("y_range_trous.txt", "r");
	
	/* IDENTIFICATION DU TROU */
	
	if (x_range_trous != NULL && y_range_trous != NULL)
	{
		
		while(fscanf(y_range_trous,"%d %d %d", &id, &ymin, &ymax) != EOF) 
		{
			
			if (y_souris >= ymin && y_souris <= ymax)
			{
				
				id_possible[i]=id;
				i++;
				
				// fprintf(log, "ID trou possible en y : %d \n", id);
				
			}
			
		}
		
		while(fscanf(x_range_trous,"%d %d %d", &id, &xmin, &xmax) == 3) 
		{
			
			for (k=0; k<=i; k++)
			{
				
				if (id == id_possible[k])
				{
					
					// fprintf(log, "ID trou possible en x : %d \n", id);
					
					if (x_souris >= xmin && x_souris <= xmax)
					{
						
						id_trou_clique=id;
						
						fprintf(log, "ID trou cliqué : %d \n", id_trou_clique);
						fprintf(log, "************** \n");

					}
					
				}
				
			}
			
		}
		
	}
	
	// Fermeture des fichiers
	fclose(y_range_trous);
	fclose(x_range_trous);
	fclose(log);
	
	return id_trou_clique;
	
}

// Fonction d'affichage du mouvement d'un pion sur le plateau
void afficher_mouvement(int depart, int arrivee, SDL_Surface *ecran, Plateau *plateau)
{
	
	int couleur;						// Couleur du pion à déplacer
	
	// couleur = plateau->tab[depart]->couleur;
	
	couleur = 3;
	
	switch(couleur)
	{
		
		// Couleur 1 : ROUGE
		case 1 : 
			
			plateau->tab[depart]->surface = IMG_Load("Image/hole.png");
			plateau->tab[arrivee]->surface = IMG_Load("Image/red.png");
		
			SDL_BlitSurface(plateau->tab[depart]->surface, NULL, ecran, &(plateau->tab[depart]->position_pion));
			SDL_BlitSurface(plateau->tab[arrivee]->surface, NULL, ecran, &(plateau->tab[arrivee]->position_pion));
		
			SDL_Flip(ecran); 
		
		break;
		
		// Couleur 2 : BLEU
		case 2 :
			
			plateau->tab[depart]->surface = IMG_Load("Image/hole.png");
			plateau->tab[arrivee]->surface = IMG_Load("Image/blue.png");
		
			SDL_BlitSurface(plateau->tab[depart]->surface, NULL, ecran, &(plateau->tab[depart]->position_pion));
			SDL_BlitSurface(plateau->tab[arrivee]->surface, NULL, ecran, &(plateau->tab[arrivee]->position_pion));
		
			SDL_Flip(ecran); 
		
		break;
		
		// Couleur 3 : JAUNE
		case 3 :
			
			plateau->tab[depart]->surface = IMG_Load("Image/hole.png");
			plateau->tab[arrivee]->surface = IMG_Load("Image/yellow.png");
		
			SDL_BlitSurface(plateau->tab[depart]->surface, NULL, ecran, &(plateau->tab[depart]->position_pion));
			SDL_BlitSurface(plateau->tab[arrivee]->surface, NULL, ecran, &(plateau->tab[arrivee]->position_pion));
		
		break;
		
		// Couleur 4 : GRIS
		case 4 :
			
			plateau->tab[depart]->surface = IMG_Load("Image/hole.png");
			plateau->tab[arrivee]->surface = IMG_Load("Image/grey.png");
		
			SDL_BlitSurface(plateau->tab[depart]->surface, NULL, ecran, &(plateau->tab[depart]->position_pion));
			SDL_BlitSurface(plateau->tab[arrivee]->surface, NULL, ecran, &(plateau->tab[arrivee]->position_pion));
		
			SDL_Flip(ecran); 	
		
		break;
		
		// Couleur 5 : VERT
		case 5 :
			
			plateau->tab[depart]->surface = IMG_Load("Image/hole.png");
			plateau->tab[arrivee]->surface = IMG_Load("Image/green.png");
		
			SDL_BlitSurface(plateau->tab[depart]->surface, NULL, ecran, &(plateau->tab[depart]->position_pion));
			SDL_BlitSurface(plateau->tab[arrivee]->surface, NULL, ecran, &(plateau->tab[arrivee]->position_pion));
		
			SDL_Flip(ecran); 
		
		break;
		
		// Couleur 6 : VIOLET
		case 6 :
			
			plateau->tab[depart]->surface = IMG_Load("Image/hole.png");
			plateau->tab[arrivee]->surface = IMG_Load("Image/purple.png");
		
			SDL_BlitSurface(plateau->tab[depart]->surface, NULL, ecran, &(plateau->tab[depart]->position_pion));
			SDL_BlitSurface(plateau->tab[arrivee]->surface, NULL, ecran, &(plateau->tab[arrivee]->position_pion));
		
			SDL_Flip(ecran); 
		
		break;
		
		default :
		
		break;
		
	}
	
}

// Fonction permettant de déplacer un pion sur le plateau
void mouvement(int id_pion, int depart, int arrivee, Plateau *plateau)
{
	
	// Penser à mettre à jour la position du pion dans pions.txt après un mouvement
	
	int id_courant;
	
	int x_pion_courant;
	int y_pion_courant;
	
	int x_pion_arrivee;
	int y_pion_arrivee;
	
	FILE *pions;
	
	pions=fopen("pions.txt", "w+");
	
	x_pion_arrivee = plateau->tab[arrivee]->position_pion.x;
	y_pion_arrivee = plateau->tab[arrivee]->position_pion.y;
	
	if (pions != NULL)
	{
		
		while(fscanf(pions,"%d %d %d", &id_courant, &x_pion_courant, &y_pion_courant) != EOF) 
		{
			
			// Recherche de la ligne correspondante
			if (id_courant== id_pion)
			{
				
				// Remplacement de la ligne
				fprintf(pions, "%d %d %d \n", id_courant, x_pion_arrivee, y_pion_arrivee);
				
			}
			
		}
		
	}
	
}
