#include <iostream>
#include "line.h"
#include <fstream>
#include <iostream>
using namespace std;

void Line::print()
{
	cout << "line " << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << "colour: ";
	switch (stroke)
	{
	case(BLACK) : cout << "black\n"; break;
	case(RED) : cout << "red\n"; break;
	case(BLUE) : cout << "blue\n"; break;
	case(GREEN) : cout << "green\n"; break;
	case(PURPLE) : cout << "purple\n"; break;
	case(ORANGE) : cout << "orange\n"; break;
	default: cout << "Problem with finding the colour for the circle!\n";
		break;
	}
}

void Line::translate(Vector &translateVector)
{
	x1 += translateVector.getCoordX();
	x2 += translateVector.getCoordX();
	y1 += translateVector.getCoordY();
	y2 += translateVector.getCoordY();
}

void Line::create()
{
	cout << "...........................................................\n";
	cout << "You will create a line."
		<< "It contains the following things that you will now enter:\n" << endl
		<< "x1 and y1 coordinats of the first point, x2 and y2 coordinates of the second point, and colour of the line.\n"
		<< "You coud enter the following colours:\n"
		<< "0 - black, 1 - red, 2 - blue, 3 - green, 4 - purple, 5 - orange\n";
	cin >> x1 >> y1 >> x2 >> y2;
	int wrongCount = 0; // I count how many wrong inputs are given for ease for error messages
	do
	{
		++wrongCount;
		if (wrongCount != 1)
			cout << "Plese enter colour between 1 and 5!\n";
		cin >> stroke;
	} while (stroke > 5);
}

bool Line::within(double maxCX, double maxCY, double lowestCX, double lowestCY)
{
	if ((x1 < maxCX && x1 > lowestCX) && (x2 < maxCX && x2 > lowestCX))
	{
		if ((y1 < maxCY && y1 > lowestCY) && (y2 < maxCY && y2 > lowestCY))
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Line::readFromFileLine(ifstream &fileRead, int partFileBegin)
{
	// I don't take the whole file but only a part of it, 
	// the part I've already red in "commands"
	// and for that part I do the changes
	fileRead.seekg(partFileBegin, ios::beg);
	int momentFileLenght = fileRead.tellg();
	fileRead.seekg(0, ios::beg);
	char *partFile= new(nothrow)char[momentFileLenght + 1];
	if (!partFile)
	{
		cerr << "Problem creating the part file array in line!\n";
		return false;
	}
	fileRead.read(partFile, momentFileLenght);
	partFile[momentFileLenght] = '\0';
	cout << partFile << endl;
	char *lineTag = nullptr;
	char *fillColourTemp;
	lineTag = strstr(partFile, "<line");
	if (lineTag != NULL)
	{
		char * x1Temp;
		x1Temp = strstr(partFile, "x1=\"");
		if (x1Temp != NULL)
		{
			fileRead.seekg(x1Temp - partFile + 4, ios::beg);
			fileRead >> x1;
		}
		else
		{
			delete[]partFile;
			cerr << "The x1 coordinate of the first dot not found!\n";
			return false;
		}
		char *y1Temp;
		y1Temp = strstr(partFile, "y1=\"");
		if (y1Temp != NULL)
		{
			fileRead.seekg(y1Temp - partFile + 4, ios::beg);
			fileRead >> y1;
		}
		else
		{
			delete[]partFile;
			cerr << "The y1 coordinate of the first dot not found!\n";
			return false;
		}
		char *x2Temp;
		x2Temp = strstr(partFile, "x2=\"");
		if (x2Temp != NULL)
		{
			fileRead.seekg(x2Temp - partFile + 4, ios::beg);
			fileRead >> x2;
		}
		else
		{
			delete[]partFile;
			cerr << "The x2 coordinate of the second dot not found!\n";
			return false;
		}
		char *y2Temp;
		y2Temp = strstr(partFile, "y2=\"");
		if (y2Temp != NULL)
		{
			fileRead.seekg(y2Temp - partFile + 4, ios::beg);
			fileRead >> y2;
		}
		else 
		{
			delete[]partFile;
			cerr << "The y2 coordinate of the second dot not found!\n";
			return false;
		}
		//colour
		char *tempColour;
		tempColour = strstr(partFile, "stroke=\"");
		char lineColour[20];
		if (tempColour != NULL)
		{
			for (int i = 0; i < 20; ++i)
			{
				if (partFile[i] == '"')
					break;
				lineColour[i] = partFile[i];
			}
			switch (supportingColours(lineColour))
			{
			case(BLACK) : stroke = BLACK; break;
			case(RED) : stroke = RED; break;
			case(BLUE) : stroke = BLUE; break;
			case(GREEN) : stroke = GREEN; break;
			case(PURPLE) : stroke = PURPLE; break;
			case(ORANGE) : stroke = ORANGE; break;
			default: cerr << "The colour is not supported!\n";
				return false;
			}
			
		}
	}
	else
	{
		delete[]partFile;
		cerr << "The line tag is not found!\n";
		return false;
	}
	delete[]partFile;
	return true;
}
