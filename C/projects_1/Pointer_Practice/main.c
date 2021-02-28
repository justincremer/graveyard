#include <stdio.h>
#include <stdlib.h>

int arrSum(int *ptrArr, const int n) {
    int sum = 0;
    int *const ptrArrEnd = ptrArr + n;

    for(; ptrArr != ptrArrEnd; ++ptrArr)
        sum += *ptrArr;


    return sum;
}

char * strCopy(char *str) {
    char *copy;
    char *copyStart = copy;

    for(; *str != '\0'; ++str, ++copy) {
        *copy = *str;
    }
    return copyStart;
}

int strLen(char *ptr) {
    int result =0;
    for(; *ptr != '\0'; ptr++, result++);
    return result;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9}; //45
    char *str = {"hello world"}; //len 11
    char *Copy = strCopy(str);

    printf("\nThe sum of the array is: %d", arrSum(arr, 9));
    printf("\n\nCopying the string...");
    printf("\n\nA copy of the string: %s", Copy);
    printf("\n\nThe length of the string is: %d\n", strLen(str));
    return 0;
}
