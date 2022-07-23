/********************************************************************** 
** Class name: Small Forest
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The header file for the Small
**				Forest class derived from the Space class.
**
***********************************************************************/      
#ifndef SMALLFOREST
#define SMALLFOREST

#include <iostream>
#include <iomanip>
#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class SmallForest : public Space
{
	public:

		// Default constructor that defines the type and occupants of each Small Forest object.
		SmallForest();
		
		// Default destructor.
   		virtual ~SmallForest();
		
		// Function that displays the number and types of individuals in the Small Forest..
		virtual void inside();

		/* Returns whether the occupants of the Small Forest resist. Uses rand() to randomize
   		   the chance that they will resist. Also displays message indicating if the
   		   occupants are resisting. */
		virtual bool resistanceOffered();

		// Prints symbolic string of the Small Forest and is called by printMap.
		virtual void printSymbol();
};

#endif 
