#ifndef _MAP_H
#define _MAP_H
#include <stdlib.h>\

const int map_width = 80;
const int map_height = 30;
const int map_size = map_width * map_height;

char* map = new char[map_size];

void initializeMap()
{
	for(int i = 0; i < map_size; i++)
		map[i] = rand() % 26 + 20;
}

void rotateMap()
{
	char* temp = new char[map_size];
	temp[0] = map[map_size - 1];
	for(int i = 0; i < map_size - 1; i++)
		temp[i + 1] = map[i];
	delete map;
	map = temp;
	temp = NULL;
}

#endif
