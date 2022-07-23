/********************************************************************** 
** Class name: House
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The header file for the House
**				class derived from the Space class.
**
***********************************************************************/      
#ifndef HOUSE
#define HOUSE

#include <iostream>
#include <iomanip>
#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class House : public Space
{
	public:

		// Default constructor that defines the type and occupants of each house object.
		House();
		
		// Default destructor.
   		virtual ~House();


		// Function that displays the number and types of individuals in the house.
		virtual void inside();

		/* Returns whether the occupants of the house resist. Uses rand() to randomize
   		   the chance that they will resist. Also displays message indicating if the
   		   occupants are resisting. */
		virtual bool resistanceOffered();
		
		// Prints symbolic string of the house and is called by printMap.
		virtual void printSymbol();
};

#endif 
