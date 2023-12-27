#include <stdio.h>
#include <string.h>
#include <math.h>

char arr[2];

int check_flag(char arr[2]);
int func_q(void);
int func_m(void);
int func_t(void);

int main(void) 
{
    printf("Input flag: ");
    if (scanf("%s", arr) == 1)
    {
        if (check_flag(arr))
        {
            if (strcmp(arr, "-q") == 0 || strcmp(arr, "/q") == 0) 
            {
                func_q();
            } 
            else if (strcmp(arr, "-m") == 0 || strcmp(arr, "/m") == 0)
            {
                func_m();
            } 
            else if (strcmp(arr, "-t") == 0 || strcmp(arr, "/t") == 0)
            {
                func_t();
            }
        } 
        else
        {
            printf("You haven't flag\n");
        }
    }
}

int check_flag(char arr[2])
{
    int check=0;
    
    if ((arr[0] == '-' || arr[0] == '/') && (arr[1] == 'q' || arr[1] == 'm' || arr[1] == 't'))
    {
        check=1;
    } 
    else
    {
        check=0;
    }
    return check;
}

int func_q(){
    double a, b, c;
    double discr, x1, x2;
    printf("input:\n");
    printf("a = ");
    if (scanf("%lf", &a) == 0) 
    {
        printf("not a number\n");
        return 0;
    }
    printf("b = ");
    if (scanf("%lf", &b) == 0) 
    {
        printf("not a number\n");
        return 0;
    }
    printf("c = ");
    if (scanf("%lf", &c) == 0) 
    {
        printf("not a number\n");
        return 0;
    }
    discr = b * b - 4 * a * c;
    if (discr > 0) 
    {
        x1 = (-b + sqrt(discr)) / (2*a);
        x2 = (-b - sqrt(discr)) / (2*a);
        printf("two roots:\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }
    else if (discr == 0)
    {
        x1 = -b / (2*a);
        printf("one root:\n");
        printf("x = %.2lf\n", x1);
    }
    else
    {
        printf("no solutions.\n");
    }
    return 0;
}

int func_m()
{
    int num1, num2;
    printf("input 2 numbers\n");
    if (scanf("%d %d", &num1, &num2) == 0)
    {
        printf("repeat\n");
        return 0;
    }
    if (num1 % num2 == 0)
    {
        printf("%d is a multiple of %d\n", num1, num2);
    } else
    {
        printf("%d is not a multiple of %d\n", num1, num2);
    }
    return 0;
}

int func_t()
{
    float a, b, c;
    printf("first side: ");
    if (scanf("%f", &a) == 0)
    {
        printf("not a number\n");
        return 0;
    }
    printf("second side: ");
    if (scanf("%f", &b) == 0)
    {
        printf("not a number\n");
        return 0;
    }
    printf("third side: ");
    if (scanf("%f", &c) == 0)
    {
        printf("not a number\n");
        return 0;
    }
    if (a > 0 && b > 0 && c > 0)
    {
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            printf("right triangle.\n");
        }
        else
        {
            printf("not right triangle.\n");
        }
    }
    else
    {
        printf("error, repeat.\n");
    }
    return 0;
}
