#include <iostream>

int main()
{
	unsigned int size = 0;

	int t1 = 0, t2 = 1;

	std::cout << "what is the size of the series? ";
	std::cin >> size;

	// Fixed a bug where the size is an unsigned int and we are checking for whether or not size is bigger or
	// equal to 0, which is always true, because of the nature of unsigned integers.
	// Fix: Substitute > for the >=.
	while (size > 0)
	{
		// The series described here the Fibonacci series.
		std::cout << t1 << ", ";

		int nextTerm = t1 + t2;
		t1 = t2;
		t2 = nextTerm;

		size--;
	}

	return 0;
}