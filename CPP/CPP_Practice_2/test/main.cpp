#include <iostream>
#include <stdlib.h>

void test()
{
	std::cout << rand() % 10 +1 << std::endl;
}

int main()
{

	test();
	test();
	test();
	return 0;
}
