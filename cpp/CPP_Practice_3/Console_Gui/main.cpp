#include <iostream>
#include "screen.h"

int main(int argc, char **argv)
{
	initializeScreen();
	while(1) {
		Sleep(55);
		rotateMap();
		updateScreen(map);
		displayScreen();
	}

	return 0;
}
