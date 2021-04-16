#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
	std::vector<std::string> names {"john", "mary", "joseph"};
	for(std::string name : names)
		std::cout << name << std::endl;
	return 0;
}
