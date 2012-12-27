typedef struct 
{
	
	SDL_Surface *surface;
	SDL_Rect position_pion;
	
} Pion;

typedef struct 
{
	
	Pion *tab[60];
	
} Plateau;

typedef struct 
{
	
	Pion *tab[121];
	
} Trou;

void init_Position(SDL_Surface *ecran, Plateau *plateau);
void init_Trou (SDL_Surface *ecran, Trou *trou);
void init_Pion(Plateau *plateau); 
void free_plateau(Plateau *plateau) ;
