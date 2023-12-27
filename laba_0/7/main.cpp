#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    srand((unsigned int)time(NULL));
    int a;
    printf("input array length: ");
    scanf("%d", &a);
    int mass[a], mass_e[a];
    printf("fill array\n");
    for (int i = 0; i < a; i++) 
    {
        mass[i] = rand() % 1000;
        mass_e[i] = mass[i];
        printf("%d ", mass[i]);
    }
    int max = mass[0], min = mass[0];
    int nmax = 0, nmin = 0;
    for (int j = 0; j < a; j++) 
    {
        if (max <= mass[j]) 
        {
            max = mass[j];
            nmax = j;
        } 
        else if (min >= mass[j])
        {
            min = mass[j];
            nmin = j;
        } 
        else
        {
            continue;
        }
    }
    printf("\n%d ", max);
    printf("%d\n", min);
    printf("array:");
    for (int i = 0; i < a; i++) 
    {
        printf("%d ", mass[i]);
    }
    mass_e[nmax] = min;
    mass_e[nmin] = max;
    printf("\nedit array:");
    for (int i = 0; i < a; i++) 
    {
        printf("%d ", mass_e[i]);
    }
    return 0;
}

