#ifndef _RECTANGLE_HEADER
#define _RECTANGLE_HEADER
#include "shape.h"
#include <fstream>
#include <iostream>
using namespace std;
class Rectangle: public Shape
{
	double x;
	double y;
	double width;
	double height;
	unsigned int fillColour;
public:
	Rectangle::Rectangle() : x(0), y(0), width(0), height(0), fillColour(0) {};
	void create() override;
	void print() override;
	Shape * clone()const override { return new Rectangle(*this); }
	void translate(Vector &translateVector) override;
	bool within(double maxCX, double maxCY, double lowestCX, double lowestCY) override;
	void fileWrite() override {};
	bool readFromFileRectangle(ifstream &fileRead, int partFileBegin);
};



#endif // !_RECTANGLE_HEADER
