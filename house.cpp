/********************************************************************** 
** Class name: House
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the House
**				class derived from the Space class.
**
***********************************************************************/      
#include "house.hpp"


// Default constructor that defines the type and occupants of each house object.
House::House() : Space("House", 3, 2, 0, 0, 0, 0)
{
}

// Default destructor.
House::~House()
{
}

// Function that displays the number and types of individuals in the house.
void House::inside()
{
	cout << "You use the ship's infrared scanners on the home...." << endl;
	if(Space::getHasOccupants())
	{	
			cout << "There are " << Space::getNumPeople() << " people, " 
				 << Space::getNumDogs() << " dogs in the house." << endl;
			cout << "You use your ship's arm to rip the roof off the house..." 
				 << endl << endl;
	}
	else
	{
		cout << "You have already abducted the occupants of this house." 
			 << endl;
	}
}

/* Returns whether the occupants of the house resist. Uses rand() to randomize
   the chance that they will resist. Also displays message indicating if the
   occupants are resisting. */
bool House::resistanceOffered()
{
	bool resistanceOffered = false;

	int resistanceChance = rand() % 3;

	if(resistanceChance == 1)
	{
		resistanceOffered = true;	
		cout << "The occupants of the house are fighting back!" << endl;
	}
	return resistanceOffered;
}

// Prints symbolic string of the house and is called by printMap.
void House::printSymbol()
{
	string spaceName = "     House      |";
	int printPadding = 17;
	cout << std::setw(printPadding) << spaceName;
}
