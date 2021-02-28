#ifndef _SCREEN_H
#define _SCREEN_H
#include <windows.h>
#include "map.h"

char* screen = new char[map_size];
DWORD bytesWritten = 0;
HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

void initializeScreen()
{
	initializeMap();
	for(int i = 0; i < map_size; i++)
		screen[i] = map[i];
	SetConsoleActiveScreenBuffer(hConsole);
	BOOL WINAPI SetConsoleScreenBufferSize(
	    _In_ HANDLE hConsole,
	    _In_ COORD  map_size
	);
}

void updateScreen(char* map)
{
	for(int x = 0; x < map_width; x++)
		for(int y = 0; y < map_height; y++)
			screen[y * map_width + x] =  map[y * map_width + x] == '*' ? map[y * map_width + x] : ' ';
}

void displayScreen()
{
	WriteConsoleOutputCharacter(hConsole, screen, map_size, { 0, 0 }, &bytesWritten);
}

#endif
