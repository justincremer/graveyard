#include <stdio.h>
#include <windows.h>

// clock variables
int d = 0, h = 23, m = 59, s = 45, tick = 900;

// format and print data to command line
void format() {
    printf("  \nCLOCK\n");
    printf("\n%02d:%02d:%02d:%02d\n", d, h, m, s);
    Sleep(tick);
    system("clear");
}

// update data on tick

void update() {
    ++s;
    if (s > 59) {
        s = 0;
        ++m;
    }
    if (m > 59) {
        m = 0;
        ++h;
    }
    if (h > 23) {
        h = 0;
        ++d;
    }
}

int main()
{
    while(1) {
        format();
        update();
    }

    return 0;
}
