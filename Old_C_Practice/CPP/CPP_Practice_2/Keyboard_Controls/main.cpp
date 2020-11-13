#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_X 120

const int field_length = 20;
char* field = new char[field_length];
int tick_count = 0;

void display(char arr[], int arr_length)
{
	system("CLS");
	for(int i = 0; i < arr_length; i++) {
		std::cout << arr[i];
	}
	std::cout << "\n\nTick count: " << tick_count << std::endl;
	tick_count++;
}

int findPlayer(char arr[], int arr_length)
{
	for(int i = 0; i < arr_length; i++) {
		if(arr[i] == '#') {
			return i;
		}
	}
	return -1;
}

char* movePlayer(char arr[], int arr_length, int player_index, int direction)
{
	arr[player_index] = '-';
	if(player_index == 0 && direction == -1) {
		arr[arr_length - 1] = '#';
	} else if(player_index == arr_length - 1 && direction == 1) {
		arr[0] = '#';
	} else {
		arr[player_index + direction] = '#';
	}

	return arr;
}

void gameLoop()
{
	int key = getch();

	while(key != KEY_X) {
		key = getch();

		switch(getch()) {
		case KEY_LEFT:
			field = movePlayer(field, field_length, findPlayer(field, field_length), -1);
			break;
		case KEY_RIGHT:
			field = movePlayer(field, field_length, findPlayer(field, field_length), 1);
			break;
		}

		display(field, field_length);
	}
}

int main()
{
	for(int i = 0; i < 20; i++) {
		field[i] = '-';
	}

	field[5] = '#';

	gameLoop();

	return 0;
}
