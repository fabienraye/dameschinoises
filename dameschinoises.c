#include <stdio.h>
#include <string.h>

#include "dameschinoises.h"

/* ***************** */
/* Dans la librairie */
/* ***************** */

void InitLibrary(char name[50])
{
	
	printf("InitLibrary \n");
	strcpy(name,"Fabien Picarougne");
	
}

void StartMatch(const unsigned int nbJoueur, const EPlayer couleur)
{
	
	printf("StartMatch \n");
	
}

void StartGame()
{
	
	printf("StartGame \n");
	
}

void EndGame()
{
	
	printf("EndGame \n");
	
}

void EndMatch()
{
	
	printf("EndMatch \n");
	
}

int NextMove(const SGameState * const gameState, int firstMove, SMove *move)
{
	
	printf("NextMove \n");
	
	return(0);
	
}

/* ****************** */
/* Dans l'exécutable */
/* ****************** */

void deroulement_du_jeu()	
//int main()
{
	//*****// à chaque utilisation de gameState, ne pas oublier de faire une copie de tous les éléments (pas fait ici)
	SGameState gameState;

	//*****// à faire pour chaque joueur
	
	// Chargement de la librairie (chargement des pointeurs de fonctions des fonctions décrites dans "backgammon.h")
	// -> à remplacer par votre code de chargement
	pfInitLibrary j1InitLibrary=InitLibrary;
	pfStartMatch j1StartMatch=StartMatch;
	pfStartGame j1StartGame=StartGame;
	pfEndGame j1EndGame=EndGame;
	pfEndMatch j1EndMatch=EndMatch;
	pfNextMove j1NextMove=NextMove;
	// ...
	pfNextMove j2NextMove=NextMove;

	// Initialisation de la librairie
	SMove move;
	char name[50];
	j1InitLibrary(name);
	j1StartMatch(3,color1);

		//*****// à faire pour chaque jeu
		j1StartGame();
			//*****// pour chaque joueur, tant que ce n'est pas fini
			move.startPos=0;
			move.endPos=0;
			if (j1NextMove(&gameState,1,move);
				// ...
		j1EndGame();

	j1EndMatch();

	return(0);
}
