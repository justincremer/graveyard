#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

char banner[] = "Hello! Welcome to Chili's! Hello! Welcome to Chili's! Hello! Welcome to Chili's! Hello! Welcome to Chili's! ";
int tick = 100;


void updateBanner() {
    char firstIndex = banner[0];
    char tempBanner[strlen(banner)];
    strcpy(tempBanner, banner);
    tempBanner[strlen(banner) - 1] = firstIndex;

    for(int i = 0; i < strlen(banner) - 1; i++) {
        tempBanner[i] = banner[i + 1];
    }

    strcpy(banner, tempBanner);
    return;
}


void updateDisplay() {
    system("clear");

    printf("%s\n", banner);
    printf("%s\n", banner+2);
    printf("%s\n", banner+4);
    printf("%s\n", banner+6);
    printf("%s\n", banner+8);
    printf("%s\n", banner+10);
    printf("%s\n", banner+12);
    printf("%s\n", banner+14);
    printf("%s\n", banner+16);
    printf("%s\n", banner+18);
    printf("%s\n", banner+20);
    printf("%s\n", banner+22);
    printf("%s\n", banner+24);

    Sleep(tick);
    return;
}


int main()
{


    while(1) {
        updateBanner();
        updateDisplay();
    }

    /*
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    printf("%s\n", banner);
    updateBanner();
    */


    return 0;
}
