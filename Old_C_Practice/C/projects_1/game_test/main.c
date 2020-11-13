#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Clock Variables
int tick = 250;
int tickCount = 0;
int tickMod = 1;

//Resource Variables
int mIncrement = 1;
int wIncrement = 1;

struct resource {
    int id;
    char *name;
    int amount;
};


struct resource gameData[] = {
    {
        100,
        "minerals",
        0
    },
    {
        101,
        "ore",
        0
    },
    {
        102,
        "metal",
        0
    },
    {
        103,
        "wood",
        0
    },
    {
        104,
        "planks",
        0
    },
    {
        105,
        "scaffolding",
        0
    }
};


void updateGameData(void) {

    gameData[0].amount += mIncrement;
    gameData[3].amount += wIncrement;
    tickCount++;

    for(int i = 0; i < 6; i++) {
        if (gameData[i].id == 100 && gameData[i].amount > 10) {
            gameData[i].amount -= 10;
            gameData[i + 1].amount += 1;
        }
    }

    for(int i = 0; i < 6; i++) {
        if (gameData[i].id == 101 && gameData[i].amount > 10) {
            gameData[i].amount -= 10;
            gameData[i + 1].amount += 1;
        }
    }

    for(int i = 0; i < 6; i++) {
        if (gameData[i].id == 103 && gameData[i].amount > 10) {
            gameData[i].amount -= 10;
            gameData[i + 1].amount += 1;
        }
    }

    for(int i = 0; i < 6; i++) {
        if (gameData[i].id == 104 && gameData[i].amount > 10) {
            gameData[i].amount -= 10;
            gameData[i + 1].amount += 1;
        }
    }

    if (tickCount / tickMod == 50) {
        mIncrement++;
        wIncrement++;
        tickMod++;
    }

    return;
}


void updateConsole(void) {
    system("clear");

    printf("  Tick Count: %d\n\n", tickCount);
    printf("  minerals p/s: %.2f\n", (float)mIncrement/((float)1000/tick));
    printf("  wood p/s: %.2f\n\n", (float)wIncrement/((float)1000/tick));
    printf("  %s: %d\n", gameData[0].name, gameData[0].amount);
    printf("  %s: %d\n", gameData[1].name, gameData[1].amount);
    printf("  %s: %d\n", gameData[2].name, gameData[2].amount);
    printf("  %s: %d\n", gameData[3].name, gameData[3].amount);
    printf("  %s: %d\n", gameData[4].name, gameData[4].amount);
    printf("  %s: %d\n", gameData[5].name, gameData[5].amount);


    return;
}


int main(void){

    while(1) {
        updateGameData();
        updateConsole();
        Sleep(tick);
    }

    return 0;
}
