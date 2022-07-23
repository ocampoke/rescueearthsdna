/********************************************************************** 
** Class name: Police Station
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The header file for the Police
**				Station class derived from the Space class..
**
***********************************************************************/      
#ifndef POLICESTATION
#define POLICESTATION

#include <iostream>
#include <iomanip>
#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class PoliceStation : public Space
{
	public:
		
		// Default constructor that defines the type and occupants of each Police Station object.
		PoliceStation();
		
		// Default destructor.
   		virtual ~PoliceStation();

		// Function that displays the number and types of individuals in the Police Station.
		virtual void inside();	
		
		/* Returns whether the occupants of the Police Station resist. Uses rand() to randomize
   		   the chance that they will resist. Also displays message indicating if the
   		   occupants are resisting. */
		virtual bool resistanceOffered();

		// Prints symbolic string of the Police Station and is called by printMap.
		virtual void printSymbol();
};

#endif 
