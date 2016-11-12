#ifndef _LINE_HEADER
#define _LINE_HEADER
#include <iostream>
#include "shape.h"
#include <fstream>
#include <iostream>
using namespace std;

class Line:public Shape
{
	double x1;
	double y1;
	double x2;
	double y2;
	unsigned int stroke;
public:
	Line() : x1(0), y1(0), x2(0), y2(0), stroke(0){};

	void print() override;
	void translate(Vector &translateVector) override;
	Shape * clone() const override { return new Line(*this); }
	void create() override;
	bool within(double maxCX, double maxCY, double lowestCX, double lowestCY) override;
	void fileWrite() override {};
	bool readFromFileLine(ifstream &fileRead, int partFileBegin);

};

#endif // !_LINE_HEADER
