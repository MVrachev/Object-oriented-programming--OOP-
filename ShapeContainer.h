#ifndef _INFORMATION_REGION_CONTAINER
#define _INFORMATION_REGION_CONTAINER
#include "shape.h"
class ShapeContainer
{
	Shape **shapesArr;
	unsigned int capacity;
	unsigned int size;
public:
	ShapeContainer() : shapesArr(nullptr), size(0), capacity(0){};
	ShapeContainer(const ShapeContainer &right);
	ShapeContainer &operator=(const ShapeContainer &right);
	~ShapeContainer(){ clear(); }

	void copyFigures(const ShapeContainer &right);
	void clear();
	void push(Shape * newShape);
	void pop(int index);
	void resize(int newsize);
	void print();

	unsigned int getSize() const { return size; }
	Shape ** getShapeArr() const { return shapesArr; }
};



#endif // !_INFORMATION_SHAPE_CONTAINER
