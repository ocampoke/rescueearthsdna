/********************************************************************** 
** Class name: Nuclear Plant
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The header file for the Nuclear
**				Plant class derived from Space class.
**
***********************************************************************/      
#ifndef NUCLEARPLANT
#define NUCLEARPLANT

#include <iostream>
#include <iomanip>
#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class NuclearPlant : public Space
{
	public:
		
		// Default constructor that defines the type and energy levels.
		NuclearPlant();
		
		// Default destructor.
   		virtual ~NuclearPlant();

		/* Function that displays that there is no organic life or that there is no
   		   more energy to be retrieved. */
		virtual void inside();

		// Displays the resistance offered by the plant.
		virtual bool resistanceOffered();

		// Prints symbolic string of the house and is called by printMap.
		virtual void printSymbol();
};

#endif 
