# include <iostream>
# include <fstream>
#include "circle.h"
#include "line.h"
#include "vector.h"
#include "commands.h"
using namespace std;

double getGreater(double x1, double x2)
{
	switch (x1>x2)
	{
	case(true) : return x1;
	case(false) : return x2;
	}
}

double getLower(double x1, double x2)
{
	switch (x1<x2)
	{
	case(true) : return x1;
	case(false) : return x2;
	}
}

char * fullStrcat(char *leftArr, char *rightArr)
{
	int newArrSize = strlen(leftArr) + strlen(rightArr) + 1;
	char *newArr = new char[newArrSize];
	strcpy_s(newArr, newArrSize, leftArr);
	strcat_s(newArr, newArrSize, rightArr);
	cout << newArr << endl;
	return newArr;
}

int supportingColours(char *checkColour)
{
	if (!strcmp(checkColour, "black"))
	{
		return 0;
	}
	else if (!strcmp(checkColour, "red"))
	{
		return 1;
	}
	else if (!strcmp(checkColour, "blue"))
	{
		return 2;
	}
	else if (!strcmp(checkColour, "green"))
	{
		return 3;
	}
	else if (!strcmp(checkColour, "purple"))
	{
		return 4;
	}
	else if (!strcmp(checkColour, "orange"))
	{
		return 5;
	}
	else
	{
		cerr << "The colour you etered is not supported!\n";
		return -1;
	}
}

bool recogniseCommands(Commands &userCommands, char *command)
{
	if (!strcmp(command, "open"))
	{
		if (userCommands.c_open() == true)
			return true;
		else if (userCommands.c_open() == false)
			return false;
	}
	else if (!strcmp(command, "save"))
	{

	}
	else if (!strcmp(command, "saveas"))
	{

	}
	else if (!strcmp(command, "create"))
	{
		char figureType[50];
		cin >> figureType;
		if (userCommands.c_create(figureType) == true)
		{
			cout << "The figure " << figureType << " was successfully created!\n";
			return true;
		}
		else if (userCommands.c_create(figureType) == false)
		{
			cerr << "The figure " << figureType << " was not created!\'n";
			return false;
		}
	}
	else if (!strcmp(command, "print"))
	{
		userCommands.c_print();
		return true;
	}
	else if (!strcmp(command, "translate"))
	{
		Vector translateVector;
		cout << "vertical= ";
		double tempVertical;
		cin >> tempVertical;
		cout << " horisontal= ";
		double tempHorisontal;
		cin >> tempHorisontal;
		translateVector.setVector(tempVertical, tempHorisontal);
		char translateType[10];
		do
		{
			cout << "Do you want to translate all figures or just one?\nall - translate everyting, one - translates one figure.\n";
			cin >> translateType;
			if (!strcmp(translateType, "all"))
			{
				userCommands.c_translateAll(translateVector);
			}
			else if (!strcmp(translateType, "one"))
			{
				cout << "Which figure of the array do you want to translate?\n";
				int index;
				cin >> index;
				if (userCommands.c_translateOne(translateVector, index) == true)
					return true;
				else
					return false;
			}
		} while (strcmp(translateType,"all") != 0 && strcmp(translateType, "one")!=0);
		return true;
	}
	else if (!strcmp(command, "erase"))
	{
		int index; 
		cin >> index;
		if (userCommands.c_erase(index) == true)
			return true;
		else
			return false;
	}
	else if (!strcmp(command, "within"))
	{
		cout << "With what kind of region do you want to do the within command?\n cicle or rectangle?\n";
		cout << "If you choose circle you will enter then x, y of the center and radius.\n";
		cout << "If you choose rectangle you will enter then enter\n"
			<< "- x1, y1 coordinates for the bottom left point"
			<< "and x2, y2 coordinates for bottom right point.\n";
		char withinType[20];
		do
		{
			cin >> withinType;
			if (!strcmp(withinType, "circle"))
			{
				double x, y;
				cin >> x >> y;
				double r;
				cin >> r;
				if (userCommands.c_within(x + r, y + r, x - r, y - r) == false)
					cerr << "There are no figures in that region!\n";

			}
			else if (!strcmp(withinType, "rectangle"))
			{
				double x1, x2, y1, y2;
				cin >> x1 >> x2 >> y1 >> y2;
				if ( userCommands.c_within(getGreater(x1, x2), getGreater(y1, y2), getLower(x1, x2), getLower(y1, y2) == false) )
				{
					cerr << "There are no figures in that region!\n";
				}
			}
		} while (strcmp(withinType,"circle")!=0 && strcmp(withinType,"rectangle")!=0 ) ;
		return true;
	}
	else if (!strcmp(command, "close"))
	{
		
	}
	else
	{
		cerr << "The command you entered is uknown!\n";
		return false;
	}
}

int main(){
	char command[100];
	cout << "You will enter a command. The availble commands are:\n";
	cout << "open - opens a specific file from a directory you will give\n";
	cout << "close - close the file without saving the file you opened\n";
	cout << "save - save the changes in the  file you opened\n";
	cout << "saveas - save the work done by the program in a file directory you will give\n";
	cout << "exit - exits the program\n";
	cout << "print - prints all existing figures'\n";
	cout << "create - creates new figure\n";
	cout << "erase - deletes a figuré\n";
	cout << "translate - translates one or all figures. if you dont show a specific figure to be tranlated all will be translated.\n";
	cout << "within - shows all figures in a given area\n";
	cout << "--------------------------------------------------------------------------------------\n";

	// A test for push and pop functions
	/*
	Circle my;
	Circle him;
	my.create();
	him.create();
	ShapeContainer exapmple;
	exapmple.push(my.clone());
	exapmple.push(him.clone());
	exapmple.print();
	cout << "..........................................................\n";
	exapmple.pop(0);
	exapmple.print();
	*/

	bool FirstTime = true;
	Commands userCommands;
	do
	{
		if (FirstTime == true)
		{
			cout << "The first command shoud be open or exit. The other commands cannot be done if there's no opened file!\n";
			cout << "After the open command please insert directory for the file you want to open.\n";
		}
		cout << "Enter a command: ";
		cin >> command;

		if (!strcmp(command, "open"))
			FirstTime = false;
		if (FirstTime == true && strcmp(command, "open")!=0)
			continue;
		if (!strcmp(command, "exit"))
		{
			// трябва да затвориш файла
			return 0;
		}
		switch (recogniseCommands(userCommands,command))
		{
		case(true) : cout << "The command " << command << " was successfully executed!\n" << endl;
			break;
		case(false) : cerr << "The command " << command << " was not executed due to a problem!\n" << endl;
			break;
		}
	} while (strcmp(command, "exit") != 0);
	
	return 0;
}
