/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Koby Montenegro
 */

#include "header.h"

string numbersInLetters[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string numbersInNumbers[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

//Use to easily get numbers
int getTheNumber(string input)
{
	for (int i = 0; i < 10; i++)
    	{
    	    //If number is valid then just stop the loop
    		if (numbersInLetters[i] == input || numbersInNumbers[i] == input)
    		{
    			break;
    		}
            //If number is not valid then return 10
    		else if (i >= 9)
    		{
    			return i;
    		}
            return i;
    	}
}



int main()
{
	std::cout<< "Please enter two single integers separated by an operator(+, -, *, /) and spaces\n";
	std::cout<< "You may use either numbers 0-9 or words zero-nine\n";
	std::cout<< "Please input them like this: 7 + 1 OR two * five\n";

	while (true)
	{
	    //GET THE NUMBERS
        string input1;
        string input2;
        char theOperator = 0;

        cin >> input1 >> theOperator >> input2;

		double num1 = getTheNumber(input1);
        double num2 = getTheNumber(input2);

        //END OF GETTING NUMBERS


        //CHECK THAT THE NUMBERS ARE SINGLE DIGIT AS WELL AS NOT NEGATIVE
        if(num1 > 9 || num2 > 9 || num1 < 0 || num2 < 0)
        {
            std::cout<< ("Stop! You can only input numbers from 0-9 or zero-nine. Please try again.\n");
            return 0;
        }
        //END OF CHECKING NUMBERS


        string function; //Use this to store the end result statement for the chosen operator
        double result; // Use this to store the actual number result

		cin >> theOperator; //Use this to get +, - , *, /

        //Where the actual calculator happens
		switch (theOperator)
		{
		case '+': //FOR ADDING
			function = "The Sum of ";
			result = num1+num2;
			break;
		case '-': //FOR SUBTRACTING
			function = "The Difference between ";
			result = num1-num2;
			break;
		case '*': //FOR MULTIPLYING
			function = "The Product of ";
			result = num1*num2;
			break;
		case '/': //FOR DIVIDING
			function = "The Quotient of ";
			if (num2==0)
			{
			    std::cout << ("You can't divide by zero!");
			}
			result = num1/num2;
			break;
		default: //For an unrecognizable input
				std::cout << ("Sorry, I don't recognize that...");
		}
        //CALCULATOR STUFF ENDS

        //Print results out here
		std::cout << function << num1 << " and " << num2 << " is " << result << ".\n";
	}
	return 0;
}