
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    
    printf("input int and positive number\n");
    int a;
    if (scanf("%d", &a) == 1 && a > 0) {

    }
    if ((a > 0) && (a)) {
        char flag[100];
        printf("input flag\n");
        scanf("%s", flag);
        if ((strcmp(flag, "-h") == 0) || (strcmp(flag, "/h") == 0)) {
            int count = 0;
            for (int i = 100; i > 1; i--) {
                if (i % a == 0) {
                    printf("%d\n", i);
                    count = count + 1;
                } 
            }
            if (count == 0) {
                printf("empty");
            }
        } else if ((strcmp(flag, "-s") == 0) || (strcmp(flag, "/s") == 0)) {
            char strA[1000];
            sprintf(strA, "%d", a);
            unsigned long len = strlen((strA));
            for (int i = 0; i <= (int)len; i++) {
                printf("%c ", strA[i]);
            }
        } else if ((strcmp(flag, "-p") == 0) || (strcmp(flag, "/p") == 0)) {
            int simple = 2;
            for (int i = 2; i < a; i = i + 1) {
                if (a % i == 0) {
                    simple = 0;
                    break;
                } else if (a % i != 0) {
                    simple = 1;
                    continue;
                } else {
                    printf("error");
                    simple = 2;
                    break;
                }
            }
            if (simple == 2) {
                printf("error");
            } else if (simple == 1) {
                printf("num is simple");
            } else if (simple == 0) {
                printf("num is composite");
            }

        } else if ((strcmp(flag, "-e") == 0) || (strcmp(flag, "/e") == 0)) {
            if (a <= 10) {
                for (int i = 1; i <= a; i++) {
                    for (int j = 1; j <= 10; j++) {
                        int mult = 1;
                        for (int k = 1; k <= i; k++) {
                            mult = mult * j;
                        }
                        printf("%d ", mult);
                    }
                    printf("\n");
                }
            } else {
                printf("err");
            }

        } else if ((strcmp(flag, "-a") == 0) || (strcmp(flag, "/a") == 0)) {
            int sum = 0;
            for (int i = 1; i <= a; i++) {
                sum = sum + i;
            }
            printf("%d", sum);

        } else if ((strcmp(flag, "-f") == 0) || (strcmp(flag, "/f") == 0)) {
            int fuck = 1;
            for (int i = 1; i <= a; i++) {
                fuck = fuck * i;
            }
            printf("%d", fuck);
        } else {
            printf("input flag again");
        }
    } else {
        printf("input num again");
    }
}
