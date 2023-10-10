#include <stdio.h>

int main(void) {
    int a;
    printf("input array length ");
    scanf("%d", &a);
    float mass[a - 1];
    printf("fill array\n");
    // for (int i = 0; i <= (a - 2); i++) {
    //     scanf("%f ", &mass[i]);
    // } 
    int b = 0;
    while (b <= a - 1)
    {
        scanf("%f ", &mass[b]);
        b++;
    }
    float max = mass[0], min = mass[0];
    for (int j = 1; j <= (a - 1); j++) {
        if (max <= mass[j]) {
            max = mass[j];
        } else if (min >= mass[j]) {
            min = mass[j];
        } else {
            continue;
        }
    }
    printf("\n%f ", max); 
    printf("%f\n", min);
    printf("array:");
    for (int i = 0; i <= (a-1); i++) {
        printf("%f ", mass[i]);
    }
    int nmax, nmin;
    for (int i = 0; i <= (a - 1); i++) {
        if (mass[i] == max) {
            nmax = i;
        } else if (mass[i] == min) {
            nmin = i;
        }
    }
    mass[nmax] = min;
    mass[nmin] = max;
    printf("\nedit array:");
    for (int i = 0; i <= (a - 1); i++) {
        printf("%f ", mass[i]);
    }
    return 0;
}

