/************************************************************************ 
** Class name: Game
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - The implementation file for the Game 
**				class of Rescue Earth's DNA Game, an alien abduction game
**				played from the perspective of an alien in a space ship. 
**				It contains the functions that contain the game mechanics 
**				of the game. It utilizes variables to define the 
**				characteristics of the ship that provide a step-limit to 
**				the game. It also uses a bool flag variable and an int to 
**				determine if the user met or failed to achieve the
**				objective of the game. It utilizes an STL queue
**				container to represent the ship's storage where
**				abductees are stored. It also uses Space pointers to
**				define the linked space structure of the game, with
**				each pointer intialized to point to an object of the
**				five unique derived classes of Space that represent
**				different types of Spaces with unique actions that the
**				player interacts with. It also utilizes counters to
**				keep track of the amount of different abductees.
**
************************************************************************/      
#include "game.hpp"

/***********************************************************************
** Function name: Default constructor of the Game class
** Description: The default constructor of the Game class that
**				initializes the ship's energy and storage values and 
**				the four direction pointers of the nine Space derived 
**				class objects that make up the spaces of the linked 
**				space structure of the game.
** Called by: main
** Calls: setter functions of the Space class
** Passed: nothing
** Returns: nothing
**
***********************************************************************/
Game::Game()
{
	shipEnergy = 50;
	maxShipStorage = 30;
	one->setTop(two);
	one->setRight(three);
	one->setLeft(four);
	one->setBottom(NULL);

	two->setTop(five);
	two->setRight(six);
	two->setLeft(seven);
	two->setBottom(one);
	
	three->setTop(six);
	three->setRight(NULL);
	three->setLeft(one);
	three->setBottom(NULL);

	four->setTop(seven);
	four->setRight(one);
	four->setLeft(NULL);
	four->setBottom(NULL);

	five->setTop(NULL);
	five->setRight(eight);
	five->setLeft(nine);
	five->setBottom(two);

	six->setTop(eight);
	six->setRight(NULL);
	six->setLeft(two);
	six->setBottom(three);

	seven->setTop(nine);
	seven->setRight(two);
	seven->setLeft(NULL);
	seven->setBottom(four);

	eight->setTop(NULL);
	eight->setRight(NULL);
	eight->setLeft(five);
	eight->setBottom(six);

	nine->setTop(NULL);
	nine->setRight(five);
	nine->setLeft(NULL);
	nine->setBottom(seven);

}

/***********************************************************************
** Function name: Game destructor
** Description: The destructor of the Game class.
** Called by: main when the program exits.
** Calls: nothing
** Passed: nothing
** Returns: nothing
**
***********************************************************************/
Game::~Game()
{
}

