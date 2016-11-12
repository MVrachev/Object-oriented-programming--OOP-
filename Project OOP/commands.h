#ifndef _COMMANDS
#define _COMMANDS
#include "shape.h"
#include "ShapeContainer.h"
using namespace std;
class Commands
{
	ShapeContainer Figures;
	char *fileDirectory;
public:

	bool c_open();		//Слагам общ префикс c_ за да покажа, че когато се викат се викат функциите от класа Commands, 
	bool c_save();	//	а не функциите от класа на някоя фигура.
	bool c_saveAs();
	void c_close(fstream &file);
						//	Команди върху самия масив от фигури
	void c_print();
	bool c_create(char *figureType);
	bool c_erase(int index);
	void c_translateAll(Vector &translateVector);
	bool c_translateOne(Vector &translateVector, int index);
	bool c_within(double maxCX, double maxCY, double lowestCX, double lowestCY);

	void setDirectory(char*newDirectory);

	Commands() : fileDirectory(nullptr){};
	Commands(const Commands &right);
	Commands &operator=(const Commands &right);
	~Commands(){ delete[]fileDirectory; }
	void copyCommands(const Commands &right);

};


#endif // !_COMMANDS-SHAPE_HEADER
