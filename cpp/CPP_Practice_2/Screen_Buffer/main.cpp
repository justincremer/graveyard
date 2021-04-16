#include <windows.h>
#include <iostream>
#include <string>

// GAME VARIABLES
const int tick_rate = 20;
int tick_count = 0;
const int wall = 176;
const int player = 231;
const int enemey = 235;

const int map_width = 80;
const int map_height = 30;
const int map_size = map_width * map_height;

const int screen_width = 80;
const int screen_height = 30;
const int screen_size = screen_width * screen_height;

char* map = new char[map_size];

typedef struct coordinates {
	int y, x;
} coordinates;

coordinates player_coordinates = {map_height/2, map_width/2};

bool game_over = false;

// GAME LOGIC

void movePlayer(char map[map_size], int x_direction, int y_direction)
{
	map[player_coordinates.y * map_width + player_coordinates.x] = ' ';
	player_coordinates.x += x_direction;
	player_coordinates.y += y_direction;

	if(player_coordinates.x < 2) {
		player_coordinates.x += 2;
	} else if(player_coordinates.x >= map_width - 2) {
		player_coordinates.x -= 2;
	} else if(player_coordinates.y < 1) {
		player_coordinates.y++;
	} else if(player_coordinates.y >= map_height - 1) {
		player_coordinates.y--;
	}

	map[player_coordinates.y * map_width + player_coordinates.x] = player;
}

// ENEMY VARIABLES

const int enemy_limit = 100;
int enemy_count = 0;
coordinates* enemies =  new coordinates[enemy_limit];

// ENEMY FUNCTIONS

void createEnemy()
{
	if(enemy_count < enemy_limit) {
		int passes = 0;
		while(1) {
			coordinates temp {rand() % screen_height, (rand() % (screen_width / 2) * 2)};
			if(temp.y > 0 && temp.y < map_height -1 && temp.x > 1 && temp.x < map_width - 2) {
				for(int i = 0; i < enemy_count; i++) {
					if(enemies[i].y != temp.y || enemies[i].x != temp.x) {
						passes++;
					}
				}
				if(passes == enemy_count && (player_coordinates.y != temp.y || player_coordinates.x != temp.x)) {
					enemies[enemy_count].y = temp.y;
					enemies[enemy_count].x = temp.x;
					map[enemies[enemy_count].y * map_width + enemies[enemy_count].x] = enemey;
					enemy_count++;
					break;
				} else passes = 0;
			}
		}
	}
}

void moveEnemies()
{
	for(int i = 0; i < enemy_count; i++) {
		map[enemies[i].y * map_width + enemies[i].x] = ' ';
		int y_diff = player_coordinates.y - enemies[i].y;
		int x_diff = player_coordinates.x - enemies[i].x;
		if(abs(y_diff) >= abs(x_diff)) {
			enemies[i].y += y_diff > 0 ? 1 : -1;
			game_over = player_coordinates.y * map_width + player_coordinates.x == enemies[i].y * map_width + enemies[i].x ? true : false;
			if(enemies[i].y < 1) enemies[i].y++;
			else if(enemies[i].y >= map_height - 1) enemies[i].y--;
		} else if (abs(x_diff) > abs(y_diff)) {
			enemies[i].x += x_diff > 0 ? 2 : -2;
			game_over = player_coordinates.y * map_width + player_coordinates.x == enemies[i].y * map_width + enemies[i].x ? true : false;
			if(enemies[i].x < 2) enemies[i].x += 2;
			else if(enemies[i].x >= map_width - 2) enemies[i].x -= 2;
		}
		map[enemies[i].y * map_width + enemies[i].x] = enemey;
	}
}

int main()
{
	for(int i = 0; i < map_size; i++) map[i] = (i < map_width || i > map_size - map_width - 1 || (i - 1) % map_width == 0 || i % map_width == 0 || (i + 1) % map_width == 0 ||(i + 2) % map_width == 0 ) ? wall : ' ';
	map[player_coordinates.y * map_width + player_coordinates.x] = player;

// Screen Buffer

	char* screen = new char[screen_size];
	for(int i = 0; i < screen_size; i++) screen[i] = ' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD bytesWritten = 0;
	BOOL WINAPI SetConsoleScreenBufferSize(
	    _In_ HANDLE hConsole,
	    _In_ COORD  map_size
	);

	while(!game_over) {
		Sleep(1000/tick_rate);

		if(GetAsyncKeyState(0x41) & 0x0001) {
			movePlayer(map, -2, 0);
		} else if(GetAsyncKeyState(0x44) & 0x0001) {
			movePlayer(map, 2, 0);
		} else if(GetAsyncKeyState(0x57) & 0x0001) {
			movePlayer(map, 0, -1);
		} else if(GetAsyncKeyState(0x53) & 0x0001) {
			movePlayer(map, 0, 1);
		} else if(GetAsyncKeyState(0x0D) & 0x0001) {
			game_over = true;
		}

		if(tick_count > 0 && tick_count % 100 == 0) createEnemy();
		if(tick_count % 3 == 0) moveEnemies();
		tick_count++;

		for(int x = 0; x < map_width; x++) {
			for(int y = 0; y < map_height; y++) {
				screen[y * map_width + x] = map[y * map_width + x];
			}
		}

		WriteConsoleOutputCharacter(hConsole, screen, screen_size, { 0, 0 }, &bytesWritten);
	}

	for(int i = 0; i < map_size; i++) map[i] = (i < map_width || i > map_size - map_width - 1 || (i - 1) % map_width == 0 || i % map_width == 0 || (i + 1) % map_width == 0 ||(i + 2) % map_width == 0 ) ? wall : ' ';
	for(int i = -4; i < 5; i++) {
		std::string temp = "GAME OVER";
		map[map_height / 2 * map_width - 40 + i] = temp[i + 4];
	}
	for(int i = -5; i < 6; i++) {
		std::string temp = "Press Enter";
		map[(map_height / 2 + 1) * map_width - 40 + i] = temp[i + 5];
	}
	for(int x = 0; x < map_width; x++) {
		for(int y = 0; y < map_height; y++) {
			screen[y * map_width + x] = map[y * map_width + x];
		}
	}

	while(!GetAsyncKeyState(0x0D) & 0x0001) WriteConsoleOutputCharacter(hConsole, screen, screen_size, { 0, 0 }, &bytesWritten);
	return 0;
}