/***********************************************************************
** Function name: play
** Description: This function contains the game mechanics of the Rescue 
**				Earth's DNA Game. It uses several menus that allow the
**				users to control the flow of the program. The menu's
**				utilize input validation to ensure that the user enters
**				a valid choice. The first menu asks the user if they 
**				want to play the game or replay the game if they chose
**				to play again. If the chooser chose to replay the game,
**				it dynamically allocates memory to a new Space derived
**				class object to the Space pointers that make up the 
**				linked space structure of the game. This is to necessary
**				as the pointers are deleted at the end of each iteration
**				of the game. The game begins by describing the back story
**				of the game and the gameplay mechanics. It then presents
**				a map of the Town which is actually a map of the linked
**				space structure of the game. The game play begins and 
**				starts by defining the currentSpace to the one Space 
**				object which is the center southern Space of the linked
**				space structure. The game mechanics involve calling 
**				functions that let the user know the type and number of
**				occupants of a space, whether it contains energy 
**				material, and whether the occupants are resisting. The
**				function then allows the user to capture or retrieve the
**				occupants or energy and to stun any defenders if 
**				resistance or heavy resistance occurs. Each individual
**				abduction and stunning occurence drains energy, and thus
**				the shipEnergy is reduced by the amount specified by each
**				interaction, with heavy resistance costing more than 
**				non-heavy resistance. The function includes the mechanics
**				for retrieving enery materials but calls the 
**				abductOccupants for the abduction mechanics. After all
**				the interactions at each space, the function then calls
**				a function that determines if the user met the objective
**				of the game, which is to capture a specified number of 
**				individuals of each type of abductee. The functions sets
**				the capturedRequiredIndividuals bool to true if the 
**				objective is met or otherwise lets the user that it is 
**				yet met. If the player's ship still has fuel or hasn't
**				met the game objectives, a menu function is called that
**				prints a map showing the player's current location and 
**				provides a menu that allows the user to move to another
**				space in a desired direction and the game mechanics 
**				repeats.. If the user runs out of energy or if the game 
**				objective is met, the game print out a message indicating 
**				whether or not the user completed the game objectives and
**				the game ends. The function then resets various variables
**				and one menu input to ensure the game is reset for another
**				iteration. It also frees up the memory allocated to the
**				nine space variables to ensure that the linked space 
**				structure is reset. The whole mechanic is in a while loop
**				so that the user is presented with a menu that allows the 
**				user to play again or exit, and the game continues
**				looping until the user chooses to exit.
** Called by: main 
** Calls: inputValid, cin.ignore, containsEnergyUnits, resistanceOffered,
**		  getter and setter functions of Space class, resistanceOffered,
**		  abductOccupants, capturedRequiredAmount, moveMenu, 
**		  printShipStorage, queue empty, queue pop, 
** Passed: nothing
** Returns: nothing
**
***********************************************************************/
void Game::play()
{	
	string playGameChoiceInput = "0", abductChoiceInput = "0", 
		   stunOrMoveChoiceInput = "0", moveMenuChoiceInput = "0", 
		   retrieveEnergyChoiceInput = "0";
	int numChoices = 2;
	bool firstRunFlag = true;
	
	do
	{
		cout << endl << endl << "***Rescue Earth's DNA Game***" << endl;
		if(firstRunFlag)
		{
			do
			{
				cout << "1. Play" << endl;
				cout << "2. Exit" << endl;
				cout << "Please make a selection: ";
				getline(cin, playGameChoiceInput);
				cout << endl;
			}while(!inputValid(playGameChoiceInput, numChoices));
			firstRunFlag = false;
		}
		else
		{
				one = new House;
				two = new House;
				three = new SmallForest;
				four = new NuclearPlant;
				five = new House;
				six = new Zoo;
				seven = new Zoo;
				eight = new PoliceStation;
				nine = new SmallForest;

				one->setTop(two);
				one->setRight(three);
				one->setLeft(four);
				one->setBottom(NULL);

				two->setTop(five);
				two->setRight(six);
				two->setLeft(seven);
				two->setBottom(one);
				
				three->setTop(six);
				three->setRight(NULL);
				three->setLeft(one);
				three->setBottom(NULL);

				four->setTop(seven);
				four->setRight(one);
				four->setLeft(NULL);
				four->setBottom(NULL);

				five->setTop(NULL);
				five->setRight(eight);
				five->setLeft(nine);
				five->setBottom(two);

				six->setTop(eight);
				six->setRight(NULL);
				six->setLeft(two);
				six->setBottom(three);

				seven->setTop(nine);
				seven->setRight(two);
				seven->setLeft(NULL);
				seven->setBottom(four);

				eight->setTop(NULL);
				eight->setRight(NULL);
				eight->setLeft(five);
				eight->setBottom(six);

				nine->setTop(NULL);
				nine->setRight(five);
				nine->setLeft(NULL);
				nine->setBottom(seven);
			do
			{
				cout << "1. Play again" << endl;
				cout << "2. Exit" << endl;
				cout << "Please make a selection: ";
				getline(cin, playGameChoiceInput);
				cout << endl;
			}while(!inputValid(playGameChoiceInput, numChoices));
		}

		if(playGameChoiceInput == "1")
		{
			cout << "It is 2150 and Earth is about to be destroyed..." << endl;
			cout << "A huge asteroid, traveling faster than the speed of light, "
				 << "will strike earth " << endl << "in one day..."
				 << endl << endl;
			cout << "You are an alien, a member of an intergalactic space-faring, "
				 << "benevolent species," << endl << "on an exploratory mission of "
				 << "earth. You have just been notified by the Intergalactic " << endl 
				 << "Scientific Agency of your home planet that you are the only "
				 << "scientist in the Milky " << endl << "Way with a ship capable of "
				 << "carrying life forms and that no other scientists can " << endl
				 << "reach Earth before it is destroyed by the asteroid. You have "
				 << "been entrusted with " << endl << "rescuing at least a tiny amount "
				 << "of the genetic diversity of Earth. However, your " << endl << "ship"
				 << " is not equipped with a long-range teleporter and you must pick "
				 << "up your samples " << endl << "with a mechanical arm attached "
				 << "to the bottom of your ship because your species is " << endl 
				 << "dimunitive and you are only a foot tall. In addition, your ship "
				 << "is equipped with a" << endl << "stun-gun to temporarily paralyze "
				 << "any organic life and electronic devices. However," << endl
				 << "because your ship is not designed to fly in earth's gravitational"
				 << " field, you must" << endl << "run your quantum engines at full "
				 << "speed to hover and thus your ship has limited" << endl
				 << "energy reserves to expend before you are unable to "
				 << "return home." << endl 
				 << endl;
			
			cout << "Press enter to continue the game..." << endl;
			cin.ignore();	

			cout << "Your scientists have indicated that they desire at least four "
				 << "individuals of any" << endl << "species you may find in order to "
				 << "obtain enough genetic diversity to sustain their" << endl 
				 << "survival." << endl << endl;

			cout << "Your ship currently has " << shipEnergy << " energy units and "
				 << maxShipStorage << " storage spaces.";
			cout << endl << "When you capture your specimens at a specific location, "
				 << "you must abduct all the " << endl << "occupants to save time"
				 << " and to avoid leaving witnesses who may cause alarm. Each"
				 << endl << "individual requires 1 energy unit to abduct."
				 << " If individuals at a location resist," << endl << "you may first" 
				 << " stun them before capturing them for an additional energy " 
				 << endl << "unit or choose to move on. Each movement costs 2"
				 << " energy units." 
				 << endl << endl;
			
			cout << "Press enter to continue the game..." << endl;
			cin.ignore();		

			cout << "You perform a planetary-wide scan of the Earth's surface."
				 << "You decide to obtain your " << endl << "samples from a small town" 
			     << " that has two zoos, a couple small forests, a few homes" << endl 
				 << "a police station, and a nuclear plant." << endl << endl;
			
			cout << "Your ship's computer prints you the following map: " << endl << endl;
			cout << std::string(20, ' ') << "*Town Map*" << std::string(21, ' ') << endl;
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
				 		<< std::string(16, ' ') << "|" << endl;
			
			cout << "|" << setw(17) << "  Small Forest  |" << setw(17) << "     House      |"
				 << setw(17) << " Police Station |" << endl;
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
				 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
				<< std::string(16, ' ') << "|" << endl;

			cout << "|" << setw(17) << "       Zoo      |" << setw(17) << "     House      |"
				 << setw(17) << "       Zoo      |" << endl;
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
				 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
				<< std::string(16, ' ') << "|" << endl;

			cout << "|" << setw(17) << " Nuclear Plant  |" << setw(17) << "     House      |"
				 << setw(17) << "  Small Forest  |"  << endl;
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
				 << std::string(16, '_') << "|" << endl << endl;
				 
			cout << "You approach and hover over one" << endl << "of "
				 << "the homes at the southern end of the town." << endl 
				 << endl;
			currentSpace = one;	
				
			while(shipEnergy > 0 && !capturedRequiredIndividuals)
			{
				currentSpace->inside();
				numChoices = 2;
				
				if(currentSpace->containsEnergyUnits())
				{
					do
					{
						cout << "The nuclear plant contains material your ship can "
							 << "process into 5 energy units!" << endl << "Do you want"
							 << " to retrieve it?" << endl;
						cout << "1. Yes" << endl;
						cout << "2. No" << endl;
						cout << "Please make a selection: ";
						getline(cin, retrieveEnergyChoiceInput);
						cout << endl;
					}while(!inputValid(retrieveEnergyChoiceInput, numChoices));

					if(retrieveEnergyChoiceInput == "1")
					{
						currentSpace->resistanceOffered();
								
						numChoices = 2;
						do
						{
							cout << "Do you want to stun the missle to disable it "
							     << "before retrieving the material for" << endl 
								 << "1 energy unit?" << endl; 
							cout << "1. Stun the missle and retrieve the material." << endl;
							cout << "2. Move on." << endl;
							cout << "Please make a selection: ";
							getline(cin, stunOrMoveChoiceInput);
							cout << endl;
						}while(!inputValid(stunOrMoveChoiceInput, numChoices));

						if(stunOrMoveChoiceInput == "1")
						{
							shipEnergy = shipEnergy - 1;
							shipEnergy = shipEnergy + currentSpace->getEnergyUnits();
							currentSpace->setEnergyUnits(currentSpace->getEnergyUnits()
													  - currentSpace->getEnergyUnits()); 	
						}
					}
				}
				else if(currentSpace->getHasOccupants())
				{	
					if(shipEnergy > 3)
					{
						do
						{
							cout << "Do you want to capture the occupants at a cost of 1 " 
								 << "energy unit per occupant?" << endl;
							cout << "1. Yes" << endl;
							cout << "2. No" << endl;
							cout << "Please make a selection: ";
							getline(cin, abductChoiceInput);
							cout << endl;
						}while(!inputValid(abductChoiceInput, numChoices));
					}
					else
					{
						cout << "Your ship does not have enough energy to power it's arm to "
							 << "abduct the occupants!" << endl;
						abductChoiceInput = "0";
					}

					if(abductChoiceInput == "1")
					{
						if(currentSpace->resistanceOffered())
						{
							numChoices = 2;

							if(currentSpace->getHeavyResistance())
							{
								cout << "The defenders are putting up a strong defense!"
									 << endl;
								cout << "You may defeat them if you increase the energy "
									 << "allocated to your stun gun, but" << endl 
									 << "it will cause a significant depletion of your "
									 << "ship's energy." 
									 << endl << endl;
								do
								{
								cout << "Do you want to increase the power of your stun gun"
									 << " and stun the occupants before" << endl 
								     << "capturing them for 4 energy units or move on?" 
									 << endl; 
								cout << "1. Stun the occupants and capture them. " << endl;
								cout << "2. Move on." << endl;
								cout << "Please make a selection: ";
								getline(cin, stunOrMoveChoiceInput);
								cout << endl;
								}while(!inputValid(stunOrMoveChoiceInput, numChoices));
							}
							else
							{
								do
								{
									cout << "Do you want to stun the occupants before "
									     << "capturing them for one energy unit or" << endl 
										 << "move on?" << endl; 
									cout << "1. Stun the occupants and capture them. " 
										 << endl;
									cout << "2. Move on." << endl;
									cout << "Please make a selection: ";
									getline(cin, stunOrMoveChoiceInput);
									cout << endl;
								}while(!inputValid(stunOrMoveChoiceInput, numChoices));
							}
							if(stunOrMoveChoiceInput == "1" && 
							!currentSpace->getHeavyResistance())
							{
								shipEnergy = shipEnergy - 1;
								Game::abductOccupants(currentSpace);			
							}
							else if(stunOrMoveChoiceInput == "1" && 
									currentSpace->getHeavyResistance())
							{
								shipEnergy = shipEnergy - 4;
								Game::abductOccupants(currentSpace);			
							}
						}
						else
						{
							Game::abductOccupants(currentSpace);			
						}
			
					}
				}
				Game::capturedRequiredAmount();
				if(shipEnergy > 0 && !capturedRequiredIndividuals)
				{
					moveMenu(currentSpace);
				}
			}
		}
		if(shipEnergy <= 0 && !capturedRequiredIndividuals)
		{
			cout << "*Mission Failure*" << endl;
			cout << "Unfortunately, you ran out of energy and your ship is "
				 << "now stranded in the town." << endl << "The asteroid arrived the "
				 << "next day and wiped out all evidence of life on Earth..." << endl;
		}
		else if(capturedRequiredIndividuals)
		{
			cout << "*Mission Accomplished!*" << endl;
			cout << endl;
			cout << "You have successfully retrieved at least four individuals of "
				 << "six earth species. You fly " << endl << "back to your homeworld, "
				 << "where your scientists welcome the survivors and assist" << endl
				 << "them in continuing Earth's genetic legacy for millions " 
				 << "of years." << endl << endl;
			Game::printShipStorage();
		}

		shipEnergy = 50, abductChoiceInput = "0";
		peopleCounter = 0, dogCounter = 0, catCounter = 0, bearCounter = 0,
		penguinCounter = 0, giraffeCounter = 0;
		capturedRequiredIndividuals = false;
		shipFull = false;
		while(!shipStorage.empty())
		{
			shipStorage.pop();
		}
		delete one;
		delete two;
		delete three;
		delete four;
		delete five;
		delete six;
		delete seven;
		delete eight;
		delete nine;
	}while(playGameChoiceInput != "2");
}

