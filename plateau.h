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
	
} Pions;

// Structure définissant les 121 trous du plateau de dames chinoises
typedef struct 
{
	
	Pion *tab[121];
	
} Plateau;

void init_position_pions (SDL_Surface *ecran, Pions *pions) ;
void init_position_trous (SDL_Surface *ecran, Plateau *plateau);
void allocation_memoire_position_pions (Pions *pions);
void liberation_memoire_position_pions (Pions *pions);
