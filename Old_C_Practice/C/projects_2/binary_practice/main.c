#include <stdio.h>
#include <stdlib.h>
#include<math.h>

unsigned int SZ = 8;
char buff[9];
const int i = 243; //178
const int j = 236;
int k = (i | j) >> 2;


// int, buff, buff length - 1
static char *binrep (unsigned int val, char *buff, int sz) {
    char *pbuff = buff;

    /* Must be able to store one character at least. */
    if (sz < 1) return NULL;

    /* Special case for zero to ensure some output. */
    if (val == 0) {
        *pbuff++ = '0';
        *pbuff = '\0';
        return buff;
    }

    /* Work from the end of the buffer back. */
    pbuff += sz;
    *pbuff-- = '\0';

    /* For each bit (going backwards) store character. */
    while (val != 0) {
        if (sz-- == 0) return NULL;
        *pbuff-- = ((val & 1) == 1) ? '1' : '0';

        /* Get next bit. */
        val >>= 1;
    }
    return pbuff+1;
}


int main(void) {
    printf("\n   BINARY OPERATIONS            Current max of %d bits\n   -----------------\n\n", SZ);
    printf("   Var I\n     Dec: %d\n     Bin: %s\n\n", i, binrep(i, buff, SZ));
    printf("   Var J\n     Dec: %d\n     Bin: %s\n\n", j, binrep(j, buff, SZ));
    printf("   Var K\n     Dec: %d\n     Bin: %s\n\n\n", k, binrep(k, buff, SZ));
    return 0;
}
