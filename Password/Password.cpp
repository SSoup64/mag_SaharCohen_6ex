#include <iostream>

struct Password
{
	char value[16];
	bool incorrect;
	Password() : value(""), incorrect(true)
	{
	}
};

int main()
{
	std::cout << "Enter your password to continue:" << std::endl;
	Password pwd;

	// BUG: If we input 16 characters into pwd.value, then the 16 characters will end up in the array and the
	//		null character will overflow to the "incorrect" variable and cause it to become false.
	//		So for example the string "1234123412341234" will let the user break into the system.
	std::cin >> pwd.value;

	if (!strcmp(pwd.value, "********"))
		pwd.incorrect = false;

	if(!pwd.incorrect)
		std::cout << "Congratulations\n";

	return 0;
}