/**********************************************************************
** Function name: abductOccupants
** Description: This function contains the abduction mechanics. It 
**				checks if the space has each type of individual. If it
**				does, it uses a for loop to add the individual to the
**				ship storage queue, decrement shipEnergy, and increment
**				the individual type counters. If the ship storage is 
**				larger than the max ship storage size, it indicates so 
**				and nothing is added to ship storage nor is energy
**				deducted.
** Called by: play
** Calls: setter and getter functions of Space, printShipStorage
** Passed: Space pointer
** Returns: nothing
**
**********************************************************************/
void Game::abductOccupants(Space* currentSpace)
{
	
	cout << "You are now abducting the occupants." << endl << endl;
	currentSpace->setHasOccupants(false);
	
	if(currentSpace->getNumPeople() > 0)
	{
		int numPeople = currentSpace->getNumPeople();
		for(int count = 0; count < numPeople; count++)
		{
			if(shipStorage.size() < maxShipStorage)
			{
				shipStorage.push("Human");
				shipEnergy--;
				peopleCounter++;
				currentSpace->setNumPeople(currentSpace->getNumPeople() - 1);	
			}
			else if(!shipFull)
			{
				cout << "Unfortunately, you do not have anymore ship storage "
					 << "to abduct another individual!" << endl << endl;
				shipFull = true;
			}
		}
	}
	
	if(currentSpace->getNumDogs() > 0)
	{
		int numDogs = currentSpace->getNumDogs();
		for(int count = 0; count < numDogs; count++) 
		{
			if(shipStorage.size() < maxShipStorage)
			{
				shipStorage.push("Dog");
				shipEnergy--;
				dogCounter++;
				currentSpace->setNumDogs(currentSpace->getNumDogs() - 1);
			}
			else if(!shipFull)
			{
				cout << "Unfortunately, you do not have anymore ship storage "
					 << "to abduct another individual!" << endl << endl;
				shipFull = true;
			}
		}
	}

	if(currentSpace->getNumCats() > 0)
	{
		int numCats = currentSpace->getNumCats();
		for(int count = 0; count < numCats; count++) 
		{
			if(shipStorage.size() < maxShipStorage)
			{
				shipStorage.push("Cat");
				shipEnergy--;
				catCounter++;
				currentSpace->setNumCats(currentSpace->getNumCats() - 1);
			}
			else if(!shipFull)
			{
				cout << "Unfortunately, you do not have anymore ship storage "
					 << "to abduct another individual!" << endl << endl;;
				shipFull = true;
			}
		}
	}

	if(currentSpace->getNumBears() > 0)
	{
		int numBears = currentSpace->getNumBears();
		for(int count = 0; count < numBears; count++) 
		{
			if(shipStorage.size() < maxShipStorage)
			{
				shipStorage.push("Bear");
				shipEnergy--;
				bearCounter++;
				currentSpace->setNumBears(currentSpace->getNumBears() - 1);
			}
			else if(!shipFull)
			{
				cout << "Unfortunately, you do not have anymore ship storage "
					 << "to abduct another individual!" << endl << endl;;
				shipFull = true;
			}
		}
	}

	if(currentSpace->getNumPenguins() > 0)
	{
		int numPenguins = currentSpace->getNumPenguins();
		for(int count = 0; count < numPenguins; count++) 
		{
			if(shipStorage.size() < maxShipStorage)
			{
				shipStorage.push("Penguins");
				shipEnergy--;
				penguinCounter++;
				currentSpace->setNumPenguins(currentSpace->getNumPenguins() - 1);
			}
			else if(!shipFull)
			{
				cout << "Unfortunately, you do not have anymore ship storage "
					 << "to abduct another individual!" << endl << endl;;
				shipFull = true;
			}
		}
	}

	if(currentSpace->getNumGiraffes() > 0)
	{
		int numGiraffes = currentSpace->getNumGiraffes();
		for(int count = 0; count < numGiraffes; count++) 
		{
			if(shipStorage.size() < maxShipStorage)
			{
				shipStorage.push("Giraffe");
				shipEnergy--;
				giraffeCounter++;
				currentSpace->setNumGiraffes(currentSpace->getNumGiraffes() - 1);
			}
			else if(!shipFull)
			{
				cout << "Unfortunately, you do not have anymore ship storage "
					 << "to abduct another individual!" << endl << endl;;
				shipFull = true;
			}

		}
	}
	Game::printShipStorage();

}

