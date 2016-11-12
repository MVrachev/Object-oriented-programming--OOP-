#ifndef _CIRCLE_HEADER
#define _CIRCLE_HEADER
#include "shape.h"
#include "vector.h"
#include <fstream>
#include <iostream>

using namespace std;
class Circle: public Shape
{
	double cx;
	double cy;
	double r;
	unsigned int fillColour;
public:
	Circle() :cx(0), cy(0), r(0), fillColour(0){};
	~Circle() override {};

	//void create();
	void print() override;
	void translate(Vector &translateVector) override;
	Shape * clone()const override { return new Circle(*this); }
	void create();
	bool within(double maxCX, double maxCY, double lowestCX, double lowestCY) override;
	void fileWrite() override;
	bool readFromFileCircle(ifstream &fileRead, int partFileBegin);

};

//Circle::Circle()
//{
//}

#endif // _CIRCLE_HEADER
