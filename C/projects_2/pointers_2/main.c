#include <stdio.h>
#include <stdlib.h>

char *test1 = "THIS";
char *test2 = "IS A";
char *test3 = "TEST";
char **testPtr = &test1;


void strPrinter(char *i) {
    char *start = i;
    while(*i) {
        printf("%c", *i++);
    }
    printf(" ");
    i = start;
}


int main() {
    strPrinter(*testPtr);
    testPtr = &test2;
    strPrinter(*testPtr);
    testPtr = &test3;
    strPrinter(*testPtr);
    testPtr = &test1;

    printf("\nAddress: %p\nAddress: %p", test1, testPtr);
    return 0;
}
