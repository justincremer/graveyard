#include <stdio.h>
#include <stdlib.h>



int main()
{
    float cases, deaths;
    float deathRate;

    printf("Enter the current number of cases followed by the number of deaths in your country, separated with a space: ");
    scanf("%f %f", &cases, &deaths);

    deathRate = deaths/cases*100;

    printf("The current death rate in your country is %2.2f%%", deathRate);

    return 0;
}
