#include <stdio.h>
#include <string.h>
#include <math.h>

int num=0;
char arr[2];

int check_flag(char array[2]);
int func_h(int num);
int func_p(int num);
int func_s(int num);
int func_e(int num);
int func_a(int num);
int func_f(int num);


int main() {
    printf("Input num: ");
    if (scanf("%d", &num) == 1 && num > 0) {
        printf("Input flag: ");
        if (scanf("%s", arr) == 1){
            if (check_flag(arr)){
                if (strcmp(arr, "-h") == 0 || strcmp(arr, "/h") == 0) {
                    func_h(num);
                } else if (strcmp(arr, "-p") == 0 || strcmp(arr, "/p") == 0) {
                    func_p(num);
                } else if (strcmp(arr, "-s") == 0 || strcmp(arr, "/s") == 0) {
                    func_s(num);
                } else if (strcmp(arr, "-e") == 0 || strcmp(arr, "/e") == 0) {
                    func_e(num);
                } else if (strcmp(arr, "-a") == 0 || strcmp(arr, "/a") == 0) {
                    func_a(num);
                } else if (strcmp(arr, "-f") == 0 || strcmp(arr, "/f") == 0) {
                    func_f(num);
                }
            }
            else{
                printf("You haven't flag\n");
            }
        }
    }
    else{
        printf("You didn't enter a positive integer\n");
    }
    return 0;
}

int check_flag(char array[2]){
    int check=0;
    if ((arr[0] == '-' || arr[0] == '/') && (arr[1] == 'h' || arr[1] == 'p' || arr[1] == 'a' || arr[1] == 'f' || arr[1] == 'e' || arr[1] == 's')){
        check=1;
    } else{
        check=0;
    }
    return check;
}

int func_h(int num){
    int h = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % num == 0) {
            printf("%d ", i);
            h = 1;
        }
    }
    if (h == 0) {
        printf("Empty\n");
    }
    printf("\n");
    return 0;
}

int func_p(int num){
    
    if (0 < num && num <= 3) {
        printf("%d is a prime number\n", num);
        return 0;
    }
    if (num % 2 == 0) {
        printf("%d is a composite number\n", num);
        return 0;
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            printf("%d is a composite number\n", num);
            return 0;
        }
    }
    printf("%d is a prime number\n", num);
    return 0;
    
    
}

int func_s(int num){
    int num1 = num, count = 0;
    while (num1 > 0) {
        num1 = num1 / 10;
        count++;
    }
    char num_str[count + 1];
    snprintf(num_str, strlen(num_str), "%d", num);
    for (int i = 0; i < count; i++) {
        printf("%c ", num_str[i]);
    }
    printf("\n");
    return 0;
}

int func_e(int num){
    if (num > 10) {
        printf("error\n");
        return 0;
    }
    for (int i = 1; i <= 10; i++) {
        
        for (int j = 1; j <= num; j++) {
            printf("%10.0f\t", pow(i, j));
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int func_a(int num){
    
    double mid = ((double)(1 + num) / 2);
    
    printf("summ: %.0f\n", mid * num);
    return 0;
}

int func_f(int num){
    long long fuck = 1;
    for (int i = 1; i <= num; i++) {
        fuck *= i;
    }
    printf("%lld\n", fuck);
    return 0;
}
