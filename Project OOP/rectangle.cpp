#include <iostream>
#include "rectangle.h"
#include <fstream>
using namespace std;


void Rectangle::create()
{
	cout << "...........................................................\n";
	cout << "You will create a rectangle. "
		<< "It contains the following things that you will now enter:\n" << endl
		<< "x defines the left position of the rectangle\n, y defines the top position of the rectangle "
		<< "width and height - which attributes of the rectangle element\n"
		<< "define the height and the width of the rectangle, "
		<< "and fill colour.\n"
		<< "You coud enter the following colours:\n"
		<< "0 - black, 1 - red, 2 - blue, 3 - green, 4 - purple, 5 - orange\n";
	cin >> x >> y >> width >> height;
	int wrongCount = 0; // броя колко грешни входа  са направени за удобство при съобщенията
	do
	{
		++wrongCount;
		if (wrongCount != 1)
			cout << "Plese enter colour between 1 and 5!\n";
		cin >> fillColour;
	} while (fillColour > 5);
}

void Rectangle::print()
{
	cout << "rectangle " << "x: " << x << " y: " << y << " width: " << width << " height: " << height << " fill colour: ";
	switch (fillColour)
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

void Rectangle::translate(Vector &translateVector)
{
	x += translateVector.getCoordX();
	y += translateVector.getCoordY();
}

bool Rectangle::within(double maxCX, double maxCY, double lowestCX, double lowestCY)
{
	bool inRegion;
	if (x < maxCX && x > lowestCX)
	{
		if (y < maxCY && y > lowestCY)
		{
			return true;
		}
		return false;
	}
	return false;
}


bool Rectangle::readFromFileRectangle(ifstream &fileRead, int partFileBegin)
{

	fileRead.seekg(partFileBegin, ios::beg);
	int momentFileLenght = fileRead.tellg();
	fileRead.seekg(0, ios::beg);
	char *partFile = new(nothrow)char[momentFileLenght + 1];
	if (!partFile)
	{
		cerr << "Problem creating the part file array in rectangle!\n";
		return false;
	}
	fileRead.read(partFile, momentFileLenght);
	partFile[momentFileLenght] = '\0';
	cout << partFile << endl;
	char *rectTag = nullptr;
	char *fillColourTemp;
	rectTag = strstr(partFile, "<rect");
	if (rectTag != NULL)
	{
		char * xTemp;
		xTemp = strstr(partFile, "x=\"");
		if (xTemp != NULL)
		{
			fileRead.seekg(xTemp - partFile + 3, ios::beg);
			fileRead >> x;
		}
		else
		{
			delete[]partFile;
			cerr << "The x attribute defining the left position of the rectangle not found!\n";
			return false;
		}
		char *yTemp;
		yTemp = strstr(partFile, "y=\"");
		if (yTemp != NULL)
		{
			fileRead.seekg(yTemp - partFile + 3, ios::beg);
			fileRead >> y;
		}
		else
		{
			delete[]partFile;
			cerr << "The y attribute defining the top position of the rectangle not found!\n";
			return false;
		}
		char *widthTemp;
		widthTemp = strstr(partFile, "width=\"");
		if (widthTemp != NULL)
		{
			fileRead.seekg(widthTemp - partFile + 7, ios::beg);
			fileRead >> width;
		}
		else
		{
			delete[]partFile;
			cerr << "The width attribute of the rectangle defininig the of the rectangle width not found!\n";
			return false;
		}
		char *heightTemp;
		heightTemp = strstr(partFile, "height=\"");
		if (heightTemp != NULL)
		{
			fileRead.seekg(heightTemp - partFile + 8, ios::beg);
			fileRead >> height;
		}
		else
		{
			delete[]partFile;
			cerr << "The height attribute of the rectangle defininig the height of the rectangle not found!\n";
			return false;
		}
		//colour
		char *tempColour;
		tempColour = strstr(partFile, "stroke=\"");
		char rectangleColour[20];
		if (tempColour != NULL)
		{
			for (int i = 0; i < 20; ++i)
			{
				if (partFile[i] == '"')
					break;
				rectangleColour[i] = partFile[i];
			}
			switch (supportingColours(rectangleColour))
			{
			case(BLACK) : fillColour = BLACK; break;
			case(RED) : fillColour = RED; break;
			case(BLUE) : fillColour = BLUE; break;
			case(GREEN) : fillColour = GREEN; break;
			case(PURPLE) : fillColour = PURPLE; break;
			case(ORANGE) : fillColour = ORANGE; break;
			default: cerr << "The colour is not supported!\n";
				return false;
			}

		}
	}
	else
	{
		delete[]partFile;
		cerr << "The rectangle tag is not found!\n";
		return false;
	}
	delete[]partFile;
	return true;
}
