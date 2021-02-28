#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


//game board 12 x 18, extra space on every side for border (actual game board is 10 x 16)
char * buildBoard(void) {

    static char board[216];

    for(int i = 0; i < 216; i++) {
        if((i + 12) % 12 == 0 || (i + 1) % 12 == 0)
            board[i] = '#';
        else if(i > 203)
            board[i] = '#';
        else
            board[i] = '  ';
    }

    return board;
}


void displayBoard(void) {

    system("clear");

    char *gameBoard = buildBoard();

    int count = 0;
    while(count < 18) {
        char boardLine[12];
        memmove(boardLine, gameBoard, 12*sizeof(char));
        printf("%s\n", boardLine);
        gameBoard += 12;
        count++;
    }
}

int main()
{
    displayBoard();
    return 0;
}
