#include <iostream>
#include <fstream>
#include <cstring>
#include "commands.h"
#include "circle.h"
#include "line.h"
#include "rectangle.h"
#include "vector.h"

using namespace std;

// Направи проверка на всяка една команда дали първо е направена команда open!

//Направи си копи конструкторите



void Commands::copyCommands(const Commands &right)
{
	setDirectory(right.fileDirectory);
	//трябва да направя копи на новия обект 
}

Commands::Commands(const Commands &right)
{
	copyCommands(right);
}
Commands &Commands::operator=(const Commands &right)
{
	if (this != &right)
	{
		copyCommands(right);
	}
	return *this;
}


bool Commands::c_open()
{
	char directory[200];
	cin.ignore();
	cin.getline(directory, 200);

	// D:/Martin's stuff/Visual Studio 2013/Projects/Project - OOP/Project - OOP/you.svg	// пример за правилно написан път
	//	D:/Martin's stuff/Visual Studio 2013/Projects/Project - OOP/Project - OOP/new.svg
	// D:/Martin's stuff/Visual Studio 2013/Projects/Project - OOP/Project - OOP/Example - SVG view.svg
	ifstream fileRead(directory, ios::in);
	if (!fileRead)
	{

		cerr << "The file is not opened. New file will be created!" << endl;
		ofstream fileWrite(directory, ios::out);
		if (!fileWrite)
		{
			cerr << "Most probably file directory you entered is wrong or there's other problem and the file is not created!\n";
			return false;
		}

		fileWrite << "<?xml version=\"1.0\" standalone=\"no\"?>" << "\n"
			"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << "\n"
			<< " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << "\n"
			<< "<svg width=\"15cm\" height=\"15cm\" viewBox=\"0 0 1200 400\"" << "\n"
			<< " xmlns=\"http://www.w3.org/2000/svg\" version =\"1.1\">" << "\n";

		fileWrite.close();
	}
	fileRead.seekg(0, fileRead.end);
	int fileLeght = fileRead.tellg();
	char *wholeFile = new(nothrow)char[fileLeght + 1];
	if (!wholeFile)
	{
		fileRead.close();
		cerr << "Problem creating the whole file array in line!\n";
		return false;
	}
	fileRead.read(wholeFile, fileLeght);
	wholeFile[fileLeght] = '\0';
	Circle newCircle;
	Line newLine;
	Rectangle newRectangle;
	int partFileBegin = 0;
	// Ще поддам два индекса за записване от файла, понеже ако започвам винаги от начало 
	// и имам два кръга, то при всяко викане на fileWrite() на circle ще се взима един и същи кръг
	for (int i = 5; i < fileLeght; ++i)
	{
		if (newCircle.readFromFileCircle(fileRead, partFileBegin) == true)
		{
			partFileBegin = i;
			newCircle.readFromFileCircle(fileRead, partFileBegin);
			Figures.push(newCircle.clone());
		}
		else if (newLine.readFromFileLine(fileRead, partFileBegin) == true)
		{
			partFileBegin = i;
			newLine.readFromFileLine(fileRead, partFileBegin);
			Figures.push(newLine.clone());
		}
		else if (newRectangle.readFromFileRectangle(fileRead, partFileBegin) == true)
		{
			partFileBegin = i;
			newRectangle.readFromFileRectangle(fileRead, partFileBegin);
			Figures.push(newRectangle.clone());
		}
	}
	
	
	cout << "The file is opened or created succsesfully!\n";
	this->setDirectory(directory);
	fileRead.close();  // трябва с команда close да се затвори
	delete[]wholeFile;
	return true;
}

void Commands::setDirectory(char *newDirectory)
{
	fileDirectory = new char[strlen(newDirectory) + 1];
	strcpy_s(fileDirectory, strlen(newDirectory) + 1, newDirectory);
}



bool Commands::c_create(char *figureType)
{
	if (!strcmp(figureType, "circle"))
	{
		Circle newCircle;
		newCircle.create();
		Figures.push(newCircle.clone());
		return true;
	}
	else if (!strcmp(figureType, "rectangle"))
	{
		Rectangle newRectangle;
		newRectangle.create();
		Figures.push(newRectangle.clone());
		return true;
	}
	else if (!strcmp(figureType, "line"))
	{
		Line newLine;
		newLine.create();
		Figures.push(newLine.clone());
		return true;
	}
	cerr << "The figure you entered is not suported!\n";
	return false;
}

void Commands::c_print()
{
	Figures.print();
}

void Commands::c_translateAll(Vector &translateVector)
{
	for (int i = 0; i < Figures.getSize(); ++i)
	{
		Figures.getShapeArr()[i]->translate(translateVector);
	}
	
}

bool Commands::c_translateOne(Vector &translateVector, int index)
{
	if (index > Figures.getSize() || index < 0)
	{
		cerr << "There's no figure on positon " << index << " .'\n";
		return false;
	}
	Figures.getShapeArr()[index]->translate(translateVector);
	return true;
}

bool Commands::c_erase(int index)
{
	if (index > Figures.getSize() || index < 0)
	{
		cerr << "There's no figure on positon " << index << " .'\n";
		return false;
	}
	delete Figures.getShapeArr()[index];
	Figures.pop(index);
	return true;
}

bool Commands::c_within(double maxCX, double maxCY, double lowestCX, double lowestCY)
{
	bool figInRegion = false;
	for (int i = 0; i < Figures.getSize(); i++)
	{
		if (Figures.getShapeArr()[i]->within(maxCX, maxCY, lowestCX, lowestCY) == true)
		{
			cout << i << "." ;
			Figures.getShapeArr()[i]->print();
			figInRegion = true;
		}
	}
	return figInRegion;
}

void Commands::c_close(fstream &file)
{
	file.close();
}




