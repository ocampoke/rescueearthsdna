/********************************************************************* 
** Function name: inputValid, isValidInteger, and inputValidRange
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final project - Header file for functions that determine 
**              if the user entered valid values for menu choices and    
**              prompt answers.
**              
*********************************************************************/
#ifndef INPUTVALID_HPP
#define INPUTVALID_HPP

#include <iostream>
#include <string>

// Function prototypes.

/**********************************************************************
** Function name: inputValid
** Description: Checks if the user enters valid input for menus. 
**              Receives a user input string and an integer to define 
**              how many integers (starting sequentially from 1) count 
**              as valid menu selections. If the user enters invalid 
**              data (i.e. letters, integers that don't match menu 
**              options), the function prints a message indicating that 
**              the input was invalid and returns false. 
** Called by: menu
** Calls: isdigit
** Passed: string and integer
** Returns: boolean
**
**********************************************************************/
bool inputValid(std::string choice, int numChoices);

/**********************************************************************
** Function name: isValidInteger
** Description: Checks if the user enters a valid integer for prompts.
**              Receives a string and checks each character of the
**              string to determine whether it is a valid integer. If 
**              all the digits are integers, it then checks if the
**              string can be converted into an integer using exception
**              handling in the same manner as used in inputValidRange
**              using adapted code from source cited below. If all the
**              tests are passed, the user input string is converted 
**              to a string using stoi and assigned to the integer
**              passed as reference which allows it to be used in the
**              calling fuction. If a test fails, the function outputs 
**              a message indicating that the input is invalid and 
**              returns false.
** Called by: menu
** Calls: stoi
** Passed: string and integer
** Returns: boolean
**
************************************************************************
** Title: Answer to question: "Checking the int limits in stoi() 
**        function in C++ [duplicate]"
** Author: Sani Singh Huttunen
** Date: 2013
** Availability: https://stackoverflow.com/questions/18534036/checking-i
**		 the-int-limits-in-stoi-function-in-c
**
***********************************************************************/
bool isValidInteger(std::string userIntegerInput, int& userInteger);

/***********************************************************************
** Function name: inputValidRange
** Description: Checks if the user entered a valid input for prompts
**              asking for the value of user-defined variables.
**              Adapted code from source cited below to check if values
**              entered are valid integers (i.e. not negative or too
**              large). If the input is a valid integer, it is checked
**              to see if it falls in the range specificed by minValue 
**              and maxValue. If all the checks are passed, the string
**              input variable is converted into an int that is assigned 
**              to the variable passed as reference. This function
**              can be used to validate input for different types of
**              prompts as minValue and maxValue are user-defined.
** Called by: menu
** Calls: stoi
** Passed: string and three floats
** Returns: boolean
**
************************************************************************
** Title: Answer to question: "Checking the int limits in stoi() 
**        function in C++ [duplicate]"
** Author: Sani Singh Huttunen
** Date: 2013
** Availability: https://stackoverflow.com/questions/18534036/checking-i
**		 the-int-limits-in-stoi-function-in-c
**
***********************************************************************/
bool inputValidRange(std::string choice, float& value, float minValue, 
					 float maxValue);
#endif