/**********************************************************************
** Function name: moveMenu
** Description: This function contains the movement menu and movement
**				mechanics. It first calls the printMap function to 
**				display the structure map and user location. It then 
**				displays the ship energy and presents a menu that allows
**				the user to chose where to go. It uses if-else if 
**				statements to assign the linked space that the user
**				wants to travel to to the currentSpace pointer. It also
**				decrements shipEnergy by two for every movement. 
** Called by: play
** Calls: printMap, getter functions of the Space class
** Passed: Space pointer
** Returns: nothing
**
**********************************************************************/
void Game::moveMenu(Space*& currentSpace)
{
	bool movedSpace = false;
	string(moveMenuChoiceInput);

	cout << endl;
	Game::printMap(currentSpace);
	do
	{
		cout << "Ship energy is now: " << shipEnergy << endl;
    	cout << "Where do you want to head now?" << endl;
	
		int numChoices = 4;	
		do
		{
			cout << "1. North: "; 
			if(currentSpace->getTop() != NULL)
			{
				cout << currentSpace->getTop()->getSpaceType() << endl;
			}
			else
			{
				cout << "Empty desert with no inhabitants." << endl;
			}
			cout << "2. East: "; 
			if(currentSpace->getRight() != NULL)
			{
				cout << currentSpace->getRight()->getSpaceType() << endl;
			}
			else
			{
				cout << "Empty desert with no inhabitants." << endl;
			}	
			cout << "3. West: "; 
			if(currentSpace->getLeft() != NULL)
			{
				cout << currentSpace->getLeft()->getSpaceType() << endl;
			}
			else
			{
				cout << "Empty desert with no inhabitants." << endl;
			}		
			cout << "4. South: "; 
			if(currentSpace->getBottom() != NULL)
			{
				cout << currentSpace->getBottom()->getSpaceType() << endl;
			}
			else
			{
				cout << "Empty desert with no inhabitants" << endl;
			}	
			cout << "Please make a selection: ";
			getline(cin, moveMenuChoiceInput);
			cout << endl;
		}while(!inputValid(moveMenuChoiceInput, numChoices));

		if(moveMenuChoiceInput == "1")
		{
			if(currentSpace->getTop() != NULL)
			{
				currentSpace = currentSpace->getTop();
				movedSpace = true;
				shipEnergy = shipEnergy - 2;
			}
			else
			{
				cout << "Unfortunately you do not have time to explore! "
					 << "Choose an inhabited location." << endl << endl;
			}
		}
		else if(moveMenuChoiceInput == "2")
		{	
			if(currentSpace->getRight() != NULL)
			{
				currentSpace = currentSpace->getRight();
				movedSpace = true;
				shipEnergy = shipEnergy - 2;
			}
			else
			{
				cout << "Unfortunately you do not have time to explore! "
					 << "Choose an inhabited location." << endl << endl;
			}

		}
		else if(moveMenuChoiceInput == "3")
		{
			if(currentSpace->getLeft() != NULL)
			{
				currentSpace = currentSpace->getLeft();
				movedSpace = true;
				shipEnergy = shipEnergy - 2;
			}
			else
			{
				cout << "Unfortunately you do not have time to explore! "
					 << "Choose an inhabited location." << endl << endl;
			}
		}
		else if(moveMenuChoiceInput == "4")
		{
			if(currentSpace->getBottom() != NULL)
			{
				currentSpace = currentSpace->getBottom();
				movedSpace = true;
				shipEnergy = shipEnergy - 2;
			}
			else
			{
				cout << "Unfortunately you do not have time to explore! "
					 << "Choose an inhabited location." << endl << endl;
			}
		}	
	}while(!movedSpace);

}

