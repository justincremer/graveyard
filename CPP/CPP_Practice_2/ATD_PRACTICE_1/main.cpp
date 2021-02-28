#include <Array.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

int main()
{
	Array x{ new int[20], 20 };
	for(int i = 0; i < 20; i++) {
		x.setIndex(i, (rand() % 50 + 1));
	}
	Array y{ new int[20], 20 };
	for(int i = 0; i < 20; i++) {
		y.setIndex(i, (rand() % 50 + 1));
	}
	x.bubbleSort();
	y.bubbleSort();
	x.display();
	y.display();
	Array z{ new int[0], 0 };
	z.merge(x, y);
	z.display();
	/*
	x.display();
	Sleep(1000);
	x.shift();
	x.shift();
	x.shift();
	x.display();
	Sleep(1000);
	x.bubbleSort();
	x.display();
	Sleep(1000);
	x.reverse();
	x.display();
	Sleep(1000);
	x.swap(0, x.getLength() - 1);
	x.display();
	std::cout << "Sorted status: " << x.isSorted() << std::endl;
	Sleep(1000);
	x.bubbleSort();
	x.display();
	std::cout << "Sorted status: " << x.isSorted() << std::endl;
	std::cout << "Maximum: " << x.getMax() << std::endl;
	std::cout << "Avgerage: " << x.getAverage() << std::endl;
	*/
	return 0;
}
