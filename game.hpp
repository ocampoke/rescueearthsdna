/************************************************************************ 
** Class name: Game
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the Game 
**				class of Rescue Earth's DNA Game, an alien abduction game
**				played from the perspective of an alien in a space ship. 
**				It contains the functions that contain the game mechanics 
**				of the game. It utilizes variables to define the 
**				characteristics of the ship that provide a step-limit to 
**				the game. It also uses a bool flag variable and an int to 
**				determine if the user met or failed to achieve the
**				objective of the game. It utilizes an STL queue
**				container to represent the ship's storage where
**				abductees are stored. It also uses Space pointers to
**				define the linked space structure of the game, with
**				each pointer intialized to point to an object of the
**				five unique derived classes of Space that represent
**				different types of Spaces with unique actions that the
**				player interacts with. It also utilizes counters to
**				keep track of the amount of different abductees.
**
************************************************************************/      
#ifndef GAME
#define GAME

#include <iostream>
#include <queue>
#include <iomanip>
#include "inputValid.hpp"
#include "space.hpp"
#include "house.hpp"
#include "nuclearPlant.hpp"
#include "smallForest.hpp"
#include "policeStation.hpp"
#include "zoo.hpp"
#include "game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;

class Game 
{
	public:

		/**********************************************************************
		** Function name: Default constructor of the Game class
		** Description: The default constructor of the Game class that
		**				initializes the ship's energy and storage values and 
		**				the four direction pointers of the nine Space derived 
		**				class objects that make up the spaces of the linked 
		**				space structure of the game.
		** Called by: main
		** Calls: setter functions of the Space class
		** Passed: nothing
		** Returns: nothing
		**
		**********************************************************************/
		Game();

        /**********************************************************************
        ** Function name: Game destructor
        ** Description: The destructor of the Game class.
        ** Called by: main when the program exits.
        ** Calls: nothing
        ** Passed: nothing
        ** Returns: nothing
        **
        **********************************************************************/
   		~Game();

		/***********************************************************************
		** Function name: play
		** Description: This function contains the game mechanics of the Rescue 
		**				Earth's DNA Game. It uses several menus that allow the
		**				users to control the flow of the program. The menu's
		**				utilize input validation to ensure that the user enters
		**				a valid choice. The first menu asks the user if they 
		**				want to play the game or replay the game if they chose
		**				to play again. If the chooser chose to replay the game,
		**				it dynamically allocates memory to a new Space derived
		**				class object to the Space pointers that make up the 
		**				linked space structure of the game. This is to necessary
		**				as the pointers are deleted at the end of each iteration
		**				of the game. The game begins by describing the back story
		**				of the game and the gameplay mechanics. It then presents
		**				a map of the Town which is actually a map of the linked
		**				space structure of the game. The game play begins and 
		**				starts by defining the currentSpace to the one Space 
		**				object which is the center southern Space of the linked
		**				space structure. The game mechanics involve calling 
		**				functions that let the user know the type and number of
		**				occupants of a space, whether it contains energy 
		**				material, and whether the occupants are resisting. The
		**				function then allows the user to capture or retrieve the
		**				occupants or energy and to stun any defenders if 
		**				resistance or heavy resistance occurs. Each individual
		**				abduction and stunning occurence drains energy, and thus
		**				the shipEnergy is reduced by the amount specified by each
		**				interaction, with heavy resistance costing more than 
		**				non-heavy resistance. The function includes the mechanics
		**				for retrieving enery materials but calls the 
		**				abductOccupants for the abduction mechanics. After all
		**				the interactions at each space, the function then calls
		**				a function that determines if the user met the objective
		**				of the game, which is to capture a specified number of 
		**				individuals of each type of abductee. The functions sets
		**				the capturedRequiredIndividuals bool to true if the 
		**				objective is met or otherwise lets the user that it is 
		**				yet met. If the player's ship still has fuel or hasn't
		**				met the game objectives, a menu function is called that
		**				prints a map showing the player's current location and 
		**				provides a menu that allows the user to move to another
		**				space in a desired direction and the game mechanics 
		**				repeats.. If the user runs out of energy or if the game 
		**				objective is met, the game print out a message indicating 
		**				whether or not the user completed the game objectives and
		**				the game ends. The function then resets various variables
		**				and one menu input to ensure the game is reset for another
		**				iteration. It also frees up the memory allocated to the
		**				nine space variables to ensure that the linked space 
		**				structure is reset. The whole mechanic is in a while loop
		**				so that the user is presented with a menu that allows the 
		**				user to play again or exit, and the game continues
		**				looping until the user chooses to exit.
		** Called by: main 
		** Calls: inputValid, cin.ignore, containsEnergyUnits, resistanceOffered,
		**		  getter and setter functions of Space class, resistanceOffered,
		**		  abductOccupants, capturedRequiredAmount, moveMenu, 
		**		  printShipStorage, queue empty, queue pop, 
		** Passed: nothing
		** Returns: nothing
		**
		***********************************************************************/
		void play();

