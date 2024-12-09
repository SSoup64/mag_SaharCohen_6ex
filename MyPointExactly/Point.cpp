#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	delete _coord;
	memcpy(_coord, other._coord, 2 * sizeof(int));	// Fixed a mistake where other's coord's address was copied instead
													// of the values themselves. This caused a double-free.
}

Point::~Point()
{
	delete _coord;
}

Point& Point::operator=(const Point& other)
{
	// Fixed the bug where self assignment would cause accessing freed memory
	if (_coord) // If we are self assigning, then no changes need to be made to the instance
	{
		delete _coord;
		_coord = new int[2];
		memcpy(_coord, other._coord, 2 * sizeof(int));	// Mistake fixed: Only removed 2 bytes instead of 8
														// Fixed by multiplying 2 (which is the length of the array) by the size of an int (which is 4)
	}
	return *this;
}

int Point::getX() const 
{ 
	return _coord[0]; 
}

int Point::getY() const
{ 
	return _coord[1]; 
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
