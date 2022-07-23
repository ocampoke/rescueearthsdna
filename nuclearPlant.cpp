/********************************************************************** 
** Class name: Nuclear Plant
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the Nuclear
**				Plant class derived from the Space class.
**
***********************************************************************/      
#include "nuclearPlant.hpp"

// Default constructor that defines the type and energy levels.
NuclearPlant::NuclearPlant() : Space("Nuclear Plant", 0, 0, 0, 0, 0, 0)
{
	Space::setEnergyUnits(5);
	Space::setHasOccupants(false);
}

// Default destructor.
NuclearPlant::~NuclearPlant()
{
}

/* Function that displays that there is no organic life or that there is no
   more energy to be retrieved. */
void NuclearPlant::inside()
{
	cout << "You use the ship's infrared scanners on the nuclear plant..." 
		 << endl;
	if(Space::getEnergyUnits() > 0)
	{
		cout << "Your scan reveals no organic life forms present but there is "
			 << "heat movement." << endl << "You use your ship's arm to rip "
			 <<  "the roof off the plant..." << endl << endl;
	}
	else
	{
		cout << "You have already extracted all the energy material at this "
			 << "plant." << endl;
	}	
}

// Displays the resistance offered by the plant.
bool NuclearPlant::resistanceOffered()
{
	bool resistanceOffered = true;

	cout << "The nuclear plant has automated defenses and has launched a "
		 << "missle at your ship!" << endl;
	return resistanceOffered;
}

// Prints symbolic string of the house and is called by printMap.
void NuclearPlant::printSymbol()
{
	string spaceName = " Nuclear Plant  |";
	int printPadding = 17;
	cout << std::setw(printPadding) << spaceName;
}

