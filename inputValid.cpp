/********************************************************************* 
** Function name: inputValid, isValidInteger, and inputValidRange
** Author: Kevin Ocampo
** Date: 6/10/2019
** Description: Final Project - Implementation file for functions that
**              determine if the user entered valid values for menu 
**              choices and prompt answers.
**              
*********************************************************************/
#include "inputValid.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

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
bool inputValid(string choice, int numChoices)
{
    bool flag = false;
    if(choice.length() == 1)
    {
        if(isdigit(choice.at(0)))
        {

            if(numChoices == 2)
            {    
                if(choice == "1" || choice == "2")
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
            
            if(numChoices == 3)
            {
                if(choice == "1" || choice == "2")
                {
                    flag = true;
                }
                else if(choice == "3")
                {
                    flag = true;
                }
                else
                {
                    
                    flag = false;
                }
            }

            if(numChoices == 4)
            {
                if(choice == "1" || choice == "2")
                {
                    flag = true;
                }
                else if(choice == "3" || choice == "4")
                {
                    flag = true;
                }
                else
                {
                    
                    flag = false;
                }
            }
        }
        else
        {
            flag = false;
        }
    }
    else
    {
        flag = false;
    }
    
    if(!flag)
    {
        cout << "You have entered an invalid selection. Please make a "
			 << "selection below." << endl;
    }
    return flag;
}

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
bool isValidInteger(std::string userIntegerInput, int& userInteger)
{
    bool flag = true;
    int checkExcept;
    int nonDigitCounter = 0;
    long unsigned int count = 0;

    for(count = 0; count < userIntegerInput.length(); count++)
    {
	   if(!(userIntegerInput.at(count) >= '0' && userIntegerInput.at(count)
		    <= '9'))
       {
       		nonDigitCounter++;
       }
        
    }
    if (nonDigitCounter > 0)
    {
        flag = false;
    }
    else
    {
        try 
        {
            checkExcept = stoi(userIntegerInput);
        }
        catch(...) 
        {
            flag = false;
        }
    }            

    if(flag == true)
    {
        userInteger = stoi(userIntegerInput);
    }
    else
    {
        cout << "You have entered an invalid value." << endl;
        flag = false;
    }

    return flag;
}

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
bool inputValidRange(string valueInput, float& value, float minValue, float
					 maxValue)
{
    bool flag = true;
    int checkExcept;
    int nonDigitCounter = 0;
    long unsigned int count = 0;

    for(count = 0; count < valueInput.length(); count++)
    {
        if(!(valueInput.at(count) >= '0' && valueInput.at(count) <= '9'))
        {
            nonDigitCounter++;
        }

        
    }
    if (nonDigitCounter > 0)
    {
        flag = false;
    }
    else
    {
        try 
        {
            checkExcept = stod(valueInput);
        }
        catch(...) 
        {
            flag = false;
        }
    }            

    if(flag == true)
    {
        value = stod(valueInput);
        if (value >= minValue && value <= maxValue) 
        {
            flag = true;
        }
        else
        {
            cout << "You have entered an invalid value." << endl;
            flag = false;
        }
    }
    else
    {
        cout << "You have entered an invalid value." << endl;
        flag = false;
    }


    return flag;
}
