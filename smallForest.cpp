/********************************************************************** 
** Class name: Small Forest
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the Small
**				Forest class derived from the Space class.
**
***********************************************************************/      
#include "smallForest.hpp"

// Default constructor that defines the type and occupants of each Small Forest object.
SmallForest::SmallForest() : Space("Small Forest", 0, 0, 2, 2, 0, 0)
{
}

// Default destructor.
SmallForest::~SmallForest()
{
}

// Function that displays the number and types of individuals in the Small Forest..
void SmallForest::inside()
{
	cout << "You use the ship's infrared scanners on the small forest..." << endl;
	if(Space::getHasOccupants())
	{	
			cout << "There are " << Space::getNumBears() << " bears and "
				 << Space::getNumCats() << " cat in the small forest." << endl;
			cout << "You use your ship's arm to rip the canopy off the small "
				 << "forest..." << endl << endl;
	}
	else
	{
		cout << "You have already abducted all the animals in this forest." 
			 << endl;
	}
}

/* Returns whether the occupants of the Small Forest resist. Uses rand() to randomize
   the chance that they will resist. Also displays message indicating if the
   occupants are resisting. */
bool SmallForest::resistanceOffered()
{
	bool resistanceOffered = false;
	int resistanceChance = rand() % 3;
	int chanceHeavyResistance = rand() % 2;

	if(resistanceChance == 1 || resistanceChance == 2)
	{
		resistanceOffered = true;	
		cout << "The animals of the small forest fighting back!" << endl;
	}
	if(chanceHeavyResistance == 1)
	{
		Space::setHeavyResistance(true);
	}
	return resistanceOffered;
}

// Prints symbolic string of the Small Forest and is called by printMap.
void SmallForest::printSymbol()
{
	string spaceName = "  Small Forest  |";
	int printPadding = 17;
	cout << std::setw(printPadding) << spaceName;
}
