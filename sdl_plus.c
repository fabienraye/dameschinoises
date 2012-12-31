#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "sdl_plus.h"
#include "plateau.h"

void pause() 
{

	int continuer;
	
	continuer=1;
	
	SDL_Event evenement;

	while(continuer == 1)
	{
		
		SDL_WaitEvent(&evenement);
		
		switch(evenement.type)
		{
			
			case SDL_QUIT :
			continuer = 0;
			break;
			
			case SDL_MOUSEBUTTONUP :
			identifier_pion(evenement.button.x, evenement.button.y);
			break;
		
			default :
			break;
			
		}
		
	}
	
} 
