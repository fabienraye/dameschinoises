#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "plateau.h"
#include "sdl_plus.h"

void pause(SDL_Surface *ecran, Plateau *plateau) 
{

	int continuer;
	
	int id_pion;
	int id_trou_depart;
	int id_trou_arrivee;
	
	continuer=1;
	
	id_pion=-1;
	id_trou_depart=-1;
	id_trou_arrivee=-1;
	
	SDL_Event evenement;

	while(continuer == 1)
	{
		
		SDL_WaitEvent(&evenement);
		
		switch(evenement.type)
		{
			
			case SDL_QUIT :
				
				continuer = 0;
			
			break;
			
			case SDL_MOUSEBUTTONDOWN :
				
				afficher_mouvement(0, 17, ecran, plateau);
			
				SDL_Flip(ecran); 
				
			/*
			
				// Premier clic, attendu sur un pion
				if (identifier_pion(evenement.button.x, evenement.button.y) != -1 && id_trou_depart == -1)
				{
					
					id_pion=identifier_pion(evenement.button.x, evenement.button.y);
					id_trou_depart=identifier_trou(evenement.button.x, evenement.button.y);
					
				}
				
				// Deuxième clic, attendu sur un trou où déplacer le pion
				else if (identifier_trou(evenement.button.x, evenement.button.y) != -1 && id_trou_depart != -1)
				{
					
					id_trou_arrivee=identifier_trou(evenement.button.x, evenement.button.y);
					
					// mouvement(id_trou_depart, id_trou_arrivee, plateau)
					
					afficher_mouvement(id_trou_depart, id_trou_arrivee, ecran, plateau);
					
					SDL_Flip(ecran); 
					
					id_pion=-1;
					id_trou_depart=-1;
					id_trou_arrivee=-1;
					
				}
				
				else
				{
					
					
					
				}
				
				*/
			
			break;
		
			default :
			break;
			
		}
		
	}
	
}
