/********************************************************************** 
** Class name: Police Station
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the Police
**				Station class derived from the Space class..
**
***********************************************************************/      
#include "policeStation.hpp"

// Default constructor that defines the type and occupants of each Police Station object.
PoliceStation::PoliceStation() : Space("Police Station", 4, 2, 0, 0, 0, 0)
{
	Space::setHeavyResistance(true);
}

// Default destructor.
PoliceStation::~PoliceStation()
{
}


// Function that displays the number and types of individuals in the Police Station.
void PoliceStation::inside()
{
	cout << "You use the ship's infrared scanners on the Police station...." 
		 << endl;
	if(Space::getHasOccupants())
	{	
			cout << "There are " << Space::getNumPeople() << " people and " 
				 << Space::getNumDogs() << " dogs in the Police Station.";
			cout << endl << "You use your ship's arm to rip the roof off the "
				 << "Police station..." 
				 << endl << endl;
	}
	else
	{
		cout << "You have already abducted the occupants of this Police Station." 
			 << endl;
	}
}

/* Returns whether the occupants of the Police Station resist. Uses rand() to randomize
   the chance that they will resist. Also displays message indicating if the
   occupants are resisting. */
bool PoliceStation::resistanceOffered()
{
	bool resistanceOffered = true;	
	cout << "The officers in the Police Station are fighting back!" << endl;
	return resistanceOffered;
}

// Prints symbolic string of the Police Station and is called by printMap.
void PoliceStation::printSymbol()
{
	string spaceName = " Police Station |";
	int printPadding = 17;
	cout << std::setw(printPadding) << spaceName;
}
