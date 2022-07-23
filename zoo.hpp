/************************************************************************ 
** Class name: Zoo
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The header file for the Zoo class
**				derived from the Space class.
**
************************************************************************/      
#ifndef ZOO
#define ZOO

#include <iostream>
#include <iomanip>
#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Zoo : public Space
{
	public:
		
		// Default constructor that defines the type and occupants of each Zoo object.
		Zoo();

		// Default destructor.
   		virtual ~Zoo();

		// Function that displays the number and types of individuals in the Zoo.
		virtual void inside();

		/* Returns whether the occupants of the Zoo resist. Uses rand() to randomize
   		   the chance that they will resist. Also displays message indicating if the
   		   occupants are resisting. */
		virtual bool resistanceOffered();

		// Prints symbolic string of the Zoo and is called by printMap.
		virtual void printSymbol();
};

#endif 
