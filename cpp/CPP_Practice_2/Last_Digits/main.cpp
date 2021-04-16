#include <iostream>

bool lastDig(int a, int b, int c)
{
	while(a >= 10) a %= 10;
	while(b >= 10) b %= 10;
	while(c >= 10) c %= 10;
	if(a * b == c) return true;
	else return false;
}

int main(int argc, char **argv)
{
	std::cout << lastDig(22, 12, 14) << std::endl;
	return 0;
}
