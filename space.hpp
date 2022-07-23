/********************************************************************** 
** Class name: Space
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The header file for the Space class. It 
**				is an abstract class from which unique space classes are
**				derived
**
***********************************************************************/      
#ifndef SPACE
#define SPACE

#include <iostream>
#include <string>
#include <queue>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Space 
{
	public:
		
		// Default constructor of the Space class.
		Space();
		
		/* Setter and getter functions for the four direction pointer variables of
   		   the Space class. */
		Space(string newType, int newNumPeople, int newNumDogs, int newNumCats, 
			  int newNumBears, int newNumPenguins, int newNumGiraffes);	

		// Default destructor of the Space class.
   		virtual ~Space();

		// Pure virtual functions of the Space class.
		virtual void inside() = 0;
		virtual bool resistanceOffered() = 0;		
		virtual void printSymbol() = 0;

		// Setter and getter functions for the direction pointer variables.
		void setTop(Space* top);
		void setRight(Space* right);
		void setLeft(Space* left);
		void setBottom(Space* bottom);

		Space* getTop();
		Space* getRight();
		Space* getLeft();
		Space* getBottom();
		
		// Setter and getter functions of the characteristics of each space.
		bool containsEnergyUnits();
		int getEnergyUnits();
		string getSpaceType();
		bool getHasOccupants();
		bool getHeavyResistance();
		int getNumPeople();
		int getNumDogs();
		int getNumCats();
		int getNumBears();
		int getNumPenguins();
		int getNumGiraffes();

		void setHasOccupants(bool newHasOccupants);
		void setHeavyResistance(bool newHeavyResistance);
		void setEnergyUnits(int newEnergy);
		void setNumPeople(int newNumPeople);
		void setNumDogs(int newNumDogs);
		void setNumCats(int newNumCats);
		void setNumBears(int newNumBears);
		void setNumPenguins(int newNumPenguins);
		void setNumGiraffes(int newNumGiraffes);
		
	private:

		// Direction pointer variables.
		Space* top;
		Space* right;
		Space* left;
		Space* bottom;
		
		// Space characteristic variables.
		string type;
		bool hasOccupants = true;
		bool heavyResistance = false;
		int numPeople = 0, numDogs = 0, numCats = 0, numBears = 0,
			numPenguins = 0, numGiraffes = 0;
		int energy = 0;
};

#endif 
