#include <stdio.h>
#include <stdlib.h>

struct person {
    char *name;
    // birthday flags
    unsigned int birthYear : 12;
    unsigned int birthMonth : 5;
    unsigned int birthDay : 6;
    // language flags
    unsigned int english : 1;
    unsigned int french : 1;
    unsigned int spanish : 1;
};


struct person people[] = {
    {"Justin", 1998, 2, 12, 1, 0, 1},
    {"Loaf", 1997, 7, 23, 1, 0, 0},
    {"Bear", 1998, 5, 17, 1, 1, 0}
};


void personUnpacker(struct person i) {
    printf("\n\n%s\n\nBirthday: %02d/%02d/%d\n\nLanguages Spoken: ", i.name, i.birthMonth, i.birthDay, i.birthYear);
    if (i.english) {printf("English, ");}
    if (i.french) {printf("French, ");}
    if (i.spanish) {printf("Spanish");}
}


int main() {
    for(int i = 0; i < 3; i++) {
        personUnpacker(people[i]);
    }
    return 0;
}
