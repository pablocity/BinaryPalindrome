// BinaryPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "HelperFunctions.h"

int main()
{
	
	char flag = '1';

	int min, max;

	do
	{
		
		bool emptyRange = true;
		std::cout << "Enter range of nonnegative, integer numbers (first minimum number, then maximum)\n";

		std::cin >> min;
		std::cin >> max;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nYour inputs must be numbers\n";
			continue;
		}

		if (min < 0 || max < 0)
		{
			std::cout << "\nNeither min nor max value can be negative\n";
			continue;
		}

		if (min > max)
		{
			std::cout << "\nYour range is reversed, please enter numbers in the specified order\n";
			continue;
		}

		for (int i = min; i < max; i++)
		{
			if (BinaryPalindrome(i))
			{
				std::cout << i << " b: " << ConvertToBinary(i) << std::endl;
				emptyRange = false;
			}
		}

		if (emptyRange)
			std::cout << "There were no binary palindromes in the given range." << std::endl;

		std::cout << "\nPress 1 to start again.\n";

		std::cin.ignore();
		flag = getchar();
	} 
	while (flag == '1');
	
}

std::string ConvertToBinary(int number)
{
	std::string result = "";

	while (number > 0)
	{
		result += std::to_string(number % 2);
		number /= 2;
	}

	return ReverseManual(result);
}

std::string Reverse(std::string text)
{
	std::reverse(text.begin(), text.end());
	return text;
}

std::string ReverseManual(std::string text)
{
	std::string result = "";

	for (int i = text.length() - 1; i > 0; i--)
	{
		result += text[i];
	}

	return text;
}

bool BinaryPalindrome(int number)
{
	std::string binaryNumber = ConvertToBinary(number);

	if (binaryNumber == Reverse(binaryNumber))
		return true;

	return false;
}