#include <iostream>
#include "ShapeContainer.h"

using namespace std;

void ShapeContainer::copyFigures(const ShapeContainer &right)
{
	size = right.size;
	capacity = right.capacity;
	shapesArr = new Shape*[size];
	for (unsigned int i = 0; i < size; ++i)
	{
		shapesArr[i] = right.shapesArr[i]->clone();	//  I clone the right objects, because I want to prevent the case when  										// 
	}					// the pointers of shapesArr and right.shapesArr will point at the same objects
}

ShapeContainer::ShapeContainer(const ShapeContainer &right)
{
	copyFigures(right);
}

ShapeContainer &ShapeContainer::operator=(const ShapeContainer &right)
{
	if (this != &right)
	{
		clear();
		copyFigures(right);
	}
	return *this;
}

void ShapeContainer::push(Shape * newShape)
{
	if (capacity == 0)
	{
		resize(1);
	}
	else if (capacity == size)
	{
		resize(capacity*2);
	}
	/*else if (size > capacity)
	{
		resize(size*2);
	}*/
	shapesArr[size] = newShape;
	++size;
}

void ShapeContainer::pop(int index)
{
	if (size == 0)
	{
		cerr << "There's nothig to delete!\n";
		return;
	}
	if (index > size)
	{
		cerr << "There's no figure with number " << index << ".\n";
	}
	for (int i = index; i < size ; ++i)
	{
		if (i == index)
			nullptr;
		if (i == size - 1)
		{
			shapesArr[i] = nullptr;
			break;
		}
		shapesArr[i] = shapesArr[i + 1];
	}
	--size ;
}


void ShapeContainer::resize(int newsize)
{
	Shape **tempArr = new Shape*[newsize];
	for (int c = 0; c < size; ++c)
	{
		tempArr[c] = shapesArr[c];
	}
	delete[] shapesArr;
	shapesArr = tempArr;
	capacity = newsize;
}

void ShapeContainer::clear()
{
	for (int i = 0; i < size; ++i)
	{
		delete shapesArr[i];
	}
	delete[]shapesArr;
}

void ShapeContainer::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << i << ".";
		shapesArr[i]->print();
	}
}
