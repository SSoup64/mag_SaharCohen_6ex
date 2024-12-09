#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "shape.h"

class Triangle : public Shape 
{
private:
	float _base;
	float _height;
public:
	Triangle(float base, float height);

	// BUG:	The function get_area was not overriden since Shape::get_area does not take any
	//		arguments and Triangle::get_area takes a boolean.
	//		Even though the Triangle:get_area has a default value for the boolean, it still does
	//		not mean the C++ compiler will acknowledge it as an override of the base function.
	// FIX: Make an override of the get_area function that just returns Triangle::get_area(false)
	virtual float get_area(bool has_depth) const;
	virtual float get_area() const override;

};


#endif	// __TRIANGLE_H__
