#ifndef HANOI_H
#define HANOI_H
#include <iostream>

void move(char a, char c) {
	std::cout << "move " << a << " to " << c << std::endl;
}

void hanoi(int n, char a, char b, char c) {
	if (n == 0) return;
	else {
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}

#endif