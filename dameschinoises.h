// Strutures à utiliser

// Etat d'une case du jeu
typedef enum
{
	
	none,
	color1,
	color2,
	color3,
	color4,
	color5,
	color6
	
} EPlayer;


// Structure de représentation du jeu avec son plateau
typedef struct
{
	
	EPlayer board[121];					// Tableau contenant les zones où les pions peuvent se trouver

} SGameState;


// Structure de représentation d'un mouvement
typedef struct
{
	
	int startPos;
	int endPos;
	
} SMove;



// Fonctions à utiliser
// Les prototypes en commentaires sont à implémenter dans la librairie
// Les types pointeur de fonction dans l'application



/**
 * Initialiser la librairie
 * @param char name[50]
 *	nom associé à la librairie
 */
//void InitLibrary(char name[50]);
typedef void (*pfInitLibrary)(char[50]);



/**
 * Initialiser l'IA pour un match
 * @param const unsigned int nbPlayer
 *	nombre de joueur
 * @param const player color
 *	couleur du joueur
 */
//void StartMatch(const unsigned int nbJoueur, const EPlayer couleur);
typedef void (*pfStartMatch)(const unsigned int, const EPlayer);



/**
 * Initialiser l'IA pour une manche (d'un match)
 */
//void StartGame();
typedef void (*pfStartGame)();



/**
 * Fin d'une manche (d'un match)
 */
//void EndGame();
typedef void (*pfEndGame)();



/**
 * Fin d'un match
 */
//void EndMatch();
typedef void (*pfEndMatch)();



/**
 * Prise de décision de la part de l'IA
 * @param const SGameState * const gameState
 *	l'état du jeu courant
 * @param SMove moves[4]
 *	mouvement à effectuer par l'IA
 * @param int firstMove
 *	vrai s'il s'agit du premier mouvement d'un tour
 * @return int
 *	booleen : 0=plus de mouvement ; 1=prendre en compte le mouvement
 */
//int NextMove(const SGameState * const gameState, int firstMove, SMove *move);
typedef int (*pfNextMove)(const SGameState * const, int, SMove *);
