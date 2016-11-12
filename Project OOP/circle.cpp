#include <iostream>
#include <fstream>
#include "circle.h"
#include "vector.h"
using namespace std;


void Circle::create()
{
	cout << "...........................................................\n";
	cout << "You will create a circle."
		<< "It contains the following things that you will now enter:\n" << endl
		<< "center coordinate x, center coordinate y, r - radius, and fill colour.\n"
		<< "You coud enter the following colours:\n"
		<< "0 - black, 1 - red, 2 - blue, 3 - green, 4 - purple, 5 - orange\n";
	cin >> cx >> cy >> r;
	int wrongCount = 0; // броя колко грешни входа  са направени за удобство при съобщенията
	do
	{
		++wrongCount;
		if (wrongCount != 1)
			cout << "Plese enter the fill colour between 1 and 5!\n";
		cin >> fillColour;
	} while (fillColour > 5);

}

void Circle::print()
{
	cout << "circle " << "cx: " << cx << " cy: " << cy << " r: " << r << " fill colour: ";
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


void Circle::translate(Vector &translateVector)
{
	cx += translateVector.getCoordX();
	cy += translateVector.getCoordY();
}

bool Circle::within(double maxCX, double maxCY, double lowestCX, double lowestCY)
{
	if ((cx + r) < maxCX && (cx - r) > lowestCX)
	{
		if ((cy + r) < maxCY && (cx - r) > lowestCY)
		{
			return true;
		}
		return false;
	}
	return false;
}

void Circle::fileWrite()
{

}

bool Circle::readFromFileCircle(ifstream &fileRead, int partFileBegin)
{
	//Не взимам целия файл, а взимам част от файла, 
	//до където съм прочел в commands и за нея правя проверките
	fileRead.seekg(partFileBegin, ios::beg);
	int momentFileLenght = fileRead.tellg();
	fileRead.seekg(0, ios::beg);
	char *partFile = new(nothrow)char[momentFileLenght + 1];
	if (!partFile)
	{
		cerr << "Problem creating the part file array in circle!\n";
		return false;
	}
	fileRead.read(partFile, momentFileLenght);
	partFile[momentFileLenght] = '\0';
	cout << partFile << endl;
	char *lineTag = nullptr;
	char *fillColourTemp;
	lineTag = strstr(partFile, "<circle");
	if (lineTag != NULL)
	{
		char * cxTemp;
		cxTemp = strstr(partFile, "cx=\"");
		if (cxTemp != NULL)
		{
			fileRead.seekg(cxTemp - partFile + 4, ios::beg);
			fileRead >> cx;
		}
		else
		{
			delete[]partFile;
			cerr << "The x coordinate of the center not found!\n";
			return false;
		}
		char *cyTemp;
		cyTemp = strstr(partFile, "cy=\"");
		if (cyTemp != NULL)
		{
			fileRead.seekg(cyTemp - partFile + 4, ios::beg);
			fileRead >> cy;
		}
		else
		{
			delete[]partFile;
			cerr << "The y coordinate of the center not found!\n";
			return false;
		}
		char *rTemp;
		rTemp = strstr(partFile, "r=\"");
		if (rTemp != NULL)
		{
			fileRead.seekg(rTemp - partFile + 3, ios::beg);
			fileRead >> r;
		}
		else
		{
			delete[]partFile;
			cerr << "The radius not found!\n";
			return false;
		}
		//colour
		char *tempColour;
		tempColour = strstr(partFile, "stroke=\"");
		char circleColour[20];
		if (tempColour != NULL)
		{
			for (int i = 0; i < 20; ++i)
			{
				if (partFile[i] == '"')
					break;
				circleColour[i] = partFile[i];
			}
			switch (supportingColours(circleColour))
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
		cerr << "The circle tag is not found!\n";
		return false;
	}
	delete[]partFile;
	return true;
}