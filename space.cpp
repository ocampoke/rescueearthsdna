/********************************************************************** 
** Class name: Space
** Author: Kevin Ocampo
** Date: 6/5/2019
** Description: Final Project - Implementation file for the Space class. 
**				It is an abstract class from which unique space classes are
**				derived.
**
***********************************************************************/      
#include "space.hpp"

// Default constructor of the Space class.
Space::Space()
{
}

/* Constructor that allows the definition of the type and number of individuals
   of each type of occupant through passed parameters. */
Space::Space(string newType, int newNumPeople, int newNumDogs, int newNumCats, 
			 int newNumBears, int newNumPenguins, int newNumGiraffes)
{
	type = newType;
	numPeople = newNumPeople;
	numDogs = newNumDogs;
	numCats = newNumCats;
	numBears = newNumBears;
	numPenguins = newNumPenguins;
	numGiraffes = newNumGiraffes;
}
 
// Default destructor of the Space class.
Space::~Space()
{
}

/* Setter and getter functions for the four direction pointer variables of
   the Space class. */
void Space::setTop(Space* top)
{
	this->top = top;
}

void Space::setRight(Space* right)
{
	this->right = right;
}

void Space::setLeft(Space* left)
{
	this->left = left;
}

void Space::setBottom(Space* bottom)
{
	this->bottom = bottom;
}

Space* Space::getTop()
{
	return top;	
}

Space* Space::getRight()
{
	return right;
}

Space* Space::getLeft()
{
	return left;
}

Space* Space::getBottom()
{
	return bottom;
}

// Checks if a space contains energy.
bool Space::containsEnergyUnits()
{
	if(energy > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Getter and setter functions for the characteristics of each space.
int Space::getEnergyUnits()
{
	return energy;
}

string Space::getSpaceType()
{
	return type;
}

bool Space::getHasOccupants()
{
	return hasOccupants;
}

bool Space::getHeavyResistance()
{
	return heavyResistance;
}

int Space::getNumPeople()
{
	return numPeople;
}
int Space::getNumDogs()
{
	return numDogs;
}

int Space::getNumCats()
{
	return numCats;
}

int Space::getNumBears()
{
	return numBears;
}

int Space::getNumPenguins()
{
	return numPenguins;
}

int Space::getNumGiraffes()
{
	return numGiraffes;
}

void Space::setHasOccupants(bool newHasOccupants)
{
	hasOccupants = newHasOccupants;
}

void Space::setHeavyResistance(bool newHeavyResistance)
{
	heavyResistance = newHeavyResistance;
}

void Space::setEnergyUnits(int newEnergy)
{
	energy = newEnergy;
}

void Space::setNumPeople(int newNumPeople)
{
	numPeople = newNumPeople;	
}

void Space::setNumDogs(int newNumDogs)
{
	numDogs = newNumDogs;
}

void Space::setNumCats(int newNumCats)
{
	numCats = newNumCats;
}

void Space::setNumBears(int newNumBears)
{
	numBears = newNumBears;
}

void Space::setNumPenguins(int newNumPenguins)
{
	numPenguins = newNumPenguins;
}

void Space::setNumGiraffes(int newNumGiraffes)
{
	numGiraffes = newNumGiraffes;
}
