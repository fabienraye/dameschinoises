
#include "sdl_plus.h"


#include "SDL/SDL.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

void pause() {
  int continuer=1;
	SDL_Event event;

	while(continuer) 
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT :
				continuer = 0;
		}
	}
} 
