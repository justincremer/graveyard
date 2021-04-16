#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "conio.h"
#include <windows.h>


// VARIABLES

const int background = 176;
const int player = 231;
const int enemey = 235;

bool exit_code = false;

const int screen_height = 18;
const int screen_width = 60;

int tick_count = 0;

char game_field[screen_height][screen_width];

typedef struct coordinates {
	int y, x;
} coordinates;

coordinates player_coordinates = {screen_height/2,screen_width/2};

// Screen Buffer



// PLAYER FUNCTIONS

void initializeGameField(char[screen_height][screen_width])
{
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			game_field[i][j] = background;
		}
	}
	game_field[player_coordinates.y][player_coordinates.x] = player;
}

void display(char game_field[screen_height][screen_width])
{
	system("CLS");
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			std::cout << game_field[i][j];
		}
		std::cout << "\n";
	}
}



void setExitCode(bool code)
{
	exit_code = code;
}

void movePlayer(char game_field[screen_height][screen_width], int x_direction, int y_direction)
{
	game_field[player_coordinates.y][player_coordinates.x] = background;
	player_coordinates.x += x_direction;
	player_coordinates.y += y_direction;

	if(player_coordinates.x < 0) {
		player_coordinates.x = screen_width - 1;
	} else if(player_coordinates.y < 0) {
		player_coordinates.y = screen_height - 1;
	} else if(player_coordinates.x >= screen_width) {
		player_coordinates.x = 0;
	} else if(player_coordinates.y >= screen_height) {
		player_coordinates.y = 0;
	}

	game_field[player_coordinates.y][player_coordinates.x] = player;
}

// ENEMY VARIABLES

const int enemy_limit = 1;
int enemy_count = 0;
coordinates* enemies = new coordinates[enemy_limit];

// ENEMY FUNCTIONS

void createEnemy()
{
	if(enemy_count < enemy_limit) {
		int passes = 0;
		while(passes < enemy_count) {
			coordinates temp {rand() % screen_height, rand() % screen_width};
			for(int i = 0; i < enemy_count; i++) {
				if(enemies[i].y != temp.y || enemies[i].x != temp.x) {
					passes++;
				}
			}
			if(passes == enemy_count && (player_coordinates.y != temp.y || player_coordinates.x != temp.x)) {
				enemies[enemy_count].y = temp.y;
				enemies[enemy_count].x = temp.x;
				enemy_count++;
				break;
			}
			passes = 0;
		}
	}
}

bool checkNextTo(int coord)
{
	return abs(coord) < 2 ? true : false;
}

void moveEnemy()
{
	for(int i = 0; i < enemy_count; i++) {
		map[enemies[i].y * map_width + enemies[i].x] = ' ';
		int y_diff = player_coordinates.y - enemies[i].y;
		int x_diff = player_coordinates.x - enemies[i].x;
		if(abs(y_diff) <= abs(x_diff)) {
			game_over = abs(y_diff) < 1 ? true : false;

		} else if (abs(x_diff) < abs(y_diff)) {
			game_over = abs(x_diff) < 2 ? true : false;
		}
	}
}

#endif //GAME_H
