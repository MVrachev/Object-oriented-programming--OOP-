#ifndef _VECTOR_HEADER
#define _VECTOR_HEADER

class Vector
{
	double coordX;
	double coordY;
public:
	Vector() : coordX(0), coordY(0){};
	Vector(int newCx, int newCy) : coordX(newCx), coordY(newCy){};
	int getCoordX() const { return coordX; }
	int getCoordY() const { return coordY; }
	void setVector(double vertical, double horisontal) { coordX = horisontal; coordY = vertical; }
};



#endif // !_VECTOR_HEADER