		/**********************************************************************
		** Function name: abductOccupants
		** Description: This function contains the abduction mechanics. It 
		**				checks if the space has each type of individual. If it
		**				does, it uses a for loop to add the individual to the
		**				ship storage queue, decrement shipEnergy, and increment
		**				the individual type counters. If the ship storage is 
		**				larger than the max ship storage size, it indicates so 
		**				and nothing is added to ship storage nor is energy
		**				deducted.
		** Called by: play
		** Calls: setter and getter functions of Space, printShipStorage 
		** Passed: Space pointer
		** Returns: nothing
		**
		**********************************************************************/
		void abductOccupants(Space* space);

		/**********************************************************************
		** Function name: moveMenu
		** Description: This function contains the movement menu and movement
		**				mechanics. It first calls the printMap function to 
		**				display the structure map and user location. It then 
		**				displays the ship energy and presents a menu that allows
		**				the user to chose where to go. It uses if-else if 
		**				statements to assign the linked space that the user
		**				wants to travel to to the currentSpace pointer. It also
		**				decrements shipEnergy by two for every movement. 
		** Called by: play
		** Calls: printMap, getter functions of the Space class
		** Passed: Space pointer
		** Returns: nothing
		**
		**********************************************************************/
		void moveMenu(Space*& space);

		/**********************************************************************
		** Function name: CapturedRequiredAmount
		** Description: This function uses nested loops to check if the player
		**				abducted the required number of each individual types.
		**				If so, it assigns true to a bool flag that indicates
		**				that the game objective has been met. Otherwise, it
		**				prints a message indicating that it hasn't.
		** Called by: play
		** Calls: nothing
		** Passed: nothing
		** Returns: nothing
		**
		**********************************************************************/
		void capturedRequiredAmount();

		/**********************************************************************
		** Function name: printShipStorage
		** Description: This function prints out the values of the counters as
		**				well as offers the user to list the contents of the 
		**				ship storage queue from earliest abductee to latest.
		** Called by: play, abductOccupant
		** Calls: inputValid, queue empty, front, pop
		** Passed: nothing
		** Returns: nothing
		**
		**********************************************************************/
		void printShipStorage();

		/**********************************************************************
		** Function name: printMap
		** Description: This function prints out the map of the linked space
		**				structure of the game and marks the location of the 
		**				player's ship. It uses if-else and nested if statements
		**				to call the printSymbol function which prints the 
		**				symbolic string of each pointer relative to the player's
		**				current location.
		** Called by: moveMenu
		** Calls: getter and setter functions of Space, printSymbol of derived 
		**		  classes of Space.
		** Passed: Space pointer
		** Returns: nothing
		**
		**********************************************************************/
		void printMap(Space*& space);
	private:
		/* Private member variables that define the ship, game play, and spaces	
 		   of the linked space structure. */
		int shipEnergy; 
		unsigned int maxShipStorage;
		bool shipFull = false;
		bool capturedRequiredIndividuals = false;
		std::queue <string> shipStorage;
		Space* currentSpace = NULL;
		Space* one = new House;
		Space* two = new House;
		Space* three = new SmallForest;
		Space* four = new NuclearPlant;
		Space* five = new House;
		Space* six = new Zoo;
		Space* seven = new Zoo;
		Space* eight = new PoliceStation;
		Space* nine = new SmallForest;
		int peopleCounter = 0, dogCounter = 0, catCounter = 0, bearCounter = 0,
			penguinCounter = 0, giraffeCounter = 0;
		int minRequiredToCapture = 4;
};

#endif 
