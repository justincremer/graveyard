#include <stdio.h>

int area() {
    float x, y;

    printf("Length Width: ");
    scanf("%f %f", &x, &y);

    printf("\n%.2f", x*y);
    return 0;
}

int main() {
    return 0;
}

