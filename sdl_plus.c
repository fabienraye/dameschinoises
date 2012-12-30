#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "SDL/SDL.h"
#include "sdl_plus.h"

void pause() 
{

	int continuer;
	
	continuer=1;
	
	SDL_Event event;

	while(continuer == 1)
	{
		
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
			
			case SDL_QUIT :
			continuer = 0;
		
		}
		
	}
	
} 