/**********************************************************************
** Function name: CapturedRequiredAmount
** Description: This function uses nested loops to check if the player
**				abducted the required number of each individual types.
**				If so, it assigns true to a bool flag that indicates
**				that the game objective has been met. Otherwise, it
**				prints a message indicating that it hasn't.
** Called by: play
** Calls: nothing
** Passed: nothing
** Returns: nothing
**
**********************************************************************/
void Game::capturedRequiredAmount()
{
	if(peopleCounter >= minRequiredToCapture)
	{
		if(dogCounter >= minRequiredToCapture)
		{
			if(catCounter >= minRequiredToCapture)
			{
				if(bearCounter >= minRequiredToCapture)
				{
					if(penguinCounter >= minRequiredToCapture)
					{
						if(giraffeCounter >= minRequiredToCapture)
						{
							capturedRequiredIndividuals = true;
						}
					}
				}
			}
		}
	}
	if(!capturedRequiredIndividuals)
	{
		cout << "You have not captured the required amount of individuals." 
	         << endl << endl;
	}
}

/**********************************************************************
** Function name: printShipStorage
** Description: This function prints out the values of the counters as
**				well as offers the user to list the contents of the 
**				ship storage queue from earliest abductee to latest.
** Called by: play, abductOccupant
** Calls: inputValid, queue empty, front, pop
** Passed: nothing
** Returns: nothing
**
**********************************************************************/
void Game::printShipStorage()
{
	int numChoices = 2;
	string printShipStorageChoiceInput, printListChoiceInput;
	std::queue<string> storageCopy;

	do
	{
		cout << "Do you want to print a list of your ship's storage contents?"
			 << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cout << "Please make a selection: ";
		getline(cin, printShipStorageChoiceInput);
		cout << endl;
	}while(!inputValid(printShipStorageChoiceInput, numChoices));

	if(printShipStorageChoiceInput == "1")
	{
		if(!shipStorage.empty())
		{
			cout << "Your ship's storage currently contains: " << endl;
			if(peopleCounter > 0)
			{
				cout << "Humans: " << peopleCounter << endl;
			}

			if(dogCounter > 0)
			{
				cout << "Dogs: " << dogCounter << endl;
			}

			if(catCounter > 0)
			{
				cout << "Cats: " << catCounter << endl;
			}

			if(bearCounter > 0)
			{
				cout << "Bears: " << bearCounter << endl;
			}
			
			if(penguinCounter > 0)
			{
				cout << "Penguins: " << penguinCounter << endl;
			}

			if(giraffeCounter > 0)
			{
				cout << "Giraffes: " << giraffeCounter << endl;
			}
			cout << endl;
			
			do
			{
				cout << "Do you want a print a list of the individuals in the "
					 << "ship's storage sorted by " << endl  << "order of "
					 << "abduction?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cout << "Please make a selection: ";
				getline(cin, printListChoiceInput);
				cout << endl;
			}while(!inputValid(printListChoiceInput, numChoices));

			if(printListChoiceInput == "1")
			{
				cout << "Your ship's storage now contains the following "
					 << "individuals from earliest to latest" << endl
					 << "abducted:" << endl;
				storageCopy = shipStorage;
				while(!storageCopy.empty())
				{
					cout << storageCopy.front() << endl;
					storageCopy.pop();
				}
				cout << endl;
			}
		}
		else 
		{
			cout << "Your ship's storage is currently empty." << endl;
		}
	}
}
		
