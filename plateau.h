// Structure définissant un pion pour la librairie SDL
typedef struct 
{
	
	SDL_Surface *surface;
	SDL_Rect position_pion;
	
} Pion;

// Structure définissant les 60 pions du jeu (6 joueurs * 10 pions par joueur)
typedef struct 
{
	
	Pion *tab[60];
	
} Plateau;

// Structure définissant les 121 trous du plateau de dames chinoises
typedef struct 
{
	
	Pion *tab[121];
	
} Trou;

void init_Position(SDL_Surface *ecran, Plateau *plateau);
void init_Trou (SDL_Surface *ecran, Trou *trou);
void init_Pion(Plateau *plateau); 
void free_plateau(Plateau *plateau) ;
