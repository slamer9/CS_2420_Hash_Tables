///
/********************************************************************************************
**	Project: Hash tables
**  Programmer: Duncan Reeves
**  Course:		cs2420
**	Section:	001
**	Assignment: 8?
**	Date:		March 27, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include <cctype>   //includes toupper, isupper, etc
#include <sstream>

#include "Hash.h"

//Global constant definitions
#define DEBUG false

//Global variable declaration
HashTable<double> myHashTable;

//Function declarations
bool populateHashTable(char fileName[]);
bool evaluateFileWeights(char fileName[]);
double evalFormula(string formula);
double calcElement(string abbriviation);


int main()
{
	char dataFileName[] = "PeriodicTableElements.txt";
	char formulaFileName[] = "formulas.txt";

	populateHashTable(dataFileName);

	evaluateFileWeights(formulaFileName);

	if(DEBUG == true)
	{
		myHashTable.displaySize();
	}

	cout << endl << endl << "Press the [Enter] key to quit...";
	getchar();
}

//Function definitions

bool populateHashTable(char fileName[])
{
	ifstream fileData;
	fileData.open(fileName/*, 0*/);
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << fileName << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		getchar();
		return false;
	}

	string elementData;
	unsigned int elementNumber;
	string abbriviation;
	double atomicWeight;
	while (getline(fileData, elementData) && !fileData.eof())
	{
		istringstream readString(elementData);

		readString >> elementNumber;   //Discard;
		readString >> abbriviation;
		readString >> atomicWeight;

		myHashTable.Insert(abbriviation, atomicWeight);
	}

	fileData.close();
	return true;
}

bool evaluateFileWeights(char fileName[])
{
	ifstream fileData;
	fileData.open(fileName/*, 0*/);
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << fileName << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		getchar();
		return false;
	}

	/*Loop and get every line in file
	//function to get total weight from every line of text in file.
	*/
	string formula;
	while (getline(fileData, formula) && !fileData.eof())
	{
		cout << endl << "Weight of " << formula << " = ";
		double formula_weight = evalFormula(formula);
		cout << formula_weight << " atomic units." << endl;
	}

	fileData.close();
	return true;
}

double evalFormula(string formula)
{
	unsigned int stringIndex = 0;
	double formula_weight = 0;

	while (stringIndex < formula.length())
	{
		unsigned int length = 0;
		if (isspace(formula[stringIndex]))
		{
			++stringIndex;
		}
		else if (formula[stringIndex] == '(')
		{
			double temp_weight = 0;
			length = 1;
			++stringIndex;

			while (formula[stringIndex + length] != ')')
			{
				++length;
			}

			temp_weight = evalFormula(formula.substr(stringIndex, length));
			stringIndex = stringIndex + length + 1;

			if (isdigit(formula[stringIndex]))
			{
				int multiplier = formula[stringIndex] - 48;    //changing from ascii to binary
				temp_weight *= multiplier;
				++stringIndex;
			}
			formula_weight += temp_weight;
		}
		else
		{
			length = 1;
			while (stringIndex + length < formula.length() && formula[stringIndex + length] != '(' && !isupper(formula[stringIndex + length]))
			{
				++length;
			}
			formula_weight += calcElement(formula.substr(stringIndex, length));
			stringIndex += length;
		}
	}

	return formula_weight;
}

double calcElement(string abbriviation)
{
	unsigned int length = 0;
	while (!isdigit(abbriviation[length]) && length < abbriviation.length())
	{
		++length;
	}

	string elementStr = abbriviation.substr(0, length);
	if (length < abbriviation.length())
	{
		return myHashTable[elementStr] * stod(abbriviation.substr(length));
	}

	return myHashTable[elementStr];
}