/**********************************************************************
** Function name: printMap
** Description: This function prints out the map of the linked space
**				structure of the game and marks the location of the 
**				player's ship. It uses if-else and nested if statements
**				to call the printSymbol function which prints the 
**				symbolic string of each pointer relative to the player's
**				current location.
** Called by: moveMenu
** Calls: getter and setter functions of Space, printSymbol of derived 
**		  classes of Space.
** Passed: Space pointer
** Returns: nothing
**
**********************************************************************/
void Game::printMap(Space*& space)
{
	cout << std::string(20, ' ') << "*Town Map*" << std::string(21, ' ') << endl;
	cout << "Your current position is marked *X* on the map below." << endl;
	if(currentSpace->getBottom() == NULL)
	{
		if(currentSpace->getLeft() != NULL && currentSpace->getRight() != NULL) 	
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getTop()->getTop()->getLeft()->printSymbol();
			currentSpace->getTop()->getTop()->printSymbol();
			currentSpace->getTop()->getTop()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getTop()->getLeft()->printSymbol();
			currentSpace->getTop()->printSymbol();
			currentSpace->getTop()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getLeft()->printSymbol();
			cout << std::setw(17) << "      *X*       |";      	
			currentSpace->getRight()->printSymbol();
			cout << endl;
		
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		else if(currentSpace->getLeft() == NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getTop()->getTop()->printSymbol();
			currentSpace->getTop()->getTop()->getRight()->printSymbol();
			currentSpace->getTop()->getTop()->getRight()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getTop()->printSymbol();
			currentSpace->getTop()->getRight()->printSymbol();
			currentSpace->getTop()->getRight()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			cout << std::setw(17) << "      *X*       |";      	
			currentSpace->getRight()->printSymbol();
			currentSpace->getRight()->getRight()->printSymbol();
			cout << endl;
		
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		else if(currentSpace->getRight() == NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;
			
			cout << "|";
			currentSpace->getTop()->getTop()->getLeft()->getLeft()->printSymbol();
			currentSpace->getTop()->getTop()->getLeft()->printSymbol();
			currentSpace->getTop()->getTop()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getTop()->getLeft()->getLeft()->printSymbol();
			currentSpace->getTop()->getLeft()->printSymbol();
			currentSpace->getTop()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getLeft()->getLeft()->printSymbol();
			currentSpace->getLeft()->printSymbol();
			cout << std::setw(17) << "      *X*       |";      	
			cout << endl;
		
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		
	}
	else if(currentSpace->getTop() != NULL && currentSpace->getBottom() != NULL)
	{
		if(currentSpace->getLeft() != NULL && currentSpace->getRight() !=NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;
			
			cout << "|";
			currentSpace->getTop()->getLeft()->printSymbol();
			currentSpace->getTop()->printSymbol();
			currentSpace->getTop()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getLeft()->printSymbol();
		 	cout << std::setw(17) << "      *X*       |";      	
			currentSpace->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getLeft()->printSymbol();
			currentSpace->getBottom()->printSymbol();
			currentSpace->getBottom()->getRight()->printSymbol();
			cout << endl;
	
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		else if(currentSpace->getLeft() == NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;
			cout << "|";
			
			currentSpace->getTop()->printSymbol();
			currentSpace->getTop()->getRight()->printSymbol();
			currentSpace->getTop()->getRight()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
		 	cout << std::setw(17) << "      *X*       |";      	
			currentSpace->getRight()->printSymbol();
			currentSpace->getRight()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->printSymbol();
			currentSpace->getBottom()->getRight()->printSymbol();
			currentSpace->getBottom()->getRight()->getRight()->printSymbol();
			cout << endl;
	
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		else if(currentSpace->getRight() == NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;
				
			cout << "|";
			currentSpace->getTop()->getLeft()->getLeft()->printSymbol();
			currentSpace->getTop()->getLeft()->printSymbol();
			currentSpace->getTop()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getLeft()->getLeft()->printSymbol();
			currentSpace->getLeft()->printSymbol();
		 	cout << std::setw(17) << "      *X*       |";      	
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getLeft()->getLeft()->printSymbol();
			currentSpace->getBottom()->getLeft()->printSymbol();
			currentSpace->getBottom()->printSymbol();
			cout << endl;
	
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		
	}
	if(currentSpace->getTop() == NULL)
	{
		if(currentSpace->getLeft() != NULL && currentSpace->getRight() != NULL) 	
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getLeft()->printSymbol();
			cout << std::setw(17) << "      *X*       |";      	
			currentSpace->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getLeft()->printSymbol();
			currentSpace->getBottom()->printSymbol();
			currentSpace->getBottom()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getBottom()->getLeft()->printSymbol();
			currentSpace->getBottom()->getBottom()->printSymbol();
			currentSpace->getBottom()->getBottom()->getRight()->printSymbol();
			cout << endl;
		
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		else if(currentSpace->getLeft() == NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;

			cout << "|";
			cout << std::setw(17) << "      *X*       |";      	
			currentSpace->getRight()->printSymbol();
			currentSpace->getRight()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->printSymbol();
			currentSpace->getBottom()->getRight()->printSymbol();
			currentSpace->getBottom()->getRight()->getRight()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getBottom()->printSymbol();
			currentSpace->getBottom()->getBottom()->getRight()->printSymbol();
			currentSpace->getBottom()->getBottom()->getRight()->getRight()->printSymbol();
			cout << endl;
		
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		else if(currentSpace->getRight() == NULL)
		{
			cout << std::string(52, '_') << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		 << std::string(16, ' ') << "|" << endl;
			
			cout << "|";
			currentSpace->getLeft()->getLeft()->printSymbol();
			currentSpace->getLeft()->printSymbol();
			cout << std::setw(17) << "      *X*       |";      	
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getLeft()->getLeft()->printSymbol();
			currentSpace->getBottom()->getLeft()->printSymbol();
			currentSpace->getBottom()->printSymbol();
			cout << endl;
			
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
			cout << "|" << std::string(16, ' ') << "|" << std::string(16, ' ') << "|" 
		 		<< std::string(16, ' ') << "|" << endl;

			cout << "|";
			currentSpace->getBottom()->getBottom()->getLeft()->getLeft()->printSymbol();
			currentSpace->getBottom()->getBottom()->getLeft()->printSymbol();
			currentSpace->getBottom()->getBottom()->printSymbol();
			cout << endl;
		
			cout << "|" << std::string(16, '_') << "|" << std::string(16, '_') << "|" 
		 		 << std::string(16, '_') << "|" << endl;
		}
		
	}
}
