#include <iostream>
#include <cmath>

struct squares {
	float largeArea, smallArea;
};

void doTheMath(float radius)
{
	squares result {.largeArea = pow((radius * 2), 2), .smallArea = (pow(((radius * 2.0) * sqrt(2) / 2), 2) / 2)};
	std::cout << "Large square area: " << result.largeArea << std::endl;
	std::cout << "Small square area: " << result.smallArea << std::endl;
}

int main()
{

	doTheMath(5.5);
	return 0;
}
