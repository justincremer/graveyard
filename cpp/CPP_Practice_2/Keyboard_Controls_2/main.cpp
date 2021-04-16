#include "game.h"

int main()
{
	initializeGameField(game_field);
	display(game_field);

	while(!exit_code) {
		Sleep(1000);
		if(GetAsyncKeyState(0x41) & 0x0001) {
			movePlayer(game_field, -1, 0);
		} else if(GetAsyncKeyState(0x44) & 0x0001) {
			movePlayer(game_field, 1, 0);
		} else if(GetAsyncKeyState(0x57) & 0x0001) {
			movePlayer(game_field, 0, -1);
		} else if(GetAsyncKeyState(0x53) & 0x0001) {
			movePlayer(game_field, 0, 1);
		} else if(GetAsyncKeyState(0x0D) & 0x0001) {
			setExitCode(true);
		}

		display(game_field);
	}

	return 0;
}
