#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pfile = NULL;
    pfile = fopen("test.txt", "r");
    char s[31];

    if(pfile == NULL) {
        perror("Failed to open file");
        return (-1);
    }

    for(int i = 0; i < 3; i++) {
        if(fgets(s, 30, pfile) != NULL) {
        printf("%s", s);
        }
        pfile++;
    }


    fclose(pfile);
    pfile = NULL;

    return 0;
}
