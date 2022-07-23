/************************************************************************ 
** Class name: Zoo
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the Zoo class
**				derived from the Space class.
**
************************************************************************/      
#include "zoo.hpp"

// Default constructor that defines the type and occupants of each Zoo object.
Zoo::Zoo() : Space("Zoo", 0, 0, 0, 0, 2, 2)
{
}

// Default destructor.
Zoo::~Zoo()
{
}

// Function that displays the number and types of individuals in the Zoo.
void Zoo::inside()
{
	cout << "You use the ship's infrared scanners on the zoo...." << endl;
	if(Space::getHasOccupants())
	{	
		cout << "There are " << Space::getNumPenguins() << " penguins and " 
			 << Space::getNumGiraffes() << " giraffes in the zoo." << endl;
		cout << "You use your ship's arm to rip through the fences of the zoo..." 
			 << endl << endl;
	}
	else
	{
		cout << "You have already abducted the animals of this zoo." 
			 << endl;
	}
}

/* Returns whether the occupants of the Zoo resist. Uses rand() to randomize
   		   the chance that they will resist. Also displays message indicating if the
   		   occupants are resisting. */
bool Zoo::resistanceOffered()
{
	bool resistanceOffered = false;

	int resistanceChance = rand() % 3;

	if(resistanceChance == 1 || resistanceChance == 2)
	{
		resistanceOffered = true;	
		cout << "The animals of the zoo are fighting back!" << endl;
	}
	return resistanceOffered;
}

// Prints symbolic string of the Zoo and is called by printMap.
void Zoo::printSymbol()
{
	string spaceName = "       Zoo      |";
	int printPadding = 17;
	cout << std::setw(printPadding) << spaceName;
}
