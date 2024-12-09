#define _CRTDBG_MAP_ALLOC //to get more details

#include <crtdbg.h>

#include "Point.h"
#include <iostream>

int main()
{
	Point p1(1, 2);
	Point p2 = p1;

	// Fixed a bug where p1 and p2 are not printed
	std::cout << "p1=" << p1 << std::endl; 
	std::cout << "p2=" << p2 << std::endl;

	return 0;
}
