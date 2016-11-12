#ifndef _SHAPE_HEADER
#define _SHAPE_HEADER
#include "vector.h"


int supportingColours(char *checkColour);

enum Colours
{
	BLACK,
	RED,
	BLUE,
	GREEN,
	PURPLE,
	ORANGE
};

class Shape
{
public:
	void create(Shape * newElement);
	virtual void print() = 0;
	virtual void translate(Vector &translateVector) = 0;
	virtual Shape * clone()const = 0;
	virtual void create() = 0;
	virtual bool within(double maxCX, double maxCY, double lowestCX, double lowestCY) = 0;
	virtual void fileWrite() = 0;
	virtual ~Shape() { }
};

#endif // !_SHAPE_HEADER
