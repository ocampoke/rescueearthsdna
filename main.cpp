/************************************************************************ 
** Program name: Rescue Earth's DNA Game 
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - this program is a game that utilizes 
**				pointer linked spaces. It includes a Space class which
**				represents the space the player can be in. The space
**				class is an abstract class that utilizes pure virtual
**				functions. There are five derived classes that derive 
**				from the Space class, each representing a different type 
**              		of space, and each having unique actions that the player
**				can interact with. The game includes nine spaces using 
**				the derived classes of Space.
**
***************i********************************************************/
#include "game.hpp"

int main()
{
	// Generate a seed for the rand function used later
	srand(time(NULL));

	// Declare an object of the game class.
	Game game;

	// Call the play function of game to start the game.
	game.play();
}
