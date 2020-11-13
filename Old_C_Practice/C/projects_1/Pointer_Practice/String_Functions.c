#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//returns the length (int) of a string
int stringLength(char *ptr) {
    int result = 0;
    char *start = ptr;

    while(*ptr) {
        ptr++;
        result++;
    }

    ptr = start;
    return result;
}

//copies a string and returns a char pointer to the copy
char * stringCopy(char *from) {
    char *copy;
    char *ptrStart = copy;

    while(*from)
        *copy++ = *from++;
    *copy = '\0';

    copy = ptrStart;
    return copy;
}


int main(void) {
    char *str = {"hello world"};
    char *newString = stringCopy(str);

    printf("\nCopy of original string: %s\n", newString);

    return 0;
}
